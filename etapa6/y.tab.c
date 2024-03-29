/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

    #include <stdio.h>
    #include <stdlib.h>
    #include "hash.h"
    #include "ast.h"
    #include "semantic.h"
    #include "tac.h"
    #include "asm.h"
    int yyerror(char *);
    int yylex();

#line 83 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_REAL = 260,                 /* KW_REAL  */
    KW_BOOL = 261,                 /* KW_BOOL  */
    KW_IF = 262,                   /* KW_IF  */
    KW_THEN = 263,                 /* KW_THEN  */
    KW_ELSE = 264,                 /* KW_ELSE  */
    KW_LOOP = 265,                 /* KW_LOOP  */
    KW_INPUT = 266,                /* KW_INPUT  */
    KW_OUTPUT = 267,               /* KW_OUTPUT  */
    KW_RETURN = 268,               /* KW_RETURN  */
    OPERATOR_LE = 269,             /* OPERATOR_LE  */
    OPERATOR_GE = 270,             /* OPERATOR_GE  */
    OPERATOR_EQ = 271,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 272,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 273,           /* TK_IDENTIFIER  */
    LIT_INT = 274,                 /* LIT_INT  */
    LIT_REAL = 275,                /* LIT_REAL  */
    LIT_CHAR = 276,                /* LIT_CHAR  */
    LIT_STRING = 277,              /* LIT_STRING  */
    TOKEN_ERROR = 278              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_REAL 260
#define KW_BOOL 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_LOOP 265
#define KW_INPUT 266
#define KW_OUTPUT 267
#define KW_RETURN 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_DIF 272
#define TK_IDENTIFIER 273
#define LIT_INT 274
#define LIT_REAL 275
#define LIT_CHAR 276
#define LIT_STRING 277
#define TOKEN_ERROR 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

        HashNode* symbol;
        AST* ast;

