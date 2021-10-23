/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "asgn5_19CS10064_19CS30008.y"

    #include <iostream>
    #include <sstream>
    #include "asgn5_19CS10064_19CS30008_translator.h"
    using namespace std;

    extern int yylex();
    void yyerror(string s);
    extern char* yytext;
    extern int yylineno;
    extern string varType;

#line 83 "asgn5_19CS10064_19CS30008.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ASGN5_19CS10064_19CS30008_TAB_H_INCLUDED
# define YY_YY_ASGN5_19CS10064_19CS30008_TAB_H_INCLUDED
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
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO = 272,
    IF = 273,
    INLINE = 274,
    INT = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID = 289,
    VOLATILE = 290,
    WHILE = 291,
    BOOL = 292,
    COMPLEX = 293,
    IMAGINARY = 294,
    SQUARE_BRACE_OPEN = 295,
    SQUARE_BRACE_CLOSE = 296,
    PARENTHESIS_OPEN = 297,
    PARENTHESIS_CLOSE = 298,
    CURLY_BRACE_OPEN = 299,
    CURLY_BRACE_CLOSE = 300,
    DOT = 301,
    ARROW = 302,
    INCREMENT = 303,
    DECREMENT = 304,
    BITWISE_AND = 305,
    MULTIPLY = 306,
    ADD = 307,
    SUBTRACT = 308,
    BITWISE_NOR = 309,
    NOT = 310,
    DIVIDE = 311,
    MODULO = 312,
    LSHIFT = 313,
    RSHIFT = 314,
    LESS_THAN = 315,
    GREATER_THAN = 316,
    LESS_THAN_EQUAL = 317,
    GREATER_THAN_EQUAL = 318,
    EQUAL = 319,
    NOT_EQUAL = 320,
    BITWISE_XOR = 321,
    BITWISE_OR = 322,
    LOGICAL_AND = 323,
    LOGICAL_OR = 324,
    QUESTION_MARK = 325,
    COLON = 326,
    SEMICOLON = 327,
    ELLIPSIS = 328,
    ASSIGN = 329,
    MULTIPLY_ASSIGN = 330,
    DIVIDE_ASSIGN = 331,
    MODULO_ASSIGN = 332,
    ADD_ASSIGN = 333,
    SUBTRACT_ASSIGN = 334,
    LSHIFT_ASSIGN = 335,
    RSHIFT_ASSIGN = 336,
    AND_ASSIGN = 337,
    XOR_ASSIGN = 338,
    OR_ASSIGN = 339,
    COMMA = 340,
    HASH = 341,
    IDENTIFIER = 342,
    INTEGER_CONSTANT = 343,
    FLOATING_CONSTANT = 344,
    CHAR_CONSTANT = 345,
    STRING_LITERAL = 346,
    THEN = 347
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "asgn5_19CS10064_19CS30008.y"

    int intval;
    char* charval;
    int instr;
    char unaryOp;
    int numParams;
    expression* expr;
    statement* stmt;
    symbol* symp;
    symbolType* symType;
    Array* arr;

#line 241 "asgn5_19CS10064_19CS30008.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASGN5_19CS10064_19CS30008_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
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
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

#define YYUNDEFTOK  2
#define YYMAXUTOK   347


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      85,    86,    87,    88,    89,    90,    91,    92
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    97,   105,   117,   123,   129,   135,   148,
     154,   159,   165,   172,   177,   182,   190,   197,   216,   222,
     224,   226,   233,   240,   242,   247,   251,   258,   263,   271,
     275,   280,   285,   317,   319,   324,   328,   332,   336,   340,
     344,   351,   355,   363,   377,   388,   399,   413,   417,   428,
     442,   446,   457,   471,   475,   489,   503,   517,   534,   538,
     554,   573,   577,   594,   598,   615,   619,   636,   640,   653,
     657,   670,   674,   695,   699,   717,   719,   721,   723,   725,
     727,   729,   731,   733,   735,   737,   742,   746,   751,   756,
     761,   763,   768,   770,   772,   774,   779,   781,   786,   788,
     793,   797,   807,   809,   811,   813,   818,   822,   826,   828,
     832,   834,   838,   840,   842,   844,   846,   848,   850,   855,
     857,   862,   864,   869,   871,   873,   878,   880,   885,   887,
     892,   894,   899,   901,   903,   908,   913,   922,   927,   932,
     936,   938,   940,   959,   976,   978,   980,   982,   984,   986,
     998,  1000,  1015,  1017,  1022,  1026,  1033,  1035,  1040,  1042,
    1047,  1049,  1054,  1056,  1061,  1063,  1068,  1073,  1077,  1079,
    1084,  1086,  1091,  1093,  1098,  1103,  1105,  1110,  1112,  1117,
    1119,  1123,  1128,  1132,  1136,  1143,  1145,  1150,  1154,  1158,
    1165,  1167,  1169,  1174,  1182,  1186,  1193,  1197,  1205,  1209,
    1216,  1220,  1227,  1236,  1246,  1251,  1262,  1273,  1282,  1291,
    1303,  1315,  1327,  1342,  1344,  1348,  1352,  1357,  1365,  1367,
    1372,  1374,  1379,  1388,  1390,  1395,  1397
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "BOOL",
  "COMPLEX", "IMAGINARY", "SQUARE_BRACE_OPEN", "SQUARE_BRACE_CLOSE",
  "PARENTHESIS_OPEN", "PARENTHESIS_CLOSE", "CURLY_BRACE_OPEN",
  "CURLY_BRACE_CLOSE", "DOT", "ARROW", "INCREMENT", "DECREMENT",
  "BITWISE_AND", "MULTIPLY", "ADD", "SUBTRACT", "BITWISE_NOR", "NOT",
  "DIVIDE", "MODULO", "LSHIFT", "RSHIFT", "LESS_THAN", "GREATER_THAN",
  "LESS_THAN_EQUAL", "GREATER_THAN_EQUAL", "EQUAL", "NOT_EQUAL",
  "BITWISE_XOR", "BITWISE_OR", "LOGICAL_AND", "LOGICAL_OR",
  "QUESTION_MARK", "COLON", "SEMICOLON", "ELLIPSIS", "ASSIGN",
  "MULTIPLY_ASSIGN", "DIVIDE_ASSIGN", "MODULO_ASSIGN", "ADD_ASSIGN",
  "SUBTRACT_ASSIGN", "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "COMMA", "HASH", "IDENTIFIER",
  "INTEGER_CONSTANT", "FLOATING_CONSTANT", "CHAR_CONSTANT",
  "STRING_LITERAL", "THEN", "$accept", "M", "N", "X", "F", "W", "D",
  "change_table", "primary_expression", "constant", "postfix_expression",
  "argument_expression_list_opt", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "enum_specifier", "identifier_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "type_qualifier_list_opt", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name", "initializer",
  "initializer_list", "designation_opt", "designation", "designator_list",
  "designator", "statement", "loop_statement", "labeled_statement",
  "compound_statement", "block_item_list_opt", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list_opt",
  "declaration_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
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
     345,   346,   347
};
# endif

