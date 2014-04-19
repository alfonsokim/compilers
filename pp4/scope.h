/* File: scope.h
 * -------------
 * The Scope class will be used to manage scopes, sort of
 * table used to map identifier names to Declaration objects.
 */

#ifndef _H_scope
#define _H_scope

#include "hashtable.h"

class Decl;
class VarDecl;
class Expr;
class Type;
class ClassDecl;
class LoopStmt;
class FnDecl;

class Scope { 

  private:
    Scope *parent;

  protected:
    Hashtable<Decl*> *table;
    ClassDecl *classDecl;
    LoopStmt *loopStmt;
    FnDecl *fnDecl;

  public:
    Scope();

    Hashtable<Decl*>* GetTable() { return table; }

    void SetParent(Scope *p) { parent = p; }
    Scope* GetParent() { return parent; }

    void SetClassDecl(ClassDecl *d) { classDecl = d; }
    ClassDecl* GetClassDecl() { return classDecl; }

    void SetLoopStmt(LoopStmt *s) { loopStmt = s; }
    LoopStmt* GetLoopStmt() { return loopStmt; }

    void SetFnDecl(FnDecl *d) { fnDecl = d; }
    FnDecl* GetFnDecl() { return fnDecl; }

    int AddDecl(Decl *decl);

    //Decl* Lookup(Identifier*);
    bool Declare(Decl *dec);
    void CopyFromScope(Scope *other, ClassDecl *cd);

};


#endif
