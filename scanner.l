%{
#include <string>
#include "ParseTree.h"
#include "parser_tab.h"

int line_count=0;
char linebuf[500];
%}

dig   [0-9]
num1   {dig}+\.?([eE][-+]?{dig}+)?
num2   {dig}*\.{dig}+([eE][-+]?{dig}+)?
number   {num1}|{num2} 

%%

#.* ;

[ \t] ;

{number} {
  yylval.dval=atof(yytext);
  //printf("TK_NUM token:%15.5e\n",yylval.dval);
  return TK_NUM;
}

[A-Za-z_][A-Za-z\._0-9]* {
  std::string s=yytext;
  yylval.sval=strdup(s.c_str());
  //printf("TK_SYM token:%s\n",yytext);
  return TK_SYM;
}

\"[^"\n]*["\n] {
  std::string s=yytext;
  s=s.substr(1,s.size()-2);
  yylval.sval=strdup(s.c_str());
  //printf("TK_STR token:%s\n",yylval.sval);
  return TK_STR;
}

\n.* {
  strcpy(linebuf,yytext+1);
  line_count++;
  yyless(1);
}

\r {}

. {
  return yytext[0];
}

%%

int yywrap()
{
  return 1;
}

int yyerror(char* s)
{
  printf("\n");
  printf("Error: yyerror(s), %s at %s in line #%d:\n%s\n",s,yytext,line_count,linebuf);
  exit(1);
}
