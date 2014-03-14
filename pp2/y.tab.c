/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 11 "parser.y"


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


/* Line 371 of yacc.c  */
#line 84 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Double = 261,
     T_String = 262,
     T_Class = 263,
     T_LessEqual = 264,
     T_GreaterEqual = 265,
     T_Equal = 266,
     T_NotEqual = 267,
     T_Dims = 268,
     T_And = 269,
     T_Or = 270,
     T_Null = 271,
     T_Extends = 272,
     T_This = 273,
     T_Interface = 274,
     T_Implements = 275,
     T_While = 276,
     T_For = 277,
     T_If = 278,
     T_Else = 279,
     T_Return = 280,
     T_Break = 281,
     T_New = 282,
     T_NewArray = 283,
     T_Print = 284,
     T_ReadInteger = 285,
     T_ReadLine = 286,
     T_Joe = 287,
     T_Switch = 288,
     T_Case = 289,
     T_Default = 290,
     T_Identifier = 291,
     T_StringConstant = 292,
     T_IntConstant = 293,
     T_DoubleConstant = 294,
     T_BoolConstant = 295
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Double 261
#define T_String 262
#define T_Class 263
#define T_LessEqual 264
#define T_GreaterEqual 265
#define T_Equal 266
#define T_NotEqual 267
#define T_Dims 268
#define T_And 269
#define T_Or 270
#define T_Null 271
#define T_Extends 272
#define T_This 273
#define T_Interface 274
#define T_Implements 275
#define T_While 276
#define T_For 277
#define T_If 278
#define T_Else 279
#define T_Return 280
#define T_Break 281
#define T_New 282
#define T_NewArray 283
#define T_Print 284
#define T_ReadInteger 285
#define T_ReadLine 286
#define T_Joe 287
#define T_Switch 288
#define T_Case 289
#define T_Default 290
#define T_Identifier 291
#define T_StringConstant 292
#define T_IntConstant 293
#define T_DoubleConstant 294
#define T_BoolConstant 295



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 82 "parser.y"

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


