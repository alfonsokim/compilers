/* File: dppmain.cc
 * ----------------
 * This file defines the main() routine for the preprocessor, 
 * the filtering tool which runs before the compiler.
 */
 

#include <string.h>
#include <stdio.h>
#include "utility.h"
#include "errors.h"
#include "scanner.h"
#include "location.h"

/* Function: main()
 * ----------------
 * Entry point to the preprocessor.
 * As given below, this "filter" just copies stdin to stdout unchanged.
 * It will be your job to actually do some filtering, either by hand-coded
 * transformation of the input or by setting up a lex scanner in the dpp.l
 * file and changing the main below to invoke it via yylex. When finished,
 * the preprocessor should echo stdin to stdout making the transformations
 * to strip comments and handle preprocessor directives.
 */
     /*
      int ch;
      while ((ch = getc(stdin)) != EOF)
        putc(ch, stdout);
      return 0;
    */
int main(int argc, char *argv[]){
    //InitScanner();
    TokenType token;
    while ((token = (TokenType)yylex()) != 0);
    return (ReportError::NumErrors() == 0? 0 : -1);
}