%{
#define PRINT_AST 0
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "node.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
struct Node* lastBlock;
 
void yyerror(const char *str) {
  fprintf(stderr, "error: %s\n", str);
  exit(1);
}


int main(int argc, char** argv) {
  if(argc < 2) {
    printf("No input file!\n");
    return 1;
  }
  yyin = fopen(argv[1], "r");
  yyparse();
  return 0;
}

%}




%union
{
  int64_t numeric;
  char* string;
  struct Node* node;
  struct Value* value;
}


%token _ADD_BYTE  _ADD_SHORT  _ADD_INT  _ADD_LONG
%token _SUB_BYTE  _SUB_SHORT  _SUB_INT  _SUB_LONG
%token _MUL_BYTE  _MUL_SHORT  _MUL_INT  _MUL_LONG
%token _DIV_BYTE  _DIV_SHORT  _DIV_INT  _DIV_LONG  _DIV_SBYTE  _DIV_SSHORT  _DIV_SINT  _DIV_SLONG
%token _AND_BYTE  _AND_SHORT  _AND_INT  _AND_LONG
%token _OR_BYTE   _OR_SHORT   _OR_INT   _OR_LONG
%token _SHR_BYTE  _SHR_SHORT  _SHR_INT  _SHR_LONG
%token _SHL_BYTE  _SHL_SHORT  _SHL_INT  _SHL_LONG
%token _EQ_BYTE   _EQ_SHORT   _EQ_INT   _EQ_LONG  _EQ_SBYTE  _EQ_SSHORT  _EQ_SINT  _EQ_SLONG
%token _NEQ_BYTE  _NEQ_SHORT  _NEQ_INT  _NEQ_LONG  _NEQ_SBYTE  _NEQ_SSHORT  _NEQ_SINT  _NEQ_SLONG
%token _LT_BYTE   _LT_SHORT   _LT_INT   _LT_LONG  _LT_SBYTE  _LT_SSHORT  _LT_SINT  _LT_SLONG
%token _LEQ_BYTE  _LEQ_SHORT  _LEQ_INT  _LEQ_LONG  _LEQ_SBYTE  _LEQ_SSHORT  _LEQ_SINT  _LEQ_SLONG
%token _GT_BYTE   _GT_SHORT   _GT_INT   _GT_LONG  _GT_SBYTE  _GT_SSHORT  _GT_SINT  _GT_SLONG
%token _GEQ_BYTE  _GEQ_SHORT  _GEQ_INT  _GEQ_LONG  _GEQ_SBYTE  _GEQ_SSHORT  _GEQ_SINT  _GEQ_SLONG
%token _INC_BYTE  _INC_SHORT  _INC_INT  _INC_LONG
%token _DEC_BYTE  _DEC_SHORT  _DEC_INT  _DEC_LONG
%token _NEG_SBYTE _NEG_SSHORT _NEG_SINT _NEG_SLONG
%token _LNOT_BYTE _LNOT_SHORT _LNOT_INT _LNOT_LONG
%token _NOT_BYTE  _NOT_SHORT  _NOT_INT  _NOT_LONG

%token _JMP _JT _JF
%token _LABEL
%token _PUSH _POP _ERASE _PUSH_BYTE _PUSH_SHORT _PUSH_INT _PUSH_LONG _POP_BYTE _POP_SHORT _POP_INT _POP_LONG
%token <string> _ID
%token <numeric> _NUMERIC
%token _INDENT _OUTDENT
%token _NEW_LINE


%left _PLUS_OP _MINUS_OP
%left _MUL_OP _DIV_OP
%left _AND_OP _OR_OP
%left _EQUALS_OP
%left _NOT_OP

%type<node> expr


%%
axiom:
      | statement_list


statement_list: statement _NEW_LINE
                |statement_list statement _NEW_LINE
statement:
            | command
            | mem_statement
            | label
            | expr


label: _LABEL id

id: _ID

command:  _ADD_BYTE
        | _ADD_SHORT
        | _ADD_INT
        | _ADD_LONG
        | _SUB_BYTE
        | _SUB_SHORT
        | _SUB_INT
        | _SUB_LONG
        | _DIV_BYTE
        | _DIV_SHORT
        | _DIV_INT
        | _DIV_LONG

mem_statement: _PUSH_BYTE
             | _PUSH_SHORT
             | _PUSH_INT
             | _PUSH_LONG
             | _POP_BYTE
             | _POP_INT
             | _POP_SHORT
             | _POP_LONG
             | _POP expr
             | _PUSH expr

expr:
     | expr _MUL_OP expr        {  $$ = createNode($1, $3, _MUL_OP); }
     | expr _DIV_OP expr        {/* $$ = $1->numeric / $3->numeric; */}
     | expr _PLUS_OP expr       {/* $$ = $1->numeric + $3->numeric; */}
     | expr _MINUS_OP expr      { /*$$ = $1->numeric - $3->numeric; */}
     | expr _AND_OP expr
     | expr _OR_OP expr
     | _NOT_OP expr
     | _NUMERIC
%%
