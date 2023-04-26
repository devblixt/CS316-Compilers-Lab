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
#line 1 "microParser.y"

	#include <stdio.h> 
	#include <string.h> 
	#include <stdlib.h> 
	#include <math.h>  
	#include <ctype.h>
	 #include <iostream>
    #include <stdio.h>
    #include <iterator>
    #include <map>
    #include <stack>
    #include <sstream>
    #include <vector>
    #include <string>
	#include "wrapper.h"
	#include "makers.h"

	int yylex();
	extern int yylineno; //For extracting line numbers
	
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
	int while_label_counter = 1;
	bool is_if = false;
	bool is_while = false;

    std::stringstream ss;

    std::vector <std::string> ID_Vector, vars, strConst;

    int registerCounter = 1;
    std::stack <std::string> defined_labels;
	std::stack <std::string> defined_while_labels;

    std::vector <ThreeAC> IR;


	// int variable_declaration = 0;
	// int cnt = 0;
	// int readwrite = 0;
	// int temporary = 0;
	
	// int adder[80];
	// int adder_index = 0;
	// int multiplier[80];
	// int multiplier_index = 0;

	// char* variable_type;
	// char* tbl_name[80];
	// int SCOPE = -1;
	// int num_blocks = 0 ;

	struct StrEntry{
		char* ID;
		char* Val;
		int line_num;
	};

	struct VarEntry{
		char* ID;
		char* Type;
		int line_num;
	};

	struct STable{
		char first;
		int num_variables;
		int num_strings;
		struct VarEntry var_s[80];
		struct StrEntry str_s[80];
	};
	struct CodeObject{
		char* instruction;
		char* codelist[1000];
		int num;
		char* result;
		char* type;
		char* factor;
		struct CodeObject* next;
	};

	struct STable SYMBOL_TABLE[80];

	void yyerror(const char *err);
	
	void nwl()
	{
		printf("\n");
	}
	void ASSIGN(int a, int b)
	{
		a = b;
	}
	int Increment(int a)
	{
		return a + 1;
	}
	struct CodeObject* current;


#line 183 "parser.tab.c"

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
    PROGRAM = 258,
    _BEGIN = 259,
    CONTINUE = 260,
    VOID = 261,
    INT = 262,
    FLOAT = 263,
    STRING = 264,
    READ = 265,
    WRITE = 266,
    FUNCTION = 267,
    RETURN = 268,
    IF = 269,
    ELSE = 270,
    ENDIF = 271,
    WHILE = 272,
    ENDWHILE = 273,
    BREAK = 274,
    END = 275,
    ADD_OP = 276,
    SUB_OP = 277,
    MUL_OP = 278,
    DIV_OP = 279,
    BRACKETS_OP = 280,
    BRACKETC_OP = 281,
    GEQ_OP = 282,
    LEQ_OP = 283,
    GT_OP = 284,
    LT_OP = 285,
    COMMA_OP = 286,
    SC_OP = 287,
    ASSIGN_OP = 288,
    EQ_OP = 289,
    NEQ_OP = 290,
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
#line 154 "microParser.y"

    int ival;
    float fval;
    char * sval;
    ASTNode * ASTPtr;

