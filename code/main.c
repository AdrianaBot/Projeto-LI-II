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
#include "dispatchtable.h"
#include "parser.h"

/**
 * @brief A nossa Main 
 */
int main() {
    DispatchFunc table[127];
    STACK *s = newStack();
    setupTable(table);

    parser(s, table);
    for (int i = 1; i <= s->sp; i++)
        printf ("%d", s->stack[i]);
        
    putchar('\n'); 
    return 0;
}