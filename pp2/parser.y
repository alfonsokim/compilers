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
    WhileStmt *whileStmt;
    ForStmt *forStmt;
    ReturnStmt *returnStmt;
    BreakStmt *breakStmt;
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    LValue *lValue;
    Call *call;
    List<Expr*> *exprList;
    PrintStmt *printStmt;
    Case *caseStmt;
    List<Case*> *caseList;
    Default *defaultExpr;
    SwitchStmt *switchStmt;
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
%token   T_Joe T_Switch T_Case T_Default 

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
%type <whileStmt>     WhileStmt
%type <forStmt>       ForStmt
%type <returnStmt>    ReturnStmt
%type <breakStmt>     BreakStmt
%type <lValue>        LValue
%type <expr>          Constant
%type <call>          Call
%type <exprList>      ExprList
%type <exprList>      CommaExprList
%type <exprList>      Actuals
%type <printStmt>     PrintStmt
%type <caseStmt>      Case
%type <caseList>      CaseList
%type <defaultExpr>   Default
%type <switchStmt>    SwitchStmt

// =============================================================
// =============================================================

%left  T_Equal
%left  '+'
%left  '/'
%left  '-'
%left  '*'

/*
%left  T_Or
%left  T_And
%left  T_NotEqual
%left  T_GreaterEqual
%left  T_LessEqual
%left  T_Dims
%left  T_Increment
%left  T_Decrement
%left  '>'
%left  '<'
%left  '%'
%right '!'
%left  '.'
%left  '['
%left  ']'
%right '='
*/

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
DeclList        : DeclList Decl        { ($$=$1)->Append($2); }
                | Decl                 { ($$ = new List<Decl*>)->Append($1); }
                | /* empty */          { $$ = new List<Decl*>; }
                ;

// =============================================================
// -------------------------------------------------------------
Decl            : VarDecl              { $$ = $1; }
                | FnDecl               { $$ = $1; }
                | ClassDecl            { $$ = $1; }
                | InterfaceDecl        { $$ = $1; }
                ;

// =============================================================
// -------------------------------------------------------------
VarDecl         : Var ';'              { $$ = $1; }
                ;

// =============================================================
// -------------------------------------------------------------
Var             : Type T_Identifier    { 
                              Identifier *id = new Identifier(@2, $2);
                              $$ = new VarDecl(id, $1);
                      }

// =============================================================
//              | T_Identifier          { Identifier *id = new Identifier(@1, $1); }
//              | T_Void                { $$ = new Type(*Type::voidType); }
//              void no se puede declarar como tipo por que se permitiria
//              como variable: void a = 10;
// -------------------------------------------------------------
Type            : T_Int                 { $$ = new Type(*Type::intType); }
                | T_Double              { $$ = new Type(*Type::doubleType); }
                | T_Bool                { $$ = new Type(*Type::boolType); }
                | T_String              { $$ = new Type(*Type::stringType); }
                | Type T_Dims           { $$ = new ArrayType(@1, $1); }
                | T_Identifier          { Identifier *id = new Identifier(@1, $1);
                                          $$ = new NamedType(id); }
                ;

// =============================================================
// -------------------------------------------------------------
VarList         : VarList ',' Var       { ($$ = $1)->Append($3); }
                | Var                   { ($$ = new List<VarDecl*>)->Append($1); }
                |                       { ($$ = new List<VarDecl*>); }
                ;

// =============================================================
// Constructor del FnDecl:
// FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
// TODO: Llamar a void SetFunctionBody(Stmt *b);
// -------------------------------------------------------------
FnDecl          : Type T_Identifier '(' VarList ')' StmtBlock  {
                          $$ = new FnDecl(new Identifier(@2, $2), $1, $4);
                          $$->SetFunctionBody($6);
                    }
                | T_Void T_Identifier '(' VarList ')' StmtBlock  {
                                              $$ = new FnDecl(new Identifier(@2, $2), 
                                                              new Type(*Type::voidType),
                                                              $4);
                                              $$->SetFunctionBody($6);
                    }
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
                | WhileStmt               { ($$ = $1); }
                | ForStmt                 { ($$ = $1); }
                | ReturnStmt              { ($$ = $1); }
                | BreakStmt               { ($$ = $1); }
                | PrintStmt               { ($$ = $1); }
                | SwitchStmt              { ($$ = $1); }
                ;