#line 282 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

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
       0,   169,   169,   168,   245,   299,   300,   300,   300,   305,
     347,   350,   365,   365,   366,   366,   368,   372,   372,   377,
     377,   379,   387,   387,   392,   392,   394,   393,   403,   408,
     408,   409,   409,   409,   410,   410,   410,   410,   414,   419,
     426,   437,   450,   455,   465,   475,   479,   489,   499,   503,
     503,   504,   505,   505,   507,   507,   509,   510,   514,   514,
     516,   516,   517,   517,   522,   526,   534,   521,   542,   541,
     545,   547,   573,   574,   575,   576,   577,   578,   592,   608,
     591,   622,   622,   623,   623,   623,   623,   623,   628,   628,
     632,   637,   646,   632,   654,   653,   656
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "_BEGIN", "CONTINUE", "VOID",
  "INT", "FLOAT", "STRING", "READ", "WRITE", "FUNCTION", "RETURN", "IF",
  "ELSE", "ENDIF", "WHILE", "ENDWHILE", "BREAK", "END", "ADD_OP", "SUB_OP",
  "MUL_OP", "DIV_OP", "BRACKETS_OP", "BRACKETC_OP", "GEQ_OP", "LEQ_OP",
  "GT_OP", "LT_OP", "COMMA_OP", "SC_OP", "ASSIGN_OP", "EQ_OP", "NEQ_OP",
  "IDENTIFIER", "INTLITERAL", "FLOATLITERAL", "STRINGLITERAL", "$accept",
  "program", "$@1", "id", "pgm_body", "decl", "string_decl", "str",
  "var_decl", "var_type", "any_type", "id_list", "id_tail",
  "param_decl_list", "param_decl", "param_decl_tail", "func_declarations",
  "func_decl", "$@2", "func_body", "stmt_list", "stmt", "base_stmt",
  "assign_stmt", "assign_expr", "read_stmt", "write_stmt", "return_stmt",
  "expr", "expr_prefix", "factor", "factor_prefix", "postfix_expr",
  "call_expr", "expr_list", "expr_list_tail", "primary", "addop", "mulop",
  "if_stmt", "$@3", "$@4", "$@5", "else_part", "$@6", "cond", "compop",
  "while_stmt", "$@7", "$@8", "aug_stmt_list", "aug_stmt", "$@9", "$@10",
  "aug_if_stmt", "$@11", "$@12", "$@13", "aug_else_part", "$@14", YY_NULLPTR
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

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -20,    20,  -129,    36,  -129,  -129,     6,  -129,  -129,
     -20,    25,    35,     6,     6,   -20,    19,  -129,    31,  -129,
      35,  -129,  -129,    18,    37,    24,  -129,  -129,   -20,  -129,
     -20,  -129,  -129,  -129,    38,  -129,    18,  -129,    42,  -129,
       1,   -20,    45,    46,  -129,    64,     1,  -129,     6,    46,
      65,    60,  -129,    56,    58,  -129,  -129,  -129,    51,  -129,
      65,  -129,  -129,    66,  -129,  -129,  -129,  -129,  -129,  -129,
     -20,   -20,    67,  -129,    71,    72,  -129,  -129,  -129,    74,
      76,  -129,    32,    21,  -129,  -129,  -129,    73,    75,  -129,
    -129,  -129,  -129,  -129,  -129,    81,    -1,  -129,  -129,    59,
      82,    83,  -129,  -129,    84,    85,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,     6,     6,  -129,    61,
      86,  -129,    65,    14,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,    14,  -129,    61,    98,    87,    89,
      88,    97,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
       6,   100,    91,    65,  -129,     6,  -129,    14,  -129,   103,
    -129,  -129,     6,   105,    14,  -129,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     2,     8,    13,    12,
       0,     0,    25,     8,     8,     0,     0,     3,     0,     5,
      25,     6,     7,    18,     0,     0,    15,    14,     0,    24,
       0,    16,    11,    10,     0,    26,    18,     9,     0,    17,
      20,     0,     0,    23,    21,     0,     0,    19,     8,    23,
      30,     0,    22,     0,     0,    45,    64,    78,     0,    28,
      30,    31,    34,     0,    35,    36,    37,    32,    33,    27,
       0,     0,     0,    48,     0,     0,    45,    29,    38,     0,
       0,    42,    43,     0,    45,    45,    39,     0,     0,    60,
      61,    44,    45,    58,    59,    57,    46,    50,    49,     0,
       0,     0,    40,    41,     0,    45,    62,    63,    47,    77,
      76,    73,    72,    74,    75,    45,     8,     8,    56,    55,
       0,    71,    30,    82,    45,    52,    51,    65,    86,    90,
      88,    83,    85,    79,    82,    84,    55,    70,     0,     0,
       0,     0,    81,    54,    68,    66,    87,    45,    89,    80,
       8,     0,     0,    30,    67,     8,    69,    82,    91,    96,
      94,    92,     8,     0,    82,    93,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,     2,  -129,   -13,  -129,  -129,  -129,    16,
    -129,   -10,    54,  -129,    77,    78,   102,  -129,  -129,  -129,
     -58,  -129,  -116,  -129,  -129,  -129,  -129,  -129,   -50,  -129,
    -129,  -129,  -129,  -129,  -129,   -45,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,   -81,  -129,  -113,  -129,  -129,
    -128,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    58,    11,    12,    13,    34,    14,    15,
      28,    24,    31,    42,    43,    47,    19,    20,    38,    51,
      59,    60,    61,    62,    63,    64,    65,    66,    99,    73,
      82,    83,    96,    97,   120,   125,    98,    91,   108,    67,
      74,   137,   151,   145,   150,   100,   115,    68,    75,   141,
     133,   134,   138,   140,   135,   139,   159,   163,   161,   162
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    22,    77,     4,   101,    72,   142,   131,     8,     9,
     132,     1,    16,     8,     9,    10,     3,    23,   131,   128,
       5,   132,   106,   107,    53,    54,    86,    55,   129,   158,
      35,    57,    36,   130,    27,    50,   166,    26,     8,     9,
       6,   131,   104,    44,   132,    17,    92,    18,   131,    30,
       3,   132,    25,    89,    90,   119,    41,     3,    93,    94,
      79,    80,    41,    33,   127,   121,   152,    40,    48,    32,
      37,    45,    23,    23,   136,    53,    54,    46,    55,    56,
      69,    70,    57,    71,    76,    95,   109,   110,   111,   112,
      39,   143,   124,   113,   114,   156,    84,    85,    78,    81,
      87,     3,    88,   122,   123,   102,   105,   103,   116,   117,
     118,   -53,   126,   144,   147,   149,   154,   155,   160,   146,
     148,   165,    29,    49,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,     0,     0,
       0,     0,   157,     0,     0,     0,     0,     0,     0,   164
};

