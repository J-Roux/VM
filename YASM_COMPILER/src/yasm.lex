%option noyywrap
%{ 
#include <stdio.h>
#include "../../YASM_VM/src/command.h"
#include "parser.h"



   

#define LEXER_DEBUG 0
%}

/* Lexemes */



/* Arithmetic */

PLUS_OP          \+
MINUS_OP         \-
MUL_OP           \*
DIV_OP           \/
AND_OP           \&
OR_OP            \|
NOT_OP           \~
INDENT           \(
OUTDENT          \)
LABEL            \:


ADD_BYTE        addb
ADD_SHORT       adds
ADD_INT         addi
ADD_LONG        addl

SUB_BYTE        subb
SUB_SHORT       subs
SUB_INT         subi
SUB_LONG        subl

MUL_BYTE        mulb
MUL_SHORT       muls
MUL_INT         muli
MUL_LONG        mull

DIV_BYTE        divb
DIV_SHORT       divs
DIV_INT         divi
DIV_LONG        divl
DIV_SBYTE       divsb
DIV_SSHORT      divss
DIV_SINT        divsi
DIV_SLONG       divsl

AND_BYTE        andb
AND_SHORT       ands
AND_INT         andi
AND_LONG        andl

OR_BYTE         orb
OR_SHORT        ors
OR_INT          ori
OR_LONG         orl

SHR_BYTE        shrb
SHR_SHORT       shrs
SHR_INT         shri
SHR_LONG        shrl

SHL_BYTE        shlb
SHL_SHORT       shls
SHL_INT         shli
SHL_LONG        shll

EQ_BYTE         eqb
EQ_SHORT        eqs
EQ_INT          eqi
EQ_LONG         eql
EQ_SBYTE        eqsb
EQ_SSHORT       eqss
EQ_SINT         eqsi
EQ_SLONG        eqsl

NEQ_BYTE        neqb
NEQ_SHORT       neqs
NEQ_INT         neqi
NEQ_LONG        neql
NEQ_SBYTE       neqsb
NEQ_SSHORT      neqss
NEQ_SINT        neqsi
NEQ_SLONG       neqsl

LT_BYTE         ltb
LT_SHORT        lts
LT_INT          lti
LT_LONG         ltl
LT_SBYTE        ltsb
LT_SSHORT       ltss
LT_SINT         ltsi
LT_SLONG        ltsl

LEQ_BYTE        leqb
LEQ_SHORT       leqs
LEQ_INT         leqi
LEQ_LONG        leql
LEQ_SBYTE       leqsb
LEQ_SSHORT      leqss
LEQ_SINT        leqsi
LEQ_SLONG       leqsl

GT_BYTE         gtb
GT_SHORT        gts
GT_INT          gti
GT_LONG         gtl
GT_SBYTE        gtsb
GT_SSHORT       gtss
GT_SINT         gtsi
GT_SLONG        gtsl

GEQ_BYTE        geqb
GEQ_SHORT       geqs
GEQ_INT         geqi
GEQ_LONG        geql
GEQ_SBYTE       geqsb
GEQ_SSHORT      geqss
GEQ_SINT        geqsi
GEQ_SLONG       geqsl

INC_BYTE        incb
INC_SHORT       incs
INC_INT         inci
INC_LONG        incl

DEC_BYTE        decb
DEC_SHORT       decs
DEC_INT         deci
DEC_LONG        decl

NEG_SBYTE       negb
NEG_SSHORT      negs
NEG_SINT        negi
NEG_SLONG       negl

LNOT_BYTE       lnotb
LNOT_SHORT      lnots
LNOT_INT        lnoti
LNOT_LONG       lnotl

NOT_BYTE        notb
NOT_SHORT       nots
NOT_INT         noti
NOT_LONG        notl


JMP             jmp
JT              jt
JF              jf

PUSH            push
POP             pop
ERASE           erase
PUSH_BYTE       pushb
PUSH_SHORT      pushs
PUSH_INT        pushi
PUSH_LONG       pushl
POP_BYTE        popb
POP_SHORT       pops
POP_INT         popi
POP_LONG        popl

