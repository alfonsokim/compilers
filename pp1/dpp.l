/*
 * file:  dpp.l
 * ------------
 * Lex inupt file to generate the scanner for the preprocessor.
 * If you decide to use lex for the preprocesor, put your rules
 * here, otherwise the file can remain empty.
 */

%{
#include "scanner.h"
#include "utility.h"
#include "errors.h"
#include <string>
#include <vector>

void inDefine( char* ); 
char* macro;
%}

/* ************************************************************
***************************************************************
************************************************************ */

UPPER_CASE      [A-Z]
SINGLE_COMMENT  (\/\/).*
%x IN_COMMENT
%x DEFINE

/* ************************************************************
***************************************************************
************************************************************ */

%%

<INITIAL>{
    "/*"        { BEGIN(IN_COMMENT); }
    "#define "  { BEGIN DEFINE; }
}

<IN_COMMENT>{
    "*/"      BEGIN(INITIAL);
    [^*\n]+   // eat comment in chunks
    "*"       // eat the lone star
    \n        yylineno++;
    <<EOF>>   { ReportError::UntermComment(); yyterminate(); } 
}

<DEFINE>[A-Z]+ {
    macro = yytext;
    printf("D[%s]\n", macro );
}

<DEFINE>[a-z0-9]+([ \.\+]*[a-z0-9]*)* {
    string aMacro = string(macro);
    string currentText = string(yytext);
    string currentMacro = aMacro.substr(0, aMacro.size()-currentText.size()-1);

    printf("M[%s] d[%s]\n", currentMacro.c_str(), yytext );
}

<DEFINE>\n {
    BEGIN(INITIAL);
}

{SINGLE_COMMENT}  { }

%%

// .*              { inDefine(yytext); printf("define[%s]", yytext); } 
/*
    \n              BEGIN(INITIAL);
    [A-Z]+          { printf("D[%s]", yytext ); };
    [[:alnum:]]+    { printf("d[%s]", yytext ); };
*/

/* ************************************************************
***************************************************************
************************************************************ */

void inDefine(char* line){

}

/*
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
*/


void InitScanner()
{
    PrintDebug("lex", "Initializing preprocessor");
    yy_flex_debug = false;
}