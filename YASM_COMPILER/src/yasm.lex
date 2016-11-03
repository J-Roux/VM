%option noyywrap
%{ 
#include <stdio.h>
#include "../../YASM_VM/src/command.h"

#define LEXER_DEBUG 0
%}

/* Lexemes */
ID               [A-z_][A-z0-9_]*
NUMERIC          [0-9]+


/* Arithmetic */
PLUS_OP          \+
MINUS_OP         \-
MUL_OP           \*
DIV_OP           \/




ASSIGN_OP        (set|=)
EQUALS_OP        is
NOT_EQ_OP        isnt
NOT_OP           not
AND_OP           and
OR_OP            or
XOR_OP           xor
NOR_OP           nor
XNOR_OP          xnor
INC_OP           inc
DEC_OP           dec
OF_OP            of

/* Keywords and aux. */
INDENT           \(
OUTDENT          \)
PROJECTS_TO      (=>)
THEN_KW          (then|do)
IF_KW            (if)
UNLESS_KW        (unless)
WHILE_KW         (while)
UNTIL_KW         (until)
FUNCTION_KW      (function|lambda)
END_KW           (end)
COMMA            ,
WITH_KW          (with)
CALL_KW          (call|exec)
WS               [ \n\r\t]
HASH             (@)
COMMENT          #.*

%%
{COMMENT}      /* Ignore comments */

{PLUS_OP}      {printf("\nплюс");}
{WS}+          /* Ignore whitespace */
%%
int main()
{
        yylex();

        return 0;
}
