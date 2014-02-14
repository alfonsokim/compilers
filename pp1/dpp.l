/*
 * file:  dpp.l
 * ------------
 * Lex inupt file to generate the scanner for the preprocessor.
 * If you decide to use lex for the preprocesor, put your rules
 * here, otherwise the file can remain empty.
 */

%{
#include <map>
#include <string>

#include "errors.h"

static void define(char*, char*);
static void replace(char*);
char* defining;

std::map<std::string, std::string> replacements;

int line_number = 1;
%}

%x COMMENT
%x STRING
%x DEFINE
%x IN_DEFINE
%x REPLACE

%%

"\n"                    { printf("\n"); line_number++; }

\/\/(.*)                {  }

<INITIAL>"/*"           { BEGIN(COMMENT);  }
<COMMENT>"*/"           { BEGIN(INITIAL);  }  
<COMMENT>"\n"           { printf("\n"); line_number++;  }
<COMMENT>([^*]|\n)+|.   { }
<COMMENT><<EOF>>        { ReportError::UntermComment(); yyterminate(); }

<INITIAL>"\""           { BEGIN(STRING); printf("\"");  }
<STRING>"\""            { BEGIN(INITIAL); printf("\""); }

<INITIAL>"#define "    { BEGIN(DEFINE); }
<DEFINE>"\n"           { BEGIN(INITIAL); printf("\n"); }
<DEFINE>[A-Z]+         { BEGIN(IN_DEFINE); defining = strdup(yytext); }
<DEFINE>[^A-Z]+        { ReportError::InvalidDirective(line_number); }

<IN_DEFINE>"\n"        { BEGIN(INITIAL); printf("\n"); }
<IN_DEFINE>[a-zA-Z0-9" "\.\+\-\*\/\{\}]+  { define(defining, yytext); }

<INITIAL>"#"[A-Z]+     {  BEGIN(REPLACE); replace(yytext); }
<REPLACE>"\n"          {  BEGIN(INITIAL); printf("\n"); }



%%

// *******************************************************************

static void define(char* defining, char* replace){
    replace++; // recortar el primer espacio
    replacements[std::string(defining)] = std::string(replace);
}

static void replace(char* replace){
    replace++; // recortar el primer espacio
    std::map<std::string, std::string>::iterator got = replacements.find(replace);
    if ( got == replacements.end() ) {
        ReportError::InvalidDirective(line_number);
    } else {
        printf("%s", got->second.c_str());
    }
}