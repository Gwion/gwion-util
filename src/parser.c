/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         gwion_parse
#define yylex           gwion_lex
#define yyerror         gwion_error
#define yydebug         gwion_debug
#define yynerrs         gwion_nerrs


/* Copy the first part of user declarations.  */
#line 5 "ly/gwion.y" /* yacc.c:339  */

#include <stdio.h> // strlen in paste operation
#include <string.h> // strlen in paste operation
#include <math.h>
#include "defs.h"
#include "map.h"
#include "symbol.h"
#include "absyn.h"
#include "hash.h"
#include "scanner.h"
#include "parser.h"
#include "lexer.h"
#define YYMALLOC xmalloc
#define scan arg->scanner
#define CHECK_FLAG(a,b,c) if(GET_FLAG(b, c)) { gwion_error(a, "flag set twice");  ; } SET_FLAG(b, c);
#define CHECK_TEMPLATE(a, b, c, free_function) { if(c->tmpl) {\
        free_id_list(b);\
        free_function(c);\
        gwion_error(a, "double template decl");\
        YYERROR;\
      }\
      c->tmpl = new_tmpl_class(b, -1);\
    };
#define OP_SYM(a) insert_symbol(op2str(a))
ANN int get_pos(const Scanner*);
ANN void gwion_error(const Scanner*, const m_str s);
m_str op2str(const Operator op);

#line 101 "src/parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "parser.h".  */
#ifndef YY_GWION_INCLUDE_PARSER_H_INCLUDED
# define YY_GWION_INCLUDE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gwion_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    CHUCK = 259,
    COMMA = 260,
    ASSIGN = 261,
    DIVIDE = 262,
    TIMES = 263,
    PERCENT = 264,
    L_HACK = 265,
    R_HACK = 266,
    LPAREN = 267,
    RPAREN = 268,
    LBRACK = 269,
    RBRACK = 270,
    LBRACE = 271,
    RBRACE = 272,
    PLUSCHUCK = 273,
    MINUSCHUCK = 274,
    TIMESCHUCK = 275,
    DIVIDECHUCK = 276,
    MODULOCHUCK = 277,
    ATCHUCK = 278,
    UNCHUCK = 279,
    TRIG = 280,
    UNTRIG = 281,
    PERCENTPAREN = 282,
    SHARPPAREN = 283,
    ATSYM = 284,
    FUNCTION = 285,
    DOLLAR = 286,
    TILDA = 287,
    QUESTION = 288,
    COLON = 289,
    EXCLAMATION = 290,
    IF = 291,
    ELSE = 292,
    WHILE = 293,
    DO = 294,
    UNTIL = 295,
    LOOP = 296,
    FOR = 297,
    GOTO = 298,
    SWITCH = 299,
    CASE = 300,
    ENUM = 301,
    RETURN = 302,
    BREAK = 303,
    CONTINUE = 304,
    PLUSPLUS = 305,
    MINUSMINUS = 306,
    NEW = 307,
    SPORK = 308,
    CLASS = 309,
    STATIC = 310,
    GLOBAL = 311,
    PRIVATE = 312,
    PROTECT = 313,
    EXTENDS = 314,
    DOT = 315,
    COLONCOLON = 316,
    AND = 317,
    EQ = 318,
    GE = 319,
    GT = 320,
    LE = 321,
    LT = 322,
    MINUS = 323,
    PLUS = 324,
    NEQ = 325,
    SHIFT_LEFT = 326,
    SHIFT_RIGHT = 327,
    S_AND = 328,
    S_OR = 329,
    S_XOR = 330,
    OR = 331,
    AST_DTOR = 332,
    OPERATOR = 333,
    TYPEDEF = 334,
    RSL = 335,
    RSR = 336,
    RSAND = 337,
    RSOR = 338,
    RSXOR = 339,
    TEMPLATE = 340,
    NOELSE = 341,
    LTB = 342,
    GTB = 343,
    UNION = 344,
    ATPAREN = 345,
    TYPEOF = 346,
    CONST = 347,
    AUTO = 348,
    PASTE = 349,
    ELLIPSE = 350,
    NUM = 351,
    FLOAT = 352,
    ID = 353,
    STRING_LIT = 354,
    CHAR_LIT = 355,
    PP_COMMENT = 356,
    PP_INCLUDE = 357,
    PP_DEFINE = 358,
    PP_UNDEF = 359,
    PP_IFDEF = 360,
    PP_IFNDEF = 361,
    PP_ELSE = 362,
    PP_ENDIF = 363,
    PP_NL = 364
  };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define CHUCK 259
#define COMMA 260
#define ASSIGN 261
#define DIVIDE 262
#define TIMES 263
#define PERCENT 264
#define L_HACK 265
#define R_HACK 266
#define LPAREN 267
#define RPAREN 268
#define LBRACK 269
#define RBRACK 270
#define LBRACE 271
#define RBRACE 272
#define PLUSCHUCK 273
#define MINUSCHUCK 274
#define TIMESCHUCK 275
#define DIVIDECHUCK 276
#define MODULOCHUCK 277
#define ATCHUCK 278
#define UNCHUCK 279
#define TRIG 280
#define UNTRIG 281
#define PERCENTPAREN 282
#define SHARPPAREN 283
#define ATSYM 284
#define FUNCTION 285
#define DOLLAR 286
#define TILDA 287
#define QUESTION 288
#define COLON 289
#define EXCLAMATION 290
#define IF 291
#define ELSE 292
#define WHILE 293
#define DO 294
#define UNTIL 295
#define LOOP 296
#define FOR 297
#define GOTO 298
#define SWITCH 299
#define CASE 300
#define ENUM 301
#define RETURN 302
#define BREAK 303
#define CONTINUE 304
#define PLUSPLUS 305
#define MINUSMINUS 306
#define NEW 307
#define SPORK 308
#define CLASS 309
#define STATIC 310
#define GLOBAL 311
#define PRIVATE 312
#define PROTECT 313
#define EXTENDS 314
#define DOT 315
#define COLONCOLON 316
#define AND 317
#define EQ 318
#define GE 319
#define GT 320
#define LE 321
#define LT 322
#define MINUS 323
#define PLUS 324
#define NEQ 325
#define SHIFT_LEFT 326
#define SHIFT_RIGHT 327
#define S_AND 328
#define S_OR 329
#define S_XOR 330
#define OR 331
#define AST_DTOR 332
#define OPERATOR 333
#define TYPEDEF 334
#define RSL 335
#define RSR 336
#define RSAND 337
#define RSOR 338
#define RSXOR 339
#define TEMPLATE 340
#define NOELSE 341
#define LTB 342
#define GTB 343
#define UNION 344
#define ATPAREN 345
#define TYPEOF 346
#define CONST 347
#define AUTO 348
#define PASTE 349
#define ELLIPSE 350
#define NUM 351
#define FLOAT 352
#define ID 353
#define STRING_LIT 354
#define CHAR_LIT 355
#define PP_COMMENT 356
#define PP_INCLUDE 357
#define PP_DEFINE 358
#define PP_UNDEF 359
#define PP_IFDEF 360
#define PP_IFNDEF 361
#define PP_ELSE 362
#define PP_ENDIF 363
#define PP_NL 364

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "ly/gwion.y" /* yacc.c:355  */

  char* sval;
  int ival;
  ae_flag flag;
  m_float fval;
  Symbol sym;
  Array_Sub array_sub;
  Var_Decl var_decl;
  Var_Decl_List var_decl_list;
  Type_Decl* type_decl;
  Exp   exp;
  Stmt_Fptr func_type;
  Stmt stmt;
  Stmt_List stmt_list;
  Arg_List arg_list;
  Decl_List decl_list;
  Func_Def func_def;
  Section* section;
  ID_List id_list;
  Type_List type_list;
  Class_Body class_body;
  ID_List class_ext;
  Class_Def class_def;
  Ast ast;

#line 385 "src/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int gwion_parse (Scanner* arg);

