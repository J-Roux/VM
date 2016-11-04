%option noyywrap
%{ 
#include <stdio.h>
#include "../../YASM_VM/src/command.h"


        //        ADD_BYTE, ADD_SHORT, ADD_INT, ADD_LONG,
        //        SUB_BYTE, SUB_SHORT, SUB_INT, SUB_LONG,
        //        MUL_BYTE, MUL_SHORT, MUL_INT, MUL_LONG,
        //        DIV_BYTE, DIV_SHORT, DIV_INT, DIV_LONG, DIV_SBYTE, DIV_SSHORT, DIV_SINT, DIV_SLONG,
        //        AND_BYTE, AND_SHORT, AND_INT, AND_LONG,
        //        OR_BYTE, OR_SHORT, OR_INT, OR_LONG,
        //        SHR_BYTE, SHR_SHORT, SHR_INT, SHR_LONG,
        //        SHL_BYTE, SHL_SHORT, SHL_INT, SHL_LONG,
        //        EQ_BYTE, EQ_SHORT, EQ_INT, EQ_LONG, EQ_SBYTE, EQ_SSHORT, EQ_SINT, EQ_SLONG,
        //        NEQ_BYTE, NEQ_SHORT, NEQ_INT, NEQ_LONG, NEQ_SBYTE, NEQ_SSHORT, NEQ_SINT, NEQ_SLONG,
        //        LT_BYTE, LT_SHORT, LT_INT, LT_LONG, LT_SBYTE, LT_SSHORT, LT_SINT, LT_SLONG,
        //        LEQ_BYTE, LEQ_SHORT, LEQ_INT, LEQ_LONG, LEQ_SBYTE, LEQ_SSHORT, LEQ_SINT, LEQ_SLONG,
        //        GT_BYTE, GT_SHORT, GT_INT, GT_LONG, GT_SBYTE, GT_SSHORT, GT_SINT, GT_SLONG,
        //        GEQ_BYTE, GEQ_SHORT, GEQ_INT, GEQ_LONG, GEQ_SBYTE, GEQ_SSHORT, GEQ_SINT, GEQ_SLONG,
        //        INC_BYTE, INC_SHORT, INC_INT, INC_LONG,
        //        DEC_BYTE, DEC_SHORT, DEC_INT, DEC_LONG,
        //        NEG_SBYTE, NEG_SSHORT, NEG_SINT, NEG_SLONG,
        //        LNOT_BYTE, LNOT_SHORT, LNOT_INT, LNOT_LONG,
        //        NOT_BYTE, NOT_SHORT, NOT_INT, NOT_LONG,
        //      // branch
        //        JMP, JT, JF,
        //      // mem
        //        PUSH, POP, ERASE, PUSH_BYTE, PUSH_SHORT, PUSH_INT, PUSH_LONG, POP_BYTE, POP_SHORT, POP_INT, POP_LONG,
        //      // type cast
        //         ONE_TO_TWO, ONE_TO_FOUR, TWO_TO_ONE, TWO_TO_FOUR, FOUR_TO_ONE, FOUR_TO_TWO

        typedef enum{
                _PLUS_OP = RET,
                _MINUS_OP,
                _MUL_OP,
                _DIV_OP,
                _INDENT,
                _OUTDENT,
                _LABEL
        } OPERATORS;


#define LEXER_DEBUG 0
%}

/* Lexemes */



/* Arithmetic */
PLUS_OP          \+
MINUS_OP         \-
MUL_OP           \*
DIV_OP           \/
INDENT           \(
OUTDENT          \)



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
{COMMENT}      /* Ignore comments */



{ADD_BYTE}        {  return ADD_BYTE; }
{ADD_SHORT}       {  return ADD_SHORT; }
{ADD_INT}         {  return ADD_INT; }
{ADD_LONG}        {  return ADD_LONG; }

{SUB_BYTE}        {  return SUB_BYTE; }
{SUB_SHORT}       {  return SUB_SHORT; }
{SUB_INT}         {  return SUB_INT; }
{SUB_LONG}        {  return SUB_LONG; }

{MUL_BYTE}        {  return MUL_BYTE; }
{MUL_SHORT}       {  return MUL_SHORT; }
{MUL_INT}         {  return MUL_INT; }
{MUL_LONG}        {  return MUL_LONG; }

{DIV_BYTE}        {  return DIV_BYTE; }
{DIV_SHORT}       {  return DIV_SHORT; }
{DIV_INT}         {  return DIV_INT; }
{DIV_LONG}        {  return DIV_LONG; }
{DIV_SBYTE}       {  return DIV_SBYTE; }
{DIV_SSHORT}      {  return DIV_SSHORT; }
{DIV_SINT}        {  return DIV_SINT; }
{DIV_SLONG}       {  return DIV_SLONG; }

{AND_BYTE}        {  return AND_BYTE; }
{AND_SHORT}       {  return AND_SHORT; }
{AND_INT}         {  return AND_INT; }
{AND_LONG}        {  return AND_LONG; }

{OR_BYTE}         {  return OR_BYTE; }
{OR_SHORT}        {  return OR_SHORT; }
{OR_INT}          {  return OR_INT; }
{OR_LONG}         {  return OR_LONG; }

{SHR_BYTE}        {  return SHR_BYTE; }
{SHR_SHORT}       {  return SHR_SHORT; }
{SHR_INT}         {  return SHR_INT; }
{SHR_LONG}        {  return SHR_LONG; }

