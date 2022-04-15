#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "dispatchtable.h"

int main() {
    DispatchFunc *table[127];
    STACK *s = newStack();
    setupTable();
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