#define YYPACT_NINF (-352)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-225)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1325,  -352,  -352,  -352,  -352,   -33,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,    64,  1325,  1325,  -352,  1325,  1325,  1288,
    -352,  -352,    -7,    43,    64,    18,  -352,    41,    69,  -352,
     968,   128,   -32,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
      72,   120,  -352,   126,    18,  -352,    64,  1012,  -352,    64,
    -352,  1325,   203,    94,   128,   109,    -3,  -352,  -352,  -352,
    -352,  -352,   119,  1128,   778,   121,  1142,  1142,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,   315,   185,  1158,  -352,   133,   127,   169,   172,   178,
     136,   132,   140,   161,   201,  -352,  -352,  -352,   195,  -352,
     879,  -352,   209,   233,   829,  -352,  1247,   -29,  1158,  -352,
     -30,   778,  -352,  -352,    -9,  1359,  -352,  1359,   236,  1158,
     196,    29,  1012,  -352,   -23,  -352,   778,  -352,  -352,  1158,
    1158,   198,   208,  -352,  -352,  -352,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,  -352,  -352,  -352,  1158,  -352,  -352,  1158,
    1158,  1158,  1158,  1158,  1158,  1158,  1158,  1158,  1158,  1158,
    1158,  1158,  1158,  1158,  1158,  -352,  -352,   226,   299,   256,
     879,  -352,  -352,  1158,  -352,   258,   270,  -352,    64,   285,
     245,  -352,  -352,   244,  -352,  -352,  -352,  -352,   296,  -352,
    1158,  -352,  -352,  -352,  1026,   301,  -352,  -352,   163,  -352,
    -352,  -352,   297,   -25,   302,   259,  -352,  -352,  -352,  -352,
    -352,  -352,  -352,   133,   133,   127,   127,   169,   169,   169,
     169,   172,   172,   178,   136,   132,  1158,  1158,  -352,   284,
    1158,   286,   288,  -352,  -352,   273,   323,  1070,   324,  -352,
    -352,  -352,   298,   -36,  -352,  -352,  -352,  -352,   322,   325,
    -352,  -352,  -352,  -352,  -352,  -352,   327,   331,  -352,  -352,
    -352,  -352,  1010,  -352,   329,  -352,   121,  -352,  -352,  -352,
    1012,   329,  -352,  -352,  1158,   140,   161,  1158,  -352,   303,
    -352,   464,   332,   333,   305,  1158,  -352,    67,  1158,   336,
    -352,   464,  -352,  -352,   299,  -352,  -352,  -352,  -352,    90,
    -352,  -352,   294,   464,  -352,  -352,   692,  -352,  -352,   294,
    -352,    -4,  -352,   299,  -352,  -352,  -352,   171,   309,  -352,
     299,  -352,  -352,  -352,  -352,  -352,  -352,  -352,   338,   464,
    -352,   337,  -352,  -352,   339,   347,   388,  -352,  -352,  -352,
    -352,  1158,  -352,   343,  -352,  -352,   464,  1158,  -352,   356,
    1158,  1084,  1084,  -352,    26,   351,    65,  -352,  -352,   384,
     353,  1158,   326,  1158,  1158,  -352,  -352,   692,    79,  -352,
     294,   294,   464,   299,  -352,   328,   361,   362,  -352,   367,
    -352,  -352,  -352,  -352,   540,   616,   299,  -352,   299,  -352,
     372,   373,  -352,  -352
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   104,   107,   132,   112,   127,   102,   111,   135,   109,
     110,   105,   133,   108,   113,   103,   114,   106,   134,   115,
     116,   117,   221,    91,    97,    97,   118,    97,    97,     0,
     218,   220,   125,     0,     0,   153,   138,     0,    90,    98,
     100,   137,     0,    96,    92,    93,    94,    95,     1,   219,
       0,     0,   156,   154,   152,    89,     0,     0,   225,    91,
       8,   223,     0,     8,   136,   130,     0,   128,   139,   155,
     157,    99,   100,     0,     0,   173,     0,     0,    35,    36,
      37,    38,    39,    40,     9,    13,    14,    15,    11,    16,
      10,    29,    41,     0,    43,    47,    50,    53,    58,    61,
      63,    65,    67,    69,    71,    73,   167,   101,     0,   226,
       0,   143,    36,     0,     0,   164,     0,     0,     0,   123,
       0,     0,    33,    86,     0,   122,   166,   122,     0,     0,
       0,     0,     0,   172,     0,   175,     0,    30,    31,     0,
      26,     0,     0,    21,    22,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,     0,    41,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     2,     2,     0,   195,     0,
       0,   148,   142,     0,   141,    36,     0,   151,   163,     0,
     158,   160,   150,     0,    88,   131,   124,   129,     0,    12,
       0,   121,   119,   120,     0,     0,   178,   168,   173,   170,
     174,   176,     0,     0,     0,    25,    27,    19,    20,    74,
      44,    45,    46,    48,    49,    51,    52,    54,    55,    56,
      57,    59,    60,    62,    64,    66,     0,     0,     2,     0,
       0,     0,     0,     7,     5,     0,     0,     0,     0,     6,
       4,   201,     9,     0,   198,   199,   179,   180,     0,     2,
     196,   181,   182,   183,   184,   145,     0,     0,   147,   140,
     162,   149,     0,   165,    34,    87,   173,    42,   177,   169,
       0,     0,    17,    18,     0,    68,    70,     0,   215,     0,
     214,     0,     2,     0,     0,     0,   217,     0,     0,     0,
       8,     0,   200,   222,     0,   144,   146,   159,   161,     0,
     171,    28,     3,     0,   192,     2,     0,     4,   213,     3,
     216,     0,     4,   195,   190,   197,    23,   173,     0,   191,
     195,     2,   185,   186,   187,   188,   189,     8,     0,     0,
       8,     0,    24,     2,     0,     0,     0,     2,   204,     2,
     193,     0,     2,     0,     2,     2,     0,     0,    72,     0,
       0,     0,     0,     3,     0,     0,     0,     2,     2,   202,
       2,     0,     0,     0,     0,     2,     2,     0,     0,   207,
       3,     3,     0,   195,   205,     0,     0,     0,   203,     0,
     208,     2,     2,   206,     0,     0,   195,   209,   195,   210,
       0,     0,   211,   212
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -352,  -155,  -157,  -284,  -352,  -352,  -352,   -59,  -352,  -352,
    -352,  -352,  -352,   -71,  -352,   -81,   110,   112,    80,   118,
     234,   246,   250,   184,   191,  -352,  -111,     2,  -352,   -73,
    -116,     0,  -352,     3,   116,  -352,   375,  -352,   -50,   -18,
     306,  -352,  -352,  -352,   312,    11,  -352,   -15,   387,  -352,
     381,   -42,  -352,  -352,   173,  -352,   -86,  -123,   159,  -197,
    -352,  -352,   310,  -229,  -351,  -249,  -352,  -278,  -352,   142,
    -190,  -246,  -199,  -176,  -352,   418,  -352,  -352,  -352
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   236,   177,   300,   293,   299,   292,   108,    89,    90,
      91,   214,   215,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   123,   156,   253,
     195,   254,    37,    59,    44,    38,    39,    24,    25,   126,
     202,    26,    33,    66,    67,    27,    28,    72,    41,    53,
      42,    54,   189,   190,   191,   117,   128,   107,   131,   132,
     133,   134,   135,   255,   331,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    29,    30,    31,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,   124,   122,    23,   116,   137,   138,   194,    40,   209,
      34,   280,   158,   205,   192,   196,   282,   129,   194,    51,
     114,   237,   157,   130,   125,     3,   384,    43,    43,    22,
      43,    43,    23,   337,   199,   198,   302,  -126,   340,   339,
      58,    12,   119,   397,   399,   341,    52,   157,   124,   200,
     212,   210,   344,    18,    32,    36,   193,    65,   157,   106,
     200,   109,   314,   124,   113,    70,   213,   332,   180,   370,
     334,   125,   324,    52,   207,   125,   200,   125,   220,   221,
     222,   200,   120,   287,   329,   127,   125,    50,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   304,   389,    34,   201,   372,   201,
     348,   200,   179,    55,   208,    35,   186,   335,   400,   188,
     401,    52,   385,   277,   289,    70,   333,   363,   332,   194,
     280,   334,   127,   157,   106,   326,   127,   316,   127,   320,
     336,    45,   216,    46,    47,   332,   332,   127,   334,   334,
     200,    36,   200,   388,    56,   328,   355,   310,   219,    65,
     330,   129,   338,    68,   200,   157,   157,   130,    62,   157,
      63,   367,   368,   270,   297,   327,   345,    35,   335,   162,
     163,   115,   266,   118,   159,   267,   172,   333,   351,   160,
     161,    70,   356,    57,   357,   335,   335,   359,   173,   361,
     362,   336,   275,   129,   333,   333,   369,   174,   279,   130,
       3,   129,   373,   374,   312,   377,   342,   130,   336,   336,
     382,   383,   319,   386,   387,   321,    12,   164,   165,   175,
      73,   110,   166,   167,   168,   169,   394,   395,    18,   178,
     358,   323,   170,   171,   111,    74,   227,   228,   229,   230,
     181,    76,    77,    78,   112,    80,    81,    82,    83,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     176,    -3,   223,   224,   182,   188,   225,   226,   346,   204,
     157,   349,   106,   206,   364,   217,   311,   366,   231,   232,
      84,    85,    86,    87,    88,   218,   238,   265,   378,   268,
     380,   381,     1,   239,   240,     2,     3,   241,   242,   243,
       4,   269,     5,     6,     7,   244,   245,   246,     8,     9,
      10,    11,    12,   247,    13,    14,    73,    15,   271,   248,
     272,   273,    16,    17,    18,   249,    19,    20,    21,   274,
     281,    74,   278,   250,   284,   283,   354,    76,    77,    78,
      79,    80,    81,    82,    83,   139,   288,   140,   290,   291,
     294,   141,   142,   143,   144,   295,   298,   303,   305,   301,
    -194,   251,   306,   276,   313,   317,   315,   318,   322,   200,
     343,   347,   350,   353,   352,   360,   252,    85,    86,    87,
      88,     1,   365,   371,     2,     3,   375,   376,   379,     4,
     390,     5,     6,     7,   391,   392,   233,     8,     9,    10,
      11,    12,   393,    13,    14,    73,    15,   402,   403,   234,
     285,    16,    17,    18,   235,    19,    20,    21,   286,    64,
      74,    71,   197,   203,    69,   309,    76,    77,    78,    79,
      80,    81,    82,    83,   211,   308,   325,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     251,     0,     0,     0,     0,     0,     0,     0,   239,   240,
       0,     0,   241,   242,   243,    84,    85,    86,    87,    88,
     244,   245,   246,     0,     0,     0,     0,     0,   247,     0,
       0,    73,     0,     0,   248,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,    74,     0,   250,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   251,     0,     0,     0,
       0,     0,     0,     0,   239,   240,     0,     0,   241,   242,
     243,   252,    85,    86,    87,    88,   244,   245,   246,     0,
       0,     0,     0,     0,   247,     0,     0,    73,     0,     0,
     248,     0,     0,     0,     0,     0,   249,     0,     0,     0,
       0,     0,    74,     0,   396,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   251,     0,     0,     0,     0,     0,     0,     0,
     239,   240,     0,     0,   241,   242,   243,   252,    85,    86,
      87,    88,   244,   245,   246,     0,     0,     0,     0,     0,
     247,     0,     0,    73,     0,     0,   248,     0,     0,     0,
       0,     0,   249,     0,     0,     0,     0,     0,    74,     0,
     398,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,     0,     0,     0,   239,   240,     0,     0,
     241,   242,   243,   252,    85,    86,    87,    88,   244,   245,
     246,     0,     0,     0,     0,     0,   247,     0,     0,    73,
       0,     0,   248,     0,     0,     0,     0,     0,   249,     0,
       0,     0,     0,     0,    74,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
      85,    86,    87,    88,     2,     3,     0,     0,     0,     4,
       0,     5,     0,     7,     0,     0,     0,     0,     9,    10,
       0,    12,     0,    13,    14,    73,     0,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     0,     0,
      74,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    73,   183,     0,     0,
       0,     0,     0,     0,    18,    84,    85,    86,    87,    88,
     184,    74,     0,     0,     0,     0,     0,    76,    77,    78,
     185,    80,    81,    82,    83,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,    73,     0,     0,     0,
       0,     0,     0,     0,    18,     0,    84,    85,    86,    87,
      88,    74,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     0,     0,
       0,     0,  -224,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,    73,
       0,     0,    57,    16,    17,    18,     0,    19,    20,    21,
       0,     0,     0,    73,    74,     0,    75,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    74,     0,
     276,     0,     0,     0,    76,    77,    78,    79,    80,    81,
      82,    83,     0,   307,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    84,    85,    86,    87,    88,    76,    77,
      78,    79,    80,    81,    82,    83,    74,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,   296,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,   251,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,    73,
     121,    84,    85,    86,    87,    88,    76,    77,    78,    79,
      80,    81,    82,    83,   136,    73,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
      74,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,    82,    83,     0,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,    19,    20,    21,     0,    48,     0,
     187,     1,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,    19,    20,    21,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,    19,    20,    21,     2,     3,     0,     0,     0,
       4,     0,     5,     0,     7,     0,     0,     0,     0,     9,
      10,     0,    12,     0,    13,    14,     0,     0,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    74,    73,     0,    63,    76,    77,   118,    23,   132,
      42,   208,    93,   129,    43,    45,    41,    40,   129,    34,
      62,   176,    93,    46,    74,     7,   377,    24,    25,    29,
      27,    28,    29,   317,    43,   121,    72,    44,   322,    43,
      40,    23,    45,   394,   395,   323,    35,   118,   121,    85,
     136,    74,   330,    35,    87,    87,    85,    87,   129,    57,
      85,    61,   291,   136,    62,    54,   139,   316,   110,    43,
     316,   121,   301,    62,    45,   125,    85,   127,   159,   160,
     161,    85,    85,   238,   313,    74,   136,    44,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   259,   383,    42,   125,    43,   127,
     339,    85,   110,    72,    85,    51,   114,   316,   396,   116,
     398,   110,    43,   204,   240,   114,   316,   356,   377,   240,
     327,   377,   121,   204,   132,    45,   125,   292,   127,    72,
     316,    25,   140,    27,    28,   394,   395,   136,   394,   395,
      85,    87,    85,   382,    85,   312,   346,   280,   156,    87,
     315,    40,   319,    43,    85,   236,   237,    46,    40,   240,
      42,   361,   362,   188,   247,    85,   331,    51,   377,    52,
      53,    87,   180,    74,    51,   183,    50,   377,   343,    56,
      57,   180,   347,    74,   349,   394,   395,   352,    66,   354,
     355,   377,   200,    40,   394,   395,   363,    67,    45,    46,
       7,    40,   367,   368,   287,   370,    45,    46,   394,   395,
     375,   376,   295,   380,   381,   298,    23,    58,    59,    68,
      27,    28,    60,    61,    62,    63,   391,   392,    35,    44,
     351,   300,    64,    65,    41,    42,   166,   167,   168,   169,
      41,    48,    49,    50,    51,    52,    53,    54,    55,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      69,    70,   162,   163,    41,   272,   164,   165,   337,    43,
     351,   340,   280,    87,   357,    87,   284,   360,   170,   171,
      87,    88,    89,    90,    91,    87,    70,    41,   371,    41,
     373,   374,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    41,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    43,    30,
      85,    87,    33,    34,    35,    36,    37,    38,    39,    43,
      43,    42,    41,    44,    85,    43,   346,    48,    49,    50,
      51,    52,    53,    54,    55,    40,    72,    42,    72,    71,
      87,    46,    47,    48,    49,    42,    42,    45,    41,    71,
      45,    72,    41,    44,    71,    42,    44,    72,    42,    85,
      71,    43,    45,    36,    45,    42,    87,    88,    89,    90,
      91,     3,    36,    42,     6,     7,    12,    44,    72,    11,
      72,    13,    14,    15,    43,    43,   172,    19,    20,    21,
      22,    23,    45,    25,    26,    27,    28,    45,    45,   173,
     236,    33,    34,    35,   174,    37,    38,    39,   237,    42,
      42,    56,   120,   127,    53,   276,    48,    49,    50,    51,
      52,    53,    54,    55,   134,   272,   304,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      -1,    -1,     8,     9,    10,    87,    88,    89,    90,    91,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,     8,     9,
      10,    87,    88,    89,    90,    91,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,     8,     9,    10,    87,    88,    89,
      90,    91,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
       8,     9,    10,    87,    88,    89,    90,    91,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,
      -1,    23,    -1,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    87,    88,    89,    90,    91,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    87,    88,    89,    90,
      91,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,
      91,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,    -1,    -1,
      -1,    -1,    44,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    27,
      -1,    -1,    74,    33,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    -1,    27,    42,    -1,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    42,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    42,    87,    88,    89,    90,    91,    48,    49,
      50,    51,    52,    53,    54,    55,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    72,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      42,    87,    88,    89,    90,    91,    48,    49,    50,    51,
      52,    53,    54,    55,    42,    27,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    37,    38,    39,    -1,     0,    -1,
      43,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    37,    38,    39,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    37,    38,    39,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   124,   126,   130,   131,   134,   138,   139,   167,
     168,   169,    87,   135,    42,    51,    87,   125,   128,   129,
     140,   141,   143,   126,   127,   127,   127,   127,     0,   168,
      44,   140,   138,   142,   144,    72,    85,    74,   124,   126,
     170,   171,    40,    42,   141,    87,   136,   137,    43,   143,
     138,   129,   140,    27,    42,    44,    48,    49,    50,    51,
      52,    53,    54,    55,    87,    88,    89,    90,    91,   101,
     102,   103,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   150,   100,   124,
      28,    41,    51,   120,   144,    87,   100,   148,    74,    45,
      85,    42,   106,   120,   122,   131,   132,   138,   149,    40,
      46,   151,   152,   153,   154,   155,    42,   106,   106,    40,
      42,    46,    47,    48,    49,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   121,   106,   108,    51,
      56,    57,    52,    53,    58,    59,    60,    61,    62,    63,
      64,    65,    50,    66,    67,    68,    69,    95,    44,   120,
     144,    41,    41,    28,    41,    51,   120,    43,   126,   145,
     146,   147,    43,    85,   119,   123,    45,   137,   149,    43,
      85,   132,   133,   133,    43,   123,    87,    45,    85,   150,
      74,   155,   149,   122,   104,   105,   120,    87,    87,   120,
     108,   108,   108,   109,   109,   110,   110,   111,   111,   111,
     111,   112,   112,   113,   114,   115,    94,    94,    70,     4,
       5,     8,     9,    10,    16,    17,    18,    24,    30,    36,
      44,    72,    87,   122,   124,   156,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    41,   120,   120,    41,    41,
     140,    43,    85,    87,    43,   120,    44,   108,    41,    45,
     152,    43,    41,    43,    85,   116,   117,    94,    72,   123,
      72,    71,    99,    97,    87,    42,    72,   122,    42,    98,
      96,    71,    72,    45,    94,    41,    41,    73,   147,   151,
     150,   120,   122,    71,   156,    44,    94,    42,    72,   122,
      72,   122,    42,   100,   156,   162,    45,    85,    95,   156,
      94,   157,   158,   163,   164,   165,   166,    96,    95,    43,
      96,   160,    45,    71,   160,    94,   100,    43,   156,   100,
      45,    94,    45,    36,   124,   163,    94,    94,   119,    94,
      42,    94,    94,   156,   122,    36,   122,   163,   163,    95,
      43,    42,    43,    94,    94,    12,    44,    94,   122,    72,
     122,   122,    94,    94,   157,    43,    95,    95,   156,   160,
      72,    43,    43,    45,    94,    94,    44,   157,    44,   157,
     160,   160,    45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   109,   109,   110,   110,   110,
     111,   111,   111,   112,   112,   112,   112,   112,   113,   113,
     113,   114,   114,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   122,   122,   123,   124,
     125,   125,   126,   126,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   130,   130,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   138,   139,   140,   140,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   150,   150,   150,
     151,   151,   152,   152,   153,   154,   154,   155,   155,   156,
     156,   156,   156,   156,   156,   157,   157,   157,   157,   157,
     158,   158,   158,   159,   160,   160,   161,   161,   162,   162,
     163,   163,   164,   164,   164,   165,   165,   165,   165,   165,
     165,   165,   165,   166,   166,   166,   166,   166,   167,   167,
     168,   168,   169,   170,   170,   171,   171
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     0,     0,     0,     1,
       1,     1,     3,     1,     1,     1,     1,     4,     4,     3,
       3,     2,     2,     6,     7,     1,     0,     1,     3,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     4,     1,
       4,     1,     9,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     0,     2,     2,     2,     2,     1,     0,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     0,     5,     6,     2,     1,     0,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     3,
       5,     4,     4,     3,     6,     5,     6,     5,     4,     5,
       4,     4,     1,     0,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     1,     1,     3,     1,     1,     3,     4,
       2,     4,     1,     0,     2,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     5,     1,     0,     1,     3,     1,     1,
       2,     1,     8,    11,     5,    10,    12,    10,    12,    14,
      14,    16,    16,     3,     2,     2,     3,     2,     1,     2,
       1,     1,     7,     1,     0,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 92 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.instr) = nextinstr();
        }
