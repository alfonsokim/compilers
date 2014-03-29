/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "errors.h"
        
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()), scope(new Scope) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

bool Decl::IsEquivalentTo(Decl *other) {
    return true;
}

Scope* Decl::GetScope() { return scope; }

// Construccion del arbol de scope
void Decl::BuildScope(Scope* parent) {
    scope->SetParent(parent);
}

void Decl::Check() {

}

const char* Decl::Name() {
    return id->Name();
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}

void VarDecl::Check(){
    if (type->IsPrimitive()){
        return;
    }

    Scope *s = scope;
    while (s != NULL) {
        Decl *d;
        if ((d = s->table->Lookup(type->Name())) != NULL) {
            if (dynamic_cast<ClassDecl*>(d) == NULL &&
                dynamic_cast<InterfaceDecl*>(d) == NULL) {
                type->ReportNotDeclaredIdentifier(LookingForType);
            }
            
            return;
        }
        s = s->GetParent();
    }

    type->ReportNotDeclaredIdentifier(LookingForType);
}
  

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}


InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

	
FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}