#endif /* !YY_GWION_INCLUDE_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 401 "src/parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  183
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1399

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  220
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  377

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   113,   117,   118,   119,   123,   125,   128,
     128,   130,   130,   133,   134,   137,   137,   138,   138,   140,
     140,   142,   143,   146,   147,   148,   152,   153,   157,   158,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   180,   181,   188,   188,   191,   194,   196,
     197,   198,   201,   203,   205,   207,   209,   211,   213,   215,
     220,   222,   227,   228,   229,   230,   234,   235,   238,   238,
     240,   240,   242,   242,   244,   244,   244,   245,   245,   246,
     246,   247,   247,   248,   248,   249,   249,   249,   250,   250,
     251,   255,   256,   257,   261,   262,   263,   267,   268,   269,
     271,   273,   275,   279,   279,   280,   280,   282,   284,   285,
     286,   287,   288,   291,   291,   292,   292,   293,   293,   296,
     298,   311,   311,   311,   311,   311,   311,   313,   314,   316,
     318,   323,   323,   326,   327,   328,   330,   332,   333,   337,
     338,   342,   351,   352,   356,   357,   358,   361,   361,   362,
     362,   362,   362,   363,   363,   364,   364,   365,   365,   365,
     366,   366,   369,   369,   370,   370,   371,   371,   372,   372,
     373,   373,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   380,   380,   383,   383,   384,   385,   385,   385,
     388,   388,   390,   399,   403,   403,   407,   408,   411,   411,
     413,   413,   415,   415,   417,   420,   422,   426,   427,   428,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "CHUCK", "COMMA", "ASSIGN",
  "DIVIDE", "TIMES", "PERCENT", "L_HACK", "R_HACK", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "PLUSCHUCK", "MINUSCHUCK",
  "TIMESCHUCK", "DIVIDECHUCK", "MODULOCHUCK", "ATCHUCK", "UNCHUCK", "TRIG",
  "UNTRIG", "PERCENTPAREN", "SHARPPAREN", "ATSYM", "FUNCTION", "DOLLAR",
  "TILDA", "QUESTION", "COLON", "EXCLAMATION", "IF", "ELSE", "WHILE", "DO",
  "UNTIL", "LOOP", "FOR", "GOTO", "SWITCH", "CASE", "ENUM", "RETURN",
  "BREAK", "CONTINUE", "PLUSPLUS", "MINUSMINUS", "NEW", "SPORK", "CLASS",
  "STATIC", "GLOBAL", "PRIVATE", "PROTECT", "EXTENDS", "DOT", "COLONCOLON",
  "AND", "EQ", "GE", "GT", "LE", "LT", "MINUS", "PLUS", "NEQ",
  "SHIFT_LEFT", "SHIFT_RIGHT", "S_AND", "S_OR", "S_XOR", "OR", "AST_DTOR",
  "OPERATOR", "TYPEDEF", "RSL", "RSR", "RSAND", "RSOR", "RSXOR",
  "TEMPLATE", "NOELSE", "LTB", "GTB", "UNION", "ATPAREN", "TYPEOF",
  "CONST", "AUTO", "PASTE", "ELLIPSE", "NUM", "FLOAT", "ID", "STRING_LIT",
  "CHAR_LIT", "PP_COMMENT", "PP_INCLUDE", "PP_DEFINE", "PP_UNDEF",
  "PP_IFDEF", "PP_IFNDEF", "PP_ELSE", "PP_ENDIF", "PP_NL", "$accept",
  "ast", "section", "class_def", "class_ext", "class_body", "class_body2",
  "id_list", "id_dot", "stmt_list", "func_type", "stmt_type", "type_decl2",
  "arg_list", "code_stmt", "stmt", "id", "opt_id", "enum_stmt",
  "label_stmt", "goto_stmt", "case_stmt", "switch_stmt", "loop_stmt",
  "selection_stmt", "jump_stmt", "exp_stmt", "exp", "binary_exp",
  "template", "op", "array_exp", "array_empty", "decl_exp", "func_args",
  "arg_type", "decl_template", "flag", "func_flag", "type_flag",
  "opt_flag", "func_def_base", "op_op", "func_def", "atsym", "type_decl",
  "decl_list", "union_stmt", "var_decl_list", "var_decl", "eq_op",
  "rel_op", "shift_op", "add_op", "mul_op", "con_exp", "log_or_exp",
  "log_and_exp", "inc_or_exp", "exc_or_exp", "and_exp", "eq_exp",
  "rel_exp", "shift_exp", "add_exp", "mul_exp", "cast_exp", "unary_op",
  "unary_exp", "dur_exp", "type_list", "call_paren", "post_op", "post_exp",
  "vec_type", "primary_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364
};
# endif

#define YYPACT_NINF -306

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-306)))