#line 1941 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 3:
#line 98 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            (yyval.stmt)->nextlist = makelist(nextinstr());
            emit("goto", "");
        }
#line 1951 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 4:
#line 106 "asgn5_19CS10064_19CS30008.y"
        {
            string newST = currentST->name + "." + blockName + "$" + to_string(STCount++);
            symbol* sym = currentST->lookup(newST);
            sym->nestedTable = new symbolTable(newST);
            sym->name = newST;
            sym->nestedTable->parent = currentST;
            sym->type = new symbolType("block");
            currentSymbol = sym;
        }
#line 1965 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 5:
#line 118 "asgn5_19CS10064_19CS30008.y"
        {
            blockName = "FOR";
        }
#line 1973 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 6:
#line 124 "asgn5_19CS10064_19CS30008.y"
        {
            blockName = "WHILE";
        }
#line 1981 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 7:
#line 130 "asgn5_19CS10064_19CS30008.y"
        {
            blockName = "DO_WHILE";
        }
#line 1989 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 8:
#line 136 "asgn5_19CS10064_19CS30008.y"
        {
            if(currentSymbol->nestedTable != NULL) {
                switchTable(currentSymbol->nestedTable);
                emit("label", currentST->name);
            }
            else {
                switchTable(new symbolTable(""));
            }
        }
