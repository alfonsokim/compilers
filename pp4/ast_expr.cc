/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>

#include "errors.h"


IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}
CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}
   
  
ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}
     
FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}


Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

Type* Call::GetType() {
    /*
    Decl *d;

    if (base == NULL) {
        ClassDecl *c = GetClassDecl(scope);
        if (c == NULL) {
            if ((d = GetFieldDecl(field, scope)) == NULL)
                return Type::errorType;
        } else {
            if ((d = GetFieldDecl(field, c->GetType())) == NULL)
                return Type::errorType;
        }
    } else {
        Type *t = base->GetType();
        if ((d = GetFieldDecl(field, t)) == NULL) {

            if (dynamic_cast<ArrayType*>(t) != NULL &&
                strcmp("length", field->Name()) == 0)
                return Type::intType;

            return Type::errorType;
        }
    }

    if (dynamic_cast<FnDecl*>(d) == NULL)
        return Type::errorType;

    return static_cast<FnDecl*>(d)->GetReturnType();
    */
    return NULL;
}

void Call::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    if (base != NULL) {
        base->BuildScope(scope);
    }

    for (int i = 0, n = actuals->NumElements(); i < n; ++i) {
        actuals->Nth(i)->BuildScope(scope);
    }
}

void Call::Check(){

    if (base == NULL) {
        printf("base es null\n");
        printf("field [%s]\n", field->GetName());
        
        ClassDecl *c = GetClassDecl();
        if (c == NULL) {
            printf("class en scope null\n");
            /*
            if ((d = GetFieldDecl(field, scope)) == NULL) {
                CheckActuals(d);
                ReportError::IdentifierNotDeclared(field, LookingForFunction);
                return;
            }
            */
        } else { // No esta dentro de una clase
            printf("class en scope [%s]\n", c->GetName());
            Decl* d = GetFieldDecl(field);
        }
    } else { // base != NULL
        base->Check();
    }
}
 

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}


NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

ClassDecl* Expr::GetClassDecl() {
    Node *n = this;
    while (n != NULL) {
        if (dynamic_cast<ClassDecl*>(n))
            return static_cast<ClassDecl*>(n);
        n = n->GetParent();
    }
    return NULL;
}   


void Expr::BuildScope(Scope* scope){

}


Decl* Expr::GetFieldDecl(Identifier *field) {
    Node* n = this;
    while (n != NULL) {
        printf("n[%s]\n", n ? "not null" : " null");
        printf("n.scope[%s]\n", n->GetScope() ? "not null" : " null");
        printf("n.scope.table[%s]\n", n->GetScope()->GetTable() ? "not null" : " null");
        Decl *d = n->GetScope()->GetTable()->Lookup(field->GetName());
        if (d != NULL)
            return d;
        n = n->GetParent();
    }
    return NULL;
}
