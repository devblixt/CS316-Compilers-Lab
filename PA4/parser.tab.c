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
#line 1 "parser.y"

    #include <iostream>
    #include <stdio.h>
    #include <iterator>
    #include <map>
    #include <stack>
    #include <sstream>
    #include <vector>
    #include <string>

    #include "headers/astNode.h"
    #include "headers/threeAC.h"
    #include "main.h"

    int yylex();
    void yyerror(char const* msg);

    extern void addSymbolTable();
    extern void makeIR(ASTNode * ast);
    extern void removeAST(ASTNode * ast);
    extern void pushBlock();
    extern std::string CondExprIR(ASTNode * node, std::string * t);

    wrapper w, p;    
    std::stack <std::string> scope;
    std::pair <std::map <std::string, wrapper>::iterator, bool> r;
    std::map <std::string, wrapper> table;
    std::map <std::string, std::map<std::string, wrapper> > symbolTable;

    int blockCounter = 0;
    int labelCounter = 1;

    std::stringstream ss;

    std::vector <std::string> idVec, vars, strConst;

    int registerCounter = 1;
    std::stack <std::string> labels;

    std::vector <ThreeAC> IR;

#line 112 "parser.tab.c"

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
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_PROGRAM = 258,
    KW_BEGIN = 259,
    KW_END = 260,
    KW_FUNCTION = 261,
    KW_READ = 262,
    KW_WRITE = 263,
    KW_IF = 264,
    KW_ELSE = 265,
    KW_FI = 266,
    KW_FOR = 267,
    KW_ROF = 268,
    KW_BREAK = 269,
    KW_CONTINUE = 270,
    KW_RETURN = 271,
    KW_INT = 272,
    KW_VOID = 273,
    KW_STRING = 274,
    KW_FLOAT = 275,
    OP_ASSIGN = 276,
    OP_ADD = 277,
    OP_SUB = 278,
    OP_MUL = 279,
    OP_DIV = 280,
    OP_EQ = 281,
    OP_NEQ = 282,
    OP_LT = 283,
    OP_GT = 284,
    OP_OP = 285,
    OP_CP = 286,
    OP_SEMICOLON = 287,
    OP_COMMA = 288,
    OP_LEQ = 289,
    OP_GEQ = 290,
    IDENTIFIER = 291,
    INTLITERAL = 292,
    FLOATLITERAL = 293,
    STRINGLITERAL = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "parser.y"

    int ival;
    float fval;
    char * sval;
    ASTNode * ASTPtr;

