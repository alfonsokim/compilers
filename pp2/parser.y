/* File: parser.y
 * --------------
 * Yacc input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should 
 *      accept the language as described in specification, and as augmented 
 *      in the pp2 handout.
 */

%{

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(char *msg); // standard error-handling routine

%}

/*
=== Donde esta cada clase?? ===
Identifier: ast.h
Type: ast_decl.h
NamedType: ast_decl.h
Identifier: ast_decl.h
Stmt: ast_decl.h
Decl: ast_decl.h
VarDecl: ast_decl.h
ClassDecl: ast_decl.h
InterfaceDecl: ast_decl.h
FnDecl: ast_decl.h
Type: ast_expr.h
Expr: ast_expr.h
EmptyExpr: ast_expr.h
IntConstant: ast_expr.h
DoubleConstant: ast_expr.h
BoolConstant: ast_expr.h
StringConstant: ast_expr.h
NullConstant: ast_expr.h
Operator: ast_expr.h
CompoundExpr: ast_expr.h
ArithmeticExpr: ast_expr.h
RelationalExpr: ast_expr.h
EqualityExpr: ast_expr.h
LogicalExpr: ast_expr.h
AssignExpr: ast_expr.h
LValue: ast_expr.h
This: ast_expr.h
ArrayAccess: ast_expr.h
FieldAccess: ast_expr.h
Call: ast_expr.h
NewExpr: ast_expr.h
NewArrayExpr: ast_expr.h
ReadIntegerExpr: ast_expr.h
ReadLineExpr: ast_expr.h
Type: ast_type.h
NamedType: ast_type.h
ArrayType: ast_type.h
*/

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */
 
/* yylval 
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attibute information about the token just scanned
 * and thus communicate that information to the parser. 
 *
 * pp2: You will need to add new fields to this union as you add different 
 *      attributes to your non-terminal symbols.
 */
%union {
    Decl *decl;
    List<Decl*> *declList;
    List<VarDecl*> *varList;
    List<VarDecl*> *varDeclList;
    List<Stmt*> *stmtList;
    List<Identifier*> *identifierList;
    List<NamedType*> *implementList;
    StmtBlock *stmtBlock;
    VarDecl *varDecl;
    VarDecl *var;
    Type  *type;
    FnDecl *fnDecl;
    Decl *field;
    Decl *prototype;
    List<Decl*> *fieldList;
    ClassDecl *classDecl;
    NamedType *namedType;
    List<Decl*> *prototypeList;
    InterfaceDecl *interfaceDecl;
    Stmt *stmt;
    Expr *expr;
    IfStmt *ifStmt;
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
}

/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Yacc will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */

%token   T_Void T_Bool T_Int T_Double T_String T_Class 
%token   T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Dims
%token   T_And T_Or T_Null T_Extends T_This T_Interface T_Implements
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_New T_NewArray T_Print T_ReadInteger T_ReadLine

%token   <identifier> T_Identifier
%token   <stringConstant> T_StringConstant 
%token   <integerConstant> T_IntConstant
%token   <doubleConstant> T_DoubleConstant
%token   <boolConstant> T_BoolConstant


/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */

// ============= DECLARACIONES =============
%type <declList>      DeclList
%type <stmtList>      StmtList
%type <stmtBlock>     StmtBlock
%type <decl>          Decl
%type <stmt>          Stmt
%type <classDecl>     ClassDecl
%type <namedType>     Extends
%type <identifierList> IdentifierList
%type <implementList> Implements
%type <field>         Field
%type <fieldList>     FieldList
%type <prototype>     Prototype
%type <prototypeList> PrototypeList
%type <interfaceDecl> InterfaceDecl
// ArrayType no es necesario declararlo como tipo


// ============== EXPRESIONES ==============
%type <varList>       VarList
%type <varDeclList>   VarDeclList
%type <var>           Var
%type <varDecl>       VarDecl
%type <type>          Type
%type <fnDecl>        FnDecl
%type <expr>          Expr
%type <expr>          OneExpr
%type <ifStmt>        IfStmt