#line 187 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_REAL = 5,                    /* KW_REAL  */
  YYSYMBOL_KW_BOOL = 6,                    /* KW_BOOL  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_THEN = 8,                    /* KW_THEN  */
  YYSYMBOL_KW_ELSE = 9,                    /* KW_ELSE  */
  YYSYMBOL_KW_LOOP = 10,                   /* KW_LOOP  */
  YYSYMBOL_KW_INPUT = 11,                  /* KW_INPUT  */
  YYSYMBOL_KW_OUTPUT = 12,                 /* KW_OUTPUT  */
  YYSYMBOL_KW_RETURN = 13,                 /* KW_RETURN  */
  YYSYMBOL_OPERATOR_LE = 14,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 15,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 16,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 17,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 18,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INT = 19,                   /* LIT_INT  */
  YYSYMBOL_LIT_REAL = 20,                  /* LIT_REAL  */
  YYSYMBOL_LIT_CHAR = 21,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 22,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 23,               /* TOKEN_ERROR  */
  YYSYMBOL_24_ = 24,                       /* '&'  */
  YYSYMBOL_25_ = 25,                       /* '~'  */
  YYSYMBOL_26_ = 26,                       /* '|'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_38_ = 38,                       /* ')'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_programa = 43,                  /* programa  */
  YYSYMBOL_listaDeclaracoes = 44,          /* listaDeclaracoes  */
  YYSYMBOL_declaracao = 45,                /* declaracao  */
  YYSYMBOL_nome = 46,                      /* nome  */
  YYSYMBOL_variavel = 47,                  /* variavel  */
  YYSYMBOL_literal = 48,                   /* literal  */
  YYSYMBOL_literais = 49,                  /* literais  */
  YYSYMBOL_tipo = 50,                      /* tipo  */
  YYSYMBOL_funcao = 51,                    /* funcao  */
  YYSYMBOL_cabecalho = 52,                 /* cabecalho  */
  YYSYMBOL_definicaoParametros = 53,       /* definicaoParametros  */
  YYSYMBOL_virgulaDefinicaoParametrosOuVazio = 54, /* virgulaDefinicaoParametrosOuVazio  */
  YYSYMBOL_definicaoListaParametros = 55,  /* definicaoListaParametros  */
  YYSYMBOL_bloco = 56,                     /* bloco  */
  YYSYMBOL_comandos = 57,                  /* comandos  */
  YYSYMBOL_comando = 58,                   /* comando  */
  YYSYMBOL_atribuicao = 59,                /* atribuicao  */
  YYSYMBOL_controleFluxo = 60,             /* controleFluxo  */
  YYSYMBOL_outputComando = 61,             /* outputComando  */
  YYSYMBOL_returnComando = 62,             /* returnComando  */
  YYSYMBOL_outputElementos = 63,           /* outputElementos  */
  YYSYMBOL_virgulaOutputElementosOuVazio = 64, /* virgulaOutputElementosOuVazio  */
  YYSYMBOL_expressao = 65,                 /* expressao  */
  YYSYMBOL_passagemParametros = 66,        /* passagemParametros  */
  YYSYMBOL_virgulaPassagemParametrosOuVazio = 67, /* virgulaPassagemParametrosOuVazio  */
  YYSYMBOL_passagemListaParametros = 68    /* passagemListaParametros  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    24,     2,
      37,    38,    31,    29,    39,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      27,    33,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    26,    41,    25,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    98,    99,   102,   103,   106,   112,   116,
     124,   125,   126,   127,   130,   131,   135,   136,   137,   138,
     144,   147,   153,   159,   160,   163,   164,   167,   170,   171,
     174,   175,   176,   177,   178,   179,   182,   184,   190,   191,
     195,   201,   203,   206,   207,   212,   213,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   235,   238,   239,   243,   246,
     247,   250,   251
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_REAL", "KW_BOOL", "KW_IF", "KW_THEN", "KW_ELSE", "KW_LOOP",
  "KW_INPUT", "KW_OUTPUT", "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE",
  "OPERATOR_EQ", "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INT", "LIT_REAL",
  "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR", "'&'", "'~'", "'|'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'='", "';'", "'['", "']'", "'('",
  "')'", "','", "'{'", "'}'", "$accept", "programa", "listaDeclaracoes",
  "declaracao", "nome", "variavel", "literal", "literais", "tipo",
  "funcao", "cabecalho", "definicaoParametros",
  "virgulaDefinicaoParametrosOuVazio", "definicaoListaParametros", "bloco",
  "comandos", "comando", "atribuicao", "controleFluxo", "outputComando",
  "returnComando", "outputElementos", "virgulaOutputElementosOuVazio",
  "expressao", "passagemParametros", "virgulaPassagemParametrosOuVazio",
  "passagemListaParametros", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-89)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -89,   -89,   -89,   -89,     5,   -89,    36,   -89,    -5,
     -89,   -31,   -89,   -89,   -89,   -29,    54,   -89,    43,    -4,
      36,   -19,    58,    85,   -89,   -23,   -89,   -12,    54,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,    -3,    -2,    -5,
     -89,    10,    85,    -1,   -89,   -89,   -89,    29,    85,    85,
     -14,     1,    97,   219,    85,    85,   -89,   -89,   -89,    43,
      31,   -89,   135,    36,    58,   -89,   282,   154,    85,    85,
     -89,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,   -89,   -89,   240,   173,    43,     9,    36,
     -89,     4,    35,   -89,   -89,   196,   116,   -89,    37,    55,
      55,    55,    55,   282,   282,    55,    55,    -7,    -7,   -89,
     -89,   -89,    41,   -89,   -89,   -89,    54,    72,   -89,   -89,
      85,   -89,   -89,    85,   -89,    54,   -89,   261,   -89,   -89
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    17,    18,    19,    16,     0,     2,     4,     5,     0,
       6,     0,     1,     3,     7,     0,    29,    20,     0,     0,
      26,     0,     0,     0,    30,     0,    31,     0,    29,    32,
      33,    34,    35,    10,    11,    12,    13,     0,     0,     0,
      25,     0,     0,     0,    62,    64,    63,    46,     0,     0,
      61,     0,    46,     0,     0,     0,    27,    28,     8,    15,
      24,    21,     0,     0,     0,    44,    55,     0,     0,    72,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,    42,     0,     0,    15,     0,     0,
      22,     0,     0,    45,    60,     0,    70,    71,     0,    57,
      56,    58,    59,    53,    54,    51,    52,    47,    48,    49,
      50,    36,     0,    14,     9,    23,     0,    38,    66,    67,
       0,    68,    65,     0,    40,     0,    69,     0,    39,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,    82,   -89,    -9,   -89,    73,     3,   -18,   -89,
     -89,     8,   -89,   -89,    81,    65,   -88,   -89,   -89,   -89,
     -89,    38,    47,   -22,   -20,   -89,   -89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    50,     8,    87,    88,     9,    10,
      11,    40,    90,    41,    26,    27,    28,    29,    30,    31,
      32,    51,    65,    52,    97,   121,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    53,    39,   117,    18,    12,    19,    25,    20,    16,
      54,    21,    55,    14,   116,    38,    22,    23,    42,    25,
      62,    68,    14,    69,    81,    82,    66,    67,   124,    56,
      60,    58,    85,    86,    59,    70,    63,   128,    24,     1,
       2,     3,     4,   114,    16,    92,    95,    96,    61,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    21,    33,    34,    35,    36,    22,    23,    64,    43,
      89,    39,    14,   118,   123,   122,    14,    44,    45,    46,
      47,   125,    25,    48,    79,    80,    81,    82,    24,    13,
     113,    37,    17,    57,    16,    49,    43,   115,    96,    83,
     126,   127,    93,    14,    44,    45,    46,    25,     0,     0,
      48,    71,    72,    73,    74,     0,    25,     0,     0,     0,
       0,    75,    49,    76,    77,    78,    79,    80,    81,    82,
      71,    72,    73,    74,     0,     0,    64,     0,     0,     0,
      75,     0,    76,    77,    78,    79,    80,    81,    82,    71,
      72,    73,    74,     0,     0,   120,     0,     0,     0,    75,
       0,    76,    77,    78,    79,    80,    81,    82,    71,    72,
      73,    74,     0,    91,     0,     0,     0,     0,    75,     0,
      76,    77,    78,    79,    80,    81,    82,    71,    72,    73,
      74,     0,    94,     0,     0,     0,     0,    75,     0,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,   112,
      71,    72,    73,    74,     0,     0,     0,     0,     0,     0,
      75,     0,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,   119,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,    75,     0,    76,    77,    78,    79,    80,
      81,    82,     0,    84,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,    75,     0,    76,    77,    78,    79,
      80,    81,    82,     0,   111,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,    75,     0,    76,    77,    78,
      79,    80,    81,    82,     0,   129,    71,    72,    73,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82
};

static const yytype_int8 yycheck[] =
{
       9,    23,    20,    91,    33,     0,    35,    16,    37,    40,
      33,     7,    35,    18,    10,    19,    12,    13,    37,    28,
      42,    35,    18,    37,    31,    32,    48,    49,   116,    41,
      39,    34,    54,    55,    36,    34,    37,   125,    34,     3,
       4,     5,     6,    34,    40,    63,    68,    69,    38,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     7,    19,    20,    21,    22,    12,    13,    39,    11,
      39,    89,    18,    38,    33,    38,    18,    19,    20,    21,
      22,     9,    91,    25,    29,    30,    31,    32,    34,     7,
      87,    18,    11,    28,    40,    37,    11,    89,   120,    52,
     120,   123,    64,    18,    19,    20,    21,   116,    -1,    -1,
      25,    14,    15,    16,    17,    -1,   125,    -1,    -1,    -1,
      -1,    24,    37,    26,    27,    28,    29,    30,    31,    32,
      14,    15,    16,    17,    -1,    -1,    39,    -1,    -1,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    14,
      15,    16,    17,    -1,    -1,    39,    -1,    -1,    -1,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    14,    15,
      16,    17,    -1,    38,    -1,    -1,    -1,    -1,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    14,    15,    16,
      17,    -1,    38,    -1,    -1,    -1,    -1,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    36,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    43,    44,    45,    47,    50,
      51,    52,     0,    44,    18,    46,    40,    56,    33,    35,
      37,     7,    12,    13,    34,    46,    56,    57,    58,    59,
      60,    61,    62,    19,    20,    21,    22,    48,    19,    50,
      53,    55,    37,    11,    19,    20,    21,    22,    25,    37,
      46,    63,    65,    65,    33,    35,    41,    57,    34,    36,
      46,    38,    65,    37,    39,    64,    65,    65,    35,    37,
      34,    14,    15,    16,    17,    24,    26,    27,    28,    29,
      30,    31,    32,    64,    34,    65,    65,    48,    49,    39,
      54,    38,    50,    63,    38,    65,    65,    66,    68,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    34,    36,    49,    34,    53,    10,    58,    38,    36,
      39,    67,    38,    33,    58,     9,    66,    65,    58,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    47,    47,
      48,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      51,    52,    53,    54,    54,    55,    55,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    61,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    67,
      67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     5,     7,
       1,     1,     1,     1,     2,     0,     1,     1,     1,     1,
       2,     5,     3,     2,     0,     1,     0,     3,     2,     0,
       1,     1,     1,     1,     1,     1,     4,     7,     5,     7,
       6,     3,     3,     2,     2,     2,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     4,     4,     4,     2,     2,
       0,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: listaDeclaracoes  */
