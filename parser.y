%{
#include <stdio.h>
#include "ParseTree.h"

  int yylex();
  int yyerror(char* s);
  extern int line_count;

%}

%union {
  ParseTree* ptp;
  double dval;
  char* sval;
}

%token <dval> TK_NUM
%token <sval> TK_SYM
%token <sval> TK_STR

%type <ptp> stmt_list
%type <ptp> stmt
%type <ptp> arg_list
%type <ptp> arg
%type <ptp> expr

%%

program : stmt_list { 
  parse_tree=new Program($1); 
  parse_tree->action(); 
}
;

stmt_list : stmt { 
  $$ = new StmtList(0,$1);
}
| stmt_list stmt { 
  $$ = new StmtList($1,$2); 
}
;

stmt : TK_SYM '(' stmt_list ')' '{' arg_list '}' {
  $$ = new Stmt($1,$3,0,$6);
  free($1);
}
| TK_SYM '(' arg_list ')' '{' arg_list '}' {
  $$ = new Stmt($1,$3,0,$6);
  free($1);
}
| TK_SYM '{' arg_list '}' {
  $$ = new Stmt($1,0,0,$3);
  free($1);
}
| TK_SYM '(' stmt_list ')' '{' stmt_list '}' {
  $$ = new Stmt($1,$3,$6,0);
  free($1);
}
| TK_SYM '(' arg_list ')' '{' stmt_list '}' {
  $$ = new Stmt($1,$3,$6,0);
  free($1);
}
| TK_SYM '{' stmt_list '}' {
  $$ = new Stmt($1,0,$3,0);
  free($1);
}
| TK_SYM '(' arg_list ')' {
  $$ = new Stmt($1,$3,0,0);
  free($1);
}
;

arg_list : arg { 
  $$ = new ArgList(0,$1); 
}
| arg_list ',' arg { 
  $$ = new ArgList($1,$3);
}
;

arg : TK_SYM '=' expr { 
  $$ = new Arg($1,$3); 
  free($1);
} |
TK_SYM {
  $$ = new Arg($1,0);
  free($1);
}
;

expr : '-' expr { $$ = new Expr( -((Expr*) $2)->getDval() ); } 
| TK_NUM { 
  $$ = new Expr($1); 
}
| TK_STR { 
  $$ = new Expr($1); 
  free($1);
}
;