#line 2003 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 9:
#line 149 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = (yyvsp[0].symp);
            (yyval.expr)->type = "non_bool";
        }
#line 2013 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 10:
#line 155 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = (yyvsp[0].symp);
        }
#line 2022 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 11:
#line 160 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = new expression();
            (yyval.expr)->loc = symbolTable::gentemp(new symbolType("ptr"), (yyvsp[0].charval));
            (yyval.expr)->loc->type->arrType = new symbolType("char");
        }
#line 2032 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 12:
#line 166 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[-1].expr);
        }
#line 2040 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 13:
#line 173 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symp) = symbolTable::gentemp(new symbolType("int"), convertIntToString((yyvsp[0].intval)));
            emit("=", (yyval.symp)->name, (yyvsp[0].intval));
        }
#line 2049 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 14:
#line 178 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symp) = symbolTable::gentemp(new symbolType("float"), string((yyvsp[0].charval)));
            emit("=", (yyval.symp)->name, string((yyvsp[0].charval)));
        }
#line 2058 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 15:
#line 183 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symp) = symbolTable::gentemp(new symbolType("float"), string((yyvsp[0].charval)));
            emit("=", (yyval.symp)->name, string((yyvsp[0].charval)));
        }
#line 2067 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 16:
#line 191 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = new Array();
            (yyval.arr)->Array = (yyvsp[0].expr)->loc;
            (yyval.arr)->type = (yyvsp[0].expr)->loc->type;
            (yyval.arr)->loc = (yyval.arr)->Array;
        }