static const yytype_int16 yycheck[] =
{
      13,    14,    60,     1,    85,    55,   134,   123,     7,     8,
     123,     3,    10,     7,     8,     9,    36,    15,   134,     5,
       0,   134,    23,    24,    10,    11,    76,    13,    14,   157,
      28,    17,    30,    19,    18,    48,   164,     6,     7,     8,
       4,   157,    92,    41,   157,    20,    25,    12,   164,    31,
      36,   164,    33,    21,    22,   105,    40,    36,    37,    38,
      70,    71,    46,    39,   122,   115,   147,    25,     4,    32,
      32,    26,    70,    71,   124,    10,    11,    31,    13,    14,
      20,    25,    17,    25,    33,    83,    27,    28,    29,    30,
      36,   136,    31,    34,    35,   153,    25,    25,    32,    32,
      26,    36,    26,   116,   117,    32,    25,    32,    26,    26,
      26,    26,    26,    15,    25,    18,    16,    26,    15,    32,
      32,    16,    20,    46,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   162
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    41,    36,    43,     0,     4,    42,     7,     8,
       9,    44,    45,    46,    48,    49,    43,    20,    12,    56,
      57,    45,    45,    43,    51,    33,     6,    49,    50,    56,
      31,    52,    32,    39,    47,    43,    43,    32,    58,    52,
      25,    49,    53,    54,    43,    26,    31,    55,     4,    54,
      45,    59,    55,    10,    11,    13,    14,    17,    43,    60,
      61,    62,    63,    64,    65,    66,    67,    79,    87,    20,
      25,    25,    68,    69,    80,    88,    33,    60,    32,    51,
      51,    32,    70,    71,    25,    25,    68,    26,    26,    21,
      22,    77,    25,    37,    38,    43,    72,    73,    76,    68,
      85,    85,    32,    32,    68,    25,    23,    24,    78,    27,
      28,    29,    30,    34,    35,    86,    26,    26,    26,    68,
      74,    68,    45,    45,    31,    75,    26,    60,     5,    14,
      19,    62,    87,    90,    91,    94,    68,    81,    92,    95,
      93,    89,    90,    75,    15,    83,    32,    25,    32,    18,
      84,    82,    85,    45,    16,    26,    60,    45,    90,    96,
      15,    98,    99,    97,    45,    16,    90
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
      83,    85,    86,    86,    86,    86,    86,    86,    88,    89,
      87,    90,    90,    91,    91,    91,    92,    91,    93,    91,
      95,    96,    97,    94,    99,    98,    98
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
       0,     3,     1,     1,     1,     1,     1,     1,     0,     0,
       9,     2,     0,     1,     1,     1,     0,     3,     0,     3,
       0,     0,     0,    11,     0,     4,     0
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
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
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 169 "microParser.y"
                        {
				scope.push("GLOBAL");
				
				// SCOPE = SCOPE + 1; 
				// tbl_name[SCOPE] = "GLOBAL";
				// SYMBOL_TABLE[SCOPE].first = 'c';
				// SYMBOL_TABLE[SCOPE].num_variables = 0;
				// SYMBOL_TABLE[SCOPE].num_strings = 0; 
				
				// current = malloc(sizeof(struct CodeObject()));
				// while(cnt < 1000) 
				// {
				// 	current->codelist[cnt] = malloc(400*sizeof(char));
				// 	cnt++;
				// }
				// cnt=0;
				// current->instruction = malloc(40*sizeof(char));
				// current->result = malloc(10*sizeof(char));
				// current->num = 0;
			}
#line 1709 "parser.tab.c"
    break;

  case 3:
#line 191 "microParser.y"
                        {
				scope.pop();
				
				// while(cnt<current->num)
				// {
				// 	char *str = malloc(400*sizeof(char));
				// 	strcat(str, current->codelist[i]);
				// 	char *ptr = strtok(str, " ");
				// 	if(!strcmp(ptr, "var") || !strcmp(ptr, "str")) {
				// 		printf("%s\n",current->codelist[i]);
				// 	}
				// 	else if(!strcmp(ptr, "STOREI") || !strcmp(ptr, "STORER")) {
				// 		printf("move");
				// 		while((ptr = strtok(NULL, " ")) != NULL){
				// 			printf(" %s", ptr);
				// 		}
				// 	printf("\n");
				// 	}
				// 	else if(!strcmp(ptr, "WRITEI") || !strcmp(ptr, "READI") || !strcmp(ptr, "WRITES") || !strcmp(ptr, "WRITER") || !strcmp(ptr, "READR")) {
				// 		printf("sys ");
				// 		char c;
				// 		while((c = *ptr))  {
				// 	      printf("%c", tolower(c));
				// 	      ptr = ptr + 1;
				// 	    }   
				// 		while((ptr = strtok(NULL, " ")) != NULL){
				// 			printf(" %s", ptr);
				// 		}
				// 		printf("\n");
				// 		}
				// 	else {
				// 		printf("move");
				// 		char *inst = malloc(50*sizeof(char));
				// 		char *rem = malloc(50*sizeof(char));
				// 		inst = ptr;
				// 		while(*ptr)  {
				// 			*ptr = tolower(*ptr);
				// 	    	ptr = ptr + 1;
				// 	    }    
				// 		ptr = strtok(NULL, " ");
				// 		printf(" %s", ptr);
				// 		ptr = strtok(NULL, " ");
				// 	    strcat(rem, ptr);
				// 		ptr = strtok(NULL, " ");
				// 		printf(" %s", ptr);
				// 	    strcat(rem, " ");
				// 	    strcat(rem, ptr);
				// 		printf("\n%s %s\n", inst, rem);    
				// 		}
				// 	}

				// printf("sys halt\n"); 
			}
#line 1767 "parser.tab.c"
    break;

  case 4:
#line 245 "microParser.y"
                           {
					(yyval.sval) = (yyvsp[0].sval);
				// if(variable_declaration==1 && scope == 0){
				// 	current->codelist[current->num] = malloc(400*sizeof(char));
				// 	strcat(current->codelist[current->num], "var "); 
				// 	strcat(current->codelist[current->num], $$); 
				// 	current->num++;
				// }
				// else if(readwrite == 1){
				// 	current->codelist[current->num] = malloc(400*sizeof(char));
				// 	strcat(current->codelist[current->num], current->instruction); 
				// 	int i;
				// 	for(i = 0; i < SYMBOL_TABLE[SCOPE].num_strings; i++ ){
				// 		if(!strcmp(SYMBOL_TABLE[SCOPE].str_s[i].ID,$$)){
				// 			strcat(current->codelist[current->num], "S ");
				// 			break;
				// 		}
				// 	}
				// 	if(i == SYMBOL_TABLE[SCOPE].num_strs){
				// 		for(i = 0; i < SYMBOL_TABLE[SCOPE].num_strings; i++ ){
				// 			if(!strcmp(SYMBOL_TABLE[0].str_s[i].ID,$$)){
				// 				strcat(current->codelist[current->num], "S ");
				// 				break;
				// 			}
				// 		}
				// 	}
				// 	for(i = 0; i < SYMBOL_TABLE[SCOPE].num_variables; i++ ){
				// 		if(!strcmp(SYMBOL_TABLE[SCOPE].var_s[i].ID,$$)){
				// 			if(!strcmp(SYMBOL_TABLE[SCOPE].var_s[i].Type,"INT")){
				// 				strcat(current->codelist[current->num], "I ");
				// 			}
				// 			else{
				// 				strcat(current->codelist[current->num], "R ");
				// 			}
				// 			break;
				// 		}
				// 	}
				// 	if(i == SYMBOL_TABLE[SCOPE].num_vars){
				// 		for(i = 0; i < SYMBOL_TABLE[0].num_variables; i++ ){
				// 			if(!strcmp(SYMBOL_TABLE[0].var_s[i].ID,$$)){
				// 				if(!strcmp(SYMBOL_TABLE[0].var_s[i].Type,"INT")){
				// 					strcat(current->codelist[current->num], "I ");
				// 				}
				// 				else{
				// 					strcat(current->codelist[current->num], "R ");
				// 				}
				// 				break;
				// 			}
				// 		}
				// 	}
				// 	strcat(current->codelist[current->num], $$); 
				// 	current->num++;
				// }
			}
#line 1826 "parser.tab.c"
    break;

  case 8:
#line 300 "microParser.y"
                                                          {
		    	addSymbolTable();
		    }
#line 1834 "parser.tab.c"
    break;

  case 9:
#line 306 "microParser.y"
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
										
										// if(SYMBOL_TABLE[SCOPE].first == 'c')
										// {
										// 	SYMBOL_TABLE[SCOPE].first = 's';
										// }
											
										// for(int i = 0; i <= SYMBOL_TABLE[SCOPE].num_strings - 1; i++ ){
										// 	if(!strcmp(SYMBOL_TABLE[SCOPE].str_s[i].ID,$2))
										// 	{
										// 		printf("DECLARATION ERROR %s",$2);
										// 		// printf("(previous declaration was at line %d)", SYMBOL_TABLE[SCOPE].str_s[i].line_num);
										// 		nwl();
										// 		return 0;
										// 	}
										// }
										// for(int i = 0; i <= SYMBOL_TABLE[SCOPE].num_variables - 1; i++ ){
										// 	if(!strcmp(SYMBOL_TABLE[SCOPE].var_s[i].ID,$2)){
										// 		printf("DECLARATION ERROR %s", $2);
										// 		nwl();
										// 		return 0;
										// 	}
										// }
										// $$ = malloc(sizeof(struct StrEntry())); 
										// $$->ID = $2; 
										// $$->line_num = yylineno; 
										// $$->Val = $4; 
										// SYMBOL_TABLE[SCOPE].str_s[SYMBOL_TABLE[SCOPE].num_strings] = *($<s_entry>$); 
										// SYMBOL_TABLE[SCOPE].num_strings = Increment(SYMBOL_TABLE[SCOPE].num_strings);
										// printf("str %s %s\n",$2,$4);//
									}