#line 76 "parser.y"
                           {
        AST* root = (yyvsp[0].ast);  
        astToFile(root);    
        checkAndSetDeclarations(root, NULL); 
        checkUndeclared(); 
        checkOperands(root);
        if(!getSemanticErrors())
        {
                fprintf(stderr, "LOG: no semantic erros...\n" "LOG: generating TACs...\n");
                TAC* tac = generateCode(root);
                fprintf(stderr, "LOG: TACs generated...\n" "LOG: generating ASM...\n");
                generateASM(tac);
                fprintf(stderr, "LOG: ASM generated...\n" "LOG: program can be found at ams.s...\n");
        }
        else
        {
                fprintf(stderr, "LOG: semantic erros found!!! Exiting...\n");
        } 
        
        (yyval.ast) = root;}
#line 1376 "y.tab.c"
    break;

  case 3: /* listaDeclaracoes: declaracao listaDeclaracoes  */
#line 98 "parser.y"
                                                {(yyval.ast) = astCreate(AST_DECLIST, NULL, (yyvsp[-1].ast), (yyvsp[0].ast), getLineNumber());}
#line 1382 "y.tab.c"
    break;

  case 4: /* listaDeclaracoes: %empty  */
#line 99 "parser.y"
                                                {(yyval.ast) = NULL;}
