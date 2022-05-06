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
 * @brief A nossa Main 
 */
int main() {
    DispatchFunc table[226] = {0}; 
    STACK *s = newStack();
    setupTable(table);

    parser(s, table);
    
    for (int i = 0; i < s->sp; i++) {
        ELEMENT x = s->stack[i];

        if (x.type == LONG) printf ("%ld", x.info.typeLong);
        else if (x.type == DOUBLE) printf ("%g", x.info.typeDouble);
        else if (x.type == CHAR) printf ("%c", x.info.typeChar);
        else if (x.type == STRING) printf ("%s", x.info.typeString);
        else if (x.type == ARRAY) printArray(s,i);
    }
    putchar('\n'); 
    free(s);
    return 0;
}