#line 1879 "parser.tab.c"
    break;

  case 10:
#line 347 "microParser.y"
                              {(yyval.sval) = (yyvsp[0].sval);}
#line 1885 "parser.tab.c"
    break;

  case 11:
#line 351 "microParser.y"
                                        {
						for(typename std::vector <std::string>::reverse_iterator itr = ID_Vector.rbegin(); itr != ID_Vector.rend(); ++itr){
							w.value[0] = (yyvsp[-2].sval);
							w.value[1] = "";
							r = table.insert(std::pair<std::string, wrapper> (*itr, w));
							if(!r.second){
								std::string temp = *itr;
								yyerror(temp.c_str());
							}
							vars.push_back(*itr);
						}
						ID_Vector.clear();
		    		}
#line 1903 "parser.tab.c"
    break;

  case 12:
#line 365 "microParser.y"
                      {  }
#line 1909 "parser.tab.c"
    break;

  case 13:
#line 365 "microParser.y"
                                 { }
#line 1915 "parser.tab.c"
    break;

  case 16:
#line 368 "microParser.y"
                           {
						ID_Vector.push_back((yyvsp[-1].sval));
				}
#line 1923 "parser.tab.c"
    break;

  case 17:
#line 372 "microParser.y"
                                    {ID_Vector.push_back((yyvsp[-1].sval));}
