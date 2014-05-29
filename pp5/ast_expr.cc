/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "codegen.h"
#include "errors.h"

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Decl* Expr::GetFieldDecl(Identifier *field, Expr *b) {

    if (b != NULL) {
        return GetFieldDecl(field, b->GetType());
    }

    Decl *d = GetFieldDecl(field, static_cast<Node*>(this));

    if (d == NULL) {
        ClassDecl *classDecl = GetClassDecl();
        if (classDecl != NULL) {
            d = GetFieldDecl(field, classDecl->GetType());
        }
    }

    return d;
}

// -------------------------------------------------------------------------------- 

Decl* Expr::GetFieldDecl(Identifier *field, Node *n) {
    while (n != NULL) {
        Decl *d = n->GetScope()->table->Lookup(field->GetName());
        if (d != NULL) {
            return d;
        }
        n = n->GetParent();
    }
    return NULL;
}

// -------------------------------------------------------------------------------- 

Decl* Expr::GetFieldDecl(Identifier *field, Type *t) {
    // It is assumed that t is *not* a primitive type. Results are undefined if
    // this assumption is not met.
    while (t != NULL) {
        Decl *tDecl = Program::gScope->table->Lookup(t->GetName());
        Decl *d = tDecl->GetScope()->table->Lookup(field->GetName());
        /*
        if (d != NULL) {
            return d;
        }
        */

        if (dynamic_cast<ClassDecl*>(tDecl)) {
            t = static_cast<ClassDecl*>(tDecl)->GetExtends();
        } else {
            break;
        }
    }
    return NULL;
}

// -------------------------------------------------------------------------------- 

ClassDecl* Expr::GetClassDecl() {
    return NULL;
}

// -------------------------------------------------------------------------------- 