// =============================================================
// =============================================================
// =============================================================

%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
*/	 

// en @1 esta yyltype

// =============================================================
// -------------------------------------------------------------
Program         :    DeclList   { 
                            @1; 
                            /* pp2: The @1 is needed to convince 
                             * yacc to set up yylloc. You can remove 
                             * it once you have other uses of @n*/
                            Program *program = new Program($1);
                            if (ReportError::NumErrors() == 0) {
                                // if no errors, advance to next phase
                                program->Print(0);
                            }
                      }
                ;

// =============================================================
// -------------------------------------------------------------
DeclList        :    DeclList Decl        { ($$=$1)->Append($2); }
                |    Decl                 { ($$ = new List<Decl*>)->Append($1); }
                ;

// =============================================================
// -------------------------------------------------------------
Decl            :    VarDecl              { $$ = $1; }
                |    FnDecl               { $$ = $1; }
                |    ClassDecl            { $$ = $1; }
                |    InterfaceDecl        { $$ = $1; }
                ;

// =============================================================
// -------------------------------------------------------------
VarDecl         :    Var ';'              { $$ = $1; }
                ;

// =============================================================
// -------------------------------------------------------------
Var             :    Type T_Identifier    { 
                              Identifier *id = new Identifier(@2, $2);
                              $$ = new VarDecl(id, $1);
                      }

// =============================================================
//              |   T_Identifier          { Identifier *id = new Identifier(@1, $1); }
//              |   T_Void                { $$ = new Type(*Type::voidType); }
//              void no se puede declarar como tipo por que se permitiria
//              como variable: void a = 10;
// -------------------------------------------------------------
Type            :   T_Int                 { $$ = new Type(*Type::intType); }
                |   T_Double              { $$ = new Type(*Type::doubleType); }
                |   T_Bool                { $$ = new Type(*Type::boolType); }
                |   T_String              { $$ = new Type(*Type::stringType); }
                |   Type T_Dims           { $$ = new ArrayType(@1, $1); }
                ;

// =============================================================
// -------------------------------------------------------------

VarList         : VarList ',' Var         { ($$ = $1)->Append($3); }
                | Var                     { ($$ = new List<VarDecl*>)->Append($1); }
                |                         { ($$ = new List<VarDecl*>); }
                ;

// =============================================================
// Constructor del FnDecl:
// FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
// TODO: Llamar a void SetFunctionBody(Stmt *b);
// -------------------------------------------------------------
FnDecl          :   Type T_Identifier '(' VarList ')' StmtBlock  {
                          $$ = new FnDecl(new Identifier(@2, $2), $1, $4);
                          $$->SetFunctionBody($6);
                    }
                |   T_Void T_Identifier '(' VarList ')' StmtBlock  {
                                              $$ = new FnDecl(new Identifier(@2, $2), 
                                                              new Type(*Type::voidType),
                                                              $4);
                                              $$->SetFunctionBody($6);
                    }
                |                         {  }
                ;

// =============================================================
// -------------------------------------------------------------
VarDeclList     : VarDeclList VarDecl     { ($$ = $1)->Append($2); }
                | VarDecl                 { ($$ = new List<VarDecl*>)->Append($1); }
                ;

// =============================================================
// -------------------------------------------------------------
StmtBlock       : '{' VarDeclList StmtList '}' { $$ = new StmtBlock($2, $3); 
                                          }
                | '{' VarDeclList '}'     { List<Stmt*> *s = new List<Stmt*>;
                                            $$ = new StmtBlock($2, s);
                                          }
                | '{' StmtList '}'        { List<VarDecl*> *v = new List<VarDecl*>;
                                            $$ = new StmtBlock(v, $2);  
                                          }
                | '{' '}'                 { List<VarDecl*> *v = new List<VarDecl*>;
                                            List<Stmt*> *s = new List<Stmt*>;
                                            $$ = new StmtBlock(v, s);
                                          }
                ;