#line 1388 "y.tab.c"
    break;

  case 5: /* declaracao: variavel  */
#line 102 "parser.y"
                           {(yyval.ast) = (yyvsp[0].ast);}
#line 1394 "y.tab.c"
    break;

  case 6: /* declaracao: funcao  */
#line 103 "parser.y"
                           {(yyval.ast) = (yyvsp[0].ast);}
#line 1400 "y.tab.c"
    break;

  case 7: /* nome: TK_IDENTIFIER  */
#line 106 "parser.y"
                        {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1406 "y.tab.c"
    break;

  case 8: /* variavel: tipo nome '=' literal ';'  */
#line 112 "parser.y"
                                    {
        AST* typename = astCreate(AST_TYPENAME, NULL, (yyvsp[-4].ast), (yyvsp[-3].ast), getLineNumber());
        (yyval.ast) = astCreate(AST_VARDEF, NULL, typename, (yyvsp[-1].ast), getLineNumber());
}
#line 1415 "y.tab.c"
    break;

  case 9: /* variavel: tipo nome '[' LIT_INT ']' literais ';'  */
#line 116 "parser.y"
                                                 {
        AST* typename = astCreate(AST_TYPENAME, NULL, (yyvsp[-6].ast), (yyvsp[-5].ast), getLineNumber());
        AST* size = astCreate(AST_SYMBOL, (yyvsp[-3].symbol), NULL, NULL, getLineNumber());
        AST* vecsizevalue = astCreate(AST_VECSIZEVALUE, NULL, size, (yyvsp[-1].ast), getLineNumber());
        (yyval.ast) = astCreate(AST_VECDEF, NULL, typename, vecsizevalue, getLineNumber());
}
#line 1426 "y.tab.c"
    break;

  case 10: /* literal: LIT_INT  */
#line 124 "parser.y"
                        {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1432 "y.tab.c"
    break;

  case 11: /* literal: LIT_REAL  */
#line 125 "parser.y"
                        {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1438 "y.tab.c"
    break;

  case 12: /* literal: LIT_CHAR  */
#line 126 "parser.y"
                        {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1444 "y.tab.c"
    break;

  case 13: /* literal: LIT_STRING  */
#line 127 "parser.y"
                        {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1450 "y.tab.c"
    break;

  case 14: /* literais: literal literais  */
#line 130 "parser.y"
                                {(yyval.ast) = astCreate(AST_LITERAIS, NULL, (yyvsp[-1].ast), (yyvsp[0].ast), getLineNumber());}
#line 1456 "y.tab.c"
    break;

  case 15: /* literais: %empty  */
#line 131 "parser.y"
                                {(yyval.ast) = NULL;}
#line 1462 "y.tab.c"
    break;

  case 16: /* tipo: KW_BOOL  */
#line 135 "parser.y"
              {(yyval.ast) = astCreate(AST_BOOL, NULL, NULL, NULL, getLineNumber());}
#line 1468 "y.tab.c"
    break;

  case 17: /* tipo: KW_CHAR  */
#line 136 "parser.y"
              {(yyval.ast) = astCreate(AST_CHAR, NULL, NULL, NULL, getLineNumber());}
#line 1474 "y.tab.c"
    break;

  case 18: /* tipo: KW_INT  */
#line 137 "parser.y"
              {(yyval.ast) = astCreate(AST_INT, NULL, NULL, NULL, getLineNumber());}
#line 1480 "y.tab.c"
    break;

  case 19: /* tipo: KW_REAL  */
#line 138 "parser.y"
              {(yyval.ast) = astCreate(AST_REAL, NULL, NULL, NULL, getLineNumber());}
#line 1486 "y.tab.c"
    break;

  case 20: /* funcao: cabecalho bloco  */
#line 144 "parser.y"
                          {(yyval.ast) = astCreate(AST_FUNCDEF, NULL, (yyvsp[-1].ast), (yyvsp[0].ast), getLineNumber());}
#line 1492 "y.tab.c"
    break;

  case 21: /* cabecalho: tipo nome '(' definicaoListaParametros ')'  */
#line 147 "parser.y"
                                                         {
        AST* typename = astCreate(AST_TYPENAME, NULL, (yyvsp[-4].ast), (yyvsp[-3].ast), getLineNumber());
        (yyval.ast) = astCreate(AST_HEADER, NULL, typename, (yyvsp[-1].ast), getLineNumber());
}
#line 1501 "y.tab.c"
    break;

  case 22: /* definicaoParametros: tipo nome virgulaDefinicaoParametrosOuVazio  */
#line 153 "parser.y"
                                                                  {
        AST* typename = astCreate(AST_TYPENAME, NULL, (yyvsp[-2].ast), (yyvsp[-1].ast), getLineNumber());
        (yyval.ast) = astCreate(AST_LIST, NULL, typename, (yyvsp[0].ast), getLineNumber());
}
#line 1510 "y.tab.c"
    break;

  case 23: /* virgulaDefinicaoParametrosOuVazio: ',' definicaoParametros  */
#line 159 "parser.y"
                                                                {(yyval.ast) = (yyvsp[0].ast);}
#line 1516 "y.tab.c"
    break;

  case 24: /* virgulaDefinicaoParametrosOuVazio: %empty  */
#line 160 "parser.y"
                                                                {(yyval.ast) = NULL;}
#line 1522 "y.tab.c"
    break;

  case 25: /* definicaoListaParametros: definicaoParametros  */
#line 163 "parser.y"
                                                {(yyval.ast) = (yyvsp[0].ast);}
#line 1528 "y.tab.c"
    break;

  case 26: /* definicaoListaParametros: %empty  */
#line 164 "parser.y"
                                                {(yyval.ast) = NULL;}
#line 1534 "y.tab.c"
    break;

  case 27: /* bloco: '{' comandos '}'  */
#line 167 "parser.y"
                                {(yyval.ast) = astCreate(AST_BLOCKCMD, NULL, (yyvsp[-1].ast), NULL, getLineNumber());}
#line 1540 "y.tab.c"
    break;

  case 28: /* comandos: comando comandos  */
#line 170 "parser.y"
                                {(yyval.ast) = astCreate(AST_COMMANDS, NULL, (yyvsp[-1].ast), (yyvsp[0].ast), getLineNumber());}
#line 1546 "y.tab.c"
    break;

  case 29: /* comandos: %empty  */
#line 171 "parser.y"
                                {(yyval.ast) = NULL;}
#line 1552 "y.tab.c"
    break;

  case 30: /* comando: ';'  */
#line 174 "parser.y"
                        {(yyval.ast) = astCreate(AST_EMPTYCMD, NULL, NULL, NULL, getLineNumber());}
#line 1558 "y.tab.c"
    break;

  case 31: /* comando: bloco  */
#line 175 "parser.y"
                        {(yyval.ast) = (yyvsp[0].ast);}
#line 1564 "y.tab.c"
    break;

  case 32: /* comando: atribuicao  */
#line 176 "parser.y"
                        {(yyval.ast) = (yyvsp[0].ast);}
#line 1570 "y.tab.c"
    break;

  case 33: /* comando: controleFluxo  */
#line 177 "parser.y"
                        {(yyval.ast) = (yyvsp[0].ast);}
#line 1576 "y.tab.c"
    break;

  case 34: /* comando: outputComando  */
#line 178 "parser.y"
                        {(yyval.ast) = (yyvsp[0].ast);}
#line 1582 "y.tab.c"
    break;

  case 35: /* comando: returnComando  */
#line 179 "parser.y"
                        {(yyval.ast) = (yyvsp[0].ast);}
#line 1588 "y.tab.c"
    break;

  case 36: /* atribuicao: nome '=' expressao ';'  */
#line 182 "parser.y"
                                     {(yyval.ast) = astCreate(AST_VARATTCMD, NULL, (yyvsp[-3].ast), (yyvsp[-1].ast), getLineNumber());}
#line 1594 "y.tab.c"
    break;

  case 37: /* atribuicao: nome '[' expressao ']' '=' expressao ';'  */
#line 184 "parser.y"
                                                       {
                AST* index = astCreate(AST_VECATTCMD, NULL, (yyvsp[-4].ast), (yyvsp[-1].ast), getLineNumber()); 
                (yyval.ast) = astCreate(AST_VECACC, NULL, (yyvsp[-6].ast), index, getLineNumber());
                }
#line 1603 "y.tab.c"
    break;

  case 38: /* controleFluxo: KW_IF '(' expressao ')' comando  */
#line 190 "parser.y"
                                                  {(yyval.ast) = astCreate(AST_IF, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1609 "y.tab.c"
    break;

  case 39: /* controleFluxo: KW_IF '(' expressao ')' comando KW_ELSE comando  */
#line 191 "parser.y"
                                                                  {
                        AST* thenElse = astCreate(AST_THENELSE, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());
                        (yyval.ast) = astCreate(AST_IF, NULL, (yyvsp[-4].ast), thenElse, getLineNumber());
                }
#line 1618 "y.tab.c"
    break;

  case 40: /* controleFluxo: KW_IF '(' expressao ')' KW_LOOP comando  */
#line 195 "parser.y"
                                                           {
                        AST* loop = astCreate(AST_LOOP, NULL, (yyvsp[0].ast), NULL, getLineNumber());
                        (yyval.ast) = astCreate(AST_IF, NULL, (yyvsp[-3].ast), loop, getLineNumber());
                }
#line 1627 "y.tab.c"
    break;

  case 41: /* outputComando: KW_OUTPUT outputElementos ';'  */
#line 201 "parser.y"
                                                {(yyval.ast) = astCreate(AST_OUTPUTCMD, NULL, (yyvsp[-1].ast), NULL, getLineNumber());}
#line 1633 "y.tab.c"
    break;

  case 42: /* returnComando: KW_RETURN expressao ';'  */
#line 203 "parser.y"
                                          {(yyval.ast) = astCreate(AST_RETURNCMD, NULL, (yyvsp[-1].ast), NULL, getLineNumber());}
#line 1639 "y.tab.c"
    break;

  case 43: /* outputElementos: expressao virgulaOutputElementosOuVazio  */
#line 206 "parser.y"
                                                                {(yyval.ast) = astCreate(AST_LIST, NULL, (yyvsp[-1].ast), (yyvsp[0].ast), getLineNumber());}
#line 1645 "y.tab.c"
    break;

  case 44: /* outputElementos: LIT_STRING virgulaOutputElementosOuVazio  */
#line 207 "parser.y"
                                                                {
                        AST* stringNode = astCreate(AST_SYMBOL, (yyvsp[-1].symbol), NULL, NULL, getLineNumber());
                        (yyval.ast) = astCreate(AST_LIST, NULL, stringNode, (yyvsp[0].ast), getLineNumber());}
#line 1653 "y.tab.c"
    break;

  case 45: /* virgulaOutputElementosOuVazio: ',' outputElementos  */
#line 212 "parser.y"
                                                        {(yyval.ast) = (yyvsp[0].ast);}
#line 1659 "y.tab.c"
    break;

  case 46: /* virgulaOutputElementosOuVazio: %empty  */
#line 213 "parser.y"
                                                        {(yyval.ast) = NULL;}
#line 1665 "y.tab.c"
    break;

  case 47: /* expressao: expressao '+' expressao  */
#line 216 "parser.y"
                                      {(yyval.ast) = astCreate(AST_ADD, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1671 "y.tab.c"
    break;

  case 48: /* expressao: expressao '-' expressao  */
#line 217 "parser.y"
                                      {(yyval.ast) = astCreate(AST_SUB, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1677 "y.tab.c"
    break;

  case 49: /* expressao: expressao '*' expressao  */
#line 218 "parser.y"
                                      {(yyval.ast) = astCreate(AST_MUL, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1683 "y.tab.c"
    break;

  case 50: /* expressao: expressao '/' expressao  */
#line 219 "parser.y"
                                      {(yyval.ast) = astCreate(AST_DIV, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1689 "y.tab.c"
    break;

  case 51: /* expressao: expressao '<' expressao  */
#line 220 "parser.y"
                                      {(yyval.ast) = astCreate(AST_LT,  NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1695 "y.tab.c"
    break;

  case 52: /* expressao: expressao '>' expressao  */
#line 221 "parser.y"
                                      {(yyval.ast) = astCreate(AST_GT,  NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1701 "y.tab.c"
    break;

  case 53: /* expressao: expressao '&' expressao  */
#line 222 "parser.y"
                                      {(yyval.ast) = astCreate(AST_AND, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1707 "y.tab.c"
    break;

  case 54: /* expressao: expressao '|' expressao  */
#line 223 "parser.y"
                                      {(yyval.ast) = astCreate(AST_OR,  NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1713 "y.tab.c"
    break;

  case 55: /* expressao: '~' expressao  */
#line 224 "parser.y"
                            {(yyval.ast) = astCreate(AST_NOT, NULL, (yyvsp[0].ast), NULL, getLineNumber());}
#line 1719 "y.tab.c"
    break;

  case 56: /* expressao: expressao OPERATOR_GE expressao  */
#line 225 "parser.y"
                                                {(yyval.ast) = astCreate(AST_GE,  NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1725 "y.tab.c"
    break;

  case 57: /* expressao: expressao OPERATOR_LE expressao  */
#line 226 "parser.y"
                                                {(yyval.ast) = astCreate(AST_LE,  NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1731 "y.tab.c"
    break;

  case 58: /* expressao: expressao OPERATOR_EQ expressao  */
#line 227 "parser.y"
                                                {(yyval.ast) = astCreate(AST_EQ,  NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1737 "y.tab.c"
    break;

  case 59: /* expressao: expressao OPERATOR_DIF expressao  */
#line 228 "parser.y"
                                                {(yyval.ast) = astCreate(AST_DIF, NULL, (yyvsp[-2].ast), (yyvsp[0].ast), getLineNumber());}
#line 1743 "y.tab.c"
    break;

  case 60: /* expressao: '(' expressao ')'  */
#line 229 "parser.y"
                                {(yyval.ast) = astCreate(AST_PARENTHESIS, NULL, (yyvsp[-1].ast), NULL, getLineNumber());}
#line 1749 "y.tab.c"
    break;

  case 61: /* expressao: nome  */
#line 230 "parser.y"
                                {(yyval.ast) = (yyvsp[0].ast);}
#line 1755 "y.tab.c"
    break;

  case 62: /* expressao: LIT_INT  */
#line 231 "parser.y"
                                {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1761 "y.tab.c"
    break;

  case 63: /* expressao: LIT_CHAR  */
#line 232 "parser.y"
                                {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1767 "y.tab.c"
    break;

  case 64: /* expressao: LIT_REAL  */
#line 233 "parser.y"
                                {(yyval.ast) = astCreate(AST_SYMBOL, (yyvsp[0].symbol), NULL, NULL, getLineNumber());}
#line 1773 "y.tab.c"
    break;

  case 65: /* expressao: nome '(' passagemListaParametros ')'  */
#line 235 "parser.y"
                                                   {(yyval.ast) = astCreate(AST_FUNCAPP, NULL, (yyvsp[-3].ast), (yyvsp[-1].ast), getLineNumber());}
#line 1779 "y.tab.c"
    break;

  case 66: /* expressao: KW_INPUT '(' tipo ')'  */
#line 238 "parser.y"
                                      {(yyval.ast) = astCreate(AST_INPUT, NULL, (yyvsp[-1].ast), NULL, getLineNumber());}
#line 1785 "y.tab.c"
    break;

  case 67: /* expressao: nome '[' expressao ']'  */
#line 239 "parser.y"
                                     { (yyval.ast) = astCreate(AST_VECACC, NULL, (yyvsp[-3].ast), (yyvsp[-1].ast), getLineNumber());}
#line 1791 "y.tab.c"
    break;

  case 68: /* passagemParametros: expressao virgulaPassagemParametrosOuVazio  */
#line 243 "parser.y"
                                                                     {(yyval.ast) = astCreate(AST_LIST, NULL, (yyvsp[-1].ast), (yyvsp[0].ast), getLineNumber());}
#line 1797 "y.tab.c"
    break;

  case 69: /* virgulaPassagemParametrosOuVazio: ',' passagemParametros  */
#line 246 "parser.y"
                                                                {(yyval.ast) = (yyvsp[0].ast);}
#line 1803 "y.tab.c"
    break;

  case 70: /* virgulaPassagemParametrosOuVazio: %empty  */
#line 247 "parser.y"
                                                                {(yyval.ast) = NULL;}
#line 1809 "y.tab.c"
    break;

  case 71: /* passagemListaParametros: passagemParametros  */
#line 250 "parser.y"
                                                {(yyval.ast) = (yyvsp[0].ast);}
#line 1815 "y.tab.c"
    break;

  case 72: /* passagemListaParametros: %empty  */
#line 251 "parser.y"
                                                {(yyval.ast) = NULL;}
#line 1821 "y.tab.c"
    break;


#line 1825 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 254 "parser.y"


int yyerror(char *msg){
    fprintf(stderr, "\n\nSyntax error at line %d!!!\n\n", getLineNumber());
    exit(3);
}