{SHL_BYTE}        {  return SHL_BYTE; }
{SHL_SHORT}       {  return SHL_SHORT; }
{SHL_INT}         {  return SHL_INT; }
{SHL_LONG}        {  return SHL_LONG; }

{EQ_BYTE}         {  return EQ_BYTE; }
{EQ_SHORT}        {  return EQ_SHORT; }
{EQ_INT}          {  return EQ_INT; }
{EQ_LONG}         {  return EQ_LONG; }
{EQ_SBYTE}        {  return EQ_SBYTE; }
{EQ_SSHORT}       {  return EQ_SSHORT; }
{EQ_SINT}         {  return EQ_SINT; }
{EQ_SLONG}        {  return EQ_SLONG; }

{NEQ_BYTE}        {  return NEQ_BYTE; }
{NEQ_SHORT}       {  return NEQ_SHORT; }
{NEQ_INT}         {  return NEQ_INT; }
{NEQ_LONG}        {  return NEQ_LONG; }
{NEQ_SBYTE}       {  return NEQ_SBYTE; }
{NEQ_SSHORT}      {  return NEQ_SSHORT; }
{NEQ_SINT}        {  return NEQ_SINT; }
{NEQ_SLONG}       {  return NEQ_SLONG; }

{LT_BYTE}         {  return LT_BYTE; }
{LT_SHORT}        {  return LT_SHORT; }
{LT_INT}          {  return LT_INT; }
{LT_LONG}         {  return LT_LONG; }
{LT_SBYTE}        {  return LT_SBYTE; }
{LT_SSHORT}       {  return LT_SSHORT; }
{LT_SINT}         {  return LT_SINT; }
{LT_SLONG}        {  return LT_SLONG; }

{LEQ_BYTE}        {  return LEQ_BYTE; }
{LEQ_SHORT}       {  return LEQ_SHORT; }
{LEQ_INT}         {  return LEQ_INT; }
{LEQ_LONG}        {  return LEQ_LONG; }
{LEQ_SBYTE}       {  return LEQ_SBYTE; }
{LEQ_SSHORT}      {  return LEQ_SSHORT; }
{LEQ_SINT}        {  return LEQ_SINT; }
{LEQ_SLONG}       {  return LEQ_SLONG; }

{GT_BYTE}         {  return GT_BYTE; }
{GT_SHORT}        {  return GT_SHORT; }
{GT_INT}          {  return GT_INT; }
{GT_LONG}         {  return GT_LONG; }
{GT_SBYTE}        {  return GT_SBYTE; }
{GT_SSHORT}       {  return GT_SSHORT; }
{GT_SINT}         {  return GT_SINT; }
{GT_SLONG}        {  return GT_SLONG; }

{GEQ_BYTE}        {  return GEQ_BYTE; }
{GEQ_SHORT}       {  return GEQ_SHORT; }
{GEQ_INT}         {  return GEQ_INT; }
{GEQ_LONG}        {  return GEQ_LONG; }
{GEQ_SBYTE}       {  return GEQ_SBYTE; }
{GEQ_SSHORT}      {  return GEQ_SSHORT; }
{GEQ_SINT}        {  return GEQ_SINT; }
{GEQ_SLONG}       {  return GEQ_SLONG; }

{INC_BYTE}        {  return INC_BYTE; }
{INC_SHORT}       {  return INC_SHORT; }
{INC_INT}         {  return INC_INT; }
{INC_LONG}        {  return INC_LONG; }

{DEC_BYTE}        {  return DEC_BYTE; }
{DEC_SHORT}       {  return DEC_SHORT; }
{DEC_INT}         {  return DEC_INT; }
{DEC_LONG}        {  return DEC_LONG; }

{NEG_SBYTE}       {  return NEG_SBYTE; }
{NEG_SSHORT}      {  return NEG_SSHORT; }
{NEG_SINT}        {  return NEG_SINT; }
{NEG_SLONG}       {  return NEG_SLONG; }

{LNOT_BYTE}       {  return LNOT_BYTE; }
{LNOT_SHORT}      {  return LNOT_SHORT; }
{LNOT_INT}        {  return LNOT_INT; }
{LNOT_LONG}       {  return LNOT_LONG; }

{NOT_BYTE}        {  return NOT_BYTE; }
{NOT_SHORT}       {  return NOT_SHORT; }
{NOT_INT}         {  return NOT_INT; }
{NOT_LONG}        {  return NOT_LONG; }


{JMP}             {  return JMP; }
{JT}              {  return JT; }
{JF}              {  return JF; }

{PUSH}            {  return PUSH; }
{POP}             {  return POP; }
{ERASE}           {  return ERASE; }
{PUSH_BYTE}       {  return PUSH_BYTE; }
{PUSH_SHORT}      {  return PUSH_SHORT; }
{PUSH_INT}        {  return PUSH_INT; }
{PUSH_LONG}       {  return PUSH_LONG; }
{POP_BYTE}        {  return POP_BYTE; }
{POP_SHORT}       {  return POP_SHORT; }
{POP_INT}         {  return POP_INT; }
{POP_LONG}        {  return POP_LONG; }

{CALL}            {  return ADD_LONG; }
{RET}             {  return ADD_LONG; }
{ID}              { printf("id"); }




{DIV_OP}        {return _DIV_OP;  }
{MUL_OP}        {return _MUL_OP;  }
{MINUS_OP}      {return _MINUS_OP;  }
{PLUS_OP}       {return _PLUS_OP; }
{WS}+          /* Ignore whitespace */
{INDENT}        return _INDENT;
{OUTDENT}       return _OUTDENT;


%%
int main()
{
        yylex();
        return 0;
}