// =============================================================
// NewExpr(yyltype loc, NamedType *clsType);
// -------------------------------------------------------------
Expr            : LValue                  { ($$ = $1); }
                | LValue '=' Expr         { 
                                    Operator *op = new Operator(@2, "=");
                                    $$ = new AssignExpr($1, op, $3);
                              }
                | T_ReadLine '(' ')'      { ($$ = new ReadLineExpr(@1)); }
                | T_New '(' T_Identifier ')' { ($$ = new NewExpr(@1, 
                                                    new NamedType(new Identifier(@3, $3))
                                            )); 
                              }
                | T_This                  { $$ = new This(@1); }
                | Constant                { $$ = $1; }
                | Call                    { $$ = $1; }
                | T_ReadInteger '(' ')'   { $$ = new ReadIntegerExpr(@1); }
                | '(' Expr ')'            { $$ = $2; }
                | Expr '+' Expr        { Operator *op = new Operator(@2, "+");
                                            $$ = new ArithmeticExpr($1, op, $3);
                                          }
                | Expr '-' Expr        { Operator *op = new Operator(@2, "-");
                                            $$ = new ArithmeticExpr($1, op, $3);
                                          }
                | Expr '*' Expr        { Operator *op = new Operator(@2, "*");
                                            $$ = new ArithmeticExpr($1, op, $3);
                                          }
                | Expr '/' Expr        { Operator *op = new Operator(@2, "/");
                                            $$ = new ArithmeticExpr($1, op, $3);
                                          }
                | Expr '%' Expr        { Operator *op = new Operator(@2, "%");
                                            $$ = new ArithmeticExpr($1, op, $3);
                                          }
                | '-' Expr             { Operator *op = new Operator(@1, "-");
                                            $$ = new ArithmeticExpr(op, $2);
                                          }
                | Expr '<' Expr        { Operator *op = new Operator(@2, "<");
                                            $$ = new RelationalExpr($1, op, $3);
                                          }
                | Expr T_LessEqual Expr {
                                            Operator *op = new Operator(@2, "<=");
                                            $$ = new RelationalExpr($1, op, $3);
                                          }
                | Expr '>' Expr        { Operator *op = new Operator(@2, ">");
                                            $$ = new RelationalExpr($1, op, $3);
                                          }
                | Expr T_GreaterEqual Expr {
                                            Operator *op = new Operator(@2, ">=");
                                            $$ = new RelationalExpr($1, op, $3);
                                          }
                | Expr T_Equal Expr    { Operator *op = new Operator(@2, "==");
                                            $$ = new EqualityExpr($1, op, $3);
                                          }
                | Expr T_NotEqual Expr {
                                            Operator *op = new Operator(@2, "!=");
                                            $$ = new EqualityExpr($1, op, $3);
                                          }
                | Expr T_And Expr      {
                                            Operator *op = new Operator(@2, "&&");
                                            $$ = new LogicalExpr($1, op, $3);
                                          }
                | Expr T_Or Expr       {
                                            Operator *op = new Operator(@2, "||");
                                            $$ = new LogicalExpr($1, op, $3);
                                          }
                | '!' Expr             { Operator *op = new Operator(@1, "!");
                                            $$ = new LogicalExpr(op, $2);
                                          }
                | T_NewArray '(' Expr ',' Type ')' {
                                      $$ = new NewArrayExpr(@1, $3, $5);
                                    }
                ;

// =============================================================
// -------------------------------------------------------------
OneExpr         : Expr                 { $$ = $1; }
                |                      { $$ = new EmptyExpr(); }
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
                |                     { $$ = NULL; }
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
                |                     { $$ = new List<NamedType*>; }
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
                | /* nada */              { $$ = new List<Decl*>; }
                ;

// =============================================================
// InterfaceDecl(Identifier *name, List<Decl*> *members);
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

// =============================================================
// WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
// -------------------------------------------------------------
WhileStmt       : T_While '(' Expr ')' Stmt {
                          $$ = new WhileStmt($3, $5);
                    }
                ;

// =============================================================
// ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
// -------------------------------------------------------------
ForStmt         : T_For '(' OneExpr ';' Expr ';' OneExpr ')' Stmt {
                          $$ = new ForStmt($3, $5, $7, $9);
                    }
                ;