#define YYTABLE_NINF -132

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     360,  -306,  -306,  1089,   783,   834,   458,  -306,  -306,    64,
    -306,  -306,     8,    12,   556,    23,    31,    56,   -27,  1089,
    1089,    64,   681,    73,   106,  -306,  -306,    16,   101,    64,
    1089,  1089,  1089,  1089,   -27,  -306,   101,  1243,    64,    36,
      16,    64,  -306,   116,    16,  -306,  -306,    37,  -306,  -306,
     133,   360,  -306,  -306,  -306,  -306,  -306,   556,   -13,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,   131,  1191,
    -306,   124,  -306,    11,    16,    16,  -306,  -306,   -27,  -306,
    -306,    -4,    77,    78,    79,    80,    34,    81,   -33,    44,
     142,   125,  1140,  -306,    97,  -306,    55,  1089,  -306,   -10,
     148,  1192,  -306,   147,  -306,   146,  -306,   145,  -306,  -306,
    -306,  -306,    64,  1089,  1089,    18,  1089,  1089,   630,   167,
     101,   137,    64,   156,  -306,   170,  -306,  -306,  -306,   149,
     160,  -306,   -27,  -306,  -306,  -306,  -306,   110,   117,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,  -306,    16,
    -306,  -306,  -306,  -306,  -306,    64,   -27,   176,    95,   -27,
     -27,  -306,   -27,  -306,  -306,  -306,  -306,  -306,  -306,  -306,
    1089,  1089,   885,  -306,  -306,  -306,   -27,   -27,   160,  -306,
     180,  1089,  1192,  1192,  1192,  1192,  1192,  -306,  -306,  1192,
    1192,  1192,  1192,  1192,    16,    16,  -306,  -306,    67,  1089,
     -27,    16,   174,  -306,  -306,   175,  -306,  -306,   173,  -306,
      64,   177,   178,  1089,  1089,   179,   181,   149,   732,  -306,
    -306,  -306,   -27,  -306,  -306,   124,   130,   190,   149,   -27,
     186,   111,    16,   -45,  -306,   191,   195,  -306,  -306,  -306,
    -306,   186,    70,  -306,   124,   -27,   182,    77,    78,    79,
      80,    34,    81,   -33,    44,   142,   125,  -306,   186,    55,
    -306,   134,   936,  -306,  -306,   987,  -306,   556,   556,   221,
     222,   556,   556,   -27,  1038,   209,    16,   211,   -27,  -306,
    -306,    16,   218,  -306,  -306,   -27,   149,  1089,   149,    -8,
    -306,    -8,  -306,  1192,   219,  -306,  -306,   220,  -306,   197,
    -306,  -306,  -306,  -306,  -306,   201,   556,   224,   -27,  -306,
     360,  -306,  -306,   -27,   101,   183,  -306,   235,   226,  -306,
    -306,   228,   101,  -306,  -306,   101,  -306,   556,  1089,  -306,
     556,   236,   360,   227,  -306,   242,  -306,   149,  1089,   -27,
    -306,  -306,  -306,  -306,  1315,  -306,  -306,  -306,  -306,    16,
    -306,  -306,   247,   556,  -306,  -306,  -306
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    67,   185,     0,     0,     0,     0,   208,   207,   113,
     189,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,     0,     0,   200,   201,     0,   188,   117,
       0,     0,     0,     0,     0,   184,     0,     0,   115,     0,
       0,   117,   209,     0,     0,   211,   212,    43,   213,   214,
       0,     2,     6,     4,    40,    41,    33,    19,   210,    38,
      34,    35,    37,    36,    31,    32,    39,    30,     0,    68,
     215,   216,    70,     0,     0,     0,   127,     5,     0,    42,
      97,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   180,     0,   182,   190,   186,   194,     0,   202,   210,
       0,     0,   220,     0,    94,     0,    28,     0,   109,   110,
     111,   112,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,    62,     0,    64,    65,   192,   131,
      23,   193,     0,    99,   100,   101,   102,     0,    17,   130,
      74,    90,   158,   157,   159,    78,    79,    80,    81,    82,
      77,    75,    83,    84,    76,   152,   150,   151,   149,   156,
     155,   153,   154,    85,    86,    87,    88,    89,   121,     0,
     124,   122,   126,   125,   123,   116,     0,   196,     0,    46,
       0,   138,     0,     1,     3,    20,   132,    48,   133,    66,
       0,     0,     0,    96,     8,   120,     0,     0,   144,    98,
     142,     0,     0,     0,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,   210,   191,     0,     0,
       0,     0,     0,   203,   206,     0,   218,   219,    91,    29,
     108,     0,     0,     0,     0,     0,     0,   131,     0,    49,
      51,    50,     0,    63,    25,    24,    10,    15,   131,     0,
       0,     0,     0,     0,    45,     0,     0,    44,    69,    71,
      95,     0,     0,   145,   146,     0,     0,   163,   165,   167,
     169,   171,   173,   175,   177,   179,   181,   183,     0,   195,
     205,     0,     0,   204,   217,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
      18,   104,     0,   107,   197,     0,   131,     0,   131,     0,
      22,     0,   143,     0,     0,    72,   199,     0,    93,    60,
      52,    53,    58,    57,    59,     0,     0,     0,    46,     9,
      12,    16,   103,     0,     0,     0,   135,     0,     0,   137,
     106,     0,     0,    21,   161,     0,   198,     0,     0,    54,
       0,     0,    13,     0,    11,    26,   128,   131,   139,    46,
     105,   119,   129,    61,     0,    55,    47,    14,     7,     0,
     136,   140,     0,     0,    27,   141,    56
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -306,   200,  -302,   184,  -306,  -306,   -98,  -172,  -169,     6,
    -306,  -306,   -14,  -114,     9,   -12,     0,  -305,  -306,  -306,
    -306,  -306,  -306,  -306,  -306,  -306,  -101,    27,   -92,  -306,
     225,    -5,  -105,   -23,  -162,   -53,  -306,    89,  -306,  -306,
       7,   193,  -306,  -306,  -222,    15,   -95,  -306,    -1,   -65,
    -306,   232,   233,   234,   240,   -41,  -306,    71,    75,    82,
      76,    83,    74,    84,    86,    72,    87,     1,    10,  -306,
    -188,  -306,   -34,    85,  -306,  -306
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    50,    51,    52,   297,   353,   354,   246,   137,    53,
      54,    55,   177,   332,    56,    57,    99,   255,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   222,
     191,    70,    71,    72,   302,   342,    73,   230,    74,    75,
     123,    76,   169,    77,   188,    78,   338,    79,   199,   200,
     209,   210,   211,   212,   213,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   101,    93,    94,
     178,   283,    95,    96,    97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    92,   115,   174,   251,   340,    58,   133,   134,   135,
     136,   256,   107,   128,    58,   293,   186,   238,   119,   186,
     113,   187,   305,   351,   114,   245,   299,   129,   352,   201,
     100,   103,   105,   281,   138,   116,   132,   131,   161,   162,
     129,     9,   130,   117,   129,   139,   120,   121,   179,   125,
     352,    58,    92,    47,   372,   130,   233,    58,   234,   181,
     196,   197,   224,   185,   304,    29,   193,   -73,   118,   219,
     295,    47,   202,   310,   129,   129,   126,     3,   198,     4,
     300,     5,   301,    34,   336,  -131,   339,   341,  -131,   130,
     130,   223,   216,   264,     7,     8,    39,   207,   112,   309,
     311,   216,   217,    40,   208,    25,    26,    43,    44,   127,
     122,   217,   159,   160,    47,   220,   314,     6,   122,   108,
     109,   110,   111,   176,   225,   244,   331,   175,   180,   240,
     122,   182,   247,   183,   189,   370,   335,   294,   192,   203,
     231,   232,   221,   235,   236,   155,   156,   157,   158,   142,
     143,   144,   204,   206,   205,   250,   214,    42,   218,   226,
     227,   228,   229,    45,    46,    47,    48,    49,   259,   129,
     239,   241,   242,   243,     5,   248,   247,   249,   186,   254,
     138,   252,   257,   253,   130,   265,   282,   285,   284,   296,
     287,   288,   291,   263,   292,   298,   261,   262,   301,   303,
     277,   278,   216,   216,   216,   216,   216,   307,   308,   216,
     216,   216,   216,   216,   129,   129,   313,   258,   216,   105,
     280,   129,   315,   286,   321,   322,   328,   330,   266,   130,
     130,   334,   345,   346,   347,   348,   130,   350,   358,   366,
     193,   360,   247,   359,   368,   224,   105,   369,   357,   138,
     375,   184,   129,   306,   367,   374,   364,   194,   343,   193,
     289,   290,   168,   371,   312,   198,   195,   130,   355,   170,
     171,   172,   344,   267,   223,   319,   320,   173,   268,   323,
     324,   270,   329,   272,   275,     0,   269,    58,    58,   271,
       0,    58,    58,   325,   273,     0,   129,   274,   247,     0,
     276,   129,     0,   279,     0,   138,     0,     0,     0,   317,
       0,   130,   105,   216,   349,     0,   333,     0,     0,     0,
       0,   327,     0,     0,     0,     0,    58,     0,   254,     0,
      58,    92,     0,   198,   337,   363,     0,     0,   365,     0,
       0,     0,     0,   356,     0,     0,     0,    58,     0,     0,
      58,   361,    58,    92,   362,     0,     0,     0,     0,   254,
       0,   376,     0,     1,     0,     0,     0,     0,     2,   129,
       3,     0,     4,    58,     5,     0,     6,     0,     0,     0,
       0,     0,     0,     0,   333,   337,     0,     7,     8,     0,
       9,     0,    10,     0,     0,    11,    12,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,     0,     0,    39,     0,    40,     0,    41,
      42,    43,    44,     0,     0,     0,    45,    46,    47,    48,
      49,     1,     0,     0,     0,     0,     2,     0,     3,     0,
       4,     0,     5,     0,     6,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
      10,     0,     0,    11,    12,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     0,    30,    31,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,    40,     0,    41,    42,    43,
      44,     0,     0,     0,    45,    46,    47,    48,    49,     1,
       0,     0,     0,     0,     2,     0,     3,     0,     4,     0,
       5,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,    10,     0,
       0,    11,    12,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       0,    30,    31,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,    38,     0,     0,     2,     0,
       3,     0,     4,    40,     5,    41,    42,    43,    44,     0,
       0,     0,    45,    46,    47,    48,    49,     7,     8,     0,
       0,     0,    10,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    26,    27,    28,   124,    30,    31,    32,    33,     2,
       0,     3,     0,     4,     0,     5,     0,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     8,
       0,     0,     0,    10,     0,     0,    11,    40,     0,     0,
      42,    43,    44,   237,     0,     0,    45,    46,    47,    48,
      49,    25,    26,    27,    28,     1,    30,    31,    32,    33,
       2,     0,     3,     0,     4,     0,     5,     0,    34,    35,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       8,     0,     0,     0,    10,     0,     0,    11,    40,     0,
       0,    42,    43,    44,     0,     0,     0,    45,    46,    47,
      48,    49,    25,    26,    27,    28,     0,    30,    31,    32,
      33,     2,     0,     3,     0,     4,   102,     5,     0,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     0,     0,    10,     0,     0,    11,    40,
       0,     0,    42,    43,    44,     0,     0,     0,    45,    46,
      47,    48,    49,    25,    26,    27,    28,     0,    30,    31,
      32,    33,     2,     0,     3,     0,     4,     0,     5,   104,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     0,     0,    10,     0,     0,    11,
      40,     0,     0,    42,    43,    44,     0,     0,     0,    45,
      46,    47,    48,    49,    25,    26,    27,    28,     0,    30,
      31,    32,    33,     2,     0,     3,     0,     4,     0,     5,
     260,    34,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     0,     0,    10,     0,     0,
      11,    40,     0,     0,    42,    43,    44,     0,     0,     0,
      45,    46,    47,    48,    49,    25,    26,    27,    28,     0,
      30,    31,    32,    33,     2,     0,     3,     0,     4,   316,
       5,     0,    34,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     0,     0,    10,     0,
       0,    11,    40,     0,     0,    42,    43,    44,     0,     0,
       0,    45,    46,    47,    48,    49,    25,    26,    27,    28,
       0,    30,    31,    32,    33,     2,     0,     3,     0,     4,
       0,     5,   318,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     0,     0,    10,
       0,     0,    11,    40,     0,     0,    42,    43,    44,     0,
       0,     0,    45,    46,    47,    48,    49,    25,    26,    27,
      28,     0,    30,    31,    32,    33,     2,     0,     3,     0,
       4,   326,     5,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     0,     0,
      10,     0,     0,    11,    40,     0,     0,    42,    43,    44,
       0,     0,     0,    45,    46,    47,    48,    49,    25,    26,
      27,    28,     0,    30,    31,    32,    33,     2,     0,     3,
       0,     4,     0,     5,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     8,     0,     0,
       0,    10,     0,     0,    11,    40,     0,     0,    42,    43,
      44,     0,     0,     0,    45,    46,    47,    48,    49,    25,
      26,    27,    28,     0,    30,    31,    32,    33,     2,     0,
       3,     0,     4,     0,     5,     0,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     0,
       0,     0,    10,     0,     0,    11,    40,     0,     0,    42,
      43,    44,     0,     0,     0,    45,    46,    47,    48,    49,
      25,    26,    27,    28,     0,   140,   190,   141,     0,     0,
       2,     0,     3,     0,     4,     0,     5,     0,    35,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   215,     7,
       8,     0,     0,     0,    10,     0,     0,    11,     0,     0,
      42,     0,     0,     0,     0,     0,    45,    46,    47,    48,
      49,     0,    25,    26,    27,    28,     0,   140,     0,   141,
     142,   143,   144,     0,   154,     0,     0,     0,     0,     0,
      35,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,   163,   164,   165,   166,   167,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     0,     0,     0,    45,    46,
      47,    48,    49,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,     0,   161,   162,     0,     0,     0,   140,
       0,   141,     0,   163,   164,   165,   166,   167,   373,     0,
       0,     0,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,   167
};

