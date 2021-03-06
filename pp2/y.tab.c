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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   711

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  220

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
      47,    48,    44,    41,    46,    43,    56,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    45,
      53,    51,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
       0,     0,     3,     5,     8,    10,    11,    13,    15,    17,
      19,    22,    25,    27,    29,    31,    33,    36,    38,    42,
      44,    45,    52,    59,    62,    64,    69,    73,    77,    80,
      83,    85,    88,    90,    92,    94,    96,    98,   100,   102,
     104,   106,   110,   114,   119,   121,   123,   125,   129,   133,
     137,   141,   145,   149,   153,   156,   160,   164,   168,   172,
     176,   180,   184,   188,   191,   198,   200,   201,   209,   212,
     213,   217,   219,   222,   223,   225,   227,   230,   231,   238,
     245,   248,   250,   251,   257,   263,   271,   277,   287,   291,
     294,   296,   300,   305,   307,   309,   311,   313,   315,   320,
     327,   329,   330,   334,   336,   342,   347,   350,   352,   356,
     364
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    62,    -1,    62,    63,    -1,    63,    -1,
      -1,    64,    -1,    68,    -1,    75,    -1,    83,    -1,    65,
      45,    -1,    66,    36,    -1,     5,    -1,     6,    -1,     4,
      -1,     7,    -1,    66,    13,    -1,    36,    -1,    67,    46,
      65,    -1,    65,    -1,    -1,    66,    36,    47,    67,    48,
      70,    -1,     3,    36,    47,    67,    48,    70,    -1,    69,
      64,    -1,    64,    -1,    49,    69,    71,    50,    -1,    49,
      69,    50,    -1,    49,    71,    50,    -1,    49,    50,    -1,
      71,    72,    -1,    72,    -1,    74,    45,    -1,    70,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,
      94,    -1,    98,    -1,    89,    -1,    89,    51,    73,    -1,
      31,    47,    48,    -1,    27,    47,    36,    48,    -1,    18,
      -1,    90,    -1,    91,    -1,    30,    47,    48,    -1,    47,
      73,    48,    -1,    73,    41,    73,    -1,    73,    43,    73,
      -1,    73,    44,    73,    -1,    73,    42,    73,    -1,    73,
      52,    73,    -1,    43,    73,    -1,    73,    53,    73,    -1,
      73,     9,    73,    -1,    73,    54,    73,    -1,    73,    10,
      73,    -1,    73,    11,    73,    -1,    73,    12,    73,    -1,
      73,    14,    73,    -1,    73,    15,    73,    -1,    55,    73,
      -1,    28,    47,    73,    46,    66,    48,    -1,    73,    -1,
      -1,     8,    36,    76,    78,    49,    80,    50,    -1,    17,
      36,    -1,    -1,    77,    46,    36,    -1,    36,    -1,    20,
      77,    -1,    -1,    64,    -1,    68,    -1,    80,    79,    -1,
      -1,    66,    36,    47,    67,    48,    45,    -1,     3,    36,
      47,    67,    48,    45,    -1,    82,    81,    -1,    81,    -1,
      -1,    19,    36,    49,    82,    50,    -1,    23,    47,    73,
      48,    72,    -1,    23,    47,    73,    48,    72,    24,    72,
      -1,    21,    47,    73,    48,    72,    -1,    22,    47,    74,
      45,    73,    45,    74,    48,    72,    -1,    25,    74,    45,
      -1,    26,    45,    -1,    36,    -1,    73,    56,    36,    -1,
      73,    57,    73,    58,    -1,    38,    -1,    39,    -1,    40,
      -1,    37,    -1,    16,    -1,    36,    47,    92,    48,    -1,
      73,    56,    36,    47,    92,    48,    -1,    93,    -1,    -1,
      93,    46,    73,    -1,    73,    -1,    29,    47,    93,    48,
      45,    -1,    34,    38,    59,    71,    -1,    96,    95,    -1,
      95,    -1,    35,    59,    71,    -1,    33,    47,    73,    48,
      49,    96,    50,    -1,    33,    47,    73,    48,    49,    96,
      97,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   244,   244,   259,   260,   261,   266,   267,   268,   269,
     274,   279,   290,   291,   292,   293,   294,   295,   301,   302,
     303,   311,   315,   325,   326,   331,   333,   336,   339,   347,
     348,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     368,   369,   373,   374,   378,   379,   380,   381,   382,   383,
     386,   389,   392,   395,   398,   401,   404,   408,   411,   415,
     418,   422,   426,   430,   433,   440,   441,   448,   456,   460,
     465,   468,   476,   481,   486,   487,   492,   493,   499,   503,
     511,   512,   513,   519,   529,   532,   540,   548,   557,   565,
     576,   580,   584,   596,   597,   598,   599,   600,   607,   611,
     620,   621,   633,   634,   642,   646,   653,   654,   659,   664,
     667
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
  "T_BoolConstant", "'+'", "'/'", "'-'", "'*'", "';'", "','", "'('", "')'",
  "'{'", "'}'", "'='", "'%'", "'<'", "'>'", "'!'", "'.'", "'['", "']'",
  "':'", "$accept", "Program", "DeclList", "Decl", "VarDecl", "Var",
  "Type", "VarList", "FnDecl", "VarDeclList", "StmtBlock", "StmtList",
  "Stmt", "Expr", "OneExpr", "ClassDecl", "Extends", "IdentifierList",
  "Implements", "Field", "FieldList", "Prototype", "PrototypeList",
  "InterfaceDecl", "IfStmt", "WhileStmt", "ForStmt", "ReturnStmt",
  "BreakStmt", "LValue", "Constant", "Call", "Actuals", "CommaExprList",
  "PrintStmt", "Case", "CaseList", "Default", "SwitchStmt", YY_NULL
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
     295,    43,    47,    45,    42,    59,    44,    40,    41,   123,
     125,    61,    37,    60,    62,    33,    46,    91,    93,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    62,    63,    63,    63,    63,
      64,    65,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    83,    84,    84,    85,    86,    87,    88,
      89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    95,    96,    96,    97,    98,
      98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     2,     1,     3,     1,
       0,     6,     6,     2,     1,     4,     3,     3,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     6,     1,     0,     7,     2,     0,
       3,     1,     2,     0,     1,     1,     2,     0,     6,     6,
       2,     1,     0,     5,     5,     7,     5,     9,     3,     2,
       1,     3,     4,     1,     1,     1,     1,     1,     4,     6,
       1,     0,     3,     1,     5,     4,     2,     1,     3,     7,
       8
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,    14,    12,    13,    15,     0,     0,    17,     0,
       2,     4,     6,     0,     0,     7,     8,     9,     0,    69,
       0,     1,     3,    10,    16,    11,    20,     0,    73,    82,
      20,    19,     0,     0,    68,     0,     0,     0,     0,    81,
       0,     0,    11,     0,     0,    71,    72,    77,     0,     0,
      83,    80,     0,    18,    66,    22,     0,     0,    20,    20,
      21,    97,    44,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,    90,    96,    93,    94,    95,     0,
       0,    28,     0,    24,    66,    32,    66,    30,    65,     0,
      33,    34,    35,    36,    37,    40,    45,    46,    38,    39,
      70,    67,    74,    75,    76,     0,     0,     0,    66,     0,
      90,     0,    89,     0,     0,     0,     0,     0,     0,   101,
      54,     0,    63,    26,    23,    66,    27,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      88,     0,     0,   103,     0,    47,    42,     0,     0,   100,
      48,    25,    56,    58,    59,    60,    61,    62,    49,    52,
      50,    51,    53,    55,    57,    91,     0,    41,    79,    78,
      66,     0,    66,    43,     0,     0,     0,     0,    98,   101,
      92,    86,     0,    84,     0,   102,   104,     0,     0,    66,
      66,    64,     0,   107,     0,    99,     0,    85,     0,     0,
     109,   106,     0,    66,    66,    66,   110,    87,   105,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    32,    33,    15,    84,
      85,    86,    87,    88,    89,    16,    28,    46,    36,   104,
      57,    39,    40,    17,    90,    91,    92,    93,    94,    95,
      96,    97,   158,   159,    98,   203,   204,   212,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int16 yypact[] =
{
     138,   -20,   -85,   -85,   -85,   -85,   -18,   -17,   -85,     6,
     138,   -85,   -85,   -23,    -8,   -85,   -85,   -85,   -21,    21,
       4,   -85,   -85,   -85,   -85,    14,   114,     7,    44,    30,
     114,   -85,    -6,    77,   -85,    51,    39,    59,    -4,   -85,
       8,   119,   -85,   114,    43,   -85,    62,   -85,    64,    70,
     -85,   -85,    43,   -85,   133,   -85,    88,    97,   114,   114,
     -85,   -85,   -85,    80,    81,   101,   656,   134,   131,   149,
     150,   151,   152,   153,    -5,   -85,   -85,   -85,   -85,   656,
     656,   -85,   656,   -85,   185,   -85,   490,   -85,   380,   136,
     -85,   -85,   -85,   -85,   -85,   135,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   129,   139,   656,   656,   656,
     155,   159,   -85,   158,   656,   656,   157,   161,   656,   656,
      53,   234,   380,   -85,   -85,   525,   -85,   -85,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   181,   656,   -85,   656,   174,   175,   251,   182,   300,
     -85,   178,   317,   380,   147,   -85,   -85,   324,   183,   184,
     -85,   -85,   380,   380,   397,   380,   380,   380,   433,   448,
      53,    37,   380,   380,   380,   186,   227,   380,   -85,   -85,
     630,   656,   630,   -85,   114,   656,   202,   180,   -85,   656,
     -85,   -85,   373,   226,    -9,   380,   -85,   217,   204,   656,
     630,   -85,   215,   -85,   118,   -85,   206,   -85,   196,   197,
     -85,   -85,   207,   630,   630,   630,   -85,   -85,   560,   595
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   248,   -30,    56,     0,    54,   210,   -85,
     -27,   -83,   -84,   -59,   -63,   -85,   -85,   -85,   -85,   -85,
     -85,   219,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,    75,   187,   -85,    68,   -85,   -85,   -85
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -109
static const yytype_int16 yytable[] =
{
      14,   125,   127,   111,    24,    24,    21,    24,   -17,    24,
      14,    37,     2,     3,     4,     5,    18,    55,    19,    20,
     120,   121,    23,   122,    83,    60,    26,   102,    25,    38,
      42,   -17,    49,    37,     2,     3,     4,     5,    27,   201,
      38,   127,   119,    34,     8,   148,   128,   129,   147,   131,
     149,   132,   133,    29,   124,   152,   153,    14,    50,   157,
     153,    30,   128,   129,    35,   131,     8,   132,   133,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,    31,   176,    41,   177,    31,    45,    47,   138,
     139,   140,    54,   141,   142,    48,   191,   137,   193,    53,
       1,     2,     3,     4,     5,   138,   139,   140,    56,   141,
     142,    58,   105,   106,    31,    31,   207,    59,     2,     3,
       4,     5,   192,    43,   100,    44,   195,   107,   108,   217,
     153,   218,   219,     8,   127,   127,   206,     2,     3,     4,
       5,     1,     2,     3,     4,     5,     6,   101,   109,    61,
       8,    62,   202,   209,    63,    64,    65,     7,    66,    67,
      68,    69,    70,    71,    72,    43,    73,    52,   210,    74,
      75,    76,    77,    78,     8,    43,    79,   145,   113,   112,
      80,   143,    54,    81,   194,    43,   144,   146,    82,     2,
       3,     4,     5,   185,   151,   186,   114,   115,   116,   117,
     118,    61,   119,    62,   150,   155,    63,    64,    65,   156,
      66,    67,    68,    69,    70,    71,    72,   175,    73,   178,
     179,    74,    75,    76,    77,    78,   183,   181,    79,   197,
     185,   188,    80,   189,    54,   123,   128,   129,   130,   131,
      82,   132,   133,   128,   129,   130,   131,   196,   132,   133,
     200,   202,   205,   208,   213,   214,   215,   216,    22,    51,
     128,   129,   130,   131,   198,   132,   133,   103,   134,   135,
     136,   137,   211,     0,     0,   134,   135,   136,   137,   138,
     139,   140,   160,   141,   142,   190,   138,   139,   140,     0,
     141,   142,   134,   135,   136,   137,     0,     0,     0,   180,
       0,     0,   154,   138,   139,   140,     0,   141,   142,   128,
     129,   130,   131,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   129,   130,   131,
       0,   132,   133,   128,   129,   130,   131,     0,   132,   133,
       0,   134,   135,   136,   137,     0,     0,     0,   182,     0,
       0,     0,   138,   139,   140,     0,   141,   142,   134,   135,
     136,   137,     0,   184,     0,   134,   135,   136,   137,   138,
     139,   140,   187,   141,   142,     0,   138,   139,   140,     0,
     141,   142,   128,   129,   130,   131,     0,   132,   133,   128,
     129,   130,   131,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   129,     0,   131,
       0,   132,   133,     0,   134,   135,   136,   137,   199,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,   141,
     142,     0,   138,   139,   140,     0,   141,   142,   134,   135,
     136,   137,   128,   129,     0,   131,     0,   132,   133,   138,
     139,   140,     0,   141,   142,     0,     0,   128,   129,     0,
     131,     0,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   140,     0,   141,
     142,   136,   137,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   140,     0,   141,   142,    61,     0,    62,     0,
       0,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,     0,    73,     0,     0,   110,    75,    76,    77,
      78,     0,     0,    79,     0,     0,     0,    80,     0,    54,
     126,    61,     0,    62,     0,    82,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
       0,   110,    75,    76,    77,    78,     0,     0,    79,     0,
       0,     0,    80,     0,    54,   161,    61,     0,    62,     0,
      82,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,     0,    73,     0,     0,   110,    75,    76,    77,
      78,     0,     0,    79,     0,   -66,     0,    80,     0,    54,
       0,    61,     0,    62,     0,    82,    63,    64,    65,     0,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
       0,   110,    75,    76,    77,    78,     0,     0,    79,     0,
       0,     0,    80,     0,    54,  -108,    61,     0,    62,     0,
      82,    63,    64,    65,     0,    66,    67,    68,    69,    70,
      71,    72,     0,    73,     0,     0,   110,    75,    76,    77,
      78,     0,    61,    79,    62,     0,     0,    80,     0,    54,
       0,     0,     0,    68,    69,    82,    71,    72,     0,     0,
       0,     0,   110,    75,    76,    77,    78,     0,     0,    79,
       0,     0,     0,    80,     0,     0,     0,     0,     0,     0,
       0,    82
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    84,    86,    66,    13,    13,     0,    13,    13,    13,
      10,     3,     4,     5,     6,     7,    36,    44,    36,    36,
      79,    80,    45,    82,    54,    52,    47,    57,    36,    29,
      36,    36,    36,     3,     4,     5,     6,     7,    17,    48,
      40,   125,    47,    36,    36,   108,     9,    10,   107,    12,
     109,    14,    15,    49,    84,   114,   115,    57,    50,   118,
     119,    47,     9,    10,    20,    12,    36,    14,    15,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,    26,   142,    30,   144,    30,    36,    49,    52,
      53,    54,    49,    56,    57,    36,   180,    44,   182,    43,
       3,     4,     5,     6,     7,    52,    53,    54,    46,    56,
      57,    47,    58,    59,    58,    59,   200,    47,     4,     5,
       6,     7,   181,    46,    36,    48,   185,    47,    47,   213,
     189,   214,   215,    36,   218,   219,   199,     4,     5,     6,
       7,     3,     4,     5,     6,     7,     8,    50,    47,    16,
      36,    18,    34,    35,    21,    22,    23,    19,    25,    26,
      27,    28,    29,    30,    31,    46,    33,    48,    50,    36,
      37,    38,    39,    40,    36,    46,    43,    48,    47,    45,
      47,    45,    49,    50,   184,    46,    51,    48,    55,     4,
       5,     6,     7,    46,    36,    48,    47,    47,    47,    47,
      47,    16,    47,    18,    45,    48,    21,    22,    23,    48,
      25,    26,    27,    28,    29,    30,    31,    36,    33,    45,
      45,    36,    37,    38,    39,    40,    48,    45,    43,    49,
      46,    48,    47,    47,    49,    50,     9,    10,    11,    12,
      55,    14,    15,     9,    10,    11,    12,    45,    14,    15,
      24,    34,    48,    38,    48,    59,    59,    50,    10,    40,
       9,    10,    11,    12,   189,    14,    15,    57,    41,    42,
      43,    44,   204,    -1,    -1,    41,    42,    43,    44,    52,
      53,    54,    48,    56,    57,    58,    52,    53,    54,    -1,
      56,    57,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,   115,    52,    53,    54,    -1,    56,    57,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      -1,    14,    15,     9,    10,    11,    12,    -1,    14,    15,
      -1,    41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    52,    53,    54,    -1,    56,    57,    41,    42,
      43,    44,    -1,    46,    -1,    41,    42,    43,    44,    52,
      53,    54,    48,    56,    57,    -1,    52,    53,    54,    -1,
      56,    57,     9,    10,    11,    12,    -1,    14,    15,     9,
      10,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    -1,    12,
      -1,    14,    15,    -1,    41,    42,    43,    44,    45,    -1,
      -1,    41,    42,    43,    44,    52,    53,    54,    -1,    56,
      57,    -1,    52,    53,    54,    -1,    56,    57,    41,    42,
      43,    44,     9,    10,    -1,    12,    -1,    14,    15,    52,
      53,    54,    -1,    56,    57,    -1,    -1,     9,    10,    -1,
      12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    -1,    56,
      57,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    -1,    56,    57,    16,    -1,    18,    -1,
      -1,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    -1,    -1,    47,    -1,    49,
      50,    16,    -1,    18,    -1,    55,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    43,    -1,
      -1,    -1,    47,    -1,    49,    50,    16,    -1,    18,    -1,
      55,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,    -1,    47,    -1,    49,
      -1,    16,    -1,    18,    -1,    55,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    38,    39,    40,    -1,    -1,    43,    -1,
      -1,    -1,    47,    -1,    49,    50,    16,    -1,    18,    -1,
      55,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    -1,    16,    43,    18,    -1,    -1,    47,    -1,    49,
      -1,    -1,    -1,    27,    28,    55,    30,    31,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    -1,    -1,    43,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    19,    36,    61,
      62,    63,    64,    65,    66,    68,    75,    83,    36,    36,
      36,     0,    63,    45,    13,    36,    47,    17,    76,    49,
      47,    65,    66,    67,    36,    20,    78,     3,    66,    81,
      82,    67,    36,    46,    48,    36,    77,    49,    36,    36,
      50,    81,    48,    65,    49,    70,    46,    80,    47,    47,
      70,    16,    18,    21,    22,    23,    25,    26,    27,    28,
      29,    30,    31,    33,    36,    37,    38,    39,    40,    43,
      47,    50,    55,    64,    69,    70,    71,    72,    73,    74,
      84,    85,    86,    87,    88,    89,    90,    91,    94,    98,
      36,    50,    64,    68,    79,    67,    67,    47,    47,    47,
      36,    74,    45,    47,    47,    47,    47,    47,    47,    47,
      73,    73,    73,    50,    64,    71,    50,    72,     9,    10,
      11,    12,    14,    15,    41,    42,    43,    44,    52,    53,
      54,    56,    57,    45,    51,    48,    48,    73,    74,    73,
      45,    36,    73,    73,    93,    48,    48,    73,    92,    93,
      48,    50,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    36,    73,    73,    45,    45,
      48,    45,    48,    48,    46,    46,    48,    48,    48,    47,
      58,    72,    73,    72,    66,    73,    45,    49,    92,    45,
      24,    48,    34,    95,    96,    48,    74,    72,    38,    35,
      50,    95,    97,    48,    59,    59,    50,    72,    71,    71
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
#line 244 "parser.y"
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
#line 259 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 260 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 261 "parser.y"
    { (yyval.declList) = new List<Decl*>; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 266 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 267 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].fnDecl); }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 268 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].classDecl); }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 269 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].interfaceDecl); }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 274 "parser.y"
    { (yyval.varDecl) = (yyvsp[(1) - (2)].var); }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 279 "parser.y"
    { 
                              Identifier *id = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier));
                              (yyval.var) = new VarDecl(id, (yyvsp[(1) - (2)].type));
                      }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 290 "parser.y"
    { (yyval.type) = new Type(*Type::intType); }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 291 "parser.y"
    { (yyval.type) = new Type(*Type::doubleType); }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 292 "parser.y"
    { (yyval.type) = new Type(*Type::boolType); }
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 293 "parser.y"
    { (yyval.type) = new Type(*Type::stringType); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 294 "parser.y"
    { (yyval.type) = new ArrayType((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].type)); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 295 "parser.y"
    { Identifier *id = new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier));
                                          (yyval.type) = new NamedType(id); }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 301 "parser.y"
    { ((yyval.varList) = (yyvsp[(1) - (3)].varList))->Append((yyvsp[(3) - (3)].var)); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 302 "parser.y"
    { ((yyval.varList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].var)); }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 303 "parser.y"
    { ((yyval.varList) = new List<VarDecl*>); }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 311 "parser.y"
    {
                          (yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList));
                          (yyval.fnDecl)->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));
                    }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 315 "parser.y"
    {
                                              (yyval.fnDecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), 
                                                              new Type(*Type::voidType),
                                                              (yyvsp[(4) - (6)].varList));
                                              (yyval.fnDecl)->SetFunctionBody((yyvsp[(6) - (6)].stmtBlock));
                    }
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 325 "parser.y"
    { ((yyval.varDeclList) = (yyvsp[(1) - (2)].varDeclList))->Append((yyvsp[(2) - (2)].varDecl)); }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 326 "parser.y"
    { ((yyval.varDeclList) = new List<VarDecl*>)->Append((yyvsp[(1) - (1)].varDecl)); }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 331 "parser.y"
    { (yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (4)].varDeclList), (yyvsp[(3) - (4)].stmtList)); 
                                          }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 333 "parser.y"
    { List<Stmt*> *s = new List<Stmt*>;
                                            (yyval.stmtBlock) = new StmtBlock((yyvsp[(2) - (3)].varDeclList), s);
                                          }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 336 "parser.y"
    { List<VarDecl*> *v = new List<VarDecl*>;
                                            (yyval.stmtBlock) = new StmtBlock(v, (yyvsp[(2) - (3)].stmtList));  
                                          }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 339 "parser.y"
    { List<VarDecl*> *v = new List<VarDecl*>;
                                            List<Stmt*> *s = new List<Stmt*>;
                                            (yyval.stmtBlock) = new StmtBlock(v, s);
                                          }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 347 "parser.y"
    { ((yyval.stmtList) = (yyvsp[(1) - (2)].stmtList))->Append((yyvsp[(2) - (2)].stmt)); }
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 348 "parser.y"
    { ((yyval.stmtList) = new List<Stmt*>)->Append((yyvsp[(1) - (1)].stmt)); }
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 353 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (2)].expr)); }
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 354 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].stmtBlock)); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 355 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].ifStmt)); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 356 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].whileStmt)); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 357 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].forStmt)); }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 358 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].returnStmt)); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 359 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].breakStmt)); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 360 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].printStmt)); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 361 "parser.y"
    { ((yyval.stmt) = (yyvsp[(1) - (1)].switchStmt)); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 368 "parser.y"
    { ((yyval.expr) = (yyvsp[(1) - (1)].lValue)); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 369 "parser.y"
    { 
                                    Operator *op = new Operator((yylsp[(2) - (3)]), "=");
                                    (yyval.expr) = new AssignExpr((yyvsp[(1) - (3)].lValue), op, (yyvsp[(3) - (3)].expr));
                              }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 373 "parser.y"
    { ((yyval.expr) = new ReadLineExpr((yylsp[(1) - (3)]))); }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 374 "parser.y"
    { ((yyval.expr) = new NewExpr((yylsp[(1) - (4)]), 
                                                    new NamedType(new Identifier((yylsp[(3) - (4)]), (yyvsp[(3) - (4)].identifier)))
                                            )); 
                              }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 378 "parser.y"
    { (yyval.expr) = new This((yylsp[(1) - (1)])); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 379 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 380 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].call); }
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 381 "parser.y"
    { (yyval.expr) = new ReadIntegerExpr((yylsp[(1) - (3)])); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 382 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 383 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "+");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 386 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "-");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 389 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "*");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 392 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "/");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 395 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "%");
                                            (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 398 "parser.y"
    { Operator *op = new Operator((yylsp[(1) - (2)]), "-");
                                            (yyval.expr) = new ArithmeticExpr(op, (yyvsp[(2) - (2)].expr));
                                          }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 401 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "<");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 404 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "<=");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 408 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), ">");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 411 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), ">=");
                                            (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 415 "parser.y"
    { Operator *op = new Operator((yylsp[(2) - (3)]), "==");
                                            (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 418 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "!=");
                                            (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 422 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "&&");
                                            (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 426 "parser.y"
    {
                                            Operator *op = new Operator((yylsp[(2) - (3)]), "||");
                                            (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr), op, (yyvsp[(3) - (3)].expr));
                                          }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 430 "parser.y"
    { Operator *op = new Operator((yylsp[(1) - (2)]), "!");
                                            (yyval.expr) = new LogicalExpr(op, (yyvsp[(2) - (2)].expr));
                                          }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 433 "parser.y"
    {
                                      (yyval.expr) = new NewArrayExpr((yylsp[(1) - (6)]), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].type));
                                    }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 440 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 441 "parser.y"
    { (yyval.expr) = new EmptyExpr(); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 448 "parser.y"
    {  
                                        Identifier *id = new Identifier((yylsp[(2) - (7)]), (yyvsp[(2) - (7)].identifier));
                                        (yyval.classDecl) = new ClassDecl(id, (yyvsp[(3) - (7)].namedType), (yyvsp[(4) - (7)].implementList), (yyvsp[(6) - (7)].fieldList));
                                      }
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 456 "parser.y"
    {
                                      Identifier *id = new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier));
                                      (yyval.namedType) = new NamedType(id);
                                    }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 460 "parser.y"
    { (yyval.namedType) = NULL; }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 465 "parser.y"
    {
                                      ((yyval.identifierList)=(yyvsp[(1) - (3)].identifierList))->Append(new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier)));
                                    }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 468 "parser.y"
    { 
                                      ((yyval.identifierList) = new List<Identifier*>)->Append(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier)));
                                    }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 476 "parser.y"
    {
                                      (yyval.implementList) = new List<NamedType*>;
                                      for (int i = 0; i < (yyvsp[(2) - (2)].identifierList)->NumElements(); i++ )
                                        (yyval.implementList)->Append(new NamedType((yyvsp[(2) - (2)].identifierList)->Nth(i)));
                                    }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 481 "parser.y"
    { (yyval.implementList) = new List<NamedType*>; }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 486 "parser.y"
    { (yyval.field) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 487 "parser.y"
    { (yyval.field) = (yyvsp[(1) - (1)].fnDecl); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 492 "parser.y"
    { ((yyval.fieldList) = (yyvsp[(1) - (2)].fieldList))->Append((yyvsp[(2) - (2)].field)); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 493 "parser.y"
    { (yyval.fieldList) = new List<Decl*>; }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 499 "parser.y"
    {
                              Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier));
                              (yyval.prototype) = new FnDecl(id, (yyvsp[(1) - (6)].type), (yyvsp[(4) - (6)].varList));
                        }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 503 "parser.y"
    {
                              Identifier *id = new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier));
                              (yyval.prototype) = new FnDecl(id, new Type(*Type::voidType), (yyvsp[(4) - (6)].varList));
                        }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 511 "parser.y"
    { ((yyval.prototypeList)=(yyvsp[(1) - (2)].prototypeList))->Append((yyvsp[(2) - (2)].prototype)); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 512 "parser.y"
    { ((yyval.prototypeList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].prototype)); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 513 "parser.y"
    { (yyval.prototypeList) = new List<Decl*>; }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 519 "parser.y"
    {
                              Identifier *id = new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier));
                              (yyval.interfaceDecl)  = new InterfaceDecl(id, (yyvsp[(4) - (5)].prototypeList));
                        }
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 529 "parser.y"
    {
                            (yyval.ifStmt) = new IfStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), NULL);
                        }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 532 "parser.y"
    {
                            (yyval.ifStmt) = new IfStmt((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt));
                        }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 540 "parser.y"
    {
                          (yyval.whileStmt) = new WhileStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt));
                    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 548 "parser.y"
    {
                          (yyval.forStmt) = new ForStmt((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt));
                    }
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 557 "parser.y"
    {
                          (yyval.returnStmt) = new ReturnStmt((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].expr));
                    }
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 565 "parser.y"
    {
                          (yyval.breakStmt) = new BreakStmt((yylsp[(1) - (2)]));
                    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 576 "parser.y"
    { 
                            Identifier *id = new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier));
                            (yyval.lValue) = new FieldAccess(NULL, id);
                      }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 580 "parser.y"
    {
                            Identifier *id = new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier));
                            (yyval.lValue) = new FieldAccess((yyvsp[(1) - (3)].expr), id);
                      }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 584 "parser.y"
    { 
                            (yyval.lValue) = new ArrayAccess((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); 
                      }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 596 "parser.y"
    { (yyval.expr) = new IntConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].integerConstant)); }
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 597 "parser.y"
    { (yyval.expr) = new DoubleConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].doubleConstant)); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 598 "parser.y"
    { (yyval.expr) = new BoolConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 599 "parser.y"
    { (yyval.expr) = new StringConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].stringConstant)); }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 600 "parser.y"
    { (yyval.expr) = new NullConstant((yylsp[(1) - (1)])); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 607 "parser.y"
    {
                                      Identifier *id = new Identifier((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].identifier));
                                      (yyval.call) = new Call((yylsp[(1) - (4)]), NULL, id, (yyvsp[(3) - (4)].exprList));
                                    }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 611 "parser.y"
    {
                                      Identifier *id = new Identifier((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].identifier));
                                      (yyval.call) = new Call((yylsp[(2) - (6)]), (yyvsp[(1) - (6)].expr), id, (yyvsp[(5) - (6)].exprList));
                                    }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 620 "parser.y"
    { (yyval.exprList) = (yyvsp[(1) - (1)].exprList); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 621 "parser.y"
    { (yyval.exprList) = new List<Expr*>; }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 633 "parser.y"
    { ((yyval.exprList)=(yyvsp[(1) - (3)].exprList))->Append((yyvsp[(3) - (3)].expr)); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 634 "parser.y"
    { 
                             ((yyval.exprList) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr));
                                    }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 642 "parser.y"
    { (yyval.printStmt) = new PrintStmt((yyvsp[(3) - (5)].exprList)); }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 646 "parser.y"
    {
                                      (yyval.caseStmt) = new Case(new IntConstant((yylsp[(2) - (4)]), (yyvsp[(2) - (4)].integerConstant)), (yyvsp[(4) - (4)].stmtList));
                                    }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 653 "parser.y"
    { ((yyval.caseList) = (yyvsp[(1) - (2)].caseList))->Append((yyvsp[(2) - (2)].caseStmt));  }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 654 "parser.y"
    { ((yyval.caseList) = new List<Case*>)->Append((yyvsp[(1) - (1)].caseStmt)); }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 659 "parser.y"
    { (yyval.defaultExpr) = new Default((yyvsp[(3) - (3)].stmtList)); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 664 "parser.y"
    {
                                      (yyval.switchStmt) = new SwitchStmt((yyvsp[(3) - (7)].expr), (yyvsp[(6) - (7)].caseList), NULL);
                                    }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 667 "parser.y"
    {
                                      (yyval.switchStmt) = new SwitchStmt((yyvsp[(3) - (8)].expr), (yyvsp[(6) - (8)].caseList), (yyvsp[(7) - (8)].defaultExpr));
                                    }
    break;


/* Line 1787 of yacc.c  */
#line 2674 "y.tab.c"
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
#line 675 "parser.y"


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