#line 2078 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 17:
#line 198 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = new Array();
            (yyval.arr)->type = (yyvsp[-3].arr)->type->arrType;
            (yyval.arr)->Array = (yyvsp[-3].arr)->Array;
            (yyval.arr)->loc = symbolTable::gentemp(new symbolType("int"));
            (yyval.arr)->atype = "arr";

            if((yyvsp[-3].arr)->atype == "arr") {
                symbol* sym = symbolTable::gentemp(new symbolType("int"));
                int sz = sizeOfType((yyval.arr)->type);
                emit("*", sym->name, (yyvsp[-1].expr)->loc->name, convertIntToString(sz));
                emit("+", (yyval.arr)->loc->name, (yyvsp[-3].arr)->loc->name, sym->name);
            }
            else {
                int sz = sizeOfType((yyval.arr)->type);
                emit("*", (yyval.arr)->loc->name, (yyvsp[-1].expr)->loc->name, convertIntToString(sz));
            }
        }
#line 2101 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 18:
#line 217 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = new Array();
            (yyval.arr)->Array = symbolTable::gentemp((yyvsp[-3].arr)->type);
            emit("call", (yyval.arr)->Array->name, (yyvsp[-3].arr)->Array->name, convertIntToString((yyvsp[-1].numParams)));
        }
#line 2111 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 19:
#line 223 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2117 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 20:
#line 225 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2123 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 21:
#line 227 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = new Array();
            (yyval.arr)->Array = symbolTable::gentemp((yyvsp[-1].arr)->Array->type);
            emit("=", (yyval.arr)->Array->name, (yyvsp[-1].arr)->Array->name);
            emit("+", (yyvsp[-1].arr)->Array->name, (yyvsp[-1].arr)->Array->name, "1");
        }
#line 2134 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 22:
#line 234 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = new Array();
            (yyval.arr)->Array = symbolTable::gentemp((yyvsp[-1].arr)->Array->type);
            emit("=", (yyval.arr)->Array->name, (yyvsp[-1].arr)->Array->name);
            emit("-", (yyvsp[-1].arr)->Array->name, (yyvsp[-1].arr)->Array->name, "1");
        }
#line 2145 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 23:
#line 241 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2151 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 24:
#line 243 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2157 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 25:
#line 248 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.numParams) = (yyvsp[0].numParams);
        }
#line 2165 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 26:
#line 252 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.numParams) = 0;
        }
#line 2173 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 27:
#line 259 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.numParams) = 1;
            emit("param", (yyvsp[0].expr)->loc->name);
        }
#line 2182 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 28:
#line 264 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.numParams) = (yyvsp[-2].numParams) + 1;
            emit("param", (yyvsp[0].expr)->loc->name);
        }
#line 2191 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 29:
#line 272 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = (yyvsp[0].arr);
        }
#line 2199 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 30:
#line 276 "asgn5_19CS10064_19CS30008.y"
        {
            emit("+", (yyvsp[0].arr)->Array->name, (yyvsp[0].arr)->Array->name, "1");
            (yyval.arr) = (yyvsp[0].arr);
        }
#line 2208 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 31:
#line 281 "asgn5_19CS10064_19CS30008.y"
        {
            emit("-", (yyvsp[0].arr)->Array->name, (yyvsp[0].arr)->Array->name, "1");
            (yyval.arr) = (yyvsp[0].arr);
        }
#line 2217 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 32:
#line 286 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = new Array();
            switch((yyvsp[-1].unaryOp)) {
                case '&':
                    (yyval.arr)->Array = symbolTable::gentemp(new symbolType("ptr"));
                    (yyval.arr)->Array->type->arrType = (yyvsp[0].arr)->Array->type;
                    emit("= &", (yyval.arr)->Array->name, (yyvsp[0].arr)->Array->name);
                    break;
                case '*':
                    (yyval.arr)->atype = "ptr";
                    (yyval.arr)->loc = symbolTable::gentemp((yyvsp[0].arr)->Array->type->arrType);
                    (yyval.arr)->Array = (yyvsp[0].arr)->Array;
                    emit("= *", (yyval.arr)->loc->name, (yyvsp[0].arr)->Array->name);
                    break;
                case '+':
                    (yyval.arr) = (yyvsp[0].arr);
                    break;
                case '-':
                    (yyval.arr)->Array = symbolTable::gentemp(new symbolType((yyvsp[0].arr)->Array->type->type));
                    emit("= -", (yyval.arr)->Array->name, (yyvsp[0].arr)->Array->name);
                    break;
                case '~':
                    (yyval.arr)->Array = symbolTable::gentemp(new symbolType((yyvsp[0].arr)->Array->type->type));
                    emit("= ~", (yyval.arr)->Array->name, (yyvsp[0].arr)->Array->name);
                    break;
                case '!':
                    (yyval.arr)->Array = symbolTable::gentemp(new symbolType((yyvsp[0].arr)->Array->type->type));
                    emit("= !", (yyval.arr)->Array->name, (yyvsp[0].arr)->Array->name);
                    break;
            }
        }
#line 2253 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 33:
#line 318 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2259 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 34:
#line 320 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2265 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 35:
#line 325 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.unaryOp) = '&';
        }
#line 2273 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 36:
#line 329 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.unaryOp) = '*';
        }
#line 2281 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 37:
#line 333 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.unaryOp) = '+';
        }
#line 2289 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 38:
#line 337 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.unaryOp) = '-';
        }
#line 2297 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 39:
#line 341 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.unaryOp) = '~';
        }
#line 2305 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 40:
#line 345 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.unaryOp) = '!';
        }
#line 2313 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 41:
#line 352 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = (yyvsp[0].arr);
        }
#line 2321 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 42:
#line 356 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.arr) = new Array();
            (yyval.arr)->Array = convertType((yyvsp[0].arr)->Array, varType);
        }