#line 211 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,    98,   107,   113,   117,   118,   119,   126,
     140,   147,   163,   164,   168,   169,   173,   179,   182,   187,
     188,   192,   203,   204,   209,   210,   214,   214,   223,   228,
     229,   233,   234,   235,   239,   240,   241,   242,   247,   254,
     263,   276,   292,   297,   309,   319,   325,   337,   347,   353,
     354,   358,   364,   367,   373,   376,   382,   383,   388,   389,
     393,   394,   398,   399,   405,   408,   416,   405,   426,   426,
     432,   436,   451,   452,   453,   454,   455,   456,   460,   461,
     465,   466,   470,   473,   481,   470,   496,   497,   501,   502,
     503,   504,   505,   509,   513,   514
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_PROGRAM", "KW_BEGIN", "KW_END",
  "KW_FUNCTION", "KW_READ", "KW_WRITE", "KW_IF", "KW_ELSE", "KW_FI",
  "KW_FOR", "KW_ROF", "KW_BREAK", "KW_CONTINUE", "KW_RETURN", "KW_INT",
  "KW_VOID", "KW_STRING", "KW_FLOAT", "OP_ASSIGN", "OP_ADD", "OP_SUB",
  "OP_MUL", "OP_DIV", "OP_EQ", "OP_NEQ", "OP_LT", "OP_GT", "OP_OP",
  "OP_CP", "OP_SEMICOLON", "OP_COMMA", "OP_LEQ", "OP_GEQ", "IDENTIFIER",
  "INTLITERAL", "FLOATLITERAL", "STRINGLITERAL", "$accept", "program",
  "$@1", "id", "pgm_body", "decl", "string_decl", "str", "var_decl",
  "var_type", "any_type", "id_list", "id_tail", "param_decl_list",
  "param_decl", "param_decl_tail", "func_declarations", "func_decl", "$@2",
  "func_body", "stmt_list", "stmt", "base_stmt", "assign_stmt",
  "assign_expr", "read_stmt", "write_stmt", "return_stmt", "expr",
  "expr_prefix", "factor", "factor_prefix", "postfix_expr", "call_expr",
  "expr_list", "expr_list_tail", "primary", "addop", "mulop", "if_stmt",
  "$@3", "$@4", "$@5", "else_part", "$@6", "cond", "compop", "init_stmt",
  "incr_stmt", "for_stmt", "$@7", "$@8", "$@9", "aug_stmt_list",
  "aug_stmt", "aug_if_stmt", "aug_else_part", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -27,    11,  -134,    18,  -134,  -134,     7,  -134,   -27,
    -134,    10,    27,     7,     7,   -27,    31,  -134,    47,  -134,
      27,  -134,  -134,    -8,     8,    16,  -134,  -134,   -27,  -134,
     -27,  -134,  -134,  -134,    36,  -134,    -8,  -134,    48,  -134,
      17,   -27,    52,    58,  -134,    81,    17,  -134,     7,    58,
      37,    87,  -134,    63,    64,  -134,  -134,  -134,    74,  -134,
      37,  -134,  -134,    65,  -134,  -134,  -134,  -134,  -134,  -134,
     -27,   -27,    66,    68,    69,  -134,  -134,  -134,  -134,    71,
      72,  -134,   -27,  -134,    28,    39,  -134,    73,    75,    53,
      77,  -134,    78,  -134,  -134,  -134,  -134,  -134,  -134,    70,
      35,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,     7,  -134,    80,    82,  -134,  -134,  -134,  -134,
      37,  -134,  -134,    76,    83,  -134,    84,  -134,  -134,  -134,
      94,   -27,    76,  -134,  -134,  -134,    86,  -134,     7,    95,
       7,    37,  -134,     5,  -134,    85,    88,    89,  -134,  -134,
    -134,     5,  -134,  -134,  -134,  -134,    99,  -134,    91,  -134,
       7,     5,   108,     7,   112,     5,  -134,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     8,    13,     0,
      12,     0,    25,     8,     8,     0,     0,     3,     0,     5,
      25,     6,     7,    18,     0,     0,    15,    14,     0,    24,
       0,    16,    11,    10,     0,    26,    18,     9,     0,    17,
      20,     0,     0,    23,    21,     0,     0,    19,     8,    23,
      30,     0,    22,     0,     0,    64,    82,    45,     0,    28,
      30,    31,    34,     0,    35,    36,    37,    32,    33,    27,
       0,     0,     0,     0,     0,    48,    45,    29,    38,     0,
       0,    45,    79,    42,    43,     0,    39,     0,     0,     0,
       0,    78,     0,    60,    61,    44,    45,    58,    59,    57,
      46,    50,    49,    40,    41,    74,    75,    72,    73,    76,
      77,    45,     8,    83,     0,    45,    62,    63,    47,    71,
      30,    45,    56,    55,     0,    65,     0,    45,    52,    51,
      70,    81,    55,    68,    66,    80,     0,    54,     8,     0,
       8,    30,    67,    87,    69,     0,     0,     0,    88,    90,
      84,    87,    89,    45,    92,    91,     0,    86,     0,    85,
       8,    87,    95,     8,     0,    87,    93,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,     1,  -134,   -13,  -134,  -134,  -134,   -10,
    -134,    19,    90,  -134,    92,    79,   104,  -134,  -134,  -134,
     -57,  -134,  -104,  -134,   -77,  -134,  -134,  -134,   -53,  -134,
    -134,  -134,  -134,  -134,  -134,    -3,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -115,  -134,  -134,  -134,   -95,
    -134,  -134,  -134,  -133,  -134,  -134,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    58,    11,    12,    13,    34,    14,    15,
      28,    24,    31,    42,    43,    47,    19,    20,    38,    51,
      59,    60,    61,    62,    63,    64,    65,    66,    89,    75,
      84,    85,   100,   101,   124,   128,   102,    95,   118,    67,
      72,   130,   139,   134,   138,    90,   111,    92,   136,    68,
      73,   121,   156,   150,   151,   152,   164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    22,     4,    77,    74,    91,   126,     1,    27,     3,
      16,     5,    53,    54,   145,    17,    23,    56,   157,   146,
     147,    57,     6,    86,     8,    30,     9,    10,   162,    35,
      41,    36,   167,    18,     8,    50,    41,    10,   158,   148,
      32,     3,    44,   114,    53,    54,    55,   148,   149,    56,
      93,    94,    25,    57,   135,    33,   149,   148,   119,   116,
     117,   148,   123,   125,     8,    26,   149,    10,    37,    96,
     149,    23,    23,     3,   132,     3,    97,    98,    40,   105,
     106,   107,   108,    45,   144,    48,    99,   109,   110,    79,
      80,    46,    69,    70,    71,    76,    81,    78,    82,   120,
     115,    83,    87,    88,   133,   103,   142,   104,   112,   127,
     113,   122,   159,   -53,   129,   153,   131,   140,   163,     0,
     154,   155,   160,   166,    29,   141,    39,   143,    52,   137,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
     165
};

