#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void executa (STACK *s, char c[]) {
    if      (c[0] == '+') soma(s);
    else if (c[0] == '-') subtracao(s);
    else if (c[0] == '*') multiplicacao(s);
    else if (c[0] == '/') divisao(s);
    else if (c[0] == '(') decrementacao(s);
    else if (c[0] == ')') incrementacao(s);
    else if (c[0] == '%') modulo(s);
    else if (c[0] == '#') exponenciacao(s);
    else if (c[0] == '&') eBitwise(s);
    else if (c[0] == '|') ouBitwise(s);
    else if (c[0] == '^') xorBitwise(s);
    else if (c[0] == '~') notBitwise(s);
    else {
        int val;
        sscanf(c, "%d", &val);
        push (s, val);
    }
}

int main() {
    STACK *s = newStack();
    char linha[BUFSIZ];
    char token[BUFSIZ];

    if (fgets (linha, BUFSIZ, stdin) != NULL) {
        while (sscanf(linha, "%s%[^\n]", token, linha) == 2) { 
            executa(s, token);
        }
        executa(s, token);

        for (int j = 1; j <= s->sp; j++)
            printf ("%d", s->stack[j]);
        putchar('\n'); 
    }
    return 0;
}