#line 2330 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 43:
#line 364 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = new expression();
            if((yyvsp[0].arr)->atype == "arr") {
                (yyval.expr)->loc = symbolTable::gentemp((yyvsp[0].arr)->loc->type);
                emit("=[]", (yyval.expr)->loc->name, (yyvsp[0].arr)->Array->name, (yyvsp[0].arr)->loc->name);
            }
            else if((yyvsp[0].arr)->atype == "ptr") {
                (yyval.expr)->loc = (yyvsp[0].arr)->loc;
            }
            else {
                (yyval.expr)->loc = (yyvsp[0].arr)->Array;
            }
        }
#line 2348 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 44:
#line 378 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].arr)->Array)) {
                (yyval.expr) = new expression();
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType((yyvsp[-2].expr)->loc->type->type));
                emit("*", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].arr)->Array->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2363 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 45:
#line 389 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].arr)->Array)) {
                (yyval.expr) = new expression();
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType((yyvsp[-2].expr)->loc->type->type));
                emit("/", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].arr)->Array->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2378 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 46:
#line 400 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].arr)->Array)) {
                (yyval.expr) = new expression();
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType((yyvsp[-2].expr)->loc->type->type));
                emit("%", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].arr)->Array->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2393 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 47:
#line 414 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2401 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 48:
#line 418 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                (yyval.expr) = new expression();
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType((yyvsp[-2].expr)->loc->type->type));
                emit("+", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2416 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 49:
#line 429 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                (yyval.expr) = new expression();
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType((yyvsp[-2].expr)->loc->type->type));
                emit("-", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2431 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 50:
#line 443 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2439 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 51:
#line 447 "asgn5_19CS10064_19CS30008.y"
        {
            if((yyvsp[0].expr)->loc->type->type == "int") {
                (yyval.expr) = new expression();
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType("int"));
                emit("<<", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2454 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 52:
#line 458 "asgn5_19CS10064_19CS30008.y"
        {
            if((yyvsp[0].expr)->loc->type->type == "int") {
                (yyval.expr) = new expression();
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType("int"));
                emit(">>", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2469 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 53:
#line 472 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2477 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 54:
#line 476 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                (yyval.expr) = new expression();
                (yyval.expr)->type = "bool";
                (yyval.expr)->truelist = makelist(nextinstr());
                (yyval.expr)->falselist = makelist(nextinstr() + 1);
                emit("<", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2495 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 55:
#line 490 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                (yyval.expr) = new expression();
                (yyval.expr)->type = "bool";
                (yyval.expr)->truelist = makelist(nextinstr());
                (yyval.expr)->falselist = makelist(nextinstr() + 1);
                emit(">", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2513 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 56:
#line 504 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                (yyval.expr) = new expression();
                (yyval.expr)->type = "bool";
                (yyval.expr)->truelist = makelist(nextinstr());
                (yyval.expr)->falselist = makelist(nextinstr() + 1);
                emit("<=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2531 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 57:
#line 518 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                (yyval.expr) = new expression();
                (yyval.expr)->type = "bool";
                (yyval.expr)->truelist = makelist(nextinstr());
                (yyval.expr)->falselist = makelist(nextinstr() + 1);
                emit(">=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2549 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 58:
#line 535 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2557 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 59:
#line 539 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                convertBoolToInt((yyvsp[-2].expr));
                convertBoolToInt((yyvsp[0].expr));
                (yyval.expr) = new expression();
                (yyval.expr)->type = "bool";
                (yyval.expr)->truelist = makelist(nextinstr());
                (yyval.expr)->falselist = makelist(nextinstr() + 1);
                emit("==", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2577 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 60:
#line 555 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                convertBoolToInt((yyvsp[-2].expr));
                convertBoolToInt((yyvsp[0].expr));
                (yyval.expr) = new expression();
                (yyval.expr)->type = "bool";
                (yyval.expr)->truelist = makelist(nextinstr());
                (yyval.expr)->falselist = makelist(nextinstr() + 1);
                emit("!=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
                emit("goto", "");
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2597 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 61:
#line 574 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2605 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 62:
#line 578 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                convertBoolToInt((yyvsp[-2].expr));
                convertBoolToInt((yyvsp[0].expr));
                (yyval.expr) = new expression();
                (yyval.expr)->type = "not_bool";
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType("int"));
                emit("&", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2623 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 63:
#line 595 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2631 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 64:
#line 599 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                convertBoolToInt((yyvsp[-2].expr));
                convertBoolToInt((yyvsp[0].expr));
                (yyval.expr) = new expression();
                (yyval.expr)->type = "not_bool";
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType("int"));
                emit("^", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2649 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 65:
#line 616 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2657 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 66:
#line 620 "asgn5_19CS10064_19CS30008.y"
        {
            if(typecheck((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
                convertBoolToInt((yyvsp[-2].expr));
                convertBoolToInt((yyvsp[0].expr));
                (yyval.expr) = new expression();
                (yyval.expr)->type = "not_bool";
                (yyval.expr)->loc = symbolTable::gentemp(new symbolType("int"));
                emit("|", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                yyerror("Type Error");
            }
        }
#line 2675 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 67:
#line 637 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2683 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 68:
#line 641 "asgn5_19CS10064_19CS30008.y"
        {
            convertIntToBool((yyvsp[-3].expr));
            convertIntToBool((yyvsp[0].expr));
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].instr));
            (yyval.expr)->truelist = (yyvsp[0].expr)->truelist;
            (yyval.expr)->falselist = merge((yyvsp[-3].expr)->falselist, (yyvsp[0].expr)->falselist);
        }
#line 2697 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 69:
#line 654 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2705 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 70:
#line 658 "asgn5_19CS10064_19CS30008.y"
        {
            convertIntToBool((yyvsp[-3].expr));
            convertIntToBool((yyvsp[0].expr));
            (yyval.expr) = new expression();
            (yyval.expr)->type = "bool";
            backpatch((yyvsp[-3].expr)->falselist, (yyvsp[-1].instr));
            (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;
            (yyval.expr)->truelist = merge((yyvsp[-3].expr)->truelist, (yyvsp[0].expr)->truelist);
        }
#line 2719 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 71:
#line 671 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2727 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 72:
#line 675 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr)->loc = symbolTable::gentemp((yyvsp[-4].expr)->loc->type);
            (yyval.expr)->loc->update((yyvsp[-4].expr)->loc->type);
            emit("=", (yyval.expr)->loc->name, (yyvsp[0].expr)->loc->name);
            list<int> l1 = makelist(nextinstr());
            emit("goto", "");
            backpatch((yyvsp[-3].stmt)->nextlist, nextinstr());
            emit("=", (yyval.expr)->loc->name, (yyvsp[-4].expr)->loc->name);
            list<int> l2 = makelist(nextinstr());
            l1 = merge(l1, l2);
            emit("goto", "");
            backpatch((yyvsp[-7].stmt)->nextlist, nextinstr());
            convertIntToBool((yyvsp[-8].expr));
            backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].instr));
            backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].instr));
            backpatch(l1, nextinstr());
        }
#line 2749 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 73:
#line 696 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2757 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 74:
#line 700 "asgn5_19CS10064_19CS30008.y"
        {
            if((yyvsp[-2].arr)->atype == "arr") {
                (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc, (yyvsp[-2].arr)->type->type);
                emit("[]=", (yyvsp[-2].arr)->Array->name, (yyvsp[-2].arr)->loc->name, (yyvsp[0].expr)->loc->name);
            }
            else if((yyvsp[-2].arr)->atype == "ptr") {
                emit("*=", (yyvsp[-2].arr)->Array->name, (yyvsp[0].expr)->loc->name);
            }
            else {
                (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc, (yyvsp[-2].arr)->Array->type->type);
                emit("=", (yyvsp[-2].arr)->Array->name, (yyvsp[0].expr)->loc->name);
            }
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2776 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 75:
#line 718 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2782 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 76:
#line 720 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2788 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 77:
#line 722 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2794 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 78:
#line 724 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2800 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 79:
#line 726 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2806 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 80:
#line 728 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2812 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 81:
#line 730 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2818 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 82:
#line 732 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2824 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 83:
#line 734 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2830 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 84:
#line 736 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2836 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 85:
#line 738 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2842 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 86:
#line 743 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 2850 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 87:
#line 747 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2856 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 88:
#line 752 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2862 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 89:
#line 757 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2868 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 90:
#line 762 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2874 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 91:
#line 764 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2880 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 92:
#line 769 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2886 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 93:
#line 771 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2892 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 94:
#line 773 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2898 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 95:
#line 775 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2904 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 96:
#line 780 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2910 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 97:
#line 782 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2916 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 98:
#line 787 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2922 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 99:
#line 789 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2928 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 100:
#line 794 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symp) = (yyvsp[0].symp);
        }
#line 2936 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 101:
#line 798 "asgn5_19CS10064_19CS30008.y"
        {
            if((yyvsp[0].symp)->value != "") {
                (yyvsp[-2].symp)->value = (yyvsp[0].symp)->value;
            }
            emit("=", (yyvsp[-2].symp)->name, (yyvsp[0].symp)->name);
        }
#line 2947 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 102:
#line 808 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2953 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 103:
#line 810 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2959 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 104:
#line 812 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2965 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 105:
#line 814 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2971 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 106:
#line 819 "asgn5_19CS10064_19CS30008.y"
        {
            varType = "void";
        }
#line 2979 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 107:
#line 823 "asgn5_19CS10064_19CS30008.y"
        {
            varType = "char";
        }
#line 2987 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 108:
#line 827 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 2993 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 109:
#line 829 "asgn5_19CS10064_19CS30008.y"
        {
            varType = "int";
        }
#line 3001 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 110:
#line 833 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3007 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 111:
#line 835 "asgn5_19CS10064_19CS30008.y"
        {
            varType = "float";
        }
#line 3015 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 112:
#line 839 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3021 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 113:
#line 841 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3027 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 114:
#line 843 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3033 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 115:
#line 845 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3039 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 116:
#line 847 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3045 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 117:
#line 849 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3051 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 118:
#line 851 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3057 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 119:
#line 856 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3063 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 120:
#line 858 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3069 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 121:
#line 863 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3075 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 122:
#line 865 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3081 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 123:
#line 870 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3087 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 124:
#line 872 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3093 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 125:
#line 874 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3099 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 126:
#line 879 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3105 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 127:
#line 881 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3111 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 128:
#line 886 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3117 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 129:
#line 888 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3123 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 130:
#line 893 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3129 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 131:
#line 895 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3135 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 132:
#line 900 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3141 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 133:
#line 902 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3147 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 134:
#line 904 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3153 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 135:
#line 909 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3159 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 136:
#line 914 "asgn5_19CS10064_19CS30008.y"
        {
            symbolType* t = (yyvsp[-1].symType);
            while(t->arrType != NULL) {
                t = t->arrType;
            }
            t->arrType = (yyvsp[0].symp)->type;
            (yyval.symp) = (yyvsp[0].symp)->update((yyvsp[-1].symType));
        }
#line 3172 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 137:
#line 923 "asgn5_19CS10064_19CS30008.y"
        {/* Ignored */}
#line 3178 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 138:
#line 928 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symp) = (yyvsp[0].symp)->update(new symbolType(varType));
            currentSymbol = (yyval.symp);
        }
#line 3187 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 139:
#line 933 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symp) = (yyvsp[-1].symp);
        }
#line 3195 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 140:
#line 937 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3201 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 141:
#line 939 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3207 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 142:
#line 941 "asgn5_19CS10064_19CS30008.y"
        {
            symbolType* t = (yyvsp[-3].symp)->type;
            symbolType* prev = NULL;
            while(t->type == "arr") {
                prev = t;
                t = t->arrType;
            }
            if(prev == NULL) {
                int temp = atoi((yyvsp[-1].expr)->loc->value.c_str());
                symbolType* tp = new symbolType("arr", (yyvsp[-3].symp)->type, temp);
                (yyval.symp) = (yyvsp[-3].symp)->update(tp);
            }
            else {
                int temp = atoi((yyvsp[-1].expr)->loc->value.c_str());
                prev->arrType = new symbolType("arr", t, temp);
                (yyval.symp) = (yyvsp[-3].symp)->update((yyvsp[-3].symp)->type);
            }
        }
#line 3230 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 143:
#line 960 "asgn5_19CS10064_19CS30008.y"
        {
            symbolType* t = (yyvsp[-2].symp)->type;
            symbolType* prev = NULL;
            while(t->type == "arr") {
                prev = t;
                t = t->arrType;
            }
            if(prev == NULL) {
                symbolType* tp = new symbolType("arr", (yyvsp[-2].symp)->type, 0);
                (yyval.symp) = (yyvsp[-2].symp)->update(tp);
            }
            else {
                prev->arrType = new symbolType("arr", t, 0);
                (yyval.symp) = (yyvsp[-2].symp)->update((yyvsp[-2].symp)->type);
            }
        }
#line 3251 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 144:
#line 977 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3257 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 145:
#line 979 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3263 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 146:
#line 981 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3269 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 147:
#line 983 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3275 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 148:
#line 985 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3281 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 149:
#line 987 "asgn5_19CS10064_19CS30008.y"
        {
            currentST->name = (yyvsp[-4].symp)->name;
            if((yyvsp[-4].symp)->type->type != "void") {
                symbol* s = currentST->lookup("return");
                s->update((yyvsp[-4].symp)->type);
            }
            (yyvsp[-4].symp)->nestedTable = currentST;
            currentST->parent = globalST;
            switchTable(globalST);
            currentSymbol = (yyval.symp);
        }
#line 3297 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 150:
#line 999 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3303 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 151:
#line 1001 "asgn5_19CS10064_19CS30008.y"
        {
            currentST->name = (yyvsp[-3].symp)->name;
            if((yyvsp[-3].symp)->type->type != "void") {
                symbol* s = currentST->lookup("return");
                s->update((yyvsp[-3].symp)->type);
            }
            (yyvsp[-3].symp)->nestedTable = currentST;
            currentST->parent = globalST;
            switchTable(globalST);
            currentSymbol = (yyval.symp);
        }
#line 3319 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 152:
#line 1016 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3325 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 153:
#line 1018 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3331 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 154:
#line 1023 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symType) = new symbolType("ptr");
        }
#line 3339 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 155:
#line 1027 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symType) = new symbolType("ptr", (yyvsp[0].symType));
        }
#line 3347 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 156:
#line 1034 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3353 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 157:
#line 1036 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3359 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 158:
#line 1041 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3365 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 159:
#line 1043 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3371 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 160:
#line 1048 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3377 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 161:
#line 1050 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3383 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 162:
#line 1055 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3389 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 163:
#line 1057 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3395 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 164:
#line 1062 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3401 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 165:
#line 1064 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3407 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 166:
#line 1069 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3413 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 167:
#line 1074 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.symp) = (yyvsp[0].expr)->loc;
        }