#line 1929 "parser.tab.c"
    break;

  case 21:
#line 379 "microParser.y"
                            {
						w.value[0] = (yyvsp[-1].sval);
						w.value[1] = "";
						r = table.insert(std::pair<std::string, wrapper>((yyvsp[0].sval), w));
						if(!r.second){
							yyerror((yyvsp[0].sval));
						}
			}
#line 1942 "parser.tab.c"
    break;

  case 26:
#line 394 "microParser.y"
                                                                {
									scope.push((yyvsp[0].sval));
									ss.str("");
									ss << (yyvsp[0].sval);
									IR.push_back(ThreeAC("LABEL", "", "", ss.str()));
								}
#line 1953 "parser.tab.c"
    break;

  case 27:
#line 400 "microParser.y"
                                                                                                                            {
									scope.pop();
								}
#line 1961 "parser.tab.c"
    break;

  case 38:
#line 414 "microParser.y"
                                  {
		    	makeIR((yyvsp[-1].ASTPtr));
		    	removeAST((yyvsp[-1].ASTPtr));
		    }
#line 1970 "parser.tab.c"
    break;

  case 39:
#line 419 "microParser.y"
                                  {
		    	std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = (yyvsp[-2].sval);
		    	ASTNodeVar * node = new ASTNodeVar(key, mapp[key].value[0]);
		    	(yyval.ASTPtr) = new ASTNodeOp("=", node, (yyvsp[0].ASTPtr));
		    }
