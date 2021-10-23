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

#line 163 "asgn5_19CS10064_19CS30008.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASGN5_19CS10064_19CS30008_TAB_H_INCLUDED  */
