/**
 * @file mathoperations.c
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt);
 * @brief Este ficheiro será a nossa main. Vai correr o programa na sua totalidade.
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

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