#line 1981 "parser.tab.c"
    break;

  case 40:
#line 426 "microParser.y"
                                                           {
				for(typename std::vector <std::string>::reverse_iterator itr = ID_Vector.rbegin(); itr != ID_Vector.rend(); ++itr){
					std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
					if (mapp[*itr].value[0] == "INT")
						IR.push_back(ThreeAC("READI", "", "", *itr));
					else
						IR.push_back(ThreeAC("READF", "", "", *itr));
					}
					ID_Vector.clear();
		    }
#line 1996 "parser.tab.c"
    break;

  case 41:
#line 437 "microParser.y"
                                                            {
		    	for(typename std::vector <std::string>::reverse_iterator itr = ID_Vector.rbegin(); itr != ID_Vector.rend(); ++itr){
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
				if (mapp[*itr].value[0] == "INT")
					IR.push_back(ThreeAC("WRITEI", "", "", *itr));
				else if (mapp[*itr].value[0] == "FLOAT")
					IR.push_back(ThreeAC("WRITEF", "", "", *itr));
				else
					IR.push_back(ThreeAC("WRITES", "", "", *itr));
			}
			ID_Vector.clear();
		    }
#line 2013 "parser.tab.c"
    break;

  case 43:
#line 455 "microParser.y"
                                   {
		    	if((yyvsp[-1].ASTPtr) != NULL){
		    		(yyvsp[-1].ASTPtr)->right = (yyvsp[0].ASTPtr);
		    		(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);
		    	}
		    	else{
		    		(yyval.ASTPtr) = (yyvsp[0].ASTPtr);
		    	}
		    }
#line 2027 "parser.tab.c"
    break;

  case 44:
#line 465 "microParser.y"
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
#line 2042 "parser.tab.c"
    break;

  case 45:
#line 475 "microParser.y"
                                                 {
						(yyval.ASTPtr) = NULL;
		    }
#line 2050 "parser.tab.c"
    break;

  case 46:
#line 479 "microParser.y"
                                           {
		    	if((yyvsp[-1].ASTPtr) != NULL){
		    		(yyvsp[-1].ASTPtr)->right = (yyvsp[0].ASTPtr);
		    		(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);
		    	}
		    	else{
		    		(yyval.ASTPtr) = (yyvsp[0].ASTPtr);
		    	}
		    }
#line 2064 "parser.tab.c"
    break;

  case 47:
#line 489 "microParser.y"
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
#line 2079 "parser.tab.c"
    break;

  case 48:
#line 499 "microParser.y"
                             {
		    	(yyval.ASTPtr) = NULL;
		    }
#line 2087 "parser.tab.c"
    break;

  case 49:
#line 503 "microParser.y"
                        {(yyval.ASTPtr) = (yyvsp[0].ASTPtr);}
#line 2093 "parser.tab.c"
    break;

  case 50:
#line 503 "microParser.y"
                                               {(yyval.ASTPtr) = (yyvsp[0].ASTPtr);}
#line 2099 "parser.tab.c"
    break;

  case 51:
#line 504 "microParser.y"
                                                     {(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);}
#line 2105 "parser.tab.c"
    break;

  case 52:
#line 505 "microParser.y"
                                    {(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);}
#line 2111 "parser.tab.c"
    break;

  case 53:
#line 505 "microParser.y"
                                                        {(yyval.ASTPtr) = NULL;}
#line 2117 "parser.tab.c"
    break;

  case 54:
#line 507 "microParser.y"
                                             {(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);}
#line 2123 "parser.tab.c"
    break;

  case 55:
#line 507 "microParser.y"
                                                                 {(yyval.ASTPtr) = NULL;}
#line 2129 "parser.tab.c"
    break;

  case 56:
#line 509 "microParser.y"
                                             {(yyval.ASTPtr) = (yyvsp[-1].ASTPtr);}
#line 2135 "parser.tab.c"
    break;

  case 57:
#line 510 "microParser.y"
                           {
				std::map <std::string, wrapper> mapp = symbolTable["GLOBAL"];
		    	std::string key = (yyvsp[0].sval);
		    	(yyval.ASTPtr) = new ASTNodeVar(key, mapp[key].value[0]);
			}
#line 2145 "parser.tab.c"
    break;

  case 58:
#line 514 "microParser.y"
                                      {(yyval.ASTPtr) = new ASTNodeInt((yyvsp[0].sval));}
#line 2151 "parser.tab.c"
    break;

  case 59:
#line 514 "microParser.y"
                                                                               {(yyval.ASTPtr) = new ASTNodeFloat((yyvsp[0].sval));}
#line 2157 "parser.tab.c"
    break;

  case 60:
#line 516 "microParser.y"
                       {(yyval.ASTPtr) = new ASTNodeOp("+");}
#line 2163 "parser.tab.c"
    break;

  case 61:
#line 516 "microParser.y"
                                                           {(yyval.ASTPtr) = new ASTNodeOp("-");}
#line 2169 "parser.tab.c"
    break;

  case 62:
#line 517 "microParser.y"
                       { (yyval.ASTPtr) = new ASTNodeOp("*");}
#line 2175 "parser.tab.c"
    break;

  case 63:
#line 517 "microParser.y"
                                                            { (yyval.ASTPtr) = new ASTNodeOp("/");}
#line 2181 "parser.tab.c"
    break;

  case 64:
#line 522 "microParser.y"
                                {
					is_if = true;
					pushBlock();
				}
#line 2190 "parser.tab.c"
    break;

  case 65:
#line 526 "microParser.y"
                                                                            {
					ss.str("");
					ss << "label" << labelCounter++;
					IR.push_back(ThreeAC("JUMP", "", "", ss.str()));
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
					defined_labels.pop();
					defined_labels.push(ss.str());
				}
#line 2203 "parser.tab.c"
    break;

  case 66:
#line 534 "microParser.y"
                                          {
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
		    		defined_labels.pop();
				}
#line 2212 "parser.tab.c"
    break;

  case 67:
#line 537 "microParser.y"
                                        {
					scope.pop();
				}
#line 2220 "parser.tab.c"
    break;

  case 68:
#line 542 "microParser.y"
                                {
					pushBlock();
				}
#line 2228 "parser.tab.c"
    break;

  case 69:
#line 545 "microParser.y"
                                               {scope.pop();}
#line 2234 "parser.tab.c"
    break;

  case 71:
#line 547 "microParser.y"
                                 {
								std::string t;
									std::string op1 = CondExprIR((yyvsp[-2].ASTPtr), &t);
									IR.push_back(ThreeAC("", "", "", "", "SAVE"));
									std::string op2 = CondExprIR((yyvsp[0].ASTPtr), &t);
									ss.str("");
									if(is_if)
									{
										ss << "label" << labelCounter++;
										IR.push_back(ThreeAC((yyvsp[-1].sval), op1, op2, ss.str(), t)); 
										defined_labels.push(ss.str());
										is_if = false; 
									}
									 
									if(is_while)
									{
										ss << "labelw" << while_label_counter++;
										IR.push_back(ThreeAC((yyvsp[-1].sval), op1, op2, ss.str(), t)); 
										defined_while_labels.push(ss.str());
										is_while = false; 
									}
									
									removeAST((yyvsp[-2].ASTPtr)); 
									removeAST((yyvsp[0].ASTPtr));
							}