CALL            call
RET             ret

ID               [a-zA-Z][a-zA-Z0-9]*
NUMERIC          [0-9]+
WS               [ \n\r\t]
COMMENT          #.*

%%
{COMMENT}     /* Ignore comments */

{LABEL}           { return _LABEL; }

{ADD_BYTE}        {  return _ADD_BYTE; }
{ADD_SHORT}       {  return _ADD_SHORT; }
{ADD_INT}         {  return _ADD_INT; }
{ADD_LONG}        {  return _ADD_LONG; }

{SUB_BYTE}        {  return _SUB_BYTE; }
{SUB_SHORT}       {  return _SUB_SHORT; }
{SUB_INT}         {  return _SUB_INT; }
{SUB_LONG}        {  return _SUB_LONG; }

{MUL_BYTE}        {  return _MUL_BYTE; }
{MUL_SHORT}       {  return _MUL_SHORT; }
{MUL_INT}         {  return _MUL_INT; }
{MUL_LONG}        {  return _MUL_LONG; }

{DIV_BYTE}        {  return _DIV_BYTE; }
{DIV_SHORT}       {  return _DIV_SHORT; }
{DIV_INT}         {  return _DIV_INT; }
{DIV_LONG}        {  return _DIV_LONG; }
{DIV_SBYTE}       {  return _DIV_SBYTE; }
{DIV_SSHORT}      {  return _DIV_SSHORT; }
{DIV_SINT}        {  return _DIV_SINT; }
{DIV_SLONG}       {  return _DIV_SLONG; }

{AND_BYTE}        {  return _AND_BYTE; }
{AND_SHORT}       {  return _AND_SHORT; }
{AND_INT}         {  return _AND_INT; }
{AND_LONG}        {  return _AND_LONG; }

{OR_BYTE}         {  return _OR_BYTE; }
{OR_SHORT}        {  return _OR_SHORT; }
{OR_INT}          {  return _OR_INT; }
{OR_LONG}         {  return _OR_LONG; }

{SHR_BYTE}        {  return _SHR_BYTE; }
{SHR_SHORT}       {  return _SHR_SHORT; }
{SHR_INT}         {  return _SHR_INT; }
{SHR_LONG}        {  return _SHR_LONG; }

{SHL_BYTE}        {  return _SHL_BYTE; }
{SHL_SHORT}       {  return _SHL_SHORT; }
{SHL_INT}         {  return _SHL_INT; }
{SHL_LONG}        {  return _SHL_LONG; }

{EQ_BYTE}         {  return _EQ_BYTE; }
{EQ_SHORT}        {  return _EQ_SHORT; }
{EQ_INT}          {  return _EQ_INT; }
{EQ_LONG}         {  return _EQ_LONG; }
{EQ_SBYTE}        {  return _EQ_SBYTE; }
{EQ_SSHORT}       {  return _EQ_SSHORT; }
{EQ_SLONG}        {  return _EQ_SLONG; }
{EQ_SINT}         {  return _EQ_SINT; }

{NEQ_BYTE}        {  return _NEQ_BYTE; }
{NEQ_SHORT}       {  return _NEQ_SHORT; }
{NEQ_INT}         {  return _NEQ_INT; }
{NEQ_LONG}        {  return _NEQ_LONG; }
{NEQ_SBYTE}       {  return _NEQ_SBYTE; }
{NEQ_SSHORT}      {  return _NEQ_SSHORT; }
{NEQ_SINT}        {  return _NEQ_SINT; }
{NEQ_SLONG}       {  return _NEQ_SLONG; }

{LT_BYTE}         {  return _LT_BYTE; }
{LT_SHORT}        {  return _LT_SHORT; }
{LT_INT}          {  return _LT_INT; }
{LT_LONG}         {  return _LT_LONG; }
{LT_SBYTE}        {  return _LT_SBYTE; }
{LT_SSHORT}       {  return _LT_SSHORT; }
{LT_SINT}         {  return _LT_SINT; }
{LT_SLONG}        {  return _LT_SLONG; }

