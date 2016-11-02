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

{PLUS_OP}      return _PLUS_OP;
{MINUS_OP}     return _MINUS_OP;
{MUL_OP}       return _MUL_OP;
{DIV_OP}       return _DIV_OP;

{ASSIGN_OP}    return _ASSIGN_OP;
{EQUALS_OP}    return _EQUALS_OP;
{NOT_EQ_OP}    return _NOT_EQ_OP;
{NOT_OP}       return _NOT_OP;
{AND_OP}       return _AND_OP;
{OR_OP}        return _OR_OP;
{XOR_OP}       return _XOR_OP;
{NOR_OP}       return _NOR_OP;
{XNOR_OP}      return _XNOR_OP;
{INC_OP}       return _INC_OP;
{DEC_OP}       return _DEC_OP;
{OF_OP}        return _OF_OP;

{CALL_KW}      return _CALL_KW;
{IF_KW}        return _IF_KW;
{UNLESS_KW}    return _UNLESS_KW; 
{WHILE_KW}     return _WHILE_KW;
{UNTIL_KW}     return _UNTIL_KW;
{WITH_KW}      return _WITH_KW;
{PROJECTS_TO}  return _PROJECTS_TO;
{COMMA}        return _COMMA;
{HASH}         return _HASH;
{FUNCTION_KW}  return _FUNCTION_KW;
{END_KW}       return _END_KW;
{THEN_KW}      return _THEN_KW;



{INDENT}       return _INDENT;
{OUTDENT}      return _OUTDENT;

{WS}+          /* Ignore whitespace */
%%