#line 2264 "parser.tab.c"
    break;

  case 72:
#line 573 "microParser.y"
                      {(yyval.sval) = (char *) "GE";}
#line 2270 "parser.tab.c"
    break;

  case 73:
#line 574 "microParser.y"
                              {(yyval.sval) = (char *) "LE"; }
#line 2276 "parser.tab.c"
    break;

  case 74:
#line 575 "microParser.y"
                             {(yyval.sval) = (char *) "NE"; }
#line 2282 "parser.tab.c"
    break;

  case 75:
#line 576 "microParser.y"
                              {(yyval.sval) = (char *) "EQ"; }
#line 2288 "parser.tab.c"
    break;

  case 76:
#line 577 "microParser.y"
                              {(yyval.sval) = (char *) "GT"; }
#line 2294 "parser.tab.c"
    break;

  case 77:
#line 578 "microParser.y"
                               {(yyval.sval) = (char *) "LT"; }
#line 2300 "parser.tab.c"
    break;

  case 78:
#line 592 "microParser.y"
                                        {
						is_while = true;
						
						pushBlock();
						ss.str("");
						ss << "labelw" << while_label_counter++;
						defined_while_labels.push(ss.str());
						IR.push_back(ThreeAC("LABEL", "", "", ss.str()));
						// SCOPE = SCOPE + 1; 
						// tbl_name[SCOPE] = "BLOCK ";
						// SYMBOL_TABLE[SCOPE].first = 'c'; 
						// SYMBOL_TABLE[SCOPE].num_strings = 0; 
						// SYMBOL_TABLE[SCOPE].num_variables = 0; 
	
					}
#line 2320 "parser.tab.c"
    break;

  case 79:
#line 608 "microParser.y"
                                        {
						// makeIR($5);
		    			// removeAST($5);
						std::string temp = defined_while_labels.top();
						defined_while_labels.pop();
						IR.push_back(ThreeAC("JUMP", "", "", defined_while_labels.top()));
						defined_while_labels.push(temp);
						IR.push_back(ThreeAC("LABEL", "", "", temp));
					}
#line 2334 "parser.tab.c"
    break;

  case 80:
#line 616 "microParser.y"
                                                   {
							// IR.push_back(ThreeAC("LABEL", "", "", defined_while_labels.top()));
							// defined_while_labels.pop();
							scope.pop();
						}
#line 2344 "parser.tab.c"
    break;

  case 86:
#line 623 "microParser.y"
                                                               {
	std::string temp = defined_while_labels.top();
	defined_while_labels.pop();
	IR.push_back(ThreeAC("JUMP", "", "", defined_while_labels.top()));
	defined_while_labels.push(temp);
}
#line 2355 "parser.tab.c"
    break;

  case 88:
#line 628 "microParser.y"
               {
	IR.push_back(ThreeAC("JUMP", "", "", defined_while_labels.top()));
}
#line 2363 "parser.tab.c"
    break;

  case 90:
#line 632 "microParser.y"
                   {
					is_if = true;
					pushBlock();
					}
#line 2372 "parser.tab.c"
    break;

  case 91:
#line 637 "microParser.y"
                                {
					ss.str("");
					ss << "label" << labelCounter++;
					IR.push_back(ThreeAC("JUMP", "", "", ss.str()));
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
					defined_labels.pop();
					defined_labels.push(ss.str());
				}
#line 2385 "parser.tab.c"
    break;

  case 92:
#line 646 "microParser.y"
                                {
					IR.push_back(ThreeAC("LABEL", "", "", defined_labels.top()));
		    		defined_labels.pop();
				}
#line 2394 "parser.tab.c"
    break;

  case 93:
#line 650 "microParser.y"
                                      {
					scope.pop();
				}
#line 2402 "parser.tab.c"
    break;

  case 94:
#line 654 "microParser.y"
                                {
					pushBlock();
				}
#line 2410 "parser.tab.c"
    break;

  case 95:
#line 656 "microParser.y"
                                                     {scope.pop();}
#line 2416 "parser.tab.c"
    break;


#line 2420 "parser.tab.c"

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 658 "microParser.y"