{LEQ_BYTE}        {  return _LEQ_BYTE; }
{LEQ_SHORT}       {  return _LEQ_SHORT; }
{LEQ_INT}         {  return _LEQ_INT; }
{LEQ_LONG}        {  return _LEQ_LONG; }
{LEQ_SBYTE}       {  return _LEQ_SBYTE; }
{LEQ_SSHORT}      {  return _LEQ_SSHORT; }
{LEQ_SINT}        {  return _LEQ_SINT; }
{LEQ_SLONG}       {  return _LEQ_SLONG; }

{GT_BYTE}         {  return _GT_BYTE; }
{GT_SHORT}        {  return _GT_SHORT; }
{GT_INT}          {  return _GT_INT; }
{GT_LONG}         {  return _GT_LONG; }
{GT_SBYTE}        {  return _GT_SBYTE; }
{GT_SSHORT}       {  return _GT_SSHORT; }
{GT_SINT}         {  return _GT_SINT; }
{GT_SLONG}        {  return _GT_SLONG; }

{GEQ_BYTE}        {  return _GEQ_BYTE; }
{GEQ_SHORT}       {  return _GEQ_SHORT; }
{GEQ_INT}         {  return _GEQ_INT; }
{GEQ_LONG}        {  return _GEQ_LONG; }
{GEQ_SBYTE}       {  return _GEQ_SBYTE; }
{GEQ_SSHORT}      {  return _GEQ_SSHORT; }
{GEQ_SINT}        {  return _GEQ_SINT; }
{GEQ_SLONG}       {  return _GEQ_SLONG; }

{INC_BYTE}        {  return _INC_BYTE; }
{INC_SHORT}       {  return _INC_SHORT; }
{INC_INT}         {  return _INC_INT; }
{INC_LONG}        {  return _INC_LONG; }

{DEC_BYTE}        {  return _DEC_BYTE; }
{DEC_SHORT}       {  return _DEC_SHORT; }
{DEC_INT}         {  return _DEC_INT; }
{DEC_LONG}        {  return _DEC_LONG; }

{NEG_SBYTE}       {  return _NEG_SBYTE; }
{NEG_SSHORT}      {  return _NEG_SSHORT; }
{NEG_SINT}        {  return _NEG_SINT; }
{NEG_SLONG}       {  return _NEG_SLONG; }

{LNOT_BYTE}       {  return _LNOT_BYTE; }
{LNOT_SHORT}      {  return _LNOT_SHORT; }
{LNOT_INT}        {  return _LNOT_INT; }
{LNOT_LONG}       {  return _LNOT_LONG; }

{NOT_BYTE}        {  return _NOT_BYTE; }
{NOT_SHORT}       {  return _NOT_SHORT; }
{NOT_INT}         {  return _NOT_INT; }
{NOT_LONG}        {  return _NOT_LONG; }


{JMP}             {  return _JMP; }
{JT}              {  return _JT; }
{JF}              {  return _JF; }

{PUSH}            {  return _PUSH; }
{POP}             {  return _POP; }
{ERASE}           {  return _ERASE; }
{PUSH_BYTE}       {  return _PUSH_BYTE; }
{PUSH_SHORT}      {  return _PUSH_SHORT; }
{PUSH_INT}        {  return _PUSH_INT; }
{PUSH_LONG}       {  return _PUSH_LONG; }
{POP_BYTE}        {  return _POP_BYTE; }
{POP_SHORT}       {  return _POP_SHORT; }
{POP_INT}         {  return _POP_INT; }
{POP_LONG}        {  return _POP_LONG; }

{CALL}            {  return _ADD_LONG; }
{RET}             {  return _ADD_LONG; }
{ID}              { yylval.string = strdup(yytext); return _ID;  }
{NUMERIC}         { yylval.numeric = atoi(yytext); return _NUMERIC;}



{DIV_OP}        {return _DIV_OP;  }
{MUL_OP}        {return _MUL_OP;  }
{MINUS_OP}      {return _MINUS_OP;  }
{PLUS_OP}       {return _PLUS_OP; }
{WS}+          /* Ignore whitespace */
{INDENT}        return _INDENT;
{OUTDENT}       return _OUTDENT;


%%

