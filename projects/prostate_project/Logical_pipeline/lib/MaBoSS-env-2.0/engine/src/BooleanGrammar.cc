
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with CTBNDL or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 2 "BooleanGrammar.y"

/* 
   MaBoSS (Markov Boolean Stochastic Simulator)
   Copyright (C) 2011 Institut Curie, 26 rue d'Ulm, Paris, France
   
   MaBoSS is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
   
   MaBoSS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA 
*/

/*
   Module:
     BooleanGrammar.y

   Authors:
     Eric Viara <viara@sysra.com>
     Gautier Stoll <gautier.stoll@curie.fr>
 
   Date:
     January-March 2011
*/

#include "BooleanGrammar.h"

extern int CTBNDLlex();
static void CTBNDLerror(const char *s);
MAP<std::string, bool> NodeDecl::node_def_map;
static Network* current_network;


/* Line 189 of yacc.c  */
#line 114 "BooleanGrammar.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum CTBNDLtokentype {
     IDENTIFIER = 258,
     VARIABLE = 259,
     STRING = 260,
     DOUBLE = 261,
     INTEGER = 262,
     LOGAND = 263,
     LOGOR = 264,
     LOGXOR = 265,
     LOGNOT = 266,
     EQUAL = 267,
     NOT_EQUAL = 268,
     NODE = 269,
     GTEQ = 270,
     LTEQ = 271
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 42 "BooleanGrammar.y"

  std::vector<NodeDecl*>* node_decl_list;
  NodeDecl* node_decl;
  std::vector<NodeDeclItem*>* node_decl_item_list;
  NodeDeclItem* node_decl_item;
  Expression* expr;
  char* str;
  double d;
  long long l;



/* Line 214 of yacc.c  */
#line 179 "BooleanGrammar.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define CTBNDLstype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "BooleanGrammar.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 CTBNDLtype_uint8;
#else
typedef unsigned char CTBNDLtype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 CTBNDLtype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char CTBNDLtype_int8;
#else
typedef short int CTBNDLtype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 CTBNDLtype_uint16;
#else
typedef unsigned short int CTBNDLtype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 CTBNDLtype_int16;
#else
typedef short int CTBNDLtype_int16;
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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int CTBNDLi)
#else
static int
YYID (CTBNDLi)
    int CTBNDLi;
#endif
{
  return CTBNDLi;
}
#endif

#if ! defined CTBNDLoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined CTBNDLoverflow || YYERROR_VERBOSE */