static const yytype_int16 yycheck[] =
{
      13,    14,     1,    60,    57,    82,   121,     3,    18,    36,
       9,     0,     7,     8,     9,     5,    15,    12,   151,    14,
      15,    16,     4,    76,    17,    33,    19,    20,   161,    28,
      40,    30,   165,     6,    17,    48,    46,    20,   153,   143,
      32,    36,    41,    96,     7,     8,     9,   151,   143,    12,
      22,    23,    21,    16,   131,    39,   151,   161,   111,    24,
      25,   165,   115,   120,    17,    18,   161,    20,    32,    30,
     165,    70,    71,    36,   127,    36,    37,    38,    30,    26,
      27,    28,    29,    31,   141,     4,    85,    34,    35,    70,
      71,    33,     5,    30,    30,    21,    30,    32,    30,   112,
      30,    32,    31,    31,    10,    32,    11,    32,    31,    33,
      32,    31,    13,    31,    31,    30,    32,    31,    10,    -1,
      32,    32,    31,    11,    20,   138,    36,   140,    49,   132,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,    -1,    -1,
     163
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    41,    36,    43,     0,     4,    42,    17,    19,
      20,    44,    45,    46,    48,    49,    43,     5,     6,    56,
      57,    45,    45,    43,    51,    21,    18,    49,    50,    56,
      33,    52,    32,    39,    47,    43,    43,    32,    58,    52,
      30,    49,    53,    54,    43,    31,    33,    55,     4,    54,
      45,    59,    55,     7,     8,     9,    12,    16,    43,    60,
      61,    62,    63,    64,    65,    66,    67,    79,    89,     5,
      30,    30,    80,    90,    68,    69,    21,    60,    32,    51,
      51,    30,    30,    32,    70,    71,    68,    31,    31,    68,
      85,    64,    87,    22,    23,    77,    30,    37,    38,    43,
      72,    73,    76,    32,    32,    26,    27,    28,    29,    34,
      35,    86,    31,    32,    68,    30,    24,    25,    78,    68,
      45,    91,    31,    68,    74,    60,    85,    33,    75,    31,
      81,    32,    68,    10,    83,    64,    88,    75,    84,    82,
      31,    45,    11,    45,    60,     9,    14,    15,    62,    89,
      93,    94,    95,    30,    32,    32,    92,    93,    85,    13,
      31,    45,    93,    10,    96,    45,    11,    93
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    42,    41,    43,    44,    45,    45,    45,    46,
      47,    48,    49,    49,    50,    50,    51,    52,    52,    53,
      53,    54,    55,    55,    56,    56,    58,    57,    59,    60,
      60,    61,    61,    61,    62,    62,    62,    62,    63,    64,
      65,    66,    67,    68,    69,    69,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    75,    76,    76,    76,    76,
      77,    77,    78,    78,    80,    81,    82,    79,    84,    83,
      83,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    88,    90,    91,    92,    89,    93,    93,    94,    94,
      94,    94,    94,    95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     1,     2,     2,     2,     0,     5,
       1,     3,     1,     1,     1,     1,     2,     3,     0,     2,
       0,     2,     3,     0,     2,     0,     0,    10,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       5,     5,     3,     2,     3,     0,     2,     3,     0,     1,
       1,     4,     2,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     0,    11,     0,     4,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     0,     0,     0,    14,     2,     0,     1,     1,
       1,     2,     2,     8,     3,     0
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
#line 98 "parser.y"
                                             {
			scope.push("GLOBAL");
		    }
#line 1512 "parser.tab.c"
    break;

  case 3:
#line 101 "parser.y"
                                    {
			scope.pop();
		    }
#line 1520 "parser.tab.c"
    break;

  case 4:
#line 107 "parser.y"
                                 {
		    	(yyval.sval) = (yyvsp[0].sval);
		    }
#line 1528 "parser.tab.c"
    break;

  case 8:
#line 119 "parser.y"
                             {
		    	addSymbolTable();
		    }
#line 1536 "parser.tab.c"
    break;

  case 9:
#line 126 "parser.y"
                                                              {
			w.value[0] = "STRING";
			w.value[1] = (yyvsp[-1].sval);
			r = table.insert(std::pair<std::string, wrapper> ((yyvsp[-3].sval), w));
			if(!r.second){
				yyerror((yyvsp[-3].sval));
			}
			ss.str("");
			ss << "str " << (yyvsp[-3].sval) << " " << (yyvsp[-1].sval);
			strConst.push_back(ss.str());
		    }
#line 1552 "parser.tab.c"
    break;

  case 10:
#line 140 "parser.y"
                                    {
		    	(yyval.sval) = (yyvsp[0].sval);
		    }
#line 1560 "parser.tab.c"
    break;

  case 11:
#line 147 "parser.y"
                                                    {
			for(typename std::vector <std::string>::reverse_iterator itr = idVec.rbegin(); itr != idVec.rend(); ++itr){
				w.value[0] = (yyvsp[-2].sval);
				w.value[1] = "";
				r = table.insert(std::pair<std::string, wrapper> (*itr, w));
				if(!r.second){
					std::string temp = *itr;
					yyerror(temp.c_str());
				}
				vars.push_back(*itr);
			}
			idVec.clear();
		    }
#line 1578 "parser.tab.c"
    break;

  case 12:
#line 163 "parser.y"
                               { (yyval.sval) = (yyvsp[0].sval); }
#line 1584 "parser.tab.c"
    break;

  case 13:
#line 164 "parser.y"
                             { (yyval.sval) = (yyvsp[0].sval); }
#line 1590 "parser.tab.c"
    break;

  case 16:
#line 173 "parser.y"
                                 {
			idVec.push_back((yyvsp[-1].sval));
		    }
#line 1598 "parser.tab.c"
    break;

  case 17:
#line 179 "parser.y"
                                          {
			idVec.push_back((yyvsp[-1].sval));
		    }
#line 1606 "parser.tab.c"
    break;

  case 21:
#line 192 "parser.y"
                                  {
			w.value[0] = (yyvsp[-1].sval);
			w.value[1] = "";
			r = table.insert(std::pair<std::string, wrapper>((yyvsp[0].sval), w));
			if(!r.second){
				yyerror((yyvsp[0].sval));
			}
		    }
#line 1619 "parser.tab.c"
    break;

  case 26:
#line 214 "parser.y"
                                              {
			scope.push((yyvsp[0].sval));
		    }
#line 1627 "parser.tab.c"
    break;

  case 27:
#line 217 "parser.y"
                                                                          {
			scope.pop();
		    }
#line 1635 "parser.tab.c"
    break;

  case 38:
#line 247 "parser.y"
                                               {
		    	makeIR((yyvsp[-1].ASTPtr));
		    	removeAST((yyvsp[-1].ASTPtr));
		    }
#line 1644 "parser.tab.c"
    break;

  case 39:
#line 254 "parser.y"
                                        {
		    	std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = (yyvsp[-2].sval);
		    	ASTNodeVar * node = new ASTNodeVar(key, mapp[key].value[0]);
		    	(yyval.ASTPtr) = new ASTNodeOp("=", node, (yyvsp[0].ASTPtr));
		    }
#line 1655 "parser.tab.c"
    break;

  case 40:
#line 263 "parser.y"
                                                               {
			for(typename std::vector <std::string>::reverse_iterator itr = idVec.rbegin(); itr != idVec.rend(); ++itr){
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
				if (mapp[*itr].value[0] == "INT")
					IR.push_back(ThreeAC("READI", "", "", *itr));
				else
					IR.push_back(ThreeAC("READF", "", "", *itr));
			}
			idVec.clear();
		    }
#line 1670 "parser.tab.c"
    break;

  case 41:
#line 276 "parser.y"
                                                                {
		    	for(typename std::vector <std::string>::reverse_iterator itr = idVec.rbegin(); itr != idVec.rend(); ++itr){
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
				if (mapp[*itr].value[0] == "INT")
					IR.push_back(ThreeAC("WRITEI", "", "", *itr));
				else if (mapp[*itr].value[0] == "FLOAT")
					IR.push_back(ThreeAC("WRITEF", "", "", *itr));
				else
					IR.push_back(ThreeAC("WRITES", "", "", *itr));

			}
			idVec.clear();
		    }
#line 1688 "parser.tab.c"
    break;

  case 43:
#line 297 "parser.y"
                                         {
		    	if((yyvsp[-1].ASTPtr) != NULL){
		    		(yyvsp[-1].ASTPtr)->right = (yyvsp[0].ASTPtr);
		    		(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);
		    	}
		    	else{
		    		(yyval.ASTPtr) = (yyvsp[0].ASTPtr);
		    	}
		    }
#line 1702 "parser.tab.c"
    break;

  case 44:
#line 309 "parser.y"
                                               {
		    	if((yyvsp[-2].ASTPtr) != NULL){
		    		(yyvsp[0].ASTPtr)->left = (yyvsp[-2].ASTPtr);
		    		(yyvsp[-2].ASTPtr)->right = (yyvsp[-1].ASTPtr);
		    	}
		    	else{
		    		(yyvsp[0].ASTPtr)->left = (yyvsp[-1].ASTPtr);
		    	}
		    	(yyval.ASTPtr) = (yyvsp[0].ASTPtr);
		    }
#line 1717 "parser.tab.c"
    break;

  case 45:
#line 319 "parser.y"
                             {
		    	(yyval.ASTPtr) = NULL;
		    }
#line 1725 "parser.tab.c"
    break;

  case 46:
#line 325 "parser.y"
                                                 {
		    	if((yyvsp[-1].ASTPtr) != NULL){
		    		(yyvsp[-1].ASTPtr)->right = (yyvsp[0].ASTPtr);
		    		(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);
		    	}
		    	else{
		    		(yyval.ASTPtr) = (yyvsp[0].ASTPtr);
		    	}
		    }
#line 1739 "parser.tab.c"
    break;

  case 47:
#line 337 "parser.y"
                                                       {
		    	if((yyvsp[-2].ASTPtr) != NULL){
		    		(yyvsp[0].ASTPtr)->left = (yyvsp[-2].ASTPtr);
		    		(yyvsp[-1].ASTPtr)->right = (yyvsp[-1].ASTPtr);
		    	}
		    	else{
		    		(yyvsp[0].ASTPtr)->left = (yyvsp[-1].ASTPtr);
		    	}
		    	(yyval.ASTPtr) = (yyvsp[0].ASTPtr);
		    }
#line 1754 "parser.tab.c"
    break;

  case 48:
#line 347 "parser.y"
                             {
		    	(yyval.ASTPtr) = NULL;
		    }
#line 1762 "parser.tab.c"
    break;

  case 49:
#line 353 "parser.y"
                              { (yyval.ASTPtr) = (yyvsp[0].ASTPtr); }
#line 1768 "parser.tab.c"
    break;

  case 50:
#line 354 "parser.y"
                                { (yyval.ASTPtr) = (yyvsp[0].ASTPtr); }
#line 1774 "parser.tab.c"
    break;

  case 51:
#line 358 "parser.y"
                                               {
		    	(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);
		    }
#line 1782 "parser.tab.c"
    break;

  case 52:
#line 364 "parser.y"
                                          {
		    	(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);
		    }
#line 1790 "parser.tab.c"
    break;

  case 53:
#line 367 "parser.y"
                             {
		    	(yyval.ASTPtr) = NULL;
		    }
#line 1798 "parser.tab.c"
    break;

  case 54:
#line 373 "parser.y"
                                                   {
		    	(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);
		    }
#line 1806 "parser.tab.c"
    break;

  case 55:
#line 376 "parser.y"
                             {
		    	(yyval.ASTPtr) = NULL;
		    }
#line 1814 "parser.tab.c"
    break;

  case 56:
#line 382 "parser.y"
                                       { (yyval.ASTPtr) = (yyvsp[-1].ASTPtr); }
#line 1820 "parser.tab.c"
    break;

  case 57:
#line 383 "parser.y"
                         { 
		    	std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = (yyvsp[0].sval);
		    	(yyval.ASTPtr) = new ASTNodeVar(key, mapp[key].value[0]);
		    }
#line 1830 "parser.tab.c"
    break;

  case 58:
#line 388 "parser.y"
                                 { (yyval.ASTPtr) = new ASTNodeInt((yyvsp[0].sval)); }
#line 1836 "parser.tab.c"
    break;

  case 59:
#line 389 "parser.y"
                                   { (yyval.ASTPtr) = new ASTNodeFloat((yyvsp[0].sval)); }
#line 1842 "parser.tab.c"
    break;

  case 60:
#line 393 "parser.y"
                             { (yyval.ASTPtr) = new ASTNodeOp("+"); }
#line 1848 "parser.tab.c"
    break;

  case 61:
#line 394 "parser.y"
                             { (yyval.ASTPtr) = new ASTNodeOp("-"); }
#line 1854 "parser.tab.c"
    break;

  case 62:
#line 398 "parser.y"
                             { (yyval.ASTPtr) = new ASTNodeOp("*"); }
#line 1860 "parser.tab.c"
    break;

  case 63:
#line 399 "parser.y"
                             { (yyval.ASTPtr) = new ASTNodeOp("/"); }
#line 1866 "parser.tab.c"
    break;

  case 64:
#line 405 "parser.y"
                            {
			pushBlock();
		    }
#line 1874 "parser.tab.c"
    break;

  case 65:
#line 408 "parser.y"
                                                    {
			ss.str("");
			ss << "label" << labelCounter++;
			IR.push_back(ThreeAC("JUMP", "", "", ss.str()));
			IR.push_back(ThreeAC("LABEL", "", "", labels.top()));
			labels.pop();
			labels.push(ss.str());
		    }
#line 1887 "parser.tab.c"
    break;

  case 66:
#line 416 "parser.y"
                              {
		    	IR.push_back(ThreeAC("LABEL", "", "", labels.top()));
		    	labels.pop();
		    }
#line 1896 "parser.tab.c"
    break;

  case 67:
#line 420 "parser.y"
                          {
		    	scope.pop();
		    }
#line 1904 "parser.tab.c"
    break;

  case 68:
#line 426 "parser.y"
                              {
			pushBlock();
		    }
#line 1912 "parser.tab.c"
    break;

  case 69:
#line 429 "parser.y"
                                   {
			scope.pop();
		    }
#line 1920 "parser.tab.c"
    break;

  case 71:
#line 436 "parser.y"
                                       {
		    	std::string t;
		    	std::string op1 = CondExprIR((yyvsp[-2].ASTPtr), &t);
		    	IR.push_back(ThreeAC("", "", "", "", "SAVE"));
		    	std::string op2 = CondExprIR((yyvsp[0].ASTPtr), &t);
		    	ss.str("");
		    	ss << "label" << labelCounter++;  
		    	IR.push_back(ThreeAC((yyvsp[-1].sval), op1, op2, ss.str(), t)); 
		    	labels.push(ss.str()); 
		    	removeAST((yyvsp[-2].ASTPtr)); 
		    	removeAST((yyvsp[0].ASTPtr));
		    }
#line 1937 "parser.tab.c"
    break;

  case 72:
#line 451 "parser.y"
                            { (yyval.sval) = (char *) "GE"; }
#line 1943 "parser.tab.c"
    break;

  case 73:
#line 452 "parser.y"
                            { (yyval.sval) = (char *) "LE"; }
#line 1949 "parser.tab.c"
    break;

  case 74:
#line 453 "parser.y"
                            { (yyval.sval) = (char *) "NE"; }
#line 1955 "parser.tab.c"
    break;

  case 75:
#line 454 "parser.y"
                             { (yyval.sval) = (char *) "EQ"; }
#line 1961 "parser.tab.c"
    break;

  case 76:
#line 455 "parser.y"
                             { (yyval.sval) = (char *) "GT"; }
#line 1967 "parser.tab.c"
    break;

  case 77:
#line 456 "parser.y"
                             { (yyval.sval) = (char *) "LT"; }
#line 1973 "parser.tab.c"
    break;

  case 78:
#line 460 "parser.y"
                                  { (yyval.ASTPtr) = (yyvsp[0].ASTPtr); }
#line 1979 "parser.tab.c"
    break;

  case 79:
#line 461 "parser.y"
                                   { (yyval.ASTPtr) = NULL; }
#line 1985 "parser.tab.c"
    break;

  case 80:
#line 465 "parser.y"
                                  { (yyval.ASTPtr) = (yyvsp[0].ASTPtr); }
#line 1991 "parser.tab.c"
    break;

  case 81:
#line 466 "parser.y"
                                   { (yyval.ASTPtr) = NULL; }
#line 1997 "parser.tab.c"
    break;

  case 82:
#line 470 "parser.y"
                             {
			pushBlock();
		    }
#line 2005 "parser.tab.c"
    break;

  case 83:
#line 473 "parser.y"
                                                 {
		    	makeIR((yyvsp[-1].ASTPtr));
		    	removeAST((yyvsp[-1].ASTPtr));
		    	ss.str("");
		    	ss << "label" << labelCounter++;
		    	labels.push(ss.str());
		    	IR.push_back(ThreeAC("LABEL", "", "", ss.str()));
		    }
#line 2018 "parser.tab.c"
    break;

  case 84:
#line 481 "parser.y"
                                                                         {
		    	makeIR((yyvsp[-3].ASTPtr));
		    	removeAST((yyvsp[-3].ASTPtr));
		    	std::string temp = labels.top();
		    	labels.pop();
		    	IR.push_back(ThreeAC("JUMP", "", "", labels.top()));
		    	labels.push(temp);
		    	IR.push_back(ThreeAC("LABEL", "", "", temp));
		    }
#line 2032 "parser.tab.c"
    break;

  case 85:
#line 490 "parser.y"
                           {
			scope.pop();
		    }
#line 2040 "parser.tab.c"
    break;


#line 2044 "parser.tab.c"

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
#line 517 "parser.y"

