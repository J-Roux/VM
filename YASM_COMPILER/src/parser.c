/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "YASM_COMPILER/src/parcer.y" /* yacc.c:339  */

#define PRINT_AST 0
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "node.h"
#include <stdlib.h>

#include "../../YASM_VM/src/command.h"


extern int yylex();
extern int yyparse();
extern FILE* yyin;



void yyerror(const char *str) {
  fprintf(stderr, "error: %s\n", str);
  exit(1);
}


int main(int argc, char** argv) {
  FILE * f;
  if(argc < 2) {
    printf("No input file!\n");
    return 1;
  }
  yyin = fopen(argv[1], "r");
  yyparse();
  push_byte(END);
  printf("program size = %i\n", pointer);
  f = fopen("result.elf","wb");
  fwrite(data, 1, pointer, f);
  fclose(f);
  return 0;
}


#line 108 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:339  */

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
#ifndef YY_YY_HOME_PAVEL_WORKSPACE_YASM_YASM_COMPILER_SRC_PARSER_H_INCLUDED
# define YY_YY_HOME_PAVEL_WORKSPACE_YASM_YASM_COMPILER_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _ADD_BYTE = 258,
    _ADD_SHORT = 259,
    _ADD_INT = 260,
    _ADD_LONG = 261,
    _SUB_BYTE = 262,
    _SUB_SHORT = 263,
    _SUB_INT = 264,
    _SUB_LONG = 265,
    _MUL_BYTE = 266,
    _MUL_SHORT = 267,
    _MUL_INT = 268,
    _MUL_LONG = 269,
    _DIV_BYTE = 270,
    _DIV_SHORT = 271,
    _DIV_INT = 272,
    _DIV_LONG = 273,
    _DIV_SBYTE = 274,
    _DIV_SSHORT = 275,
    _DIV_SINT = 276,
    _DIV_SLONG = 277,
    _AND_BYTE = 278,
    _AND_SHORT = 279,
    _AND_INT = 280,
    _AND_LONG = 281,
    _OR_BYTE = 282,
    _OR_SHORT = 283,
    _OR_INT = 284,
    _OR_LONG = 285,
    _SHR_BYTE = 286,
    _SHR_SHORT = 287,
    _SHR_INT = 288,
    _SHR_LONG = 289,
    _SHL_BYTE = 290,
    _SHL_SHORT = 291,
    _SHL_INT = 292,
    _SHL_LONG = 293,
    _EQ_BYTE = 294,
    _EQ_SHORT = 295,
    _EQ_INT = 296,
    _EQ_LONG = 297,
    _EQ_SBYTE = 298,
    _EQ_SSHORT = 299,
    _EQ_SINT = 300,
    _EQ_SLONG = 301,
    _NEQ_BYTE = 302,
    _NEQ_SHORT = 303,
    _NEQ_INT = 304,
    _NEQ_LONG = 305,
    _NEQ_SBYTE = 306,
    _NEQ_SSHORT = 307,
    _NEQ_SINT = 308,
    _NEQ_SLONG = 309,
    _LT_BYTE = 310,
    _LT_SHORT = 311,
    _LT_INT = 312,
    _LT_LONG = 313,
    _LT_SBYTE = 314,
    _LT_SSHORT = 315,
    _LT_SINT = 316,
    _LT_SLONG = 317,
    _LEQ_BYTE = 318,
    _LEQ_SHORT = 319,
    _LEQ_INT = 320,
    _LEQ_LONG = 321,
    _LEQ_SBYTE = 322,
    _LEQ_SSHORT = 323,
    _LEQ_SINT = 324,
    _LEQ_SLONG = 325,
    _GT_BYTE = 326,
    _GT_SHORT = 327,
    _GT_INT = 328,
    _GT_LONG = 329,
    _GT_SBYTE = 330,
    _GT_SSHORT = 331,
    _GT_SINT = 332,
    _GT_SLONG = 333,
    _GEQ_BYTE = 334,
    _GEQ_SHORT = 335,
    _GEQ_INT = 336,
    _GEQ_LONG = 337,
    _GEQ_SBYTE = 338,
    _GEQ_SSHORT = 339,
    _GEQ_SINT = 340,
    _GEQ_SLONG = 341,
    _INC_BYTE = 342,
    _INC_SHORT = 343,
    _INC_INT = 344,
    _INC_LONG = 345,
    _DEC_BYTE = 346,
    _DEC_SHORT = 347,
    _DEC_INT = 348,
    _DEC_LONG = 349,
    _NEG_SBYTE = 350,
    _NEG_SSHORT = 351,
    _NEG_SINT = 352,
    _NEG_SLONG = 353,
    _LNOT_BYTE = 354,
    _LNOT_SHORT = 355,
    _LNOT_INT = 356,
    _LNOT_LONG = 357,
    _NOT_BYTE = 358,
    _NOT_SHORT = 359,
    _NOT_INT = 360,
    _NOT_LONG = 361,
    _DUB_OP = 362,
    _JMP = 363,
    _JT = 364,
    _JF = 365,
    _LABEL = 366,
    _CALL_OP = 367,
    _PUSH = 368,
    _POP = 369,
    _ERASE = 370,
    _PUSH_BYTE = 371,
    _PUSH_SHORT = 372,
    _PUSH_INT = 373,
    _PUSH_LONG = 374,
    _POP_BYTE = 375,
    _POP_SHORT = 376,
    _POP_INT = 377,
    _POP_LONG = 378,
    _ID = 379,
    _NUMERIC = 380,
    _INDENT = 381,
    _OUTDENT = 382,
    _NEW_LINE = 383,
    _PLUS_OP = 384,
    _MINUS_OP = 385,
    _MUL_OP = 386,
    _DIV_OP = 387,
    _AND_OP = 388,
    _OR_OP = 389,
    _EQUALS_OP = 390,
    _NOT_OP = 391
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 47 "YASM_COMPILER/src/parcer.y" /* yacc.c:355  */

  int64_t numeric;
  char* string;
  struct Node* node;
  struct Value* value;

