/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 104 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