// =============================================================
// -------------------------------------------------------------
StmtList        : StmtList Stmt           { ($$ = $1)->Append($2); }
                | Stmt                    { ($$ = new List<Stmt*>)->Append($1); }
                ;

// =============================================================
// -------------------------------------------------------------
Stmt            : OneExpr ';'             { ($$ = $1); }
                | StmtBlock               { ($$ = $1); }
                | IfStmt                  { ($$ = $1); }
                ;


// =============================================================
// NewExpr(yyltype loc, NamedType *clsType);
// -------------------------------------------------------------
Expr            : T_ReadLine '(' ')'      { ($$ = new ReadLineExpr(@1)); }
                | T_New T_Identifier      { ($$ = new NewExpr(@1, 
                                                      new NamedType(new Identifier(@2, $2))
                                            )); 
                                          }
                ;

// =============================================================
// -------------------------------------------------------------
OneExpr         : Expr                    { $$ = $1; }
                |                         { $$ = new EmptyExpr(); }
                ;

// =============================================================
// ClassDecl(Identifier *name, NamedType *extends, 
//            List<NamedType*> *implements, List<Decl*> *members);
// -------------------------------------------------------------
ClassDecl       : T_Class T_Identifier Extends Implements '{' FieldList '}' {  
                                        Identifier *id = new Identifier(@2, $2);
                                        $$ = new ClassDecl(id, $3, $4, $6);
                                      }
                ;

// =============================================================
// -------------------------------------------------------------
Extends         : T_Extends T_Identifier     {
                                      Identifier *id = new Identifier(@2, $2);
                                      $$ = new NamedType(id);
                                    }
                |                        { $$ = NULL; }
                ;

// =============================================================
// -------------------------------------------------------------
IdentifierList  : IdentifierList ',' T_Identifier     {
                                      ($$=$1)->Append(new Identifier(@3, $3));
                                    }
                | T_Identifier   { 
                                      ($$ = new List<Identifier*>)->Append(new Identifier(@1, $1));
                                    }
                ;


// =============================================================
// -------------------------------------------------------------
Implements      : T_Implements IdentifierList     {
                                      $$ = new List<NamedType*>;
                                      for (int i = 0; i < $2->NumElements(); i++ )
                                        $$->Append(new NamedType($2->Nth(i)));
                                    }
                |                        { $$ = new List<NamedType*>; }
                ;

// =============================================================
// -------------------------------------------------------------
Field           : VarDecl          { $$ = $1; }
                | FnDecl           { $$ = $1; }
                ;

// =============================================================
// -------------------------------------------------------------
FieldList       : FieldList Field   { ($$ = $1)->Append($2); }
                |                   { $$ = new List<Decl*>; }
                ;
        
// =============================================================
// FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
// -------------------------------------------------------------
Prototype       : Type T_Identifier '(' VarList ')' ';' {
                              Identifier *id = new Identifier(@2, $2);
                              $$ = new FnDecl(id, $1, $4);
                        }
                | T_Void T_Identifier '(' VarList ')' ';' {
                              Identifier *id = new Identifier(@2, $2);
                              $$ = new FnDecl(id, new Type(*Type::voidType), $4);
                        }
                ;

// =============================================================
// -------------------------------------------------------------
PrototypeList   : PrototypeList Prototype { ($$=$1)->Append($2); }
                | Prototype               { ($$ = new List<Decl*>)->Append($1); }
                ;

// =============================================================
// -------------------------------------------------------------
InterfaceDecl   : T_Interface T_Identifier '{' PrototypeList '}' {
                              Identifier *id = new Identifier(@2, $2);
                              $$  = new InterfaceDecl(id, $4);
                        }
                ;
          ;

// =============================================================
// IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
// -------------------------------------------------------------
IfStmt          : T_If '(' Expr ')' Stmt {
                            $$ = new IfStmt($3, $5, NULL);
                        }
                | T_If '(' Expr ')' Stmt T_Else Stmt {
                            $$ = new IfStmt($3, $5, $7);
                }
                ;

%%

// =============================================================
// =============================================================
// =============================================================

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}
