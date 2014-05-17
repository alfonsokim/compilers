/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp5: You will need to extend the Stmt classes to implement
 * code generation for statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "hashtable.h"
#include "ast.h"
#include "codegen.h"
#include "ast_decl.h"

class VarDecl;
class Expr;

class Scope
{
  public:
    Hashtable<Decl*> *table;

  public:
    Scope() {
      table = new Hashtable<Decl*>();
    }

    void AddDecl(Decl *d) {
      table->Enter(d->GetName(), d);
    }
    
    /*
    friend ostream& operator<<(ostream& out, Scope *s) {
        out << "========== Scope ==========" << std::endl;
        Iterator<Decl*> iter = s->table->GetIterator();
        Decl *d;
        while ((d = iter.GetNextValue()) != NULL)
            out << d << std::endl;
        return out;
    }*/
};

// ===================================================================
// -------------------------------------------------------------------

class Program : public Node
{
  protected:
     List<Decl*> *decls;
     CodeGenerator *generator;
     
  public:
     static Scope *globalScope;

     Program(List<Decl*> *declList);
     void Check();
     void Emit();
};

// ===================================================================
// -------------------------------------------------------------------

class Stmt : public Node
{
  public:
     Stmt() : Node() { scope = new Scope; }
     Stmt(yyltype loc) : Node(loc) { scope = new Scope; }

     //virtual void BuildScope() = 0;
     void BuildScope() {}

};

// ===================================================================
// -------------------------------------------------------------------

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class LoopStmt : public ConditionalStmt 
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;
  
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class WhileStmt : public LoopStmt 
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);
    void BuildScope();
};

// ===================================================================
// -------------------------------------------------------------------

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);
    void BuildScope();
};


#endif
