%{
#define PRINT_AST 0
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "node.h"
#include <stdlib.h>

#include "../../YASM_VM/src/command.h"


extern int yylex();
extern int yyparse();
extern FILE* yyin;



void yyerror(const char *str) {
  fprintf(stderr, "error: %s\n", str);
  exit(1);
}


int main(int argc, char** argv) {
  FILE * f;
  if(argc < 2) {
    printf("No input file!\n");
    return 1;
  }
  yyin = fopen(argv[1], "r");
  yyparse();
  push_byte(END);
  printf("program size = %i\n", pointer);
  f = fopen("result.elf","wb");
  fwrite(data, 1, pointer, f);
  fclose(f);
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
%token _DUB_OP
%token _JMP _JT _JF
%token _LABEL _CALL_OP
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

%type<numeric> expr
%type<string> id

%%
axiom:
      | statement_list


statement_list: statement _NEW_LINE
                |statement_list statement _NEW_LINE
statement:
            | command
            | mem_statement
            | label
            | _NUMERIC    { push_value($1); }
            | call_statement
            | jmp_statement
            | dub_statement
            ;

dub_statement: _DUB_OP  expr { push_byte(DUB); push_short(get_id_value($2));}

jmp_statement:
              |_JMP id     { push_byte(JMP); push_short(get_id_value($2)); }
              | _JF id     { push_byte(JF); push_short(get_id_value($2)); }
              | _JT id     { push_byte(JT); push_short(get_id_value($2)); }

call_statement: _CALL_OP expr {push_byte(CALL); push_value($2);}


label:  id  _LABEL  { add_to_map($1, pointer); }

id: _ID

command:  _ADD_BYTE       { push_byte(ADD_BYTE); }
        | _ADD_SHORT      { push_byte(ADD_SHORT); }
        | _ADD_INT        { push_byte(ADD_INT); }
        | _ADD_LONG       { push_byte(ADD_LONG); }
        | _SUB_BYTE       { push_byte(SUB_BYTE); }
        | _SUB_SHORT      { push_byte(SUB_SHORT); }
        | _SUB_INT        { push_byte(SUB_INT); }
        | _SUB_LONG       { push_byte(SUB_LONG); }
        | _DIV_BYTE       { push_byte(DIV_BYTE); }
        | _DIV_SHORT      { push_byte(DIV_SHORT); }
        | _DIV_INT        { push_byte(DIV_INT); }
        | _DIV_LONG       { push_byte(DIV_LONG); }
        | _DIV_SBYTE      { push_byte(DIV_SBYTE); }
        | _DIV_SHORT      { push_byte(DIV_SSHORT); }
        | _DIV_SINT       { push_byte(DIV_SINT); }
        | _DIV_SLONG      { push_byte(DIV_SLONG); }
        | _AND_BYTE       { push_byte(AND_BYTE);}
        | _AND_SHORT      { push_byte(AND_SHORT);}
        | _AND_INT        { push_byte(AND_INT);}
        | _AND_LONG       { push_byte(AND_LONG);}
        | _OR_BYTE        { push_byte(OR_BYTE); }
        | _OR_SHORT       { push_byte(OR_SHORT); }
        | _OR_INT         { push_byte(OR_INT); }
        | _OR_LONG        { push_byte(OR_LONG); }
        | _SHR_BYTE       { push_byte(SHR_BYTE); }
        | _SHR_SHORT      { push_byte(SHR_SHORT); }
        | _SHR_INT        { push_byte(SHR_INT); }
        | _SHR_LONG       { push_byte(SHR_LONG); }
        | _SHL_BYTE       { push_byte(SHL_BYTE); }
        | _SHL_SHORT      { push_byte(SHL_SHORT); }
        | _SHL_INT        { push_byte(SHL_INT); }
        | _SHL_LONG       { push_byte(SHL_LONG); }
        | _EQ_BYTE        { push_byte(EQ_BYTE); }
        | _EQ_SHORT       { push_byte(EQ_SHORT); }
        | _EQ_INT         { push_byte(EQ_INT); }
        | _EQ_LONG        { push_byte(EQ_LONG); }
        | _EQ_SBYTE       { push_byte(EQ_SBYTE); }
        | _EQ_SSHORT      { push_byte(EQ_SSHORT); }
        | _EQ_SINT        { push_byte(EQ_SINT); }
        | _EQ_SLONG       { push_byte(EQ_SLONG); }
        | _NEQ_BYTE       { push_byte(NEQ_BYTE); }
        | _NEQ_SHORT      { push_byte(NEQ_SHORT); }
        | _NEQ_INT        { push_byte(NEQ_INT); }
        | _NEQ_LONG       { push_byte(NEQ_LONG); }
        | _NEQ_SBYTE      { push_byte(NEQ_SBYTE); }
        | _NEQ_SSHORT     { push_byte(NEQ_SSHORT); }
        | _NEQ_SINT       { push_byte(NEQ_SINT); }
        | _NEQ_SLONG      { push_byte(NEQ_SLONG); }
        | _LT_BYTE        { push_byte(LT_BYTE); }
        | _LT_SHORT       { push_byte(LT_SHORT); }
        | _LT_INT         { push_byte(LT_INT); }
        | _LT_LONG        { push_byte(LT_LONG); }
        | _LT_SBYTE       { push_byte(LT_SBYTE); }
        | _LT_SSHORT      { push_byte(LT_SSHORT); }
        | _LT_SINT        { push_byte(LT_SINT); }
        | _LT_SLONG       { push_byte(LT_SLONG); }
        | _LEQ_BYTE       { push_byte(LEQ_BYTE); }
        | _LEQ_SHORT      { push_byte(LEQ_SHORT); }
        | _LEQ_INT        { push_byte(LEQ_INT); }
        | _LEQ_LONG       { push_byte(LEQ_LONG); }
        | _LEQ_SBYTE      { push_byte(LEQ_SBYTE); }
        | _LEQ_SSHORT     { push_byte(LEQ_SSHORT); }
        | _LEQ_SINT       { push_byte(LEQ_SINT); }
        | _LEQ_SLONG      { push_byte(LEQ_SLONG); }
        | _GT_BYTE        { push_byte(GT_BYTE); }
        | _GT_SHORT       { push_byte(GT_SHORT); }
        | _GT_INT         { push_byte(GT_INT); }
        | _GT_LONG        { push_byte(GT_LONG); }
        | _GT_SBYTE       { push_byte(GT_SBYTE); }
        | _GT_SSHORT      { push_byte(GT_SSHORT); }
        | _GT_SINT        { push_byte(GT_SINT); }
        | _GT_SLONG       { push_byte(GT_SLONG); }
        | _GEQ_BYTE       { push_byte(GEQ_BYTE); }
        | _GEQ_SHORT      { push_byte(GEQ_SHORT); }
        | _GEQ_INT        { push_byte(GEQ_INT); }
        | _GEQ_LONG       { push_byte(GEQ_LONG); }
        | _GEQ_SBYTE      { push_byte(GEQ_SBYTE); }
        | _GEQ_SSHORT     { push_byte(GEQ_SSHORT); }
        | _GEQ_SINT       { push_byte(GEQ_SINT); }
        | _GEQ_SLONG      { push_byte(GEQ_SLONG); }

mem_statement: _PUSH_BYTE       {push_byte(PUSH_BYTE);}
             | _PUSH_SHORT      {push_byte(PUSH_SHORT);}
             | _PUSH_INT        {push_byte(PUSH_INT);}
             | _PUSH_LONG       {push_byte(PUSH_LONG);}
             | _POP_BYTE        {push_byte(POP_BYTE);}
             | _POP_INT         {push_byte(POP_INT);}
             | _POP_SHORT       {push_byte(POP_SHORT);}
             | _POP_LONG        {push_byte(POP_LONG);}
             | _POP expr        {push_byte(POP); push_value($2);}
             | _PUSH expr       {push_byte(PUSH); push_value($2);}

expr:
     | expr _MUL_OP expr        { $$ = $1 * $3; }
     | expr _DIV_OP expr        { $$ = $1 / $3; }
     | expr _PLUS_OP expr       { $$ = $1 + $3; }
     | expr _MINUS_OP expr      { $$ = $1 - $3; }
     | expr _AND_OP expr        { $$ = $1 & $3; }
     | expr _OR_OP expr         { $$ = $1 | $3; }
     | _NOT_OP expr             { $$ = ~$2; }
     | _NUMERIC                 { $$ = $1; }
%%