/* Line 387 of yacc.c  */
#line 250 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 291 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   579

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  212

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    52,     2,     2,
      43,    44,    50,    48,    42,    49,    56,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    41,
      53,    47,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      21,    24,    26,    28,    30,    32,    35,    39,    41,    42,
      49,    56,    57,    60,    62,    67,    71,    75,    78,    81,
      83,    86,    88,    90,    92,    94,    96,    98,   100,   102,
     104,   108,   112,   115,   117,   119,   121,   125,   129,   133,
     137,   141,   145,   149,   152,   156,   160,   164,   168,   172,
     176,   180,   184,   187,   189,   190,   198,   201,   202,   206,
     208,   211,   212,   214,   216,   219,   220,   227,   234,   237,
     239,   245,   251,   259,   265,   275,   279,   282,   284,   288,
     293,   295,   297,   299,   301,   303,   308,   315,   317,   318,
     321,   323,   327,   329,   335,   340,   343,   345,   349,   357
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    -1,    62,    63,    -1,    63,    -1,
      64,    -1,    68,    -1,    75,    -1,    83,    -1,    65,    41,
      -1,    66,    36,    -1,     5,    -1,     6,    -1,     4,    -1,
       7,    -1,    66,    13,    -1,    67,    42,    65,    -1,    65,
      -1,    -1,    66,    36,    43,    67,    44,    70,    -1,     3,
      36,    43,    67,    44,    70,    -1,    -1,    69,    64,    -1,
      64,    -1,    45,    69,    71,    46,    -1,    45,    69,    46,
      -1,    45,    71,    46,    -1,    45,    46,    -1,    71,    72,
      -1,    72,    -1,    74,    41,    -1,    70,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    95,    -1,
      99,    -1,    89,    -1,    89,    47,    73,    -1,    31,    43,
      44,    -1,    27,    36,    -1,    18,    -1,    90,    -1,    91,
      -1,    30,    43,    44,    -1,    43,    73,    44,    -1,    73,
      48,    73,    -1,    73,    49,    73,    -1,    73,    50,    73,
      -1,    73,    51,    73,    -1,    73,    52,    73,    -1,    49,
      73,    -1,    73,    53,    73,    -1,    73,     9,    73,    -1,
      73,    54,    73,    -1,    73,    10,    73,    -1,    73,    11,
      73,    -1,    73,    12,    73,    -1,    73,    14,    73,    -1,
      73,    15,    73,    -1,    55,    73,    -1,    73,    -1,    -1,
       8,    36,    76,    78,    45,    80,    46,    -1,    17,    36,
      -1,    -1,    77,    42,    36,    -1,    36,    -1,    20,    77,
      -1,    -1,    64,    -1,    68,    -1,    80,    79,    -1,    -1,
      66,    36,    43,    67,    44,    41,    -1,     3,    36,    43,
      67,    44,    41,    -1,    82,    81,    -1,    81,    -1,    19,
      36,    45,    82,    46,    -1,    23,    43,    73,    44,    72,
      -1,    23,    43,    73,    44,    72,    24,    72,    -1,    21,
      43,    73,    44,    72,    -1,    22,    43,    74,    41,    73,
      41,    74,    44,    72,    -1,    25,    74,    41,    -1,    26,
      41,    -1,    36,    -1,    73,    56,    36,    -1,    73,    57,
      73,    58,    -1,    38,    -1,    39,    -1,    40,    -1,    37,
      -1,    16,    -1,    36,    43,    92,    44,    -1,    73,    56,
      36,    43,    92,    44,    -1,    93,    -1,    -1,    93,    73,
      -1,    73,    -1,    94,    42,    73,    -1,    73,    -1,    29,
      43,    94,    44,    41,    -1,    34,    38,    59,    71,    -1,
      97,    96,    -1,    96,    -1,    35,    59,    71,    -1,    33,
      43,    73,    44,    45,    97,    46,    -1,    33,    43,    73,
      44,    45,    97,    98,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   216,   216,   231,   232,   237,   238,   239,   240,   245,
     250,   261,   262,   263,   264,   265,   270,   271,   272,   280,
     284,   290,   295,   296,   301,   303,   306,   309,   317,   318,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   338,
     339,   343,   344,   348,   349,   350,   351,   352,   353,   356,
     359,   362,   365,   368,   371,   374,   378,   381,   385,   388,
     392,   396,   400,   407,   408,   415,   423,   427,   432,   435,
     443,   448,   453,   454,   459,   460,   466,   470,   478,   479,
     485,   495,   498,   506,   514,   523,   531,   542,   546,   550,
     562,   563,   564,   565,   566,   573,   577,   586,   587,   592,
     593,   598,   599,   607,   611,   618,   619,   624,   629,   632
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_LessEqual", "T_GreaterEqual", "T_Equal",
  "T_NotEqual", "T_Dims", "T_And", "T_Or", "T_Null", "T_Extends", "T_This",
  "T_Interface", "T_Implements", "T_While", "T_For", "T_If", "T_Else",
  "T_Return", "T_Break", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Joe", "T_Switch", "T_Case", "T_Default", "T_Identifier",
  "T_StringConstant", "T_IntConstant", "T_DoubleConstant",
  "T_BoolConstant", "';'", "','", "'('", "')'", "'{'", "'}'", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'!'", "'.'", "'['", "']'",
  "':'", "$accept", "Program", "DeclList", "Decl", "VarDecl", "Var",
  "Type", "VarList", "FnDecl", "VarDeclList", "StmtBlock", "StmtList",
  "Stmt", "Expr", "OneExpr", "ClassDecl", "Extends", "IdentifierList",
  "Implements", "Field", "FieldList", "Prototype", "PrototypeList",
  "InterfaceDecl", "IfStmt", "WhileStmt", "ForStmt", "ReturnStmt",
  "BreakStmt", "LValue", "Constant", "Call", "Actuals", "ExprList",
  "CommaExprList", "PrintStmt", "Case", "CaseList", "Default",
  "SwitchStmt", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    59,    44,    40,    41,   123,   125,    61,    43,    45,
      42,    47,    37,    60,    62,    33,    46,    91,    93,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    64,
      65,    66,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    68,    69,    69,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    84,    84,    85,    86,    87,    88,    89,    89,    89,
      90,    90,    90,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    94,    95,    96,    97,    97,    98,    99,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     2,     3,     1,     0,     6,
       6,     0,     2,     1,     4,     3,     3,     2,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     0,     7,     2,     0,     3,     1,
       2,     0,     1,     1,     2,     0,     6,     6,     2,     1,
       5,     5,     7,     5,     9,     3,     2,     1,     3,     4,
       1,     1,     1,     1,     1,     4,     6,     1,     0,     2,
       1,     3,     1,     5,     4,     2,     1,     3,     7,     8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      21,     0,    13,    11,    12,    14,     0,     0,     0,     2,
       4,     5,     0,     0,     6,     7,     8,     0,    67,     0,
       1,     3,     9,    15,    10,    18,     0,    71,     0,    18,
      17,     0,     0,    66,     0,     0,     0,     0,    79,     0,
       0,    10,     0,     0,    69,    70,    75,     0,     0,    80,
      78,     0,    16,    64,    20,     0,     0,    18,    18,    19,
      94,    43,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,    87,    93,    90,    91,    92,     0,    27,     0,
       0,    23,    64,    31,    64,    29,    63,     0,    32,    33,
      34,    35,    36,    39,    44,    45,    37,    38,    68,    65,
      72,    73,    74,     0,     0,     0,    64,     0,     0,    86,
      42,     0,     0,     0,     0,    98,     0,    53,    62,    25,
      22,    64,    26,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    85,   102,     0,    46,
      41,     0,   100,     0,    97,    47,    24,    55,    57,    58,
      59,    60,    61,    48,    49,    50,    51,    52,    54,    56,
      88,     0,    40,    77,    76,    64,     0,    64,     0,     0,
       0,    95,    99,    98,    89,    83,     0,    81,   101,   103,
       0,     0,    64,    64,     0,   106,     0,    96,     0,    82,
       0,     0,   108,   105,     0,    64,    64,    64,   109,    84,
     104,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    31,    32,    14,    82,
      83,    84,    85,    86,    87,    15,    27,    45,    35,   102,
      56,    38,    39,    16,    88,    89,    90,    91,    92,    93,
      94,    95,   153,   154,   148,    96,   195,   196,   204,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int16 yypact[] =
{
     112,   -34,   -85,   -85,   -85,   -85,   -25,   -16,    15,   112,
     -85,   -85,   -17,    -1,   -85,   -85,   -85,     4,    35,    42,
     -85,   -85,   -85,   -85,     8,   218,    43,    74,   241,   218,
     -85,     3,   -21,   -85,    65,    58,    70,     5,   -85,    22,
       6,   -85,   218,    66,   -85,    68,   -85,    89,    94,   -85,
     -85,    66,   -85,   118,   -85,   102,    67,   218,   218,   -85,
     -85,   -85,    99,   103,   110,   524,   119,   123,   129,   132,
     133,   135,   136,   -85,   -85,   -85,   -85,   524,   -85,   524,
     524,   -85,   164,   -85,   393,   -85,   351,   121,   -85,   -85,
     -85,   -85,   -85,   127,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,    34,    91,   524,   524,   524,   140,   -85,
     -85,   524,   139,   144,   524,   524,   217,   351,   351,   -85,
     -85,   428,   -85,   -85,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   148,   524,   -85,
     524,   151,   155,   228,   157,   277,   -85,   351,   108,   -85,
     -85,   288,   351,   161,   524,   -85,   -85,   351,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     156,   206,   351,   -85,   -85,   498,   524,   498,   524,   165,
     163,   -85,   351,   524,   -85,   -85,   302,   187,   351,   -85,
     178,   170,   524,   498,   192,   -85,   131,   -85,   189,   -85,
     175,   176,   -85,   -85,   190,   498,   498,   498,   -85,   -85,
      59,   463
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   232,   -49,   -12,    10,   -26,   193,   -85,
     -29,   -77,   -84,   -71,   -64,   -85,   -85,   -85,   -85,   -85,
     -85,   211,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,    69,   -85,   -85,   -85,    55,   -85,   -85,   -85
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     123,   108,    17,    40,    81,   121,   116,   100,   117,   118,
      13,    18,    23,    30,    54,    20,    23,    30,    23,    13,
      19,    42,    59,    43,    22,    36,     2,     3,     4,     5,
      52,   103,   104,   120,   143,    24,   145,   123,    37,    41,
     147,    48,   144,   151,   152,    30,    30,    25,    42,    37,
      51,    29,    26,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    13,   171,    49,   172,
       1,     2,     3,     4,     5,    60,    42,    61,   141,    33,
      62,    63,    64,   182,    65,    66,    67,    28,    68,    69,
      70,   185,    71,   187,    34,    72,    73,    74,    75,    76,
     -64,    44,    77,    46,    53,   186,    47,   188,    79,   199,
      55,    53,   152,    99,    80,     1,     2,     3,     4,     5,
       6,   209,     2,     3,     4,     5,   123,   123,   198,   210,
     211,     7,    57,    42,    60,   142,    61,    58,    98,    62,
      63,    64,   105,    65,    66,    67,   106,    68,    69,    70,
     178,    71,   179,   107,    72,    73,    74,    75,    76,   110,
     109,    77,   139,    53,    78,   194,   201,    79,     2,     3,
       4,     5,   111,    80,   140,   112,   113,   202,   114,   115,
      60,   146,    61,   149,   170,    62,    63,    64,   150,    65,
      66,    67,   173,    68,    69,    70,   174,    71,   176,   183,
      72,    73,    74,    75,    76,   181,   189,    77,   190,    53,
     119,   193,   194,    79,   197,   124,   125,   126,   127,    80,
     128,   129,     2,     3,     4,     5,   124,   125,   126,   127,
     200,   128,   129,   205,   206,   207,   208,   124,   125,   126,
     127,    21,   128,   129,    36,     2,     3,     4,     5,   101,
      50,   203,   191,     0,   130,   131,   132,   133,   134,   135,
     136,   155,   137,   138,   184,   130,   131,   132,   133,   134,
     135,   136,   175,   137,   138,     0,   130,   131,   132,   133,
     134,   135,   136,     0,   137,   138,   124,   125,   126,   127,
       0,   128,   129,     0,     0,     0,     0,   124,   125,   126,
     127,     0,   128,   129,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   126,   127,     0,   128,   129,     0,     0,
       0,   177,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,   180,   137,   138,     0,   130,   131,   132,   133,
     134,   135,   136,   192,   137,   138,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,     0,   137,   138,
     124,   125,   126,   127,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,   137,   138,    60,
       0,    61,     0,     0,    62,    63,    64,     0,    65,    66,
      67,     0,    68,    69,    70,     0,    71,     0,     0,    72,
      73,    74,    75,    76,     0,     0,    77,     0,    53,   122,
       0,     0,    79,     0,    60,     0,    61,     0,    80,    62,
      63,    64,     0,    65,    66,    67,     0,    68,    69,    70,
       0,    71,     0,     0,    72,    73,    74,    75,    76,     0,
       0,    77,     0,    53,   156,     0,     0,    79,     0,    60,
       0,    61,     0,    80,    62,    63,    64,     0,    65,    66,
      67,     0,    68,    69,    70,     0,    71,     0,     0,    72,
      73,    74,    75,    76,     0,     0,    77,     0,    53,  -107,
       0,     0,    79,     0,    60,     0,    61,     0,    80,    62,
      63,    64,     0,    65,    66,    67,     0,    68,    69,    70,
       0,    71,     0,     0,    72,    73,    74,    75,    76,     0,
      60,    77,    61,    53,     0,     0,     0,    79,     0,     0,
       0,    67,     0,    80,    69,    70,     0,     0,     0,     0,
      72,    73,    74,    75,    76,     0,     0,    77,     0,     0,
       0,     0,     0,    79,     0,     0,     0,     0,     0,    80
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      84,    65,    36,    29,    53,    82,    77,    56,    79,    80,
       0,    36,    13,    25,    43,     0,    13,    29,    13,     9,
      36,    42,    51,    44,    41,     3,     4,     5,     6,     7,
      42,    57,    58,    82,   105,    36,   107,   121,    28,    36,
     111,    36,   106,   114,   115,    57,    58,    43,    42,    39,
      44,    43,    17,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    56,   138,    46,   140,
       3,     4,     5,     6,     7,    16,    42,    18,    44,    36,
      21,    22,    23,   154,    25,    26,    27,    45,    29,    30,
      31,   175,    33,   177,    20,    36,    37,    38,    39,    40,
      41,    36,    43,    45,    45,   176,    36,   178,    49,   193,
      42,    45,   183,    46,    55,     3,     4,     5,     6,     7,
       8,   205,     4,     5,     6,     7,   210,   211,   192,   206,
     207,    19,    43,    42,    16,    44,    18,    43,    36,    21,
      22,    23,    43,    25,    26,    27,    43,    29,    30,    31,
      42,    33,    44,    43,    36,    37,    38,    39,    40,    36,
      41,    43,    41,    45,    46,    34,    35,    49,     4,     5,
       6,     7,    43,    55,    47,    43,    43,    46,    43,    43,
      16,    41,    18,    44,    36,    21,    22,    23,    44,    25,
      26,    27,    41,    29,    30,    31,    41,    33,    41,    43,
      36,    37,    38,    39,    40,    44,    41,    43,    45,    45,
      46,    24,    34,    49,    44,     9,    10,    11,    12,    55,
      14,    15,     4,     5,     6,     7,     9,    10,    11,    12,
      38,    14,    15,    44,    59,    59,    46,     9,    10,    11,
      12,     9,    14,    15,     3,     4,     5,     6,     7,    56,
      39,   196,   183,    -1,    48,    49,    50,    51,    52,    53,
      54,    44,    56,    57,    58,    48,    49,    50,    51,    52,
      53,    54,    44,    56,    57,    -1,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,     9,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    44,    56,    57,    -1,    48,    49,    50,    51,
      52,    53,    54,    41,    56,    57,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
       9,    10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    16,
      -1,    18,    -1,    -1,    21,    22,    23,    -1,    25,    26,
      27,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    43,    -1,    45,    46,
      -1,    -1,    49,    -1,    16,    -1,    18,    -1,    55,    21,
      22,    23,    -1,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    43,    -1,    45,    46,    -1,    -1,    49,    -1,    16,
      -1,    18,    -1,    55,    21,    22,    23,    -1,    25,    26,
      27,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    43,    -1,    45,    46,
      -1,    -1,    49,    -1,    16,    -1,    18,    -1,    55,    21,
      22,    23,    -1,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      16,    43,    18,    45,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    27,    -1,    55,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    19,    61,    62,
      63,    64,    65,    66,    68,    75,    83,    36,    36,    36,
       0,    63,    41,    13,    36,    43,    17,    76,    45,    43,
      65,    66,    67,    36,    20,    78,     3,    66,    81,    82,
      67,    36,    42,    44,    36,    77,    45,    36,    36,    46,
      81,    44,    65,    45,    70,    42,    80,    43,    43,    70,
      16,    18,    21,    22,    23,    25,    26,    27,    29,    30,
      31,    33,    36,    37,    38,    39,    40,    43,    46,    49,
      55,    64,    69,    70,    71,    72,    73,    74,    84,    85,
      86,    87,    88,    89,    90,    91,    95,    99,    36,    46,
      64,    68,    79,    67,    67,    43,    43,    43,    74,    41,
      36,    43,    43,    43,    43,    43,    73,    73,    73,    46,
      64,    71,    46,    72,     9,    10,    11,    12,    14,    15,
      48,    49,    50,    51,    52,    53,    54,    56,    57,    41,
      47,    44,    44,    73,    74,    73,    41,    73,    94,    44,
      44,    73,    73,    92,    93,    44,    46,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      36,    73,    73,    41,    41,    44,    41,    44,    42,    44,
      44,    44,    73,    43,    58,    72,    73,    72,    73,    41,
      45,    92,    41,    24,    34,    96,    97,    44,    74,    72,
      38,    35,    46,    96,    98,    44,    59,    59,    46,    72,
      71,    71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 216 "parser.y"
    { 
                            (yylsp[(1) - (1)]); 
                            /* pp2: The @1 is needed to convince 
                             * yacc to set up yylloc. You can remove 
                             * it once you have other uses of @n*/
                            Program *program = new Program((yyvsp[(1) - (1)].declList));
                            if (ReportError::NumErrors() == 0) {
                                // if no errors, advance to next phase
                                program->Print(0);
                            }
                      }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 232 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 237 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].fnDecl); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 239 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].classDecl); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 240 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].interfaceDecl); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 245 "parser.y"
    { (yyval.varDecl) = (yyvsp[(1) - (2)].var); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 250 "parser.y"
    { 
                              Identifier *id = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier));
                              (yyval.var) = new VarDecl(id, (yyvsp[(1) - (2)].type));
                      }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 261 "parser.y"
    { (yyval.type) = new Type(*Type::intType); }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 262 "parser.y"
    { (yyval.type) = new Type(*Type::doubleType); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 263 "parser.y"
    { (yyval.type) = new Type(*Type::boolType); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 264 "parser.y"
    { (yyval.type) = new Type(*Type::stringType); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 265 "parser.y"
    { (yyval.type) = new ArrayType((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].type)); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 270 "parser.y"
    { ((yyval.varList) = (yyvsp[(1) - (3)].varList))->Append((yyvsp[(3) - (3)].var)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 271 "parser.y"
    { ((yyval.varList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].var)); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 272 "parser.y"
    { ((yyval.varList) = new List<VarDecl*>); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 280 "parser.y"
    {
                          (yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList));
                          (yyval.fnDecl)->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));
                    }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 284 "parser.y"
    {
                                              (yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), 
                                                              new Type(*Type::voidType),
                                                              (yyvsp[(4) - (6)].varList));
                                              (yyval.fnDecl)->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));
                    }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 290 "parser.y"
    {  }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 295 "parser.y"
    { ((yyval.varDeclList) = (yyvsp[(1) - (2)].varDeclList))->Append((yyvsp[(2) - (2)].varDecl)); }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 296 "parser.y"
    { ((yyval.varDeclList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].varDecl)); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 301 "parser.y"
    { (yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (4)].varDeclList), (yyvsp[(3) - (4)].stmtList)); 
                                          }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 303 "parser.y"
    { List<Stmt*> *s = new List<Stmt*>;
                                            (yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (3)].varDeclList), s);
                                          }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 306 "parser.y"
    { List<VarDecl*> *v = new List<VarDecl*>;
                                            (yyval.stmtBlock) = new StmtBlock(v, (yyvsp[(2) - (3)].stmtList));  
                                          }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 309 "parser.y"
    { List<VarDecl*> *v = new List<VarDecl*>;
                                            List<Stmt*> *s = new List<Stmt*>;
                                            (yyval.stmtBlock) = new StmtBlock(v, s);
                                          }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 317 "parser.y"
    { ((yyval.stmtList) = (yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].stmt)); }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 318 "parser.y"
    { ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].stmt)); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 323 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (2)].expr)); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 324 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].stmtBlock)); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 325 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].ifStmt)); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 326 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].whileStmt)); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 327 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].forStmt)); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 328 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].returnStmt)); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 329 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].breakStmt)); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 330 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].printStmt)); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 331 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].switchStmt)); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 338 "parser.y"
    { ((yyval.expr) = (yyvsp[(1) - (1)].lValue)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 339 "parser.y"
    { 
                                    Operator *op = new Operator((yylsp[(2) - (3)]), "=");
                                    (yyval.expr) = new AssignExpr((yyvsp[(1) - (3)].lValue), op, (yyvsp[(3) - (3)].expr));
                              }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 343 "parser.y"
    { ((yyval.expr) = new ReadLineExpr((yylsp[(1) - (3)]))); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 344 "parser.y"
    { ((yyval.expr) = new NewExpr((yylsp[(1) - (2)]), 
                                                      new NamedType(new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)))
                                            )); 
                              }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 348 "parser.y"
    { (yyval.expr) = new This((yylsp[(1) - (1)])); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 349 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 350 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].call); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 351 "parser.y"
    { (yyval.expr) = new ReadIntegerExpr((yylsp[(1) - (3)])); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 352 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 353 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "+");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 356 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "-");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 359 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "*");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 362 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "/");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 365 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "%");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 368 "parser.y"
    { Operator *op = new Operator((yylsp[(1) - (2)]), "-");
                                            (yyval.expr) = new ArithmeticExpr(op, (yyvsp[(2) - (2)].expr));
                                          }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 371 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "<");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 374 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "<=");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 378 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), ">");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 381 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), ">=");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 385 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "==");
                                            (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 388 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "!=");
                                            (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 392 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "&&");
                                            (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 396 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "||");
                                            (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 400 "parser.y"
    { Operator *op = new Operator((yylsp[(1) - (2)]), "!");
                                            (yyval.expr) = new LogicalExpr(op, (yyvsp[(2) - (2)].expr));
                                          }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 407 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 408 "parser.y"
    { (yyval.expr) = new EmptyExpr(); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 415 "parser.y"
    {  
                                        Identifier *id = new Identifier((yylsp[(2) - (7)]), (yyvsp[(2) - (7)].identifier));
                                        (yyval.classDecl) = new ClassDecl(id, (yyvsp[(3) - (7)].namedType), (yyvsp[(4) - (7)].implementList), (yyvsp[(6) - (7)].fieldList));
                                      }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 423 "parser.y"
    {
                                      Identifier *id = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier));
                                      (yyval.namedType) = new NamedType(id);
                                    }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 427 "parser.y"
    { (yyval.namedType) = NULL; }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 432 "parser.y"
    {
                                      ((yyval.identifierList)=(yyvsp[(1) - (3)].identifierList))->Append(new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier)));
                                    }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 435 "parser.y"
    { 
                                      ((yyval.identifierList) = new List<Identifier*>)->Append(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)));
                                    }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 443 "parser.y"
    {
                                      (yyval.implementList) = new List<NamedType*>;
                                      for (int i = 0; i < (yyvsp[(2) - (2)].identifierList)->NumElements(); i++ )
                                        (yyval.implementList)->Append(new NamedType((yyvsp[(2) - (2)].identifierList)->Nth(i)));
                                    }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 448 "parser.y"
    { (yyval.implementList) = new List<NamedType*>; }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 453 "parser.y"
    { (yyval.field) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 454 "parser.y"
    { (yyval.field) = (yyvsp[(1) - (1)].fnDecl); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 459 "parser.y"
    { ((yyval.fieldList) = (yyvsp[(1) - (2)].fieldList))->Append((yyvsp[(2) - (2)].field)); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 460 "parser.y"
    { (yyval.fieldList) = new List<Decl*>; }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 466 "parser.y"
    {
                              Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier));
                              (yyval.prototype) = new FnDecl(id, (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList));
                        }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 470 "parser.y"
    {
                              Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier));
                              (yyval.prototype) = new FnDecl(id, new Type(*Type::voidType), (yyvsp[(4) - (6)].varList));
                        }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 478 "parser.y"
    { ((yyval.prototypeList)=(yyvsp[(1) - (2)].prototypeList))->Append((yyvsp[(2) - (2)].prototype)); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 479 "parser.y"
    { ((yyval.prototypeList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].prototype)); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 485 "parser.y"
    {
                              Identifier *id = new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier));
                              (yyval.interfaceDecl)  = new InterfaceDecl(id, (yyvsp[(4) - (5)].prototypeList));
                        }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 495 "parser.y"
    {
                            (yyval.ifStmt) = new IfStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), NULL);
                        }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 498 "parser.y"
    {
                            (yyval.ifStmt) = new IfStmt((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
                        }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 506 "parser.y"
    {
                          (yyval.whileStmt) = new WhileStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt));
                    }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 514 "parser.y"
    {
                          (yyval.forStmt) = new ForStmt((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt));
                    }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 523 "parser.y"
    {
                          (yyval.returnStmt) = new ReturnStmt((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].expr));
                    }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 531 "parser.y"
    {
                          (yyval.breakStmt) = new BreakStmt((yylsp[(1) - (2)]));
                    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 542 "parser.y"
    { 
                            Identifier *id = new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier));
                            (yyval.lValue) = new FieldAccess(NULL, id);
                      }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 546 "parser.y"
    {
                            Identifier *id = new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier));
                            (yyval.lValue) = new FieldAccess((yyvsp[(1) - (3)].expr), id);
                      }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 550 "parser.y"
    { 
                            (yyval.lValue) = new ArrayAccess((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); 
                      }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 562 "parser.y"
    { (yyval.expr) = new IntConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].integerConstant)); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 563 "parser.y"
    { (yyval.expr) = new DoubleConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].doubleConstant)); }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 564 "parser.y"
    { (yyval.expr) = new BoolConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 565 "parser.y"
    { (yyval.expr) = new StringConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].stringConstant)); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 566 "parser.y"
    { (yyval.expr) = new NullConstant((yylsp[(1) - (1)])); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 573 "parser.y"
    {
                                      Identifier *id = new Identifier((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].identifier));
                                      (yyval.call) = new Call((yylsp[(1) - (4)]), NULL, id, (yyvsp[(3) - (4)].exprList));
                                    }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 577 "parser.y"
    {
                                      Identifier *id = new Identifier((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].identifier));
                                      (yyval.call) = new Call((yylsp[(2) - (6)]), (yyvsp[(1) - (6)].expr), id, (yyvsp[(5) - (6)].exprList));
                                    }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 586 "parser.y"
    { (yyval.exprList) = (yyvsp[(1) - (1)].exprList); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 587 "parser.y"
    { (yyval.exprList) = new List<Expr*>; }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 592 "parser.y"
    { ((yyval.exprList) = (yyvsp[(1) - (2)].exprList))->Append((yyvsp[(2) - (2)].expr)); }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 593 "parser.y"
    { ((yyval.exprList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr)); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 598 "parser.y"
    { ((yyval.exprList)=(yyvsp[(1) - (3)].exprList))->Append((yyvsp[(3) - (3)].expr)); }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 599 "parser.y"
    { 
                             ((yyval.exprList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr));
                                    }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 607 "parser.y"
    { (yyval.printStmt) = new PrintStmt((yyvsp[(3) - (5)].exprList)); }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 611 "parser.y"
    {
                                      (yyval.caseStmt) = new Case(new IntConstant((yylsp[(2) - (4)]), (yyvsp[(2) - (4)].integerConstant)), (yyvsp[(4) - (4)].stmtList));
                                    }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 618 "parser.y"
    { ((yyval.caseList) = (yyvsp[(1) - (2)].caseList))->Append((yyvsp[(2) - (2)].caseStmt));  }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 619 "parser.y"
    { ((yyval.caseList) = new List<Case*>)->Append((yyvsp[(1) - (1)].caseStmt)); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 624 "parser.y"
    { (yyval.defaultExpr) = new Default((yyvsp[(3) - (3)].stmtList)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 629 "parser.y"
    {
                                      (yyval.switchStmt) = new SwitchStmt((yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].caseList), NULL);
                                    }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 632 "parser.y"
    {
                                      (yyval.switchStmt) = new SwitchStmt((yyvsp[(3) - (8)].expr), (yyvsp[(6) - (8)].caseList), (yyvsp[(7) - (8)].defaultExpr));
                                    }
    break;


/* Line 1787 of yacc.c  */
#line 2633 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 640 "parser.y"


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