Location* Expr::GetThisLoc() {
    return NULL;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

// -------------------------------------------------------------------------------- 

Type* IntConstant::GetType() {
    return Type::intType;
}

// -------------------------------------------------------------------------------- 

Location* IntConstant::Emit(CodeGenerator *cg) {
    return cg->GenLoadConstant(value);
}

// -------------------------------------------------------------------------------- 

int IntConstant::GetMemBytes() {
    return 4;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

// -------------------------------------------------------------------------------- 

Type* DoubleConstant::GetType() {
    return Type::doubleType;
}

// -------------------------------------------------------------------------------- 

Location* DoubleConstant::Emit(CodeGenerator *cg) {
    return NULL;
}

// -------------------------------------------------------------------------------- 

int DoubleConstant::GetMemBytes() {
    return 0;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

// -------------------------------------------------------------------------------- 

Type* BoolConstant::GetType() {
    return Type::boolType;
}

// -------------------------------------------------------------------------------- 

Location* BoolConstant::Emit(CodeGenerator *cg) {
    // Los bools son tratados como enteros
    return cg->GenLoadConstant(value ? 1 : 0);
}

// -------------------------------------------------------------------------------- 

int BoolConstant::GetMemBytes() {
    return 4;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

// -------------------------------------------------------------------------------- 

Type* StringConstant::GetType() {
    return Type::stringType;
}

// -------------------------------------------------------------------------------- 

Location* StringConstant::Emit(CodeGenerator *cg) {
    return cg->GenLoadConstant(value);
}

// -------------------------------------------------------------------------------- 

int StringConstant::GetMemBytes() {
    return 4;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Type* NullConstant::GetType() {
    return Type::nullType;
}

// -------------------------------------------------------------------------------- 

Location* NullConstant::Emit(CodeGenerator *cg) {
    return NULL;
}

// -------------------------------------------------------------------------------- 

int NullConstant::GetMemBytes() {
    return 4;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

// -------------------------------------------------------------------------------- 

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this);
    (right=r)->SetParent(this);
}

// -------------------------------------------------------------------------------- 

CompoundExpr::CompoundExpr(Operator *o, Expr *r)
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL;
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Type* ArithmeticExpr::GetType() {
    return right->GetType();
}

// -------------------------------------------------------------------------------- 

Location* ArithmeticExpr::Emit(CodeGenerator *cg) {
    if (left == NULL) {
        return EmitUnary(cg);
    } else {
        return EmitBinary(cg);
    }
}

// -------------------------------------------------------------------------------- 

int ArithmeticExpr::GetMemBytes() {
    if (left == NULL) {
        return GetMemBytesUnary();
    } else {
        return GetMemBytesBinary();
    }
}

// -------------------------------------------------------------------------------- 

Location* ArithmeticExpr::EmitUnary(CodeGenerator *cg) {
    Location *rtemp = right->Emit(cg);

    Location *zero = cg->GenLoadConstant(0);
    return cg->GenBinaryOp(op->GetTokenString(), zero, rtemp);
}

// -------------------------------------------------------------------------------- 

int ArithmeticExpr::GetMemBytesUnary() {
    return right->GetMemBytes() + 2 * CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* ArithmeticExpr::EmitBinary(CodeGenerator *cg) {
    Location *ltemp = left->Emit(cg);
    Location *rtemp = right->Emit(cg);

    return cg->GenBinaryOp(op->GetTokenString(), ltemp, rtemp);
}

// -------------------------------------------------------------------------------- 

int ArithmeticExpr::GetMemBytesBinary() {
    return right->GetMemBytes() + left->GetMemBytes() + CodeGenerator::VarSize;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Type* RelationalExpr::GetType() {
    return Type::boolType;
}

// -------------------------------------------------------------------------------- 

Location* RelationalExpr::Emit(CodeGenerator *cg) {
    const char *tok = op->GetTokenString();

    if (strcmp("<", tok) == 0) {
        return EmitLess(cg, left, right);
    } else if (strcmp("<=", tok) == 0) {
        return EmitLessEqual(cg, left, right);
    } else if (strcmp(">", tok) == 0) {
        return EmitLess(cg, right, left);
    } else if (strcmp(">=", tok) == 0) {
        return EmitLessEqual(cg, right, left);
    }

    return NULL;
}

// -------------------------------------------------------------------------------- 

int RelationalExpr::GetMemBytes() {
    const char *tok = op->GetTokenString();

    if (strcmp("<", tok) == 0) {
        return GetMemBytesLess(left, right);
    } else if (strcmp("<=", tok) == 0) {
        return GetMemBytesLessEqual(left, right);
    } else if (strcmp(">", tok) == 0) {
        return GetMemBytesLess(right, left);
    } else if (strcmp(">=", tok) == 0) {
        return GetMemBytesLessEqual(right, left);
    }

    return 0;
}

// -------------------------------------------------------------------------------- 

Location* RelationalExpr::EmitLess(CodeGenerator *cg, Expr *l, Expr *r) {
    Location *ltmp = l->Emit(cg);
    Location *rtmp = r->Emit(cg);

    return cg->GenBinaryOp("<", ltmp, rtmp);
}

// -------------------------------------------------------------------------------- 

int RelationalExpr::GetMemBytesLess(Expr *l, Expr *r) {
    return l->GetMemBytes() + r->GetMemBytes() + CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* RelationalExpr::EmitLessEqual(CodeGenerator *cg, Expr *l, Expr *r) {
    Location *ltmp = l->Emit(cg);
    Location *rtmp = r->Emit(cg);

    Location *less = cg->GenBinaryOp("<", ltmp, rtmp);
    Location *equal = cg->GenBinaryOp("==", ltmp, rtmp);

    return cg->GenBinaryOp("||", less, equal);
}

// -------------------------------------------------------------------------------- 

int RelationalExpr::GetMemBytesLessEqual(Expr *l, Expr *r) {
    return l->GetMemBytes() + r->GetMemBytes() + 3 * CodeGenerator::VarSize;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Type* EqualityExpr::GetType() {
    return Type::boolType;
}

// -------------------------------------------------------------------------------- 

Location* EqualityExpr::Emit(CodeGenerator *cg) {
    const char *tok = op->GetTokenString();

    if (strcmp("==", tok) == 0) {
        return EmitEqual(cg);
    } else if (strcmp("!=", tok) == 0) {
        return NULL;
    }

    return NULL;
}

// -------------------------------------------------------------------------------- 

int EqualityExpr::GetMemBytes() {
    const char *tok = op->GetTokenString();

    if (strcmp("==", tok) == 0) {
        return GetMemBytesEqual();
    }

    return 0;
}

// -------------------------------------------------------------------------------- 

Location* EqualityExpr::EmitEqual(CodeGenerator *cg) {
    Location *ltmp = left->Emit(cg);
    Location *rtmp = right->Emit(cg);

    if (left->GetType()->IsEquivalentTo(Type::stringType)) {
        return cg->GenBuiltInCall(StringEqual, ltmp, rtmp);
    } else {
        return cg->GenBinaryOp("==", ltmp, rtmp);
    }
}

// -------------------------------------------------------------------------------- 

int EqualityExpr::GetMemBytesEqual() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* EqualityExpr::EmitNotEqual(CodeGenerator *cg) {
    return NULL;
}

// -------------------------------------------------------------------------------- 

int EqualityExpr::GetMemBytesNotEqual() {
    return left->GetMemBytes() + right->GetMemBytes() +
           4 * CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Type* LogicalExpr::GetType() {
    return Type::boolType;
}

// -------------------------------------------------------------------------------- 

Location* LogicalExpr::Emit(CodeGenerator *cg) {
    const char *tok = op->GetTokenString();

    if (strcmp("&&", tok) == 0) {
        return EmitAnd(cg);
    } else if (strcmp("||", tok) == 0) {
        return EmitOr(cg);
    } else if (strcmp("!", tok) == 0) {
        return NULL;
    }

    return 0;
}

// -------------------------------------------------------------------------------- 

int LogicalExpr::GetMemBytes() {
    const char *tok = op->GetTokenString();

    if (strcmp("&&", tok) == 0) {
        return GetMemBytesAnd();
    } else if (strcmp("||", tok) == 0) {
        return GetMemBytesOr();
    }

    return 0;
}

// -------------------------------------------------------------------------------- 

Location* LogicalExpr::EmitAnd(CodeGenerator *cg) {
    Location *ltmp = left->Emit(cg);
    Location *rtmp = right->Emit(cg);

    return cg->GenBinaryOp("&&", ltmp, rtmp);
}

// -------------------------------------------------------------------------------- 

int LogicalExpr::GetMemBytesAnd() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* LogicalExpr::EmitOr(CodeGenerator *cg) {
    Location *ltmp = left->Emit(cg);
    Location *rtmp = right->Emit(cg);

    return cg->GenBinaryOp("||", ltmp, rtmp);
}

// -------------------------------------------------------------------------------- 

int LogicalExpr::GetMemBytesOr() {
    return left->GetMemBytes() + right->GetMemBytes() + CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* LogicalExpr::EmitNot(CodeGenerator *cg) {
    return NULL;
}

// -------------------------------------------------------------------------------- 

int LogicalExpr::GetMemBytesNot() {
    return right->GetMemBytes();
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Type* AssignExpr::GetType() {
    return left->GetType();
}

// -------------------------------------------------------------------------------- 

Location* AssignExpr::Emit(CodeGenerator *cg) {
    Location *rtemp = right->Emit(cg);
    LValue *lval = dynamic_cast<LValue*>(left);

    Location *ltemp = left->Emit(cg);
    cg->GenAssign(ltemp, rtemp);
    return ltemp;
}

// -------------------------------------------------------------------------------- 

int AssignExpr::GetMemBytes() {
    LValue *lval = dynamic_cast<LValue*>(left);
    return right->GetMemBytes() + left->GetMemBytes();
}

// -------------------------------------------------------------------------------- 

Type* This::GetType() {
    return NULL;
}

// -------------------------------------------------------------------------------- 

Location* This::Emit(CodeGenerator *cg) {
    return NULL;
}

// -------------------------------------------------------------------------------- 
int This::GetMemBytes() {
    return 0;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this);
    (subscript=s)->SetParent(this);
}

// -------------------------------------------------------------------------------- 

Type* ArrayAccess::GetType() {
    return base->GetType();
}

// -------------------------------------------------------------------------------- 

Location* ArrayAccess::Emit(CodeGenerator *cg) {
    return cg->GenLoad(EmitAddr(cg));
}

// -------------------------------------------------------------------------------- 

int ArrayAccess::GetMemBytes() {
    return GetMemBytesAddr() + CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* ArrayAccess::EmitStore(CodeGenerator *cg, Location *val) {
    return NULL;
}

// -------------------------------------------------------------------------------- 

int ArrayAccess::GetMemBytesStore() {
    return GetMemBytesAddr() + CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* ArrayAccess::EmitAddr(CodeGenerator *cg) {
    Location *b = base->Emit(cg);
    Location *s = subscript->Emit(cg);

    EmitRuntimeSubscriptCheck(cg, b, s);

    Location *con = cg->GenLoadConstant(CodeGenerator::VarSize);
    Location *num = cg->GenBinaryOp("*", s, con);

    Location *off = cg->GenBinaryOp("+", num, con);

    return cg->GenBinaryOp("+", b, off);
}

// -------------------------------------------------------------------------------- 

int ArrayAccess::GetMemBytesAddr() {
    return base->GetMemBytes() + subscript->GetMemBytes() +
           4 * CodeGenerator::VarSize + GetMemBytesRuntimeSubscriptCheck();
}

// -------------------------------------------------------------------------------- 

Location* ArrayAccess::EmitRuntimeSubscriptCheck(CodeGenerator *cg,
                                                 Location *arr,
                                                 Location *sub) {
    Location *zro = cg->GenLoadConstant(0);
    Location *siz = cg->GenLoad(arr);

    Location *lessZro = cg->GenBinaryOp("<", sub, zro);
    Location *gratSiz = cg->GenBinaryOp("<", siz, sub);
    Location *equlSiz = cg->GenBinaryOp("==", siz, sub);
    Location *gratEqulSiz = cg->GenBinaryOp("||", gratSiz, equlSiz);
    Location *gratEqulSizLessZro = cg->GenBinaryOp("||", gratEqulSiz, lessZro);

    const char *passCheck = cg->NewLabel();
    cg->GenIfZ(gratEqulSizLessZro, passCheck);
    cg->GenBuiltInCall(PrintString, cg->GenLoadConstant(err_arr_out_of_bounds));
    cg->GenBuiltInCall(Halt);
    cg->GenLabel(passCheck);

    return NULL;
}

// -------------------------------------------------------------------------------- 

int ArrayAccess::GetMemBytesRuntimeSubscriptCheck() {
    return 8 * CodeGenerator::VarSize;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

FieldAccess::FieldAccess(Expr *b, Identifier *f) : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    base = b;
    (field=f)->SetParent(this);
}

// -------------------------------------------------------------------------------- 

Type* FieldAccess::GetType() {
    VarDecl *d = GetDecl();
    Assert(d != NULL);
    return d->GetType();
}

// -------------------------------------------------------------------------------- 

Location* FieldAccess::Emit(CodeGenerator *cg) {
    FieldAccess *baseAccess = dynamic_cast<FieldAccess*>(base);
    VarDecl *fieldDecl = GetDecl();
    Assert(fieldDecl != NULL);
    
    if (baseAccess == NULL) {
        return EmitMemLoc(cg, fieldDecl);
    }

    VarDecl *baseDecl = baseAccess->GetDecl();
    Assert(baseDecl != NULL);
    int fieldOffset = fieldDecl->GetMemOffset();
    return cg->GenLoad(baseDecl->GetMemLoc(), fieldOffset);
}

// -------------------------------------------------------------------------------- 

int FieldAccess::GetMemBytes() {
    FieldAccess *baseAccess = dynamic_cast<FieldAccess*>(base);
    VarDecl *fieldDecl = GetDecl();
    Assert(fieldDecl != NULL);
    return CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* FieldAccess::EmitStore(CodeGenerator *cg, Location *val) {
    FieldAccess *baseAccess = dynamic_cast<FieldAccess*>(base);
    VarDecl *fieldDecl = GetDecl();
    Assert(fieldDecl != NULL);

    VarDecl *baseDecl = baseAccess->GetDecl();
    Assert(baseDecl != NULL);
    int fieldOffset = fieldDecl->GetMemOffset();
    Location *ltemp = baseDecl->GetMemLoc();
    cg->GenStore(ltemp, val, fieldOffset);
    return ltemp;
}

// -------------------------------------------------------------------------------- 

int FieldAccess::GetMemBytesStore() {
    FieldAccess *baseAccess = dynamic_cast<FieldAccess*>(base);
    VarDecl *fieldDecl = GetDecl();
    Assert(fieldDecl != NULL);
    return 0;
}

// -------------------------------------------------------------------------------- 

VarDecl* FieldAccess::GetDecl() {
    Decl *d = GetFieldDecl(field, base);
    return dynamic_cast<VarDecl*>(d);
}

// -------------------------------------------------------------------------------- 

Location* FieldAccess::EmitMemLoc(CodeGenerator *cg, VarDecl *fieldDecl) {
    Location *loc = fieldDecl->GetMemLoc();
    if (loc != NULL)
        return loc;
    Location *This = GetThisLoc();
    return cg->GenLoad(This, fieldDecl->GetMemOffset());
}

// -------------------------------------------------------------------------------- 

int FieldAccess::GetMemBytesMemLoc(VarDecl *fieldDecl) {
    return 0;
}

// -------------------------------------------------------------------------------- 

Location* FieldAccess::EmitMemLocStore(CodeGenerator *cg, Location *val,
                                       VarDecl *fieldDecl) {
    Location *loc = fieldDecl->GetMemLoc();
    Location *This = GetThisLoc();
    cg->GenStore(This, val, fieldDecl->GetMemOffset());
    return This;
}

// -------------------------------------------------------------------------------- 

int FieldAccess::GetMemBytesMemLocStore(VarDecl *fieldDecl) {
    return 0;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

// -------------------------------------------------------------------------------- 

Type* Call::GetType() {
    FnDecl *d = GetDecl();
    Assert(d != NULL);
    return d->GetType();
}

// -------------------------------------------------------------------------------- 

Location* Call::Emit(CodeGenerator *cg) {
    return EmitLabel(cg);
}

// -------------------------------------------------------------------------------- 

int Call::GetMemBytes() {
    if (IsArrayLengthCall()) {
        return GetMemBytesArrayLength();
    }

    return GetMemBytesLabel();
}

// -------------------------------------------------------------------------------- 

Location* Call::EmitLabel(CodeGenerator *cg) {
    List<Location*> *params = new List<Location*>;
    for (int i = 0, n = actuals->NumElements(); i < n; ++i) {
        params->Append(actuals->Nth(i)->Emit(cg));
    }

    int n = params->NumElements();
    for (int i = n-1; i >= 0; --i) {
        cg->GenPushParam(params->Nth(i));
    }

    Location *ret;
    if (!IsMethodCall()) {
        FnDecl *d = GetDecl();
        ret = cg->GenLCall(d->GetLabel(), d->HasReturnVal());

        cg->GenPopParams(n * CodeGenerator::VarSize);
    } else {
        
        Location *b;
        cg->GenPushParam(b);
        ret = EmitDynamicDispatch(cg, b);

        cg->GenPopParams((n+1) * CodeGenerator::VarSize);
    }

    return ret;
}

// -------------------------------------------------------------------------------- 

int Call::GetMemBytesLabel() {
    int memBytes = 0;
    for (int i = 0, n = actuals->NumElements(); i < n; ++i) {
        memBytes += actuals->Nth(i)->GetMemBytes();
    }

    if (IsMethodCall()) {
        if (base != NULL) {
            memBytes += base->GetMemBytes();
        }
        memBytes += GetMemBytesDynamicDispatch();
    }

    if (GetDecl()->HasReturnVal()) {
        memBytes += CodeGenerator::VarSize;
    }

    return memBytes;
}

// -------------------------------------------------------------------------------- 

Location* Call::EmitArrayLength(CodeGenerator *cg) {
    return cg->GenLoad(base->Emit(cg));
}

// -------------------------------------------------------------------------------- 

int Call::GetMemBytesArrayLength() {
    return base->GetMemBytes() + CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Location* Call::EmitDynamicDispatch(CodeGenerator *cg, Location *b) {
    Location *vtable = cg->GenLoad(b);
    int methodOffset = GetDecl()->GetVTblOffset();
    Location *faddr = cg->GenLoad(vtable, methodOffset);
    return cg->GenACall(faddr, GetDecl()->HasReturnVal());
}

// -------------------------------------------------------------------------------- 

int Call::GetMemBytesDynamicDispatch() {
    return 2 * CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

FnDecl* Call::GetDecl() {
    Decl *d = GetFieldDecl(field, base);
    return dynamic_cast<FnDecl*>(d);
}

// -------------------------------------------------------------------------------- 

bool Call::IsArrayLengthCall() {
    return true;
}

// -------------------------------------------------------------------------------- 

bool Call::IsMethodCall() {
    return false;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) {
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

// -------------------------------------------------------------------------------- 

Type* NewExpr::GetType() {
    Decl *d = Program::gScope->table->Lookup(cType->GetName());
    ClassDecl *c = dynamic_cast<ClassDecl*>(d);
    Assert(c != NULL);
    return c->GetType();
}

// -------------------------------------------------------------------------------- 

Location* NewExpr::Emit(CodeGenerator *cg) {
    const char *name = cType->GetName();

    Decl *d = Program::gScope->table->Lookup(name);
    Assert(d != NULL);

    Location *s = cg->GenLoadConstant(d->GetMemBytes());
    Location *c = cg->GenLoadConstant(CodeGenerator::VarSize);

    Location *mem = cg->GenBuiltInCall(Alloc, cg->GenBinaryOp("+", c, s));
    cg->GenStore(mem, cg->GenLoadLabel(name));

    return mem;
}

// -------------------------------------------------------------------------------- 

int NewExpr::GetMemBytes() {
    return 5 * CodeGenerator::VarSize;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this);
    (elemType=et)->SetParent(this);
}

// -------------------------------------------------------------------------------- 

Type* NewArrayExpr::GetType() {
    return new ArrayType(elemType);
}

// -------------------------------------------------------------------------------- 

Location* NewArrayExpr::Emit(CodeGenerator *cg) {
    Location *s = size->Emit(cg);
    Location *c = cg->GenLoadConstant(CodeGenerator::VarSize);

    EmitRuntimeSizeCheck(cg, s);

    Location *n = cg->GenBinaryOp("*", s, c);
    Location *mem = cg->GenBuiltInCall(Alloc, cg->GenBinaryOp("+", c, n));
    cg->GenStore(mem, s);

    return mem;
}

// -------------------------------------------------------------------------------- 

int NewArrayExpr::GetMemBytes() {
    return size->GetMemBytes() + 4 * CodeGenerator::VarSize +
           GetMemBytesRuntimeSizeCheck();
}

// -------------------------------------------------------------------------------- 

Location* NewArrayExpr::EmitRuntimeSizeCheck(CodeGenerator *cg, Location *siz) {
    return NULL;
}

int NewArrayExpr::GetMemBytesRuntimeSizeCheck() {
    return 5 * CodeGenerator::VarSize;
}

// ********************************************************************************
// -------------------------------------------------------------------------------- 

Type* ReadIntegerExpr::GetType() {
    return Type::intType;
}

// -------------------------------------------------------------------------------- 

Location* ReadIntegerExpr::Emit(CodeGenerator *cg) {
    return cg->GenBuiltInCall(ReadInteger);
}

// -------------------------------------------------------------------------------- 

int ReadIntegerExpr::GetMemBytes() {
    return CodeGenerator::VarSize;
}

// -------------------------------------------------------------------------------- 

Type* ReadLineExpr::GetType() {
    return Type::stringType;
}

// -------------------------------------------------------------------------------- 

Location* ReadLineExpr::Emit(CodeGenerator *cg) {
    return cg->GenBuiltInCall(ReadLine);
}

// -------------------------------------------------------------------------------- 

int ReadLineExpr::GetMemBytes() {
    return CodeGenerator::VarSize;
}
