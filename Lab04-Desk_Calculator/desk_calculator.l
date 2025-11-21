%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100
double val_stack[MAX];
char op_stack[MAX];
int val_top = -1, op_top = -1;

void push_val(double v) { val_stack[++val_top] = v; }
void push_op(char c) { op_stack[++op_top] = c; }
double pop_val() { return val_stack[val_top--]; }
char pop_op() { return op_stack[op_top--]; }

int precedence(char op) {
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

void apply_op() {
    double b = pop_val();
    double a = pop_val();
    char op = pop_op();
    if(op=='+') push_val(a+b);
    else if(op=='-') push_val(a-b);
    else if(op=='*') push_val(a*b);
    else if(op=='/') push_val(a/b);
}
%}

%%
[0-9]+(\.[0-9]+)?  { push_val(atof(yytext)); }
[+\-*/] {
    while(op_top>=0 && precedence(op_stack[op_top])>=precedence(yytext[0]))
        apply_op();
    push_op(yytext[0]);
}
"(" { push_op('('); }
")" {
    while(op_top>=0 && op_stack[op_top]!='(') apply_op();
    pop_op(); /* pop '(' */
}
[\t\r ]+ { /* ignore whitespace */ }
\n {
    while(op_top>=0) apply_op();
    printf("Result = %lf\n", pop_val());
    val_top = op_top = -1;
}
. { /* ignore any unknown char */ }
%%

int main() {
    printf("Desk Calculator (type expression, press Enter):\n");
    yylex();
    return 0;
}