static const yytype_int16 yycheck[] =
{
       0,     0,    14,    37,   176,    13,     6,    30,    31,    32,
      33,   180,     6,    27,    14,   237,    29,   118,    18,    29,
      12,    34,    67,   328,    12,   130,   248,    27,   330,    33,
       3,     4,     5,   221,    34,    12,    29,    28,    71,    72,
      40,    30,    27,    12,    44,    36,    19,    20,    41,    22,
     352,    51,    51,    98,   359,    40,    38,    57,    40,    44,
      74,    75,    96,    57,   252,    54,    71,    12,    12,    14,
     242,    98,    76,     3,    74,    75,     3,    10,    78,    12,
     249,    14,    12,    67,   306,    98,   308,    95,    98,    74,
      75,    96,    92,   198,    27,    28,    85,    63,     9,   261,
     262,   101,    92,    87,    70,    50,    51,    91,    92,     3,
      21,   101,    68,    69,    98,    60,   278,    16,    29,    55,
      56,    57,    58,    87,    97,   130,   298,    38,    12,   120,
      41,    94,   132,     0,     3,   357,   305,   238,    14,    62,
     113,   114,    87,   116,   117,    64,    65,    66,    67,     7,
       8,     9,    74,    73,    75,   169,    31,    90,    61,    11,
      13,    15,    17,    96,    97,    98,    99,   100,   191,   169,
       3,    34,    16,     3,    14,    65,   176,    60,    29,   179,
     180,     5,   182,    88,   169,     5,    12,    14,    13,    59,
      13,    13,    13,   198,    13,     5,   196,   197,    12,    88,
     214,   215,   202,   203,   204,   205,   206,    16,    13,   209,
     210,   211,   212,   213,   214,   215,    34,   190,   218,   192,
     220,   221,    88,   228,     3,     3,    17,    16,   201,   214,
     215,    13,    13,    13,    37,    34,   221,    13,     3,     3,
     245,    13,   242,    17,    17,   279,   219,     5,    65,   249,
       3,    51,   252,   253,   352,   369,   348,    73,   311,   264,
     233,   234,    37,   358,   265,   265,    73,   252,   333,    37,
      37,    37,   313,   202,   279,   287,   288,    37,   203,   291,
     292,   205,   296,   209,   212,    -1,   204,   287,   288,   206,
      -1,   291,   292,   293,   210,    -1,   296,   211,   298,    -1,
     213,   301,    -1,   218,    -1,   305,    -1,    -1,    -1,   282,
      -1,   296,   285,   313,   326,    -1,   301,    -1,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,   326,    -1,   328,    -1,
     330,   330,    -1,   333,   307,   347,    -1,    -1,   350,    -1,
      -1,    -1,    -1,   334,    -1,    -1,    -1,   347,    -1,    -1,
     350,   342,   352,   352,   345,    -1,    -1,    -1,    -1,   359,
      -1,   373,    -1,     3,    -1,    -1,    -1,    -1,     8,   369,
      10,    -1,    12,   373,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   369,   358,    -1,    27,    28,    -1,
      30,    -1,    32,    -1,    -1,    35,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    96,    97,    98,    99,
     100,     3,    -1,    -1,    -1,    -1,     8,    -1,    10,    -1,
      12,    -1,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      32,    -1,    -1,    35,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    90,    91,
      92,    -1,    -1,    -1,    96,    97,    98,    99,   100,     3,
      -1,    -1,    -1,    -1,     8,    -1,    10,    -1,    12,    -1,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    35,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    79,    -1,    -1,     8,    -1,
      10,    -1,    12,    87,    14,    89,    90,    91,    92,    -1,
      -1,    -1,    96,    97,    98,    99,   100,    27,    28,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,     3,    55,    56,    57,    58,     8,
      -1,    10,    -1,    12,    -1,    14,    -1,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    32,    -1,    -1,    35,    87,    -1,    -1,
      90,    91,    92,    93,    -1,    -1,    96,    97,    98,    99,
     100,    50,    51,    52,    53,     3,    55,    56,    57,    58,
       8,    -1,    10,    -1,    12,    -1,    14,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    32,    -1,    -1,    35,    87,    -1,
      -1,    90,    91,    92,    -1,    -1,    -1,    96,    97,    98,
      99,   100,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,     8,    -1,    10,    -1,    12,    13,    14,    -1,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,    87,
      -1,    -1,    90,    91,    92,    -1,    -1,    -1,    96,    97,
      98,    99,   100,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,     8,    -1,    10,    -1,    12,    -1,    14,    15,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      87,    -1,    -1,    90,    91,    92,    -1,    -1,    -1,    96,
      97,    98,    99,   100,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,     8,    -1,    10,    -1,    12,    -1,    14,
      15,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,
      35,    87,    -1,    -1,    90,    91,    92,    -1,    -1,    -1,
      96,    97,    98,    99,   100,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,     8,    -1,    10,    -1,    12,    13,
      14,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    32,    -1,
      -1,    35,    87,    -1,    -1,    90,    91,    92,    -1,    -1,
      -1,    96,    97,    98,    99,   100,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,     8,    -1,    10,    -1,    12,
      -1,    14,    15,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    32,
      -1,    -1,    35,    87,    -1,    -1,    90,    91,    92,    -1,
      -1,    -1,    96,    97,    98,    99,   100,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,     8,    -1,    10,    -1,
      12,    13,    14,    -1,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      32,    -1,    -1,    35,    87,    -1,    -1,    90,    91,    92,
      -1,    -1,    -1,    96,    97,    98,    99,   100,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,     8,    -1,    10,
      -1,    12,    -1,    14,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    87,    -1,    -1,    90,    91,
      92,    -1,    -1,    -1,    96,    97,    98,    99,   100,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,     8,    -1,
      10,    -1,    12,    -1,    14,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    32,    -1,    -1,    35,    87,    -1,    -1,    90,
      91,    92,    -1,    -1,    -1,    96,    97,    98,    99,   100,
      50,    51,    52,    53,    -1,     4,     5,     6,    -1,    -1,
       8,    -1,    10,    -1,    12,    -1,    14,    -1,    68,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    78,    27,
      28,    -1,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
     100,    -1,    50,    51,    52,    53,    -1,     4,    -1,     6,
       7,     8,     9,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      68,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   100,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    -1,    -1,    -1,     4,
      -1,     6,    -1,    80,    81,    82,    83,    84,    13,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     8,    10,    12,    14,    16,    27,    28,    30,
      32,    35,    36,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    67,    68,    77,    78,    79,    85,
      87,    89,    90,    91,    92,    96,    97,    98,    99,   100,
     111,   112,   113,   119,   120,   121,   124,   125,   126,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     141,   142,   143,   146,   148,   149,   151,   153,   155,   157,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   182,   183,   184,   185,   126,
     137,   177,    13,   137,    15,   137,    17,   119,    55,    56,
      57,    58,   147,    12,    12,   125,    12,    12,    12,   126,
     137,   137,   147,   150,     3,   137,     3,     3,   122,   126,
     155,   124,   150,   143,   143,   143,   143,   118,   126,   124,
       4,     6,     7,     8,     9,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    63,    64,    65,    66,    67,    68,
      69,    71,    72,    80,    81,    82,    83,    84,   140,   152,
     161,   162,   163,   164,   182,   147,    87,   122,   180,   150,
      12,   155,    94,     0,   111,   119,    29,    34,   154,     3,
       5,   140,    14,   141,   113,   151,   122,   122,   126,   158,
     159,    33,    76,    62,    74,    75,    73,    63,    70,   160,
     161,   162,   163,   164,    31,    78,   126,   178,    61,    14,
      60,    87,   139,   141,   182,   137,    11,    13,    15,    17,
     147,   137,   137,    38,    40,   137,   137,    93,   136,     3,
     124,    34,    16,     3,   141,   142,   117,   126,    65,    60,
     122,   117,     5,    88,   126,   127,   118,   126,   137,   143,
      15,   126,   126,   141,   142,     5,   137,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   122,   122,   183,
     126,   180,    12,   181,    13,    14,   141,    13,    13,   137,
     137,    13,    13,   154,   136,   117,    59,   114,     5,   154,
     118,    12,   144,    88,   180,    67,   126,    16,    13,   144,
       3,   144,   158,    34,   144,    88,    13,   137,    15,   125,
     125,     3,     3,   125,   125,   126,    13,   137,    17,   122,
      16,   117,   123,   155,    13,   118,   154,   137,   156,   154,
      13,    95,   145,   145,   165,    13,    13,    37,    34,   125,
      13,   127,   112,   115,   116,   159,   124,    65,     3,    17,
      13,   124,   124,   125,   138,   125,     3,   116,    17,     5,
     154,   156,   127,    13,   123,     3,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   110,   111,   111,   112,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   121,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   129,   130,
     131,   132,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   135,   135,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   141,   142,   142,   142,   143,   143,   143,
     143,   143,   143,   144,   144,   145,   145,   146,   147,   147,
     147,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   152,   152,   152,   152,   152,   153,   153,   153,
     153,   154,   154,   155,   155,   155,   155,   155,   155,   156,
     156,   157,   158,   158,   159,   159,   159,   160,   160,   161,
     161,   161,   161,   162,   162,   163,   163,   164,   164,   164,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   177,   177,   177,   177,   177,   177,
     178,   178,   178,   178,   179,   179,   180,   180,   181,   181,
     182,   182,   183,   183,   183,   183,   183,   184,   184,   184,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     7,     2,     2,
       0,     1,     0,     1,     2,     1,     3,     1,     3,     1,
       2,     5,     4,     1,     2,     2,     2,     4,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     7,     2,     3,
       3,     3,     5,     5,     6,     7,     9,     5,     5,     5,
       5,     7,     2,     3,     2,     2,     2,     1,     1,     3,
       1,     3,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     5,     2,     3,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     1,     4,     2,     1,
       1,     1,     1,     1,     2,     1,     2,     0,     1,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     6,     6,
       2,     0,     1,     2,     4,     5,     7,     5,     2,     2,
       3,     8,     1,     3,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     3,     1,     3,     3,     2,
       1,     1,     1,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      yyerror (arg, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, arg); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, Scanner* arg)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (arg);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, Scanner* arg)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, arg);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, Scanner* arg)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , arg);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, arg); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    default: /* Avoid compiler warnings. */
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, Scanner* arg)
{
  YYUSE (yyvaluep);
  YYUSE (arg);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 120: /* func_type  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1734 "src/parser.c" /* yacc.c:1258  */
        break;

    case 121: /* stmt_type  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1740 "src/parser.c" /* yacc.c:1258  */
        break;

    case 124: /* code_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1746 "src/parser.c" /* yacc.c:1258  */
        break;

    case 125: /* stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1752 "src/parser.c" /* yacc.c:1258  */
        break;

    case 128: /* enum_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1758 "src/parser.c" /* yacc.c:1258  */
        break;

    case 129: /* label_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1764 "src/parser.c" /* yacc.c:1258  */
        break;

    case 130: /* goto_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1770 "src/parser.c" /* yacc.c:1258  */
        break;

    case 131: /* case_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1776 "src/parser.c" /* yacc.c:1258  */
        break;

    case 132: /* switch_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1782 "src/parser.c" /* yacc.c:1258  */
        break;

    case 133: /* loop_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1788 "src/parser.c" /* yacc.c:1258  */
        break;

    case 134: /* selection_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1794 "src/parser.c" /* yacc.c:1258  */
        break;

    case 135: /* jump_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1800 "src/parser.c" /* yacc.c:1258  */
        break;

    case 136: /* exp_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1806 "src/parser.c" /* yacc.c:1258  */
        break;

    case 137: /* exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1812 "src/parser.c" /* yacc.c:1258  */
        break;

    case 138: /* binary_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1818 "src/parser.c" /* yacc.c:1258  */
        break;

    case 143: /* decl_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1824 "src/parser.c" /* yacc.c:1258  */
        break;

    case 157: /* union_stmt  */
#line 107 "ly/gwion.y" /* yacc.c:1258  */
      { free_stmt(((*yyvaluep).stmt)); }
#line 1830 "src/parser.c" /* yacc.c:1258  */
        break;

    case 165: /* con_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1836 "src/parser.c" /* yacc.c:1258  */
        break;

    case 166: /* log_or_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1842 "src/parser.c" /* yacc.c:1258  */
        break;

    case 167: /* log_and_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1848 "src/parser.c" /* yacc.c:1258  */
        break;

    case 168: /* inc_or_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1854 "src/parser.c" /* yacc.c:1258  */
        break;

    case 169: /* exc_or_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1860 "src/parser.c" /* yacc.c:1258  */
        break;

    case 170: /* and_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1866 "src/parser.c" /* yacc.c:1258  */
        break;

    case 171: /* eq_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1872 "src/parser.c" /* yacc.c:1258  */
        break;

    case 172: /* rel_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1878 "src/parser.c" /* yacc.c:1258  */
        break;

    case 173: /* shift_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1884 "src/parser.c" /* yacc.c:1258  */
        break;

    case 174: /* add_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1890 "src/parser.c" /* yacc.c:1258  */
        break;

    case 175: /* mul_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1896 "src/parser.c" /* yacc.c:1258  */
        break;

    case 176: /* cast_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1902 "src/parser.c" /* yacc.c:1258  */
        break;

    case 178: /* unary_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1908 "src/parser.c" /* yacc.c:1258  */
        break;

    case 179: /* dur_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1914 "src/parser.c" /* yacc.c:1258  */
        break;

    case 181: /* call_paren  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1920 "src/parser.c" /* yacc.c:1258  */
        break;

    case 183: /* post_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1926 "src/parser.c" /* yacc.c:1258  */
        break;

    case 185: /* primary_exp  */
#line 108 "ly/gwion.y" /* yacc.c:1258  */
      { free_exp(((*yyvaluep).exp)); }
#line 1932 "src/parser.c" /* yacc.c:1258  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Scanner* arg)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
      yychar = yylex (&yylval, scan);
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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 112 "ly/gwion.y" /* yacc.c:1651  */
    { arg->ast = (yyval.ast) = new_ast((yyvsp[0].section), NULL);  }
#line 2200 "src/parser.c" /* yacc.c:1651  */
    break;

  case 3:
#line 113 "ly/gwion.y" /* yacc.c:1651  */
    { arg->ast = (yyval.ast) = new_ast((yyvsp[-1].section), (yyvsp[0].ast)); }
#line 2206 "src/parser.c" /* yacc.c:1651  */
    break;

  case 4:
#line 117 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.section) = new_section_stmt_list((yyvsp[0].stmt_list)); }
#line 2212 "src/parser.c" /* yacc.c:1651  */
    break;

  case 5:
#line 118 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.section) = new_section_func_def ((yyvsp[0].func_def)); }
#line 2218 "src/parser.c" /* yacc.c:1651  */
    break;

  case 6:
#line 119 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.section) = new_section_class_def((yyvsp[0].class_def)); }
#line 2224 "src/parser.c" /* yacc.c:1651  */
    break;

  case 7:
#line 124 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.class_def) = new_class_def((yyvsp[-5].flag), (yyvsp[-4].id_list), (yyvsp[-3].type_decl), (yyvsp[-1].class_body)); }
#line 2230 "src/parser.c" /* yacc.c:1651  */
    break;

  case 8:
#line 125 "ly/gwion.y" /* yacc.c:1651  */
    { CHECK_TEMPLATE(arg, (yyvsp[-1].id_list), (yyvsp[0].class_def), free_class_def); (yyval.class_def) = (yyvsp[0].class_def); }
#line 2236 "src/parser.c" /* yacc.c:1651  */
    break;

  case 9:
#line 128 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = (yyvsp[0].type_decl); }
#line 2242 "src/parser.c" /* yacc.c:1651  */
    break;

  case 10:
#line 128 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = NULL; }
#line 2248 "src/parser.c" /* yacc.c:1651  */
    break;

  case 12:
#line 130 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.class_body) = NULL; }
#line 2254 "src/parser.c" /* yacc.c:1651  */
    break;

  case 13:
#line 133 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.class_body) = new_class_body((yyvsp[0].section), NULL); }
#line 2260 "src/parser.c" /* yacc.c:1651  */
    break;

  case 14:
#line 134 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.class_body) = new_class_body((yyvsp[-1].section), (yyvsp[0].class_body)); }
#line 2266 "src/parser.c" /* yacc.c:1651  */
    break;

  case 15:
#line 137 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.id_list) = new_id_list((yyvsp[0].sym), get_pos(arg)); }
#line 2272 "src/parser.c" /* yacc.c:1651  */
    break;

  case 16:
#line 137 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.id_list) = prepend_id_list((yyvsp[-2].sym), (yyvsp[0].id_list), get_pos(arg)); }
#line 2278 "src/parser.c" /* yacc.c:1651  */
    break;

  case 17:
#line 138 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.id_list) = new_id_list((yyvsp[0].sym), get_pos(arg)); }
#line 2284 "src/parser.c" /* yacc.c:1651  */
    break;

  case 18:
#line 138 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.id_list) = prepend_id_list((yyvsp[-2].sym), (yyvsp[0].id_list), get_pos(arg)); }
#line 2290 "src/parser.c" /* yacc.c:1651  */
    break;

  case 19:
#line 140 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = new_stmt_list((yyvsp[0].stmt), NULL);}
#line 2296 "src/parser.c" /* yacc.c:1651  */
    break;

  case 20:
#line 140 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = new_stmt_list((yyvsp[-1].stmt), (yyvsp[0].stmt_list));}
#line 2302 "src/parser.c" /* yacc.c:1651  */
    break;

  case 21:
#line 142 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_fptr((yyvsp[-2].sym), (yyvsp[-3].type_decl), (yyvsp[-1].arg_list), (yyvsp[0].ival)); (yyvsp[-3].type_decl)->flag |= (yyvsp[-4].flag); }
#line 2308 "src/parser.c" /* yacc.c:1651  */
    break;

  case 22:
#line 143 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_type((yyvsp[-2].type_decl), (yyvsp[-1].sym)); (yyvsp[-2].type_decl)->flag |= (yyvsp[-3].flag); }
#line 2314 "src/parser.c" /* yacc.c:1651  */
    break;

  case 24:
#line 147 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = add_type_decl_array((yyvsp[-1].type_decl), (yyvsp[0].array_sub)); }
#line 2320 "src/parser.c" /* yacc.c:1651  */
    break;

  case 25:
#line 148 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = add_type_decl_array((yyvsp[-1].type_decl), (yyvsp[0].array_sub)); }
#line 2326 "src/parser.c" /* yacc.c:1651  */
    break;

  case 26:
#line 152 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.arg_list) = new_arg_list((yyvsp[-1].type_decl), (yyvsp[0].var_decl), NULL); }
#line 2332 "src/parser.c" /* yacc.c:1651  */
    break;

  case 27:
#line 153 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.arg_list) = new_arg_list((yyvsp[-3].type_decl), (yyvsp[-2].var_decl), (yyvsp[0].arg_list)); }
#line 2338 "src/parser.c" /* yacc.c:1651  */
    break;

  case 28:
#line 157 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt(ae_stmt_code, get_pos(arg)); }
#line 2344 "src/parser.c" /* yacc.c:1651  */
    break;

  case 29:
#line 158 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_code((yyvsp[-1].stmt_list)); }
#line 2350 "src/parser.c" /* yacc.c:1651  */
    break;

  case 43:
#line 180 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.sym) = insert_symbol((yyvsp[0].sval)); }
#line 2356 "src/parser.c" /* yacc.c:1651  */
    break;

  case 44:
#line 181 "ly/gwion.y" /* yacc.c:1651  */
    {
    char c[strlen(s_name((yyvsp[0].sym))) + strlen((yyvsp[-2].sval))];
    sprintf(c, "%s%s", (yyvsp[-2].sval), s_name((yyvsp[0].sym)));
    (yyval.sym) = insert_symbol(c);
  }
#line 2366 "src/parser.c" /* yacc.c:1651  */
    break;

  case 46:
#line 188 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.sym) = NULL; }
#line 2372 "src/parser.c" /* yacc.c:1651  */
    break;

  case 47:
#line 191 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_enum((yyvsp[-3].id_list), (yyvsp[-1].sym));
    (yyval.stmt)->d.stmt_enum.flag = (yyvsp[-5].flag); }
