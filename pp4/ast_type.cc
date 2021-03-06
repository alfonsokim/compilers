/* File: ast_type.cc
 * -----------------
 * Implementation of type node classes.
 */

#include <string.h>
 #include <cstring>
#include "ast_type.h"
#include "ast_decl.h"

/* Class constants
 * ---------------
 * These are public constants for the built-in base types (int, double, etc.)
 * They can be accessed with the syntax Type::intType. This allows you to
 * directly access them and share the built-in types where needed rather that
 * creates lots of copies.
 */

Type *Type::intType    = new Type("int");
Type *Type::doubleType = new Type("double");
Type *Type::voidType   = new Type("void");
Type *Type::boolType   = new Type("bool");
Type *Type::nullType   = new Type("null");
Type *Type::stringType = new Type("string");
Type *Type::errorType  = new Type("error"); 

Type::Type(const char *n) {
    Assert(n);
    typeName = strdup(n);
}

Type::Type(yyltype loc, const char *str) : Node(loc) {
    Assert(str);
    typeName = strdup(str);
}

bool Type::IsEquivalent(Type *other) {
    if (IsEqualTo(Type::errorType)) {
        return true;
    }
        
    if (IsEqualTo(Type::nullType) && dynamic_cast<NamedType*>(other)) {
        return true;
    }

    return IsEqualTo(other);
}

NamedType::NamedType(Identifier *i) : Type(*i->GetLocation(), i->GetName()) {
    //printf("constructor de NamedType [%s]\n", i->GetName());
    Assert(i != NULL);
    (id=i)->SetParent(this);
}

void NamedType::ReportNotDeclaredIdentifier(reasonT reason) {
    ReportError::IdentifierNotDeclared(id, reason);
}

bool NamedType::IsEqualTo(Type *other) {
    NamedType *namedOther = dynamic_cast<NamedType*>(other);

    if (namedOther == NULL) {
        return false;
    }

    //return *id == *(namedOther->id);
    /*
    printf("en NamedType::IsEqualTo this[%s] other[%s] == [%s] strcmp [%s]\n", 
        GetId()->GetName(), namedOther->GetId()->GetName(),
        GetId()->GetName() == namedOther->GetId()->GetName() ? "si" : "no",
        std::strcmp(GetId()->GetName(), namedOther->GetId()->GetName()) ? "si" : "no");
    */
    //return GetId() == namedOther->GetId();
    return !(std::strcmp(GetId()->GetName(), namedOther->GetId()->GetName()));
}

bool NamedType::IsEquivalent(Type *other) {

    if (IsEqualTo(other)) {
        return true;
    }

    NamedType *nType = this;
    Decl *lookup;

    while ((lookup = Program::gScope->TableLookup(nType->Name())) != NULL) {
        ClassDecl *c = dynamic_cast<ClassDecl*>(lookup);

        if (c == NULL) {
            return false;
        }

        List<NamedType*> *imps = c->GetImplements();
        for (int i = 0, n = imps->NumElements(); i < n; ++i) {
            if (imps->Nth(i)->IsEqualTo(other)) {
                return true;
            }
        }

        nType = c->GetExtends();

        if (nType == NULL) {
            break;
        }

        if (nType->IsEqualTo(other)) {
            return true;
        }
    }

    return false;
}

ArrayType::ArrayType(yyltype loc, Type *et) : Type(loc, et->Name()) {
    Assert(et != NULL);
    (elemType=et)->SetParent(this);
}

/*
ArrayType::ArrayType(Type *et) : Type() {
    Assert(et != NULL);
    (elemType=et)->SetParent(this);
}
*/

void ArrayType::ReportNotDeclaredIdentifier(reasonT reason) {
    elemType->ReportNotDeclaredIdentifier(reason);
}

bool ArrayType::IsEqualTo(Type *other) {
    ArrayType *arrayOther = dynamic_cast<ArrayType*>(other);

    if (arrayOther == NULL) {
        return false;
    }

    return elemType->IsEqualTo(arrayOther->elemType);
}

bool ArrayType::IsEquivalent(Type *other) {
    ArrayType *arrayOther = dynamic_cast<ArrayType*>(other);

    if (arrayOther == NULL) {
        return false;
    }

    return elemType->IsEquivalent(arrayOther->elemType);
}