// =============================================================
// ReturnStmt(yyltype loc, Expr *expr);
// -------------------------------------------------------------
ReturnStmt      : T_Return OneExpr ';' {
                          $$ = new ReturnStmt(@1, $2);
                    }
                ;

// =============================================================
// BreakStmt(yyltype loc) : Stmt(loc) {}
// -------------------------------------------------------------
BreakStmt       : T_Break ';' {
                          $$ = new BreakStmt(@1);
                    }
                ;

// =============================================================
// LValue(yyltype loc) : Expr(loc) {}
// ident |  Expr  . ident | Expr [ Expr ]
// FieldAccess(Expr *base, Identifier *field); //ok to pass NULL base
// ArrayAccess(yyltype loc, Expr *base, Expr *subscript);
// -------------------------------------------------------------
LValue    :    T_Identifier         { 
                            Identifier *id = new Identifier(@1, $1);
                            $$ = new FieldAccess(NULL, id);
                      }
          | Expr '.' T_Identifier {
                            Identifier *id = new Identifier(@3, $3);
                            $$ = new FieldAccess($1, id);
                      }
          | Expr '[' Expr ']'    { 
                            $$ = new ArrayAccess(@1, $1, $3); 
                      }
          ;

// =============================================================
// IntConstant(yyltype loc, int val);
// DoubleConstant(yyltype loc, double val);
// BoolConstant(yyltype loc, bool val);
// StringConstant(yyltype loc, const char *val);
// NullConstant(yyltype loc) : Expr(loc) {}
// -------------------------------------------------------------
Constant  : T_IntConstant        { $$ = new IntConstant(@1, $1); }
          | T_DoubleConstant     { $$ = new DoubleConstant(@1, $1); }
          | T_BoolConstant       { $$ = new BoolConstant(@1, $1); }
          | T_StringConstant     { $$ = new StringConstant(@1, $1); }
          | T_Null               { $$ = new NullConstant(@1); }
          ;

// =============================================================
// Call ::= ident ( Actuals ) | Expr . ident ( Actuals )
// Call(yyltype loc, Expr *base, Identifier *field, List<Expr*> *args);
// -------------------------------------------------------------
Call      : T_Identifier '(' Actuals ')' {
                                      Identifier *id = new Identifier(@1, $1);
                                      $$ = new Call(@1, NULL, id, $3);
                                    }
          | Expr '.' T_Identifier '(' Actuals ')' {
                                      Identifier *id = new Identifier(@3, $3);
                                      $$ = new Call(@2, $1, id, $5);
                                    }
          ;

// =============================================================
// Actuals ::= Expr+, | ε
// -------------------------------------------------------------
Actuals   : CommaExprList        { $$ = $1; }
          |                      { $$ = new List<Expr*>; }
          ;

// =============================================================
// 
// -------------------------------------------------------------
ExprList  : ExprList Expr           { ($$ = $1)->Append($2); }
          | Expr                    { ($$ = new List<Expr*>)->Append($1); }
          ;

// =============================================================
// -------------------------------------------------------------
CommaExprList  : CommaExprList ',' Expr     { ($$=$1)->Append($3); }
               | Expr              { 
                             ($$ = new List<Expr*>)->Append($1);
                                    }
               ;

// =============================================================
// PrintStmt(List<Expr*> *arguments);
// -------------------------------------------------------------
PrintStmt :    T_Print '(' CommaExprList ')' ';' { $$ = new PrintStmt($3); }

// =============================================================
// -------------------------------------------------------------
Case      : T_Case T_IntConstant ':' StmtList {
                                      $$ = new Case(new IntConstant(@2, $2), $4);
                                    }
          ;

// =============================================================
// -------------------------------------------------------------
CaseList  : CaseList Case     { ($$ = $1)->Append($2);  }
          | Case              { ($$ = new List<Case*>)->Append($1); }
          ;

// =============================================================
// -------------------------------------------------------------
Default   : T_Default ':' StmtList  { $$ = new Default($3); }
          ;

// =============================================================
// -------------------------------------------------------------
SwitchStmt : T_Switch '(' Expr ')' '{' CaseList '}' {
                                      $$ = new SwitchStmt($3, $6, NULL);
                                    }
           | T_Switch '(' Expr ')' '{' CaseList Default '}' {
                                      $$ = new SwitchStmt($3, $6, $7);
                                    }
          ;

// =============================================================
// -------------------------------------------------------------

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