#line 3421 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 168:
#line 1078 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3427 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 169:
#line 1080 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3433 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 170:
#line 1085 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3439 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 171:
#line 1087 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3445 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 172:
#line 1092 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3451 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 173:
#line 1094 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3457 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 174:
#line 1099 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3463 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 175:
#line 1104 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3469 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 176:
#line 1106 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3475 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 177:
#line 1111 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3481 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 178:
#line 1113 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3487 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 179:
#line 1118 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3493 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 180:
#line 1120 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3501 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 181:
#line 1124 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            (yyval.stmt)->nextlist = (yyvsp[0].expr)->nextlist;
        }
#line 3510 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 182:
#line 1129 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3518 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 183:
#line 1133 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3526 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 184:
#line 1137 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3534 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 185:
#line 1144 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3540 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 186:
#line 1146 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            (yyval.stmt)->nextlist = (yyvsp[0].expr)->nextlist;
        }
#line 3549 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 187:
#line 1151 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3557 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 188:
#line 1155 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3565 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 189:
#line 1159 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3573 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 190:
#line 1166 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3579 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 191:
#line 1168 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3585 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 192:
#line 1170 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3591 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 193:
#line 1175 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[-1].stmt);
            switchTable(currentST->parent);
        }
#line 3600 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 194:
#line 1183 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3608 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 195:
#line 1187 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
        }
