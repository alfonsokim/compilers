/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"

Decl::Decl(Identifier *n) : Node(*n->GetLocation()), scope(new Scope) {
    Assert(n != NULL);
    (id=n)->SetParent(this);
}

bool Decl::ConflictsWithPrevious(Decl *prev) {
     ReportError::DeclConflict(this, prev);
     return true;
}

bool Decl::IsEquivalent(Decl *other) {
    /* TODO: Once all subclasses support this function it should be made a pure
     * virtual function.
     */
    return true;
}

void Decl::BuildScope(Scope *parent) {
    scope->SetParent(parent);
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    //printf("Constructor VarDecl con type %snull\n", t ? "not " : "");
    //printf("Constructor VarDecl con type [%s] --- %snull\n", t->Name(), t ? "not " : "");
    (type=t)->SetParent(this);
}

bool VarDecl::IsEquivalent(Decl *other) {
    VarDecl *varDecl = dynamic_cast<VarDecl*>(other);
    if (varDecl == NULL)
        return false;

    return type->IsEquivalent(varDecl->type);
}

void VarDecl::Check() {
    CheckType();
    //printf("Saliendo de VarDecl::Check\n");
}

void VarDecl::CheckType() {

    if (type->IsPrimitive()) {
        return;
    }

    Scope *s = scope;
    while (s != NULL) {

        Decl *d;
        if ((d = s->GetTable()->Lookup(type->Name())) != NULL) {
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

void ClassDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);
    scope->SetClassDecl(this);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        scope->Declare(members->Nth(i));

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->BuildScope(scope);
}

void ClassDecl::Check() {
    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->Check();

    CheckExtends();
    CheckImplements();

    for (int i = 0, n = implements->NumElements(); i < n; ++i)
        CheckImplementedMembers(implements->Nth(i));

    CheckExtendedMembers(extends);
    CheckImplementsInterfaces();
}

void ClassDecl::CheckExtends() {
    if (extends == NULL)
        return;

    Decl *lookup = scope->GetParent()->GetTable()->Lookup(extends->Name());
    if (dynamic_cast<ClassDecl*>(lookup) == NULL)
        extends->ReportNotDeclaredIdentifier(LookingForClass);
}

void ClassDecl::CheckImplements() {
    Scope *s = scope->GetParent();

    for (int i = 0, n = implements->NumElements(); i < n; ++i) {
        NamedType *nth = implements->Nth(i);
        Decl *lookup = s->GetTable()->Lookup(implements->Nth(i)->Name());

        if (dynamic_cast<InterfaceDecl*>(lookup) == NULL)
            nth->ReportNotDeclaredIdentifier(LookingForInterface);
    }
}

void ClassDecl::CheckExtendedMembers(NamedType *extType) {
    if (extType == NULL)
        return;

    Decl *lookup = scope->GetParent()->GetTable()->Lookup(extType->Name());
    ClassDecl *extDecl = dynamic_cast<ClassDecl*>(lookup);
    if (extDecl == NULL)
        return;

    CheckExtendedMembers(extDecl->extends);
    CheckAgainstScope(extDecl->scope);
}

void ClassDecl::CheckImplementedMembers(NamedType *impType) {
    Decl *lookup = scope->GetParent()->GetTable()->Lookup(impType->Name());
    InterfaceDecl *intDecl = dynamic_cast<InterfaceDecl*>(lookup);
    if (intDecl == NULL)
        return;

    CheckAgainstScope(intDecl->GetScope());
}

void ClassDecl::CheckAgainstScope(Scope *other) {
    Iterator<Decl*> iter = scope->GetTable()->GetIterator();
    Decl *d;
    while ((d = iter.GetNextValue()) != NULL) {
        Decl *lookup = other->GetTable()->Lookup(d->GetName());

        if (lookup == NULL)
            continue;

        if (dynamic_cast<VarDecl*>(lookup) != NULL)
            ReportError::DeclConflict(d, lookup);

        if (dynamic_cast<FnDecl*>(lookup) != NULL &&
            !d->IsEquivalent(lookup)) {
            ReportError::OverrideMismatch(d);
        }
    }
}

void ClassDecl::CheckImplementsInterfaces() {
    Scope *s = scope->GetParent();

    for (int i = 0, n = implements->NumElements(); i < n; ++i) {
        NamedType *nth = implements->Nth(i);
        Decl *lookup = s->GetTable()->Lookup(implements->Nth(i)->Name());
        InterfaceDecl *intDecl = dynamic_cast<InterfaceDecl*>(lookup);

        if (intDecl == NULL)
            continue;

        List<Decl*> *intMembers = intDecl->GetMembers();

        for (int i = 0, n = intMembers->NumElements(); i < n; ++i) {
            Decl *d = intMembers->Nth(i);

            ClassDecl *classDecl = this;
            Decl *classLookup;
            while (classDecl != NULL) {
                classLookup = classDecl->GetScope()->GetTable()->Lookup(d->GetName());

                if (classLookup != NULL)
                    break;

                if (classDecl->GetExtends() == NULL) {
                    classDecl = NULL;
                } else {
                    const char *extName = classDecl->GetExtends()->Name();
                    Decl *ext = Program::gScope->GetTable()->Lookup(extName);
                    classDecl = dynamic_cast<ClassDecl*>(ext);
                }
            }

            if (classLookup == NULL) {
                //ReportError::InterfaceNotImplemented(this, nth);
                return;
            }
        }
    }
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        scope->Declare(members->Nth(i));

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->BuildScope(scope);
}

void InterfaceDecl::Check() {
    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->Check();
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

bool FnDecl::ConflictsWithPrevious(Decl *prev) {
    /*
    if (IsMethodDecl() && prev->IsMethodDecl() && parent != prev->GetParent()) {
        if (!MatchesPrototype(dynamic_cast<FnDecl*>(prev))) {
            ReportError::OverrideMismatch(this);
            return true;
        }
        return false;
    }
    ReportError::DeclConflict(this, prev);
    return true;
    */
}

bool FnDecl::IsEquivalent(Decl *other) {
    FnDecl *fnDecl = dynamic_cast<FnDecl*>(other);

    if (fnDecl == NULL) { return false; }

    if (!returnType->IsEquivalent(fnDecl->returnType)) { return false; }

    if (formals->NumElements() != fnDecl->formals->NumElements()) {
        return false;
    }

    for (int i = 0, n = formals->NumElements(); i < n; ++i) {
        if (!formals->Nth(i)->IsEquivalent(fnDecl->formals->Nth(i))) {
            return false;
        }
    }

    return true;
}

void FnDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);
    scope->SetFnDecl(this);

    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        scope->Declare(formals->Nth(i));

    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        formals->Nth(i)->BuildScope(scope);

    if (body)
        body->BuildScope(scope);
}

void FnDecl::Check() {
    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        formals->Nth(i)->Check();

    if (body)
        body->Check();
}

bool FnDecl::IsMethodDecl() { 
    return dynamic_cast<ClassDecl*>(parent) != NULL || 
           dynamic_cast<InterfaceDecl*>(parent) != NULL; 
}

bool FnDecl::MatchesPrototype(FnDecl *other) {
    if (!returnType->IsEquivalent(other->returnType)) {
        return false;
    }
    
    if (formals->NumElements() != other->formals->NumElements()) {
        return false;
    }

    for (int i = 0; i < formals->NumElements(); i++) {
        if (!formals->Nth(i)->GetDeclaredType()->IsEquivalent(other->formals->Nth(i)->GetDeclaredType())) {
            return false;
        }
    }
    return true;
}