#line 2379 "src/parser.c" /* yacc.c:1651  */
    break;

  case 48:
#line 194 "ly/gwion.y" /* yacc.c:1651  */
    {  (yyval.stmt) = new_stmt_jump((yyvsp[-1].sym), 1, get_pos(arg)); }
#line 2385 "src/parser.c" /* yacc.c:1651  */
    break;

  case 49:
#line 196 "ly/gwion.y" /* yacc.c:1651  */
    {  (yyval.stmt) = new_stmt_jump((yyvsp[-1].sym), 0, get_pos(arg)); }
#line 2391 "src/parser.c" /* yacc.c:1651  */
    break;

  case 50:
#line 197 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_exp(ae_stmt_case, (yyvsp[-1].exp)); }
#line 2397 "src/parser.c" /* yacc.c:1651  */
    break;

  case 51:
#line 198 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_switch((yyvsp[-1].exp), (yyvsp[0].stmt));}
#line 2403 "src/parser.c" /* yacc.c:1651  */
    break;

  case 52:
#line 202 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_flow(ae_stmt_while, (yyvsp[-2].exp), (yyvsp[0].stmt), 0); }
#line 2409 "src/parser.c" /* yacc.c:1651  */
    break;

  case 53:
#line 204 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_flow(ae_stmt_while, (yyvsp[-1].exp), (yyvsp[-3].stmt), 1); }
#line 2415 "src/parser.c" /* yacc.c:1651  */
    break;

  case 54:
#line 206 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_for((yyvsp[-3].stmt), (yyvsp[-2].stmt), NULL, (yyvsp[0].stmt)); }
#line 2421 "src/parser.c" /* yacc.c:1651  */
    break;

  case 55:
#line 208 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_for((yyvsp[-4].stmt), (yyvsp[-3].stmt), (yyvsp[-2].exp), (yyvsp[0].stmt)); }
#line 2427 "src/parser.c" /* yacc.c:1651  */
    break;

  case 56:
#line 210 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_auto((yyvsp[-4].sym), (yyvsp[-2].exp), (yyvsp[0].stmt)); (yyval.stmt)->d.stmt_auto.is_ptr = (yyvsp[-5].ival); }
#line 2433 "src/parser.c" /* yacc.c:1651  */
    break;

  case 57:
#line 212 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_flow(ae_stmt_until, (yyvsp[-2].exp), (yyvsp[0].stmt), 0); }
#line 2439 "src/parser.c" /* yacc.c:1651  */
    break;

  case 58:
#line 214 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_flow(ae_stmt_until, (yyvsp[-1].exp), (yyvsp[-3].stmt), 1); }
#line 2445 "src/parser.c" /* yacc.c:1651  */
    break;

  case 59:
#line 216 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_loop((yyvsp[-2].exp), (yyvsp[0].stmt)); }
#line 2451 "src/parser.c" /* yacc.c:1651  */
    break;

  case 60:
#line 221 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_if((yyvsp[-2].exp), (yyvsp[0].stmt)); }
#line 2457 "src/parser.c" /* yacc.c:1651  */
    break;

  case 61:
#line 223 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_if((yyvsp[-4].exp), (yyvsp[-2].stmt)); (yyval.stmt)->d.stmt_if.else_body = (yyvsp[0].stmt); }
#line 2463 "src/parser.c" /* yacc.c:1651  */
    break;

  case 62:
#line 227 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt(ae_stmt_return, get_pos(arg)); (yyval.stmt)->d.stmt_exp.self = (yyval.stmt); }
#line 2469 "src/parser.c" /* yacc.c:1651  */
    break;

  case 63:
#line 228 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_exp(ae_stmt_return, (yyvsp[-1].exp)); }
#line 2475 "src/parser.c" /* yacc.c:1651  */
    break;

  case 64:
#line 229 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt(ae_stmt_break, get_pos(arg)); }
#line 2481 "src/parser.c" /* yacc.c:1651  */
    break;

  case 65:
#line 230 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt(ae_stmt_continue, get_pos(arg)); }
#line 2487 "src/parser.c" /* yacc.c:1651  */
    break;

  case 66:
#line 234 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt_exp(ae_stmt_exp, (yyvsp[-1].exp)); }
#line 2493 "src/parser.c" /* yacc.c:1651  */
    break;

  case 67:
#line 235 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.stmt) = new_stmt(ae_stmt_exp, get_pos(arg)); }
#line 2499 "src/parser.c" /* yacc.c:1651  */
    break;

  case 69:
#line 238 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = prepend_exp((yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 2505 "src/parser.c" /* yacc.c:1651  */
    break;

  case 71:
#line 240 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), (yyvsp[-1].ival), (yyvsp[0].exp)); }
#line 2511 "src/parser.c" /* yacc.c:1651  */
    break;

  case 72:
#line 242 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_list) = (yyvsp[-1].type_list); }
#line 2517 "src/parser.c" /* yacc.c:1651  */
    break;

  case 73:
#line 242 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_list) = NULL; }
#line 2523 "src/parser.c" /* yacc.c:1651  */
    break;

  case 74:
#line 244 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_chuck; }
#line 2529 "src/parser.c" /* yacc.c:1651  */
    break;

  case 75:
#line 244 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_unchuck; }
#line 2535 "src/parser.c" /* yacc.c:1651  */
    break;

  case 76:
#line 244 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_eq; }
#line 2541 "src/parser.c" /* yacc.c:1651  */
    break;

  case 77:
#line 245 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_ref; }
#line 2547 "src/parser.c" /* yacc.c:1651  */
    break;

  case 78:
#line 245 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_radd; }
#line 2553 "src/parser.c" /* yacc.c:1651  */
    break;

  case 79:
#line 246 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rsub; }
#line 2559 "src/parser.c" /* yacc.c:1651  */
    break;

  case 80:
#line 246 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rmul; }
#line 2565 "src/parser.c" /* yacc.c:1651  */
    break;

  case 81:
#line 247 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rdiv; }
#line 2571 "src/parser.c" /* yacc.c:1651  */
    break;

  case 82:
#line 247 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rmod; }
#line 2577 "src/parser.c" /* yacc.c:1651  */
    break;

  case 83:
#line 248 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_trig; }
#line 2583 "src/parser.c" /* yacc.c:1651  */
    break;

  case 84:
#line 248 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_untrig; }
#line 2589 "src/parser.c" /* yacc.c:1651  */
    break;

  case 85:
#line 249 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rsl; }
#line 2595 "src/parser.c" /* yacc.c:1651  */
    break;

  case 86:
#line 249 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rsr; }
#line 2601 "src/parser.c" /* yacc.c:1651  */
    break;

  case 87:
#line 249 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rsand; }
#line 2607 "src/parser.c" /* yacc.c:1651  */
    break;

  case 88:
#line 250 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rsor; }
#line 2613 "src/parser.c" /* yacc.c:1651  */
    break;

  case 89:
#line 250 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_rsxor; }
#line 2619 "src/parser.c" /* yacc.c:1651  */
    break;

  case 90:
#line 251 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_assign; }
#line 2625 "src/parser.c" /* yacc.c:1651  */
    break;

  case 91:
#line 255 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.array_sub) = new_array_sub((yyvsp[-1].exp)); }
#line 2631 "src/parser.c" /* yacc.c:1651  */
    break;

  case 92:
#line 256 "ly/gwion.y" /* yacc.c:1651  */
    { if((yyvsp[-2].exp)->next){ gwion_error(arg, "invalid format for array init [...][...]..."); free_exp((yyvsp[-2].exp)); free_array_sub((yyvsp[0].array_sub)); YYERROR; } (yyval.array_sub) = prepend_array_sub((yyvsp[0].array_sub), (yyvsp[-2].exp)); }
#line 2637 "src/parser.c" /* yacc.c:1651  */
    break;

  case 93:
#line 257 "ly/gwion.y" /* yacc.c:1651  */
    { gwion_error(arg, "partially empty array init [...][]..."); free_exp((yyvsp[-3].exp)); YYERROR; }
#line 2643 "src/parser.c" /* yacc.c:1651  */
    break;

  case 94:
#line 261 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.array_sub) = new_array_sub(NULL); }
#line 2649 "src/parser.c" /* yacc.c:1651  */
    break;

  case 95:
#line 262 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.array_sub) = prepend_array_sub((yyvsp[-2].array_sub), NULL); }
#line 2655 "src/parser.c" /* yacc.c:1651  */
    break;

  case 96:
#line 263 "ly/gwion.y" /* yacc.c:1651  */
    { gwion_error(arg, "partially empty array init [][...]"); free_array_sub((yyvsp[-1].array_sub)); free_array_sub((yyvsp[0].array_sub)); YYERROR; }
#line 2661 "src/parser.c" /* yacc.c:1651  */
    break;

  case 98:
#line 268 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp)= new_exp_decl((yyvsp[-1].type_decl), (yyvsp[0].var_decl_list)); }
#line 2667 "src/parser.c" /* yacc.c:1651  */
    break;

  case 99:
#line 270 "ly/gwion.y" /* yacc.c:1651  */
    { CHECK_FLAG(arg, (yyvsp[0].exp)->d.exp_decl.td, ae_flag_static);  (yyval.exp) = (yyvsp[0].exp); }