#line 3616 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 196:
#line 1194 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3624 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 197:
#line 1198 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
            backpatch((yyvsp[-2].stmt)->nextlist, (yyvsp[-1].instr));
        }
#line 3633 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 198:
#line 1206 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
        }
#line 3641 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 199:
#line 1210 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 3649 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 200:
#line 1217 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = (yyvsp[-1].expr);
        }
#line 3657 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 201:
#line 1221 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.expr) = new expression();
        }
#line 3665 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 202:
#line 1228 "asgn5_19CS10064_19CS30008.y"
        {
            backpatch((yyvsp[-4].stmt)->nextlist, nextinstr());
            convertIntToBool((yyvsp[-5].expr));
            (yyval.stmt) = new statement();
            backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].instr));
            list<int> temp = merge((yyvsp[-5].expr)->falselist, (yyvsp[-1].stmt)->nextlist);
            (yyval.stmt)->nextlist = merge((yyvsp[0].stmt)->nextlist, temp);
        }
#line 3678 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 203:
#line 1237 "asgn5_19CS10064_19CS30008.y"
        {
            backpatch((yyvsp[-7].stmt)->nextlist, nextinstr());
            convertIntToBool((yyvsp[-8].expr));
            (yyval.stmt) = new statement();
            backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].instr));
            backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].instr));
            list<int> temp = merge((yyvsp[-4].stmt)->nextlist, (yyvsp[-3].stmt)->nextlist);
            (yyval.stmt)->nextlist = merge((yyvsp[0].stmt)->nextlist, temp);
        }
#line 3692 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 204:
#line 1247 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3698 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 205:
#line 1252 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-3].expr));
            backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-4].instr));
            backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].instr));
            (yyval.stmt)->nextlist = (yyvsp[-3].expr)->falselist;
            emit("goto", convertIntToString((yyvsp[-4].instr)));
            blockName = "";
            switchTable(currentST->parent);
        }
#line 3713 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 206:
#line 1263 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-5].expr));
            backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-6].instr));
            backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].instr));
            (yyval.stmt)->nextlist = (yyvsp[-5].expr)->falselist;
            emit("goto", convertIntToString((yyvsp[-6].instr)));
            blockName = "";
            switchTable(currentST->parent);
        }
#line 3728 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 207:
#line 1274 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-2].expr));
            backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-7].instr));
            backpatch((yyvsp[-6].stmt)->nextlist, (yyvsp[-5].instr));
            (yyval.stmt)->nextlist = (yyvsp[-2].expr)->falselist;
            blockName = "";
        }
#line 3741 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 208:
#line 1283 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-2].expr));
            backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-8].instr));
            backpatch((yyvsp[-7].stmt)->nextlist, (yyvsp[-5].instr));
            (yyval.stmt)->nextlist = (yyvsp[-2].expr)->falselist;
            blockName = "";
        }
#line 3754 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 209:
#line 1292 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-6].expr));
            backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].instr));
            backpatch((yyvsp[-3].stmt)->nextlist, (yyvsp[-7].instr));
            backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-5].instr));
            emit("goto", convertIntToString((yyvsp[-5].instr)));
            (yyval.stmt)->nextlist = (yyvsp[-6].expr)->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
#line 3770 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 210:
#line 1304 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-6].expr));
            backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].instr));
            backpatch((yyvsp[-3].stmt)->nextlist, (yyvsp[-7].instr));
            backpatch((yyvsp[0].stmt)->nextlist, (yyvsp[-5].instr));
            emit("goto", convertIntToString((yyvsp[-5].instr)));
            (yyval.stmt)->nextlist = (yyvsp[-6].expr)->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
#line 3786 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 211:
#line 1316 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-8].expr));
            backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-3].instr));
            backpatch((yyvsp[-5].stmt)->nextlist, (yyvsp[-9].instr));
            backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-7].instr));
            emit("goto", convertIntToString((yyvsp[-7].instr)));
            (yyval.stmt)->nextlist = (yyvsp[-8].expr)->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
#line 3802 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 212:
#line 1328 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            convertIntToBool((yyvsp[-8].expr));
            backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-3].instr));
            backpatch((yyvsp[-5].stmt)->nextlist, (yyvsp[-9].instr));
            backpatch((yyvsp[-1].stmt)->nextlist, (yyvsp[-7].instr));
            emit("goto", convertIntToString((yyvsp[-7].instr)));
            (yyval.stmt)->nextlist = (yyvsp[-8].expr)->falselist;
            blockName = "";
            switchTable(currentST->parent);
        }
#line 3818 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 213:
#line 1343 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3824 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 214:
#line 1345 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
        }
#line 3832 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 215:
#line 1349 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
        }
#line 3840 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 216:
#line 1353 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            emit("return", (yyvsp[-1].expr)->loc->name);
        }
#line 3849 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 217:
#line 1358 "asgn5_19CS10064_19CS30008.y"
        {
            (yyval.stmt) = new statement();
            emit("return", "");
        }
#line 3858 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 218:
#line 1366 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3864 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 219:
#line 1368 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3870 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 220:
#line 1373 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3876 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 221:
#line 1375 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3882 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 222:
#line 1380 "asgn5_19CS10064_19CS30008.y"
        {   
            currentST->parent = globalST;
            STCount = 0;
            switchTable(globalST);
        }
#line 3892 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 223:
#line 1389 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3898 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 224:
#line 1391 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3904 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 225:
#line 1396 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3910 "asgn5_19CS10064_19CS30008.tab.c"
    break;

  case 226:
#line 1398 "asgn5_19CS10064_19CS30008.y"
        { /* Ignored */ }
#line 3916 "asgn5_19CS10064_19CS30008.tab.c"
    break;


#line 3920 "asgn5_19CS10064_19CS30008.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 1401 "asgn5_19CS10064_19CS30008.y"


void yyerror(string s) {
    cout << "Error occurred: " << s << endl;
    cout << "Line no.: " << yylineno << endl;
    cout << "Unable to parse: " << yytext << endl; 
}
