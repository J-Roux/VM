/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 47 "YASM_COMPILER/src/parcer.y" /* yacc.c:1909  */

  int64_t numeric;
  char* string;
  struct Node* node;
  struct Value* value;

#line 198 "/home/pavel/workspace/YASM/YASM_COMPILER/src/parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_PAVEL_WORKSPACE_YASM_YASM_COMPILER_SRC_PARSER_H_INCLUDED  */
