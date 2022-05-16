/**
 * @file main.c
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís
 * @brief Este ficheiro será o ficheiro onde se encontram todas as grandes operações deste projeto. A main.
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "parser.h"

/**
 * @brief A nossa Main.
 * 
 * Esta vai primeiramente criar uma Stack, logo asseguir vai correr o parser, para depois colocar os resultados 
 * obtidos para ser impresso no Terminal.
 * 
 */
int main() {
    STACK *s = newStack();

    parser(s);
    
    for (int i = 0; i < s->sp; i++) {
        ELEMENT x = s->stack[i];

        if (x.type == LONG) printf ("%ld", x.info.typeLong);
        else if (x.type == DOUBLE) printf ("%g", x.info.typeDouble);
        else if (x.type == CHAR) printf ("%c", x.info.typeChar);
        else if (x.type == STRING) printf ("%s", x.info.typeString);
        else if (x.type == BLOCK) printf ("%s", x.info.typeString);
        else if (x.type == ARRAY) printArray(s,i);
    }
    putchar('\n'); 
    free(s);
    return 0;
}