#line 292 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_PAVEL_WORKSPACE_YASM_YASM_COMPILER_SRC_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 309 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:358  */

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
# elif ! defined YYSIZE_T
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

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  116
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   391

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    94,    94,    95,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   110,   112,   113,   114,   115,   117,
     120,   122,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   216,   217,   218,   219,   220,   221,   222,   223,
     224
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ADD_BYTE", "_ADD_SHORT", "_ADD_INT",
  "_ADD_LONG", "_SUB_BYTE", "_SUB_SHORT", "_SUB_INT", "_SUB_LONG",
  "_MUL_BYTE", "_MUL_SHORT", "_MUL_INT", "_MUL_LONG", "_DIV_BYTE",
  "_DIV_SHORT", "_DIV_INT", "_DIV_LONG", "_DIV_SBYTE", "_DIV_SSHORT",
  "_DIV_SINT", "_DIV_SLONG", "_AND_BYTE", "_AND_SHORT", "_AND_INT",
  "_AND_LONG", "_OR_BYTE", "_OR_SHORT", "_OR_INT", "_OR_LONG", "_SHR_BYTE",
  "_SHR_SHORT", "_SHR_INT", "_SHR_LONG", "_SHL_BYTE", "_SHL_SHORT",
  "_SHL_INT", "_SHL_LONG", "_EQ_BYTE", "_EQ_SHORT", "_EQ_INT", "_EQ_LONG",
  "_EQ_SBYTE", "_EQ_SSHORT", "_EQ_SINT", "_EQ_SLONG", "_NEQ_BYTE",
  "_NEQ_SHORT", "_NEQ_INT", "_NEQ_LONG", "_NEQ_SBYTE", "_NEQ_SSHORT",
  "_NEQ_SINT", "_NEQ_SLONG", "_LT_BYTE", "_LT_SHORT", "_LT_INT",
  "_LT_LONG", "_LT_SBYTE", "_LT_SSHORT", "_LT_SINT", "_LT_SLONG",
  "_LEQ_BYTE", "_LEQ_SHORT", "_LEQ_INT", "_LEQ_LONG", "_LEQ_SBYTE",
  "_LEQ_SSHORT", "_LEQ_SINT", "_LEQ_SLONG", "_GT_BYTE", "_GT_SHORT",
  "_GT_INT", "_GT_LONG", "_GT_SBYTE", "_GT_SSHORT", "_GT_SINT",
  "_GT_SLONG", "_GEQ_BYTE", "_GEQ_SHORT", "_GEQ_INT", "_GEQ_LONG",
  "_GEQ_SBYTE", "_GEQ_SSHORT", "_GEQ_SINT", "_GEQ_SLONG", "_INC_BYTE",
  "_INC_SHORT", "_INC_INT", "_INC_LONG", "_DEC_BYTE", "_DEC_SHORT",
  "_DEC_INT", "_DEC_LONG", "_NEG_SBYTE", "_NEG_SSHORT", "_NEG_SINT",
  "_NEG_SLONG", "_LNOT_BYTE", "_LNOT_SHORT", "_LNOT_INT", "_LNOT_LONG",
  "_NOT_BYTE", "_NOT_SHORT", "_NOT_INT", "_NOT_LONG", "_DUB_OP", "_JMP",
  "_JT", "_JF", "_LABEL", "_CALL_OP", "_PUSH", "_POP", "_ERASE",
  "_PUSH_BYTE", "_PUSH_SHORT", "_PUSH_INT", "_PUSH_LONG", "_POP_BYTE",
  "_POP_SHORT", "_POP_INT", "_POP_LONG", "_ID", "_NUMERIC", "_INDENT",
  "_OUTDENT", "_NEW_LINE", "_PLUS_OP", "_MINUS_OP", "_MUL_OP", "_DIV_OP",
  "_AND_OP", "_OR_OP", "_EQUALS_OP", "_NOT_OP", "$accept", "axiom",
  "statement_list", "statement", "dub_statement", "jmp_statement",
  "call_statement", "label", "id", "command", "mem_statement", "expr", YY_NULLPTR
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
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -7

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
     -41,  -107,  -107,  -107,   -41,   -41,   -41,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,    94,    -3,   -30,
    -124,  -124,  -124,  -124,    -9,  -124,  -124,  -124,   -41,   -44,
    -124,  -124,  -124,   -44,   -44,   -44,  -124,   -25,  -124,  -124,
    -124,   -41,   -41,   -41,   -41,   -41,   -41,  -124,  -123,  -123,
     -37,   -37,  -124,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     112,     0,     0,     0,   112,   112,   112,   102,   103,   104,
     105,   106,   108,   107,   109,    21,    10,     0,     3,     0,
      13,    12,    11,     9,     0,     7,     8,   120,   112,    14,
      16,    18,    17,    19,   111,   110,     1,     0,     4,    20,
     119,   112,   112,   112,   112,   112,   112,     5,   115,   116,
     113,   114,   117,   118
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -124,  -124,  -124,    14,  -124,  -124,  -124,  -124,    10,  -124,
    -124,    15
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       1,     2,     3,     4,     5,     6,     7,     8,   123,   124,
     125,   126,     9,    10,    11,    12,    13,    95,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,   107,   121,   122,   123,   124,   125,
     126,   110,   111,   112,   116,   108,   125,   126,   118,   113,
     114,   115,   119,   127,    80,    81,    82,    83,     0,    84,
      85,    86,   117,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   120,     0,    -6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   129,   130,   131,
     132,   133
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    10,   131,   132,
     133,   134,    15,    16,    17,    18,    19,   124,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,   125,   129,   130,   131,   132,   133,
     134,    81,    82,    83,     0,   136,   133,   134,   128,    84,
      85,    86,   111,   128,   107,   108,   109,   110,    -1,   112,
     113,   114,    98,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   108,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,   124,
     125,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    15,
      16,    17,    18,    19,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
     107,   108,   109,   110,   112,   113,   114,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   125,   136,   148,
     145,   145,   145,   148,   148,   148,     0,   140,   128,   111,
     148,   129,   130,   131,   132,   133,   134,   128,   148,   148,
     148,   148,   148,   148
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   137,   138,   138,   139,   139,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   142,   142,   142,   142,   143,
     144,   145,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   148,   148,   148,   148,   148,   148,   148,   148,
     148
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     2,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     3,     3,     3,     3,     3,     3,     2,
       1
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
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
        case 10:
#line 104 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_value((yyvsp[0].numeric)); }
#line 1532 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 110 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DUB); push_short(get_id_value((yyvsp[0].numeric)));}
#line 1538 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 113 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(JMP); push_short(get_id_value((yyvsp[0].string))); }
#line 1544 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 114 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(JF); push_short(get_id_value((yyvsp[0].string))); }
#line 1550 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 115 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(JT); push_short(get_id_value((yyvsp[0].string))); }
#line 1556 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 117 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(CALL); push_value((yyvsp[0].numeric));}
#line 1562 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 120 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { add_to_map((yyvsp[-1].string), pointer); }
#line 1568 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 124 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(ADD_BYTE); }
#line 1574 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 125 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(ADD_SHORT); }
#line 1580 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 126 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(ADD_INT); }
#line 1586 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 127 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(ADD_LONG); }
#line 1592 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 128 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SUB_BYTE); }
#line 1598 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 129 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SUB_SHORT); }
#line 1604 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 130 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SUB_INT); }
#line 1610 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 131 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SUB_LONG); }
#line 1616 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 132 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_BYTE); }
#line 1622 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 133 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_SHORT); }
#line 1628 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 134 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_INT); }
#line 1634 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 135 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_LONG); }
#line 1640 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 136 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_SBYTE); }
#line 1646 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 137 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_SSHORT); }
#line 1652 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 138 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_SINT); }
#line 1658 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 139 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(DIV_SLONG); }
#line 1664 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 140 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(AND_BYTE);}
#line 1670 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 141 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(AND_SHORT);}
#line 1676 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 142 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(AND_INT);}
#line 1682 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 143 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(AND_LONG);}
#line 1688 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 144 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(OR_BYTE); }
#line 1694 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 145 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(OR_SHORT); }
#line 1700 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 146 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(OR_INT); }
#line 1706 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 147 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(OR_LONG); }
#line 1712 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 148 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHR_BYTE); }
#line 1718 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 149 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHR_SHORT); }
#line 1724 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 150 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHR_INT); }
#line 1730 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 151 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHR_LONG); }
#line 1736 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 152 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHL_BYTE); }
#line 1742 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 153 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHL_SHORT); }
#line 1748 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 154 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHL_INT); }
#line 1754 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 155 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(SHL_LONG); }
#line 1760 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 156 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_BYTE); }
#line 1766 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 157 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_SHORT); }
#line 1772 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 158 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_INT); }
#line 1778 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 159 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_LONG); }
#line 1784 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 160 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_SBYTE); }
#line 1790 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 161 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_SSHORT); }
#line 1796 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 162 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_SINT); }
#line 1802 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 163 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(EQ_SLONG); }
#line 1808 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 164 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_BYTE); }
#line 1814 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 165 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_SHORT); }
#line 1820 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 166 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_INT); }
#line 1826 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 167 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_LONG); }
#line 1832 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 168 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_SBYTE); }
#line 1838 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 169 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_SSHORT); }
#line 1844 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 170 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_SINT); }
#line 1850 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 171 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(NEQ_SLONG); }
#line 1856 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 172 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_BYTE); }
#line 1862 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 173 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_SHORT); }
#line 1868 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 174 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_INT); }
#line 1874 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 175 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_LONG); }
#line 1880 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 176 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_SBYTE); }
#line 1886 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 177 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_SSHORT); }
#line 1892 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 178 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_SINT); }
#line 1898 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 179 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LT_SLONG); }
#line 1904 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 180 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_BYTE); }
#line 1910 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 181 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_SHORT); }
#line 1916 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 182 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_INT); }
#line 1922 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 183 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_LONG); }
#line 1928 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 184 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_SBYTE); }
#line 1934 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 185 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_SSHORT); }
#line 1940 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 186 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_SINT); }
#line 1946 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 187 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(LEQ_SLONG); }
#line 1952 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 188 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_BYTE); }
#line 1958 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 189 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_SHORT); }
#line 1964 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 190 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_INT); }
#line 1970 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 191 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_LONG); }
#line 1976 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 192 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_SBYTE); }
#line 1982 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 193 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_SSHORT); }
#line 1988 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 194 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_SINT); }
#line 1994 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 195 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GT_SLONG); }
#line 2000 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 196 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_BYTE); }
#line 2006 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 197 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_SHORT); }
#line 2012 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 198 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_INT); }
#line 2018 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 199 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_LONG); }
#line 2024 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 200 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_SBYTE); }
#line 2030 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 201 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_SSHORT); }
#line 2036 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 202 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_SINT); }
#line 2042 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 203 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { push_byte(GEQ_SLONG); }
#line 2048 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 205 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(PUSH_BYTE);}
#line 2054 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 206 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(PUSH_SHORT);}
#line 2060 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 207 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(PUSH_INT);}
#line 2066 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 208 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(PUSH_LONG);}
#line 2072 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 209 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(POP_BYTE);}
#line 2078 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 210 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(POP_INT);}
#line 2084 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 211 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(POP_SHORT);}
#line 2090 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 212 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(POP_LONG);}
#line 2096 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 213 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(POP); push_value((yyvsp[0].numeric));}
#line 2102 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 214 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    {push_byte(PUSH); push_value((yyvsp[0].numeric));}
#line 2108 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 217 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = (yyvsp[-2].numeric) * (yyvsp[0].numeric); }
#line 2114 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 218 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = (yyvsp[-2].numeric) / (yyvsp[0].numeric); }
#line 2120 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 219 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = (yyvsp[-2].numeric) + (yyvsp[0].numeric); }
#line 2126 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 220 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = (yyvsp[-2].numeric) - (yyvsp[0].numeric); }
#line 2132 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 221 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = (yyvsp[-2].numeric) & (yyvsp[0].numeric); }
#line 2138 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 222 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = (yyvsp[-2].numeric) | (yyvsp[0].numeric); }
#line 2144 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 223 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = ~(yyvsp[0].numeric); }
#line 2150 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 224 "YASM_COMPILER/src/parcer.y" /* yacc.c:1646  */
    { (yyval.numeric) = (yyvsp[0].numeric); }
#line 2156 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
    break;


#line 2160 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 225 "YASM_COMPILER/src/parcer.y" /* yacc.c:1906  */