#if (! defined CTBNDLoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union CTBNDLalloc
{
  CTBNDLtype_int16 CTBNDLss_alloc;
  YYSTYPE CTBNDLvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union CTBNDLalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (CTBNDLtype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T CTBNDLi;				\
	  for (CTBNDLi = 0; CTBNDLi < (Count); CTBNDLi++)	\
	    (To)[CTBNDLi] = (From)[CTBNDLi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T CTBNDLnewbytes;						\
	YYCOPY (&CTBNDLptr->Stack_alloc, Stack, CTBNDLsize);			\
	Stack = &CTBNDLptr->Stack_alloc;					\
	CTBNDLnewbytes = CTBNDLstacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	CTBNDLptr += CTBNDLnewbytes / sizeof (*CTBNDLptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   79

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNRULES -- Number of states.  */
#define YYNSTATES  84

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   271

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? CTBNDLtranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const CTBNDLtype_uint8 CTBNDLtranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,     2,     2,     2,     2,     2,
      23,    24,    28,    25,     2,    26,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    19,    21,
      30,    20,    31,    33,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const CTBNDLtype_uint8 CTBNDLprhs[] =
{
       0,     0,     3,     5,     8,    14,    19,    24,    26,    29,
      34,    39,    41,    44,    46,    48,    50,    54,    56,    58,
      61,    64,    67,    70,    72,    76,    80,    82,    86,    90,
      92,    96,   100,   104,   108,   110,   114,   118,   120,   124,
     126,   130,   132,   136,   140,   142,   148,   150,   151
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const CTBNDLtype_int8 CTBNDLrhs[] =
{
      35,     0,    -1,    36,    -1,    35,    36,    -1,    14,     3,
      17,    37,    18,    -1,    14,     3,    17,    18,    -1,     3,
      19,    50,    51,    -1,    38,    -1,    37,    38,    -1,     3,
      20,    50,    21,    -1,     3,    20,     5,    21,    -1,     3,
      -1,    22,     3,    -1,     4,    -1,     7,    -1,     6,    -1,
      23,    50,    24,    -1,    39,    -1,    40,    -1,    25,    41,
      -1,    26,    41,    -1,    27,    41,    -1,    11,    41,    -1,
      41,    -1,    42,    28,    41,    -1,    42,    29,    41,    -1,
      42,    -1,    43,    25,    42,    -1,    43,    26,    42,    -1,
      43,    -1,    44,    30,    43,    -1,    44,    31,    43,    -1,
      44,    16,    43,    -1,    44,    15,    43,    -1,    44,    -1,
      45,    12,    44,    -1,    45,    13,    44,    -1,    45,    -1,
      46,     8,    45,    -1,    46,    -1,    47,     9,    46,    -1,
      47,    -1,    48,    10,    47,    -1,    48,    32,    47,    -1,
      48,    -1,    48,    33,    50,    19,    49,    -1,    49,    -1,
      -1,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const CTBNDLtype_uint16 CTBNDLrline[] =
{
       0,    79,    79,    84,    91,    95,    99,   108,   113,   120,
     124,   130,   135,   139,   143,   147,   151,   157,   187,   191,
     195,   199,   203,   209,   213,   217,   223,   227,   231,   237,
     241,   245,   249,   253,   259,   263,   267,   273,   277,   283,
     287,   293,   297,   301,   307,   311,   317,   323,   324
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const CTBNDLtname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "VARIABLE", "STRING",
  "DOUBLE", "INTEGER", "LOGAND", "LOGOR", "LOGXOR", "LOGNOT", "EQUAL",
  "NOT_EQUAL", "NODE", "GTEQ", "LTEQ", "'{'", "'}'", "':'", "'='", "';'",
  "'@'", "'('", "')'", "'+'", "'-'", "'!'", "'*'", "'/'", "'<'", "'>'",
  "'^'", "'?'", "$accept", "translation_unit", "node_decl",
  "node_decl_item_list", "node_decl_item", "primary_expression",
  "postfix_expression", "unary_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression",
  "logical_xor_expression", "conditional_expression", "expression",
  "term_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const CTBNDLtype_uint16 CTBNDLtoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   123,   125,    58,
      61,    59,    64,    40,    41,    43,    45,    33,    42,    47,
      60,    62,    94,    63
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const CTBNDLtype_uint8 CTBNDLr1[] =
{
       0,    34,    35,    35,    36,    36,    36,    37,    37,    38,
      38,    39,    39,    39,    39,    39,    39,    40,    41,    41,
      41,    41,    41,    42,    42,    42,    43,    43,    43,    44,
      44,    44,    44,    44,    45,    45,    45,    46,    46,    47,
      47,    48,    48,    48,    49,    49,    50,    51,    51
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const CTBNDLtype_uint8 CTBNDLr2[] =
{
       0,     2,     1,     2,     5,     4,     4,     1,     2,     4,
       4,     1,     2,     1,     1,     1,     3,     1,     1,     2,
       2,     2,     2,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     5,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const CTBNDLtype_uint8 CTBNDLdefact[] =
{
       0,     0,     0,     0,     2,     0,     0,     1,     3,    11,
      13,    15,    14,     0,     0,     0,     0,     0,     0,    17,
      18,    23,    26,    29,    34,    37,    39,    41,    44,    46,
      47,     0,    22,    12,     0,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     6,     0,     5,     0,     7,    16,
      24,    25,    27,    28,    33,    32,    30,    31,    35,    36,
      38,    40,    42,    43,     0,     0,     4,     8,     0,     0,
       0,    45,    10,     9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const CTBNDLtype_int8 CTBNDLdefgoto[] =
{
      -1,     3,     4,    57,    58,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -16
static const CTBNDLtype_int8 CTBNDLpact[] =
{
      20,   -11,    39,    16,   -16,    32,    36,   -16,   -16,   -16,
     -16,   -16,   -16,    32,    45,    32,    32,    32,    32,   -16,
     -16,   -16,   -14,    -5,    31,    28,    48,    58,    -8,   -16,
      47,     0,   -16,   -16,    46,   -16,   -16,   -16,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,   -16,   -16,    49,   -16,     4,   -16,   -16,
     -16,   -16,   -14,   -14,    -5,    -5,    -5,    -5,    31,    31,
      28,    48,    58,    58,    52,     6,   -16,   -16,    32,    51,
      53,   -16,   -16,   -16
};

/* YYPGOTO[NTERM-NUM].  */
static const CTBNDLtype_int8 CTBNDLpgoto[] =
{
     -16,   -16,    70,   -16,    18,   -16,   -16,   -12,    23,     7,
      -2,    29,    27,    15,   -16,     1,   -15,   -16
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const CTBNDLtype_uint8 CTBNDLtable[] =
{
      34,    32,    50,    55,    35,    36,    37,    55,     5,     9,
      10,    79,    11,    12,    38,    39,     7,    13,    56,     1,
      40,    41,    76,     1,    51,    52,    60,    61,    14,    15,
       2,    16,    17,    18,     2,     9,    10,    74,    11,    12,
      46,    47,     6,    13,    68,    69,    42,    43,    33,    64,
      65,    66,    67,    31,    14,    15,    48,    16,    17,    18,
      80,    44,    45,    62,    63,    72,    73,    49,    53,    75,
      59,    78,    82,     8,    83,    77,    71,    70,     0,    81
};

static const CTBNDLtype_int8 CTBNDLcheck[] =
{
      15,    13,    10,     3,    16,    17,    18,     3,    19,     3,
       4,     5,     6,     7,    28,    29,     0,    11,    18,     3,
      25,    26,    18,     3,    32,    33,    38,    39,    22,    23,
      14,    25,    26,    27,    14,     3,     4,    52,     6,     7,
      12,    13,     3,    11,    46,    47,    15,    16,     3,    42,
      43,    44,    45,    17,    22,    23,     8,    25,    26,    27,
      75,    30,    31,    40,    41,    50,    51,     9,    21,    20,
      24,    19,    21,     3,    21,    57,    49,    48,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const CTBNDLtype_uint8 CTBNDLstos[] =
{
       0,     3,    14,    35,    36,    19,     3,     0,    36,     3,
       4,     6,     7,    11,    22,    23,    25,    26,    27,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    17,    41,     3,    50,    41,    41,    41,    28,    29,
      25,    26,    15,    16,    30,    31,    12,    13,     8,     9,
      10,    32,    33,    21,    51,     3,    18,    37,    38,    24,
      41,    41,    42,    42,    43,    43,    43,    43,    44,    44,
      45,    46,    47,    47,    50,    20,    18,    38,    19,     5,
      50,    49,    21,    21
};

#define CTBNDLerrok		(CTBNDLerrstatus = 0)
#define CTBNDLclearin	(CTBNDLchar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto CTBNDLacceptlab
#define YYABORT		goto CTBNDLabortlab
#define YYERROR		goto CTBNDLerrorlab


/* Like YYERROR except do call CTBNDLerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto CTBNDLerrlab

#define YYRECOVERING()  (!!CTBNDLerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (CTBNDLchar == YYEMPTY && CTBNDLlen == 1)				\
    {								\
      CTBNDLchar = (Token);						\
      CTBNDLlval = (Value);						\
      CTBNDLtoken = YYTRANSLATE (CTBNDLchar);				\
      YYPOPSTACK (1);						\
      goto CTBNDLbackup;						\
    }								\
  else								\
    {								\
      CTBNDLerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `CTBNDLlex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX CTBNDLlex (YYLEX_PARAM)
#else
# define YYLEX CTBNDLlex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (CTBNDLdebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (CTBNDLdebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      CTBNDL_symbol_print (stderr,						  \
		  Type, Value); \
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
CTBNDL_symbol_value_print (FILE *CTBNDLoutput, int CTBNDLtype, YYSTYPE const * const CTBNDLvaluep)
#else
static void
CTBNDL_symbol_value_print (CTBNDLoutput, CTBNDLtype, CTBNDLvaluep)
    FILE *CTBNDLoutput;
    int CTBNDLtype;
    YYSTYPE const * const CTBNDLvaluep;
#endif
{
  if (!CTBNDLvaluep)
    return;
# ifdef YYPRINT
  if (CTBNDLtype < YYNTOKENS)
    YYPRINT (CTBNDLoutput, CTBNDLtoknum[CTBNDLtype], *CTBNDLvaluep);
# else
  YYUSE (CTBNDLoutput);
# endif
  switch (CTBNDLtype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
CTBNDL_symbol_print (FILE *CTBNDLoutput, int CTBNDLtype, YYSTYPE const * const CTBNDLvaluep)
#else
static void
CTBNDL_symbol_print (CTBNDLoutput, CTBNDLtype, CTBNDLvaluep)
    FILE *CTBNDLoutput;
    int CTBNDLtype;
    YYSTYPE const * const CTBNDLvaluep;
#endif
{
  if (CTBNDLtype < YYNTOKENS)
    YYFPRINTF (CTBNDLoutput, "token %s (", CTBNDLtname[CTBNDLtype]);
  else
    YYFPRINTF (CTBNDLoutput, "nterm %s (", CTBNDLtname[CTBNDLtype]);

  CTBNDL_symbol_value_print (CTBNDLoutput, CTBNDLtype, CTBNDLvaluep);
  YYFPRINTF (CTBNDLoutput, ")");
}

/*------------------------------------------------------------------.
| CTBNDL_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
CTBNDL_stack_print (CTBNDLtype_int16 *CTBNDLbottom, CTBNDLtype_int16 *CTBNDLtop)
#else
static void
CTBNDL_stack_print (CTBNDLbottom, CTBNDLtop)
    CTBNDLtype_int16 *CTBNDLbottom;
    CTBNDLtype_int16 *CTBNDLtop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; CTBNDLbottom <= CTBNDLtop; CTBNDLbottom++)
    {
      int CTBNDLbot = *CTBNDLbottom;
      YYFPRINTF (stderr, " %d", CTBNDLbot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (CTBNDLdebug)							\
    CTBNDL_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
CTBNDL_reduce_print (YYSTYPE *CTBNDLvsp, int CTBNDLrule)
#else
static void
CTBNDL_reduce_print (CTBNDLvsp, CTBNDLrule)
    YYSTYPE *CTBNDLvsp;
    int CTBNDLrule;
#endif
{
  int CTBNDLnrhs = CTBNDLr2[CTBNDLrule];
  int CTBNDLi;
  unsigned long int CTBNDLlno = CTBNDLrline[CTBNDLrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     CTBNDLrule - 1, CTBNDLlno);
  /* The symbols being reduced.  */
  for (CTBNDLi = 0; CTBNDLi < CTBNDLnrhs; CTBNDLi++)
    {
      YYFPRINTF (stderr, "   $%d = ", CTBNDLi + 1);
      CTBNDL_symbol_print (stderr, CTBNDLrhs[CTBNDLprhs[CTBNDLrule] + CTBNDLi],
		       &(CTBNDLvsp[(CTBNDLi + 1) - (CTBNDLnrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (CTBNDLdebug)				\
    CTBNDL_reduce_print (CTBNDLvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int CTBNDLdebug;
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

# ifndef CTBNDLstrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define CTBNDLstrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
CTBNDLstrlen (const char *CTBNDLstr)
#else
static YYSIZE_T
CTBNDLstrlen (CTBNDLstr)
    const char *CTBNDLstr;
#endif
{
  YYSIZE_T CTBNDLlen;
  for (CTBNDLlen = 0; CTBNDLstr[CTBNDLlen]; CTBNDLlen++)
    continue;
  return CTBNDLlen;
}
#  endif
# endif

# ifndef CTBNDLstpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define CTBNDLstpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
CTBNDLstpcpy (char *CTBNDLdest, const char *CTBNDLsrc)
#else
static char *
CTBNDLstpcpy (CTBNDLdest, CTBNDLsrc)
    char *CTBNDLdest;
    const char *CTBNDLsrc;
#endif
{
  char *CTBNDLd = CTBNDLdest;
  const char *CTBNDLs = CTBNDLsrc;

  while ((*CTBNDLd++ = *CTBNDLs++) != '\0')
    continue;

  return CTBNDLd - 1;
}
#  endif
# endif

# ifndef CTBNDLtnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for CTBNDLerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from CTBNDLtname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
CTBNDLtnamerr (char *CTBNDLres, const char *CTBNDLstr)
{
  if (*CTBNDLstr == '"')
    {
      YYSIZE_T CTBNDLn = 0;
      char const *CTBNDLp = CTBNDLstr;

      for (;;)
	switch (*++CTBNDLp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++CTBNDLp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (CTBNDLres)
	      CTBNDLres[CTBNDLn] = *CTBNDLp;
	    CTBNDLn++;
	    break;

	  case '"':
	    if (CTBNDLres)
	      CTBNDLres[CTBNDLn] = '\0';
	    return CTBNDLn;
	  }
    do_not_strip_quotes: ;
    }

  if (! CTBNDLres)
    return CTBNDLstrlen (CTBNDLstr);

  return CTBNDLstpcpy (CTBNDLres, CTBNDLstr) - CTBNDLres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
CTBNDLsyntax_error (char *CTBNDLresult, int CTBNDLstate, int CTBNDLchar)
{
  int CTBNDLn = CTBNDLpact[CTBNDLstate];

  if (! (YYPACT_NINF < CTBNDLn && CTBNDLn <= YYLAST))
    return 0;
  else
    {
      int CTBNDLtype = YYTRANSLATE (CTBNDLchar);
      YYSIZE_T CTBNDLsize0 = CTBNDLtnamerr (0, CTBNDLtname[CTBNDLtype]);
      YYSIZE_T CTBNDLsize = CTBNDLsize0;
      YYSIZE_T CTBNDLsize1;
      int CTBNDLsize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *CTBNDLarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int CTBNDLx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *CTBNDLfmt;
      char const *CTBNDLf;
      static char const CTBNDLunexpected[] = "syntax error, unexpected %s";
      static char const CTBNDLexpecting[] = ", expecting %s";
      static char const CTBNDLor[] = " or %s";
      char CTBNDLformat[sizeof CTBNDLunexpected
		    + sizeof CTBNDLexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof CTBNDLor - 1))];
      char const *CTBNDLprefix = CTBNDLexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int CTBNDLxbegin = CTBNDLn < 0 ? -CTBNDLn : 0;

      /* Stay within bounds of both CTBNDLcheck and CTBNDLtname.  */
      int CTBNDLchecklim = YYLAST - CTBNDLn + 1;
      int CTBNDLxend = CTBNDLchecklim < YYNTOKENS ? CTBNDLchecklim : YYNTOKENS;
      int CTBNDLcount = 1;

      CTBNDLarg[0] = CTBNDLtname[CTBNDLtype];
      CTBNDLfmt = CTBNDLstpcpy (CTBNDLformat, CTBNDLunexpected);

      for (CTBNDLx = CTBNDLxbegin; CTBNDLx < CTBNDLxend; ++CTBNDLx)
	if (CTBNDLcheck[CTBNDLx + CTBNDLn] == CTBNDLx && CTBNDLx != YYTERROR)
	  {
	    if (CTBNDLcount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		CTBNDLcount = 1;
		CTBNDLsize = CTBNDLsize0;
		CTBNDLformat[sizeof CTBNDLunexpected - 1] = '\0';
		break;
	      }
	    CTBNDLarg[CTBNDLcount++] = CTBNDLtname[CTBNDLx];
	    CTBNDLsize1 = CTBNDLsize + CTBNDLtnamerr (0, CTBNDLtname[CTBNDLx]);
	    CTBNDLsize_overflow |= (CTBNDLsize1 < CTBNDLsize);
	    CTBNDLsize = CTBNDLsize1;
	    CTBNDLfmt = CTBNDLstpcpy (CTBNDLfmt, CTBNDLprefix);
	    CTBNDLprefix = CTBNDLor;
	  }

      CTBNDLf = YY_(CTBNDLformat);
      CTBNDLsize1 = CTBNDLsize + CTBNDLstrlen (CTBNDLf);
      CTBNDLsize_overflow |= (CTBNDLsize1 < CTBNDLsize);
      CTBNDLsize = CTBNDLsize1;

      if (CTBNDLsize_overflow)
	return YYSIZE_MAXIMUM;

      if (CTBNDLresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *CTBNDLp = CTBNDLresult;
	  int CTBNDLi = 0;
	  while ((*CTBNDLp = *CTBNDLf) != '\0')
	    {
	      if (*CTBNDLp == '%' && CTBNDLf[1] == 's' && CTBNDLi < CTBNDLcount)
		{
		  CTBNDLp += CTBNDLtnamerr (CTBNDLp, CTBNDLarg[CTBNDLi++]);
		  CTBNDLf += 2;
		}
	      else
		{
		  CTBNDLp++;
		  CTBNDLf++;
		}
	    }
	}
      return CTBNDLsize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
CTBNDLdestruct (const char *CTBNDLmsg, int CTBNDLtype, YYSTYPE *CTBNDLvaluep)
#else
static void
CTBNDLdestruct (CTBNDLmsg, CTBNDLtype, CTBNDLvaluep)
    const char *CTBNDLmsg;
    int CTBNDLtype;
    YYSTYPE *CTBNDLvaluep;
#endif
{
  YYUSE (CTBNDLvaluep);

  if (!CTBNDLmsg)
    CTBNDLmsg = "Deleting";
  YY_SYMBOL_PRINT (CTBNDLmsg, CTBNDLtype, CTBNDLvaluep, CTBNDLlocationp);

  switch (CTBNDLtype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int CTBNDLparse (void *YYPARSE_PARAM);
#else
int CTBNDLparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int CTBNDLparse (void);
#else
int CTBNDLparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int CTBNDLchar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE CTBNDLlval;

/* Number of syntax errors so far.  */
int CTBNDLnerrs;



/*-------------------------.
| CTBNDLparse or CTBNDLpush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
CTBNDLparse (void *YYPARSE_PARAM)
#else
int
CTBNDLparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
CTBNDLparse (void)
#else
int
CTBNDLparse ()

#endif
#endif
{


    int CTBNDLstate;
    /* Number of tokens to shift before error messages enabled.  */
    int CTBNDLerrstatus;

    /* The stacks and their tools:
       `CTBNDLss': related to states.
       `CTBNDLvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow CTBNDLoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    CTBNDLtype_int16 CTBNDLssa[YYINITDEPTH];
    CTBNDLtype_int16 *CTBNDLss;
    CTBNDLtype_int16 *CTBNDLssp;

    /* The semantic value stack.  */
    YYSTYPE CTBNDLvsa[YYINITDEPTH];
    YYSTYPE *CTBNDLvs;
    YYSTYPE *CTBNDLvsp;

    YYSIZE_T CTBNDLstacksize;

  int CTBNDLn;
  int CTBNDLresult;
  /* Lookahead token as an internal (translated) token number.  */
  int CTBNDLtoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE CTBNDLval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char CTBNDLmsgbuf[128];
  char *CTBNDLmsg = CTBNDLmsgbuf;
  YYSIZE_T CTBNDLmsg_alloc = sizeof CTBNDLmsgbuf;
#endif

#define YYPOPSTACK(N)   (CTBNDLvsp -= (N), CTBNDLssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int CTBNDLlen = 0;

  CTBNDLtoken = 0;
  CTBNDLss = CTBNDLssa;
  CTBNDLvs = CTBNDLvsa;
  CTBNDLstacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  CTBNDLstate = 0;
  CTBNDLerrstatus = 0;
  CTBNDLnerrs = 0;
  CTBNDLchar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  CTBNDLssp = CTBNDLss;
  CTBNDLvsp = CTBNDLvs;

  goto CTBNDLsetstate;

/*------------------------------------------------------------.
| CTBNDLnewstate -- Push a new state, which is found in CTBNDLstate.  |
`------------------------------------------------------------*/
 CTBNDLnewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  CTBNDLssp++;

 CTBNDLsetstate:
  *CTBNDLssp = CTBNDLstate;

  if (CTBNDLss + CTBNDLstacksize - 1 <= CTBNDLssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T CTBNDLsize = CTBNDLssp - CTBNDLss + 1;

#ifdef CTBNDLoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *CTBNDLvs1 = CTBNDLvs;
	CTBNDLtype_int16 *CTBNDLss1 = CTBNDLss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if CTBNDLoverflow is a macro.  */
	CTBNDLoverflow (YY_("memory exhausted"),
		    &CTBNDLss1, CTBNDLsize * sizeof (*CTBNDLssp),
		    &CTBNDLvs1, CTBNDLsize * sizeof (*CTBNDLvsp),
		    &CTBNDLstacksize);

	CTBNDLss = CTBNDLss1;
	CTBNDLvs = CTBNDLvs1;
      }
#else /* no CTBNDLoverflow */
# ifndef YYSTACK_RELOCATE
      goto CTBNDLexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= CTBNDLstacksize)
	goto CTBNDLexhaustedlab;
      CTBNDLstacksize *= 2;
      if (YYMAXDEPTH < CTBNDLstacksize)
	CTBNDLstacksize = YYMAXDEPTH;

      {
	CTBNDLtype_int16 *CTBNDLss1 = CTBNDLss;
	union CTBNDLalloc *CTBNDLptr =
	  (union CTBNDLalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (CTBNDLstacksize));
	if (! CTBNDLptr)
	  goto CTBNDLexhaustedlab;
	YYSTACK_RELOCATE (CTBNDLss_alloc, CTBNDLss);
	YYSTACK_RELOCATE (CTBNDLvs_alloc, CTBNDLvs);
#  undef YYSTACK_RELOCATE
	if (CTBNDLss1 != CTBNDLssa)
	  YYSTACK_FREE (CTBNDLss1);
      }
# endif
#endif /* no CTBNDLoverflow */

      CTBNDLssp = CTBNDLss + CTBNDLsize - 1;
      CTBNDLvsp = CTBNDLvs + CTBNDLsize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) CTBNDLstacksize));

      if (CTBNDLss + CTBNDLstacksize - 1 <= CTBNDLssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", CTBNDLstate));

  if (CTBNDLstate == YYFINAL)
    YYACCEPT;

  goto CTBNDLbackup;

/*-----------.
| CTBNDLbackup.  |
`-----------*/
CTBNDLbackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  CTBNDLn = CTBNDLpact[CTBNDLstate];
  if (CTBNDLn == YYPACT_NINF)
    goto CTBNDLdefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (CTBNDLchar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      CTBNDLchar = YYLEX;
    }

  if (CTBNDLchar <= YYEOF)
    {
      CTBNDLchar = CTBNDLtoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      CTBNDLtoken = YYTRANSLATE (CTBNDLchar);
      YY_SYMBOL_PRINT ("Next token is", CTBNDLtoken, &CTBNDLlval, &CTBNDLlloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  CTBNDLn += CTBNDLtoken;
  if (CTBNDLn < 0 || YYLAST < CTBNDLn || CTBNDLcheck[CTBNDLn] != CTBNDLtoken)
    goto CTBNDLdefault;
  CTBNDLn = CTBNDLtable[CTBNDLn];
  if (CTBNDLn <= 0)
    {
      if (CTBNDLn == 0 || CTBNDLn == YYTABLE_NINF)
	goto CTBNDLerrlab;
      CTBNDLn = -CTBNDLn;
      goto CTBNDLreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (CTBNDLerrstatus)
    CTBNDLerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", CTBNDLtoken, &CTBNDLlval, &CTBNDLlloc);

  /* Discard the shifted token.  */
  CTBNDLchar = YYEMPTY;

  CTBNDLstate = CTBNDLn;
  *++CTBNDLvsp = CTBNDLlval;

  goto CTBNDLnewstate;


/*-----------------------------------------------------------.
| CTBNDLdefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
CTBNDLdefault:
  CTBNDLn = CTBNDLdefact[CTBNDLstate];
  if (CTBNDLn == 0)
    goto CTBNDLerrlab;
  goto CTBNDLreduce;


/*-----------------------------.
| CTBNDLreduce -- Do a reduction.  |
`-----------------------------*/
CTBNDLreduce:
  /* CTBNDLn is the number of a rule to reduce with.  */
  CTBNDLlen = CTBNDLr2[CTBNDLn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  CTBNDLval = CTBNDLvsp[1-CTBNDLlen];


  YY_REDUCE_PRINT (CTBNDLn);
  switch (CTBNDLn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 80 "BooleanGrammar.y"
    {
  (CTBNDLval.node_decl_list) = new std::vector<NodeDecl*>();
  (CTBNDLval.node_decl_list)->push_back((CTBNDLvsp[(1) - (1)].node_decl));
;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 85 "BooleanGrammar.y"
    {
  (CTBNDLvsp[(1) - (2)].node_decl_list)->push_back((CTBNDLvsp[(2) - (2)].node_decl));
  (CTBNDLval.node_decl_list) = (CTBNDLvsp[(1) - (2)].node_decl_list);
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 92 "BooleanGrammar.y"
    {
  (CTBNDLval.node_decl) = new NodeDecl((CTBNDLvsp[(2) - (5)].str), (CTBNDLvsp[(4) - (5)].node_decl_item_list));
;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 96 "BooleanGrammar.y"
    {
  (CTBNDLval.node_decl) = new NodeDecl((CTBNDLvsp[(2) - (4)].str), NULL);
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 100 "BooleanGrammar.y"
    {
  NodeDeclItem* decl_item = new NodeDeclItem("logic", (CTBNDLvsp[(3) - (4)].expr));
  std::vector<NodeDeclItem*>* decl_item_v = new std::vector<NodeDeclItem*>();
  decl_item_v->push_back(decl_item);
  (CTBNDLval.node_decl) = new NodeDecl((CTBNDLvsp[(1) - (4)].str), decl_item_v);
;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 109 "BooleanGrammar.y"
    {
  (CTBNDLval.node_decl_item_list) = new std::vector<NodeDeclItem*>();
  (CTBNDLval.node_decl_item_list)->push_back((CTBNDLvsp[(1) - (1)].node_decl_item));
;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 114 "BooleanGrammar.y"
    {
  (CTBNDLvsp[(1) - (2)].node_decl_item_list)->push_back((CTBNDLvsp[(2) - (2)].node_decl_item));
  (CTBNDLval.node_decl_item_list) = (CTBNDLvsp[(1) - (2)].node_decl_item_list);
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 121 "BooleanGrammar.y"
    {
  (CTBNDLval.node_decl_item) = new NodeDeclItem((CTBNDLvsp[(1) - (4)].str), (CTBNDLvsp[(3) - (4)].expr));
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 125 "BooleanGrammar.y"
    {
  (CTBNDLval.node_decl_item) = new NodeDeclItem((CTBNDLvsp[(1) - (4)].str), (CTBNDLvsp[(3) - (4)].str));
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 131 "BooleanGrammar.y"
    {
  Node* node = current_network->getOrMakeNode((CTBNDLvsp[(1) - (1)].str));
  (CTBNDLval.expr) = new NodeExpression(node);
;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 136 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new AliasExpression((CTBNDLvsp[(2) - (2)].str));
;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 140 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new SymbolExpression(SymbolTable::getInstance()->getOrMakeSymbol((CTBNDLvsp[(1) - (1)].str)));
;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 144 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new ConstantExpression((CTBNDLvsp[(1) - (1)].l));
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 148 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new ConstantExpression((CTBNDLvsp[(1) - (1)].d));
;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 152 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new ParenthesisExpression((CTBNDLvsp[(2) - (3)].expr));
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 158 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 188 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 192 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(2) - (2)].expr);
;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 196 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new SubExpression(new ConstantExpression(0.0), (CTBNDLvsp[(2) - (2)].expr));
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 200 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new NotLogicalExpression((CTBNDLvsp[(2) - (2)].expr));
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 204 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new NotLogicalExpression((CTBNDLvsp[(2) - (2)].expr));
;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 210 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 214 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new MulExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 218 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new DivExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 224 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 228 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new AddExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 232 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new SubExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 238 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 242 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new LetterExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 246 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new GreaterExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 250 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new LetterOrEqualExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 254 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new GreaterOrEqualExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 260 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 264 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new EqualExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 268 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new NotEqualExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 274 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 278 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new AndLogicalExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 284 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 288 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new OrLogicalExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 294 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 298 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new XorLogicalExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 302 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new XorLogicalExpression((CTBNDLvsp[(1) - (3)].expr), (CTBNDLvsp[(3) - (3)].expr));
;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 308 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 312 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = new CondExpression((CTBNDLvsp[(1) - (5)].expr), (CTBNDLvsp[(3) - (5)].expr), (CTBNDLvsp[(5) - (5)].expr));
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 318 "BooleanGrammar.y"
    {
  (CTBNDLval.expr) = (CTBNDLvsp[(1) - (1)].expr);
;}
    break;



/* Line 1455 of yacc.c  */
#line 1866 "BooleanGrammar.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", CTBNDLr1[CTBNDLn], &CTBNDLval, &CTBNDLloc);

  YYPOPSTACK (CTBNDLlen);
  CTBNDLlen = 0;
  YY_STACK_PRINT (CTBNDLss, CTBNDLssp);

  *++CTBNDLvsp = CTBNDLval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  CTBNDLn = CTBNDLr1[CTBNDLn];

  CTBNDLstate = CTBNDLpgoto[CTBNDLn - YYNTOKENS] + *CTBNDLssp;
  if (0 <= CTBNDLstate && CTBNDLstate <= YYLAST && CTBNDLcheck[CTBNDLstate] == *CTBNDLssp)
    CTBNDLstate = CTBNDLtable[CTBNDLstate];
  else
    CTBNDLstate = CTBNDLdefgoto[CTBNDLn - YYNTOKENS];

  goto CTBNDLnewstate;


/*------------------------------------.
| CTBNDLerrlab -- here on detecting error |
`------------------------------------*/
CTBNDLerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!CTBNDLerrstatus)
    {
      ++CTBNDLnerrs;
#if ! YYERROR_VERBOSE
      CTBNDLerror (YY_("syntax error"));
#else
      {
	YYSIZE_T CTBNDLsize = CTBNDLsyntax_error (0, CTBNDLstate, CTBNDLchar);
	if (CTBNDLmsg_alloc < CTBNDLsize && CTBNDLmsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T CTBNDLalloc = 2 * CTBNDLsize;
	    if (! (CTBNDLsize <= CTBNDLalloc && CTBNDLalloc <= YYSTACK_ALLOC_MAXIMUM))
	      CTBNDLalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (CTBNDLmsg != CTBNDLmsgbuf)
	      YYSTACK_FREE (CTBNDLmsg);
	    CTBNDLmsg = (char *) YYSTACK_ALLOC (CTBNDLalloc);
	    if (CTBNDLmsg)
	      CTBNDLmsg_alloc = CTBNDLalloc;
	    else
	      {
		CTBNDLmsg = CTBNDLmsgbuf;
		CTBNDLmsg_alloc = sizeof CTBNDLmsgbuf;
	      }
	  }

	if (0 < CTBNDLsize && CTBNDLsize <= CTBNDLmsg_alloc)
	  {
	    (void) CTBNDLsyntax_error (CTBNDLmsg, CTBNDLstate, CTBNDLchar);
	    CTBNDLerror (CTBNDLmsg);
	  }
	else
	  {
	    CTBNDLerror (YY_("syntax error"));
	    if (CTBNDLsize != 0)
	      goto CTBNDLexhaustedlab;
	  }
      }
#endif
    }



  if (CTBNDLerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (CTBNDLchar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (CTBNDLchar == YYEOF)
	    YYABORT;
	}
      else
	{
	  CTBNDLdestruct ("Error: discarding",
		      CTBNDLtoken, &CTBNDLlval);
	  CTBNDLchar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto CTBNDLerrlab1;


/*---------------------------------------------------.
| CTBNDLerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
CTBNDLerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label CTBNDLerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto CTBNDLerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (CTBNDLlen);
  CTBNDLlen = 0;
  YY_STACK_PRINT (CTBNDLss, CTBNDLssp);
  CTBNDLstate = *CTBNDLssp;
  goto CTBNDLerrlab1;


/*-------------------------------------------------------------.
| CTBNDLerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
CTBNDLerrlab1:
  CTBNDLerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      CTBNDLn = CTBNDLpact[CTBNDLstate];
      if (CTBNDLn != YYPACT_NINF)
	{
	  CTBNDLn += YYTERROR;
	  if (0 <= CTBNDLn && CTBNDLn <= YYLAST && CTBNDLcheck[CTBNDLn] == YYTERROR)
	    {
	      CTBNDLn = CTBNDLtable[CTBNDLn];
	      if (0 < CTBNDLn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (CTBNDLssp == CTBNDLss)
	YYABORT;


      CTBNDLdestruct ("Error: popping",
		  CTBNDLstos[CTBNDLstate], CTBNDLvsp);
      YYPOPSTACK (1);
      CTBNDLstate = *CTBNDLssp;
      YY_STACK_PRINT (CTBNDLss, CTBNDLssp);
    }

  *++CTBNDLvsp = CTBNDLlval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", CTBNDLstos[CTBNDLn], CTBNDLvsp, CTBNDLlsp);

  CTBNDLstate = CTBNDLn;
  goto CTBNDLnewstate;


/*-------------------------------------.
| CTBNDLacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
CTBNDLacceptlab:
  CTBNDLresult = 0;
  goto CTBNDLreturn;

/*-----------------------------------.
| CTBNDLabortlab -- YYABORT comes here.  |
`-----------------------------------*/
CTBNDLabortlab:
  CTBNDLresult = 1;
  goto CTBNDLreturn;

#if !defined(CTBNDLoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| CTBNDLexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
CTBNDLexhaustedlab:
  CTBNDLerror (YY_("memory exhausted"));
  CTBNDLresult = 2;
  /* Fall through.  */
#endif

CTBNDLreturn:
  if (CTBNDLchar != YYEMPTY)
     CTBNDLdestruct ("Cleanup: discarding lookahead",
		 CTBNDLtoken, &CTBNDLlval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (CTBNDLlen);
  YY_STACK_PRINT (CTBNDLss, CTBNDLssp);
  while (CTBNDLssp != CTBNDLss)
    {
      CTBNDLdestruct ("Cleanup: popping",
		  CTBNDLstos[*CTBNDLssp], CTBNDLvsp);
      YYPOPSTACK (1);
    }
#ifndef CTBNDLoverflow
  if (CTBNDLss != CTBNDLssa)
    YYSTACK_FREE (CTBNDLss);
#endif
#if YYERROR_VERBOSE
  if (CTBNDLmsg != CTBNDLmsgbuf)
    YYSTACK_FREE (CTBNDLmsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (CTBNDLresult);
}



/* Line 1675 of yacc.c  */
#line 327 "BooleanGrammar.y"


#include "lex.CTBNDL.cc"

void set_current_network(Network* network)
{
  current_network = network;
}

Network* get_current_network()
{
  return current_network;
}


