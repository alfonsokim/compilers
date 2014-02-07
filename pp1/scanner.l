/* File:  scanner.l
 * ----------------
 * Lex inupt file to generate the scanner for the compiler.
 */

%option yylineno
%option noyywrap

%{

/* The text within this first region delimited by %{ and %} is assumed to
 * be C/C++ code and will be copied verbatim to the lex.yy.c file ahead
 * of the definitions of the yylex() function. Add other header file inclusions
 * or C++ variable declarations/prototypes that are needed by your code here.
 */

#include <string.h>
#include <sstream>
#include "scanner.h"
#include "utility.h" // for PrintDebug()
#include "errors.h"
#include "location.h"

/* Global variable: yylval
 * -----------------------
 * This global variable is how we get attribute information about the token
 * just scanned to the client. The scanner sets the global variable
 * appropriately and since it's global the client can just read it.  In the
 * future, this variable will be declared for us in the y.tab.c file
 * produced by Yacc, but for now, we declare it manually.
 */
YYSTYPE yylval;  // manually declared for pp1, later Yacc provides

/* Global variable: yylloc
 * -----------------------
 * This global variable is how we get position information about the token
 * just scanned to the client. (Operates similarly to yylval above)
 */
struct yyltype yylloc; // manually dclared for pp1, later Yacc provides

/* Macro: YY_USER_ACTION 
 * ---------------------
 * This flex built-in macro can be defined to provide an action which is
 * always executed prior to any matched rule's action. Basically, it is
 * a way of having a piece of code common to all actions factored out to
 * this routine.  We already defined it for you and left the empty
 * function DoBeforeEachAction ready for your use as needed. It will
 * be called once for each pattern scanned from the file, before
 * executing its action.
 */
static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();

int num_chars = 1;
int num_lines = 1;

%}

 /* The section before the first %% is the Definitions section of the lex
  * input file. Here is where you set options for the scanner, define lex
  * states, and can set up definitions to give names to regular expressions
  * as a simple substitution mechanism that allows for more readable
  * entries in the Rules section later. 
  */

%x STRING

%%             /* BEGIN RULES SECTION */
 /* All patterns and actions should be placed between the start and stop
  * %% markers which delimit the Rules section. 
  */ 

[\n]            { num_chars = 1; num_lines++; }
[[:space:]]     {  }

"+"             { return TokenType::T_Plus; }
"-"             { return TokenType::T_Minus; }
"\*"            { return TokenType::T_Times; }
"\/"            { return TokenType::T_Div; }
"\."            { return TokenType::T_Dot; }    
";"             { return TokenType::T_Colon; }
"\%"            { return TokenType::T_Mod; }
"\!"            { return TokenType::T_Not; }
"\>"            { return TokenType::T_GreaterThan; }
"\<"            { return TokenType::T_LessThan; }
"\,"            { return TokenType::T_Comma; }
"="             { return TokenType::T_Eq; }

"=="            { return TokenType::T_Equal; }
"!="            { return TokenType::T_NotEqual; }
"&&"            { return TokenType::T_And; }
"||"            { return TokenType::T_Or; }
">="            { return TokenType::T_GreaterEqual; }
"<="            { return TokenType::T_LessEqual; }
"\("            { return TokenType::T_OpenParenthesis; }
"\)"            { return TokenType::T_CloseParenthesis; }
"\["            { return TokenType::T_OpenBraces; }
"\]"            { return TokenType::T_CloseBraces; }
"\{"            { return TokenType::T_OpenCurly; }
"\}"            { return TokenType::T_CloseCurly; }

void            { return TokenType::T_Void; } 
"int"           { return TokenType::T_Int; }
double          { return TokenType::T_Double; }
bool            { return TokenType::T_Bool; }
string          { return TokenType::T_String; }
class           { return TokenType::T_Class; }
interface       { return TokenType::T_Interface; }
null            { return TokenType::T_Null; }
this            { return TokenType::T_This; }
extends         { return TokenType::T_Extends; }
implements      { return TokenType::T_Implements; }
for             { return TokenType::T_For; }
while           { return TokenType::T_While; }
if              { return TokenType::T_If; }
else            { return TokenType::T_Else; }
return          { return TokenType::T_Return; }
break           { return TokenType::T_Break; }
New             { return TokenType::T_New; }
NewArray        { return TokenType::T_NewArray; }

"true"          { yylval.boolConstant = true; return TokenType::T_BoolConstant; }
"false"         { yylval.boolConstant = false; return TokenType::T_BoolConstant; }

"\""[^(\")]*"\"" {yylval.stringConstant = yytext; return TokenType::T_StringConstant; }

(0[xX])?[0-9a-fA-F]+     { yylval.integerConstant = atoi(yytext); return TokenType::T_IntConstant; }

[-+]?([0-9]*\.[0-9]+)[eE]?[+-]?[0-9]+ { 
    yylval.doubleConstant = atof(yytext); 
    return TokenType::T_DoubleConstant; 
} 

[a-zA-Z]+[a-zA-Z0-9_]* { 
    if(strlen(yytext) > MaxIdentLen){
        ReportError::LongIdentifier(&yylloc, yytext);
    }
    strcpy(yylval.identifier, yytext);
    return TokenType::T_Identifier; 
}

%%

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated lex.yy.c file.
 * This section is where you put definitions of helper functions.
 */


/* Function: InitScanner
 * ---------------------
 * This function will be called before any calls to yylex().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the scanner (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yy_flex_debug that controls whether flex prints debugging information
 * about each token and what rule was matched. If set to false, no information
 * is printed. Setting it to true will give you a running trail that might
 * be helpful when debugging your scanner. Please be sure the variable is
 * set to false when submitting your final version.
 */
void InitScanner()
{
    PrintDebug("lex", "Initializing scanner");
    yy_flex_debug = false;
}


/* Function: DoBeforeEachAction()
 * ------------------------------
 * This function is installed as the YY_USER_ACTION. This is a place
 * to group code common to all actions.
 */
static void DoBeforeEachAction() {
    yylloc.first_column = num_chars;
    num_chars += strlen(yytext);
    yylloc.last_column = num_chars - 1;
    yylloc.first_line = num_lines;
    yylloc.last_line = num_lines;
}