#line 2673 "src/parser.c" /* yacc.c:1651  */
    break;

  case 100:
#line 272 "ly/gwion.y" /* yacc.c:1651  */
    { CHECK_FLAG(arg, (yyvsp[0].exp)->d.exp_decl.td, ae_flag_global);  (yyval.exp) = (yyvsp[0].exp); }
#line 2679 "src/parser.c" /* yacc.c:1651  */
    break;

  case 101:
#line 274 "ly/gwion.y" /* yacc.c:1651  */
    { CHECK_FLAG(arg, (yyvsp[0].exp)->d.exp_decl.td, ae_flag_private); (yyval.exp) = (yyvsp[0].exp); }
#line 2685 "src/parser.c" /* yacc.c:1651  */
    break;

  case 102:
#line 276 "ly/gwion.y" /* yacc.c:1651  */
    { CHECK_FLAG(arg, (yyvsp[0].exp)->d.exp_decl.td, ae_flag_protect); (yyval.exp) = (yyvsp[0].exp); }
#line 2691 "src/parser.c" /* yacc.c:1651  */
    break;

  case 103:
#line 279 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.arg_list) = (yyvsp[0].arg_list); }
#line 2697 "src/parser.c" /* yacc.c:1651  */
    break;

  case 104:
#line 279 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.arg_list) = NULL; }
#line 2703 "src/parser.c" /* yacc.c:1651  */
    break;

  case 105:
#line 280 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = ae_flag_variadic; }
#line 2709 "src/parser.c" /* yacc.c:1651  */
    break;

  case 106:
#line 280 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = 0; }
#line 2715 "src/parser.c" /* yacc.c:1651  */
    break;

  case 107:
#line 282 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.id_list) = (yyvsp[-1].id_list); }
#line 2721 "src/parser.c" /* yacc.c:1651  */
    break;

  case 108:
#line 284 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = (yyvsp[-1].flag) | (yyvsp[0].flag); }
#line 2727 "src/parser.c" /* yacc.c:1651  */
    break;

  case 109:
#line 285 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = ae_flag_static; }
#line 2733 "src/parser.c" /* yacc.c:1651  */
    break;

  case 110:
#line 286 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = ae_flag_global; }
#line 2739 "src/parser.c" /* yacc.c:1651  */
    break;

  case 111:
#line 287 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = ae_flag_private; }
#line 2745 "src/parser.c" /* yacc.c:1651  */
    break;

  case 112:
#line 288 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = ae_flag_protect; }
#line 2751 "src/parser.c" /* yacc.c:1651  */
    break;

  case 113:
#line 291 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = 0; }
#line 2757 "src/parser.c" /* yacc.c:1651  */
    break;

  case 114:
#line 291 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = (yyvsp[0].flag); }
#line 2763 "src/parser.c" /* yacc.c:1651  */
    break;

  case 115:
#line 292 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = 0; }
#line 2769 "src/parser.c" /* yacc.c:1651  */
    break;

  case 116:
#line 292 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = (yyvsp[0].flag); }
#line 2775 "src/parser.c" /* yacc.c:1651  */
    break;

  case 117:
#line 293 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = 0; }
#line 2781 "src/parser.c" /* yacc.c:1651  */
    break;

  case 118:
#line 293 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.flag) = (yyvsp[0].flag); }
#line 2787 "src/parser.c" /* yacc.c:1651  */
    break;

  case 119:
#line 297 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.func_def) = new_func_def((yyvsp[-4].type_decl), (yyvsp[-3].sym), (yyvsp[-2].arg_list), (yyvsp[0].stmt), (yyvsp[-5].flag) | (yyvsp[-1].ival)); }
#line 2793 "src/parser.c" /* yacc.c:1651  */
    break;

  case 120:
#line 299 "ly/gwion.y" /* yacc.c:1651  */
    {
      if((yyvsp[0].func_def)->tmpl) {
        free_id_list((yyvsp[-1].id_list));
        free_func_def((yyvsp[0].func_def));
        gwion_error(arg, "double template decl");
        YYERROR;
      }
      (yyvsp[0].func_def)->tmpl = new_tmpl_list((yyvsp[-1].id_list), -1);
      (yyval.func_def) = (yyvsp[0].func_def); SET_FLAG((yyval.func_def), ae_flag_template);
    }
#line 2808 "src/parser.c" /* yacc.c:1651  */
    break;

  case 128:
#line 315 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.func_def) = new_func_def((yyvsp[-3].type_decl), OP_SYM((yyvsp[-4].ival)), (yyvsp[-2].arg_list), (yyvsp[0].stmt), ae_flag_op); }
#line 2814 "src/parser.c" /* yacc.c:1651  */
    break;

  case 129:
#line 317 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.func_def) = new_func_def((yyvsp[-3].type_decl), OP_SYM((yyvsp[-5].ival)), (yyvsp[-2].arg_list), (yyvsp[0].stmt), ae_flag_op | ae_flag_unary); }
#line 2820 "src/parser.c" /* yacc.c:1651  */
    break;

  case 130:
#line 319 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.func_def) = new_func_def(new_type_decl(new_id_list(insert_symbol("void"), get_pos(arg)), 0),
       insert_symbol("dtor"), NULL, (yyvsp[0].stmt), ae_flag_dtor); }
#line 2827 "src/parser.c" /* yacc.c:1651  */
    break;

  case 131:
#line 323 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = 0; }
#line 2833 "src/parser.c" /* yacc.c:1651  */
    break;

  case 132:
#line 323 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = ae_flag_ref; }
#line 2839 "src/parser.c" /* yacc.c:1651  */
    break;

  case 133:
#line 326 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = new_type_decl(new_id_list((yyvsp[-1].sym), get_pos(arg)), (yyvsp[0].ival)); }
#line 2845 "src/parser.c" /* yacc.c:1651  */
    break;

  case 134:
#line 327 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = new_type_decl((yyvsp[-2].id_list), (yyvsp[0].ival)); }
#line 2851 "src/parser.c" /* yacc.c:1651  */
    break;

  case 135:
#line 328 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = new_type_decl(new_id_list((yyvsp[-1].sym), get_pos(arg)),
      (yyvsp[0].ival)); (yyval.type_decl)->types = (yyvsp[-3].type_list); }
#line 2858 "src/parser.c" /* yacc.c:1651  */
    break;

  case 136:
#line 330 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = new_type_decl((yyvsp[-2].id_list), (yyvsp[0].ival));
      (yyval.type_decl)->types = (yyvsp[-5].type_list); }
#line 2865 "src/parser.c" /* yacc.c:1651  */
    break;

  case 137:
#line 332 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_decl) = new_type_decl2((yyvsp[-2].id_list), (yyvsp[0].ival)); }
#line 2871 "src/parser.c" /* yacc.c:1651  */
    break;

  case 138:
#line 333 "ly/gwion.y" /* yacc.c:1651  */
    { CHECK_FLAG(arg, (yyvsp[0].type_decl), ae_flag_const); (yyval.type_decl) = (yyvsp[0].type_decl); }
#line 2877 "src/parser.c" /* yacc.c:1651  */
    break;

  case 139:
#line 337 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.decl_list) = new_decl_list((yyvsp[-1].exp), NULL); }
#line 2883 "src/parser.c" /* yacc.c:1651  */
    break;

  case 140:
#line 338 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.decl_list) = new_decl_list((yyvsp[-2].exp), (yyvsp[0].decl_list)); }
#line 2889 "src/parser.c" /* yacc.c:1651  */
    break;

  case 141:
#line 342 "ly/gwion.y" /* yacc.c:1651  */
    {
      (yyval.stmt) = new_stmt_union((yyvsp[-3].decl_list), get_pos(arg));
      (yyval.stmt)->d.stmt_union.type_xid = (yyvsp[-5].sym);
      (yyval.stmt)->d.stmt_union.xid = (yyvsp[-1].sym);
      (yyval.stmt)->d.stmt_union.flag = (yyvsp[-6].flag);
    }
#line 2900 "src/parser.c" /* yacc.c:1651  */
    break;

  case 142:
#line 351 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.var_decl_list) = new_var_decl_list((yyvsp[0].var_decl), NULL); }
#line 2906 "src/parser.c" /* yacc.c:1651  */
    break;

  case 143:
#line 352 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.var_decl_list) = new_var_decl_list((yyvsp[-2].var_decl), (yyvsp[0].var_decl_list)); }
#line 2912 "src/parser.c" /* yacc.c:1651  */
    break;

  case 144:
#line 356 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.var_decl) = new_var_decl((yyvsp[0].sym), NULL, get_pos(arg)); }
#line 2918 "src/parser.c" /* yacc.c:1651  */
    break;

  case 145:
#line 357 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.var_decl) = new_var_decl((yyvsp[-1].sym),   (yyvsp[0].array_sub), get_pos(arg)); }
#line 2924 "src/parser.c" /* yacc.c:1651  */
    break;

  case 146:
#line 358 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.var_decl) = new_var_decl((yyvsp[-1].sym),   (yyvsp[0].array_sub), get_pos(arg)); }
#line 2930 "src/parser.c" /* yacc.c:1651  */
    break;

  case 147:
#line 361 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_eq; }
#line 2936 "src/parser.c" /* yacc.c:1651  */
    break;

  case 148:
#line 361 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_ne; }
#line 2942 "src/parser.c" /* yacc.c:1651  */
    break;

  case 149:
