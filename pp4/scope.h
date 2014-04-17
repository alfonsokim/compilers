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
    Scope* parent;

  protected:
    Hashtable<Decl*> *table;
    ClassDecl *classDecl;
    LoopStmt *loopStmt;
    FnDecl *fnDecl;

  public:
    Scope() : table(new Hashtable<Decl*>), 
              classDecl(NULL), 
              loopStmt(NULL), 
              fnDecl(NULL) {}

    Hashtable<Decl*>* GetTable() { return table; }    
    Decl* Lookup(Identifier*);
    bool Declare(Decl*);
    void CopyFromScope(Scope*, ClassDecl*);

    void SetParent(Scope* p) { parent = p; }
    Scope* GetParent() { return parent; }



};


#endif