#line 362 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_lt; }
#line 2948 "src/parser.c" /* yacc.c:1651  */
    break;

  case 150:
#line 362 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_gt; }
#line 2954 "src/parser.c" /* yacc.c:1651  */
    break;

  case 151:
#line 362 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_le; }
#line 2960 "src/parser.c" /* yacc.c:1651  */
    break;

  case 152:
#line 362 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_ge; }
#line 2966 "src/parser.c" /* yacc.c:1651  */
    break;

  case 153:
#line 363 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_shl; }
#line 2972 "src/parser.c" /* yacc.c:1651  */
    break;

  case 154:
#line 363 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_shr; }
#line 2978 "src/parser.c" /* yacc.c:1651  */
    break;

  case 155:
#line 364 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_add; }
#line 2984 "src/parser.c" /* yacc.c:1651  */
    break;

  case 156:
#line 364 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_sub; }
#line 2990 "src/parser.c" /* yacc.c:1651  */
    break;

  case 157:
#line 365 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_mul; }
#line 2996 "src/parser.c" /* yacc.c:1651  */
    break;

  case 158:
#line 365 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_div; }
#line 3002 "src/parser.c" /* yacc.c:1651  */
    break;

  case 159:
#line 365 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_mod; }
#line 3008 "src/parser.c" /* yacc.c:1651  */
    break;

  case 161:
#line 367 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_if((yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 3014 "src/parser.c" /* yacc.c:1651  */
    break;

  case 163:
#line 369 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), op_or, (yyvsp[0].exp)); }
#line 3020 "src/parser.c" /* yacc.c:1651  */
    break;

  case 165:
#line 370 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), op_and, (yyvsp[0].exp)); }
#line 3026 "src/parser.c" /* yacc.c:1651  */
    break;

  case 167:
#line 371 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), op_sor, (yyvsp[0].exp)); }
#line 3032 "src/parser.c" /* yacc.c:1651  */
    break;

  case 169:
#line 372 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), op_sxor, (yyvsp[0].exp)); }
#line 3038 "src/parser.c" /* yacc.c:1651  */
    break;

  case 171:
#line 373 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), op_sand, (yyvsp[0].exp)); }
#line 3044 "src/parser.c" /* yacc.c:1651  */
    break;

  case 173:
#line 374 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), (yyvsp[-1].ival), (yyvsp[0].exp)); }
#line 3050 "src/parser.c" /* yacc.c:1651  */
    break;

  case 175:
#line 375 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), (yyvsp[-1].ival), (yyvsp[0].exp)); }
#line 3056 "src/parser.c" /* yacc.c:1651  */
    break;

  case 177:
#line 376 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), (yyvsp[-1].ival), (yyvsp[0].exp)); }
#line 3062 "src/parser.c" /* yacc.c:1651  */
    break;

  case 179:
#line 377 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), (yyvsp[-1].ival), (yyvsp[0].exp)); }
#line 3068 "src/parser.c" /* yacc.c:1651  */
    break;

  case 181:
#line 378 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_binary((yyvsp[-2].exp), (yyvsp[-1].ival), (yyvsp[0].exp)); }
#line 3074 "src/parser.c" /* yacc.c:1651  */
    break;

  case 183:
#line 381 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_cast((yyvsp[0].type_decl), (yyvsp[-2].exp)); }
#line 3080 "src/parser.c" /* yacc.c:1651  */
    break;

  case 184:
#line 383 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_sub; }
#line 3086 "src/parser.c" /* yacc.c:1651  */
    break;

  case 185:
#line 383 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_mul; }
#line 3092 "src/parser.c" /* yacc.c:1651  */
    break;

  case 187:
#line 385 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_not; }
#line 3098 "src/parser.c" /* yacc.c:1651  */
    break;

  case 188:
#line 385 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_spork; }
#line 3104 "src/parser.c" /* yacc.c:1651  */
    break;

  case 189:
#line 385 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_cmp; }
#line 3110 "src/parser.c" /* yacc.c:1651  */
    break;

  case 191:
#line 389 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_unary((yyvsp[-1].ival), (yyvsp[0].exp)); }
#line 3116 "src/parser.c" /* yacc.c:1651  */
    break;

  case 192:
#line 391 "ly/gwion.y" /* yacc.c:1651  */
    {
      if((yyvsp[0].type_decl)->array && !(yyvsp[0].type_decl)->array->exp) {
        free_type_decl((yyvsp[0].type_decl));
        gwion_error(arg, "can't use empty '[]' in 'new' expression");
        YYERROR;
      }
      (yyval.exp) = new_exp_unary2(op_new, (yyvsp[0].type_decl));
    }
#line 3129 "src/parser.c" /* yacc.c:1651  */
    break;

  case 193:
#line 400 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_unary3(op_spork, (yyvsp[0].stmt)); }
#line 3135 "src/parser.c" /* yacc.c:1651  */
    break;

  case 195:
#line 404 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_dur((yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 3141 "src/parser.c" /* yacc.c:1651  */
    break;

  case 196:
#line 407 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_list) = new_type_list((yyvsp[0].type_decl), NULL); }
#line 3147 "src/parser.c" /* yacc.c:1651  */
    break;

  case 197:
#line 408 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.type_list) = new_type_list((yyvsp[-2].type_decl), (yyvsp[0].type_list)); }
#line 3153 "src/parser.c" /* yacc.c:1651  */
    break;

  case 198:
#line 411 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = (yyvsp[-1].exp); }
#line 3159 "src/parser.c" /* yacc.c:1651  */
    break;

  case 199:
#line 411 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = NULL; }
#line 3165 "src/parser.c" /* yacc.c:1651  */
    break;

  case 200:
#line 413 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_inc; }
#line 3171 "src/parser.c" /* yacc.c:1651  */
    break;

  case 201:
#line 413 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = op_dec; }
#line 3177 "src/parser.c" /* yacc.c:1651  */
    break;

  case 203:
#line 416 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_array((yyvsp[-1].exp), (yyvsp[0].array_sub)); }
#line 3183 "src/parser.c" /* yacc.c:1651  */
    break;

  case 204:
#line 418 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_call((yyvsp[-2].exp), (yyvsp[0].exp));
      if((yyvsp[-1].type_list))(yyval.exp)->d.exp_call.tmpl = new_tmpl_call((yyvsp[-1].type_list)); }
#line 3190 "src/parser.c" /* yacc.c:1651  */
    break;

  case 205:
#line 421 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_dot((yyvsp[-2].exp), (yyvsp[0].sym)); }
#line 3196 "src/parser.c" /* yacc.c:1651  */
    break;

  case 206:
#line 423 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_post((yyvsp[-1].exp), (yyvsp[0].ival)); }
#line 3202 "src/parser.c" /* yacc.c:1651  */
    break;

  case 207:
#line 426 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = ae_primary_complex; }
#line 3208 "src/parser.c" /* yacc.c:1651  */
    break;

  case 208:
#line 427 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = ae_primary_polar;   }
#line 3214 "src/parser.c" /* yacc.c:1651  */
    break;

  case 209:
#line 428 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.ival) = ae_primary_vec;     }
#line 3220 "src/parser.c" /* yacc.c:1651  */
    break;

  case 210:
#line 431 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_id(     (yyvsp[0].sym), get_pos(arg)); }
#line 3226 "src/parser.c" /* yacc.c:1651  */
    break;

  case 211:
#line 432 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_int(    (yyvsp[0].ival), get_pos(arg)); }
#line 3232 "src/parser.c" /* yacc.c:1651  */
    break;

  case 212:
#line 433 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_float(  (yyvsp[0].fval), get_pos(arg)); }
#line 3238 "src/parser.c" /* yacc.c:1651  */
    break;

  case 213:
#line 434 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_string( (yyvsp[0].sval), get_pos(arg)); }
#line 3244 "src/parser.c" /* yacc.c:1651  */
    break;

  case 214:
#line 435 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_char(   (yyvsp[0].sval), get_pos(arg)); }
#line 3250 "src/parser.c" /* yacc.c:1651  */
    break;

  case 215:
#line 436 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_array(  (yyvsp[0].array_sub), get_pos(arg)); }
#line 3256 "src/parser.c" /* yacc.c:1651  */
    break;

  case 216:
#line 437 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_array(  (yyvsp[0].array_sub), get_pos(arg)); }
#line 3262 "src/parser.c" /* yacc.c:1651  */
    break;

  case 217:
#line 438 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_vec((yyvsp[-2].ival), (yyvsp[-1].exp)); }
#line 3268 "src/parser.c" /* yacc.c:1651  */
    break;

  case 218:
#line 439 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_hack(   (yyvsp[-1].exp)); }
#line 3274 "src/parser.c" /* yacc.c:1651  */
    break;

  case 219:
#line 440 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) =                      (yyvsp[-1].exp);                }
#line 3280 "src/parser.c" /* yacc.c:1651  */
    break;

  case 220:
#line 441 "ly/gwion.y" /* yacc.c:1651  */
    { (yyval.exp) = new_exp_prim_nil(        get_pos(arg)); }
#line 3286 "src/parser.c" /* yacc.c:1651  */
    break;


#line 3290 "src/parser.c" /* yacc.c:1651  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (arg, YY_("syntax error"));
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
        yyerror (arg, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval, arg);
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, arg);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (arg, YY_("memory exhausted"));
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
                  yytoken, &yylval, arg);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, arg);
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
  return yyresult;
}
#line 443 "ly/gwion.y" /* yacc.c:1910  */

