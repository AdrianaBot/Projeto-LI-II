/**
 * @file parser.c
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís
 * @brief Este ficheiro vai possibilitar utilizar o nosso parser.
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int readType (STACK* s, char h[]) {
    if (h[0] >= 'a' && h[0] <= 'z' && h[1] == '\0') {
        ELEMENT a = {
            .type = CHAR, 
            .info.typeChar = h[0],
        };
        push(s,a);
        return 0;
    }
    char* endptr;
    long num = strtol(h,&endptr,10);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = LONG, 
            .info.typeLong = num,
        };
        push(s,a);
        return 0 ;
    }
    double b = strtod(h,&endptr);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = DOUBLE, 
            .info.typeDouble = b,
        };
        push(s,a);
        return 0;
    }
    return 1;
}

/**
 * @brief Parser
 * 
 * A função __parser__,quando executada, identifica qual a operação que deverá ser aplicada. 
 * Caso não seja uma operação, simplesmente adiciona à stack.
 * 
 * @param s -> pointer da stack
 * @param c -> array de characteres
 */
void parser(STACK *s, DispatchFunc table[]) {
    char line[BUFSIZ];

    ELEMENT variables[26] = {0};
    setupVar(variables);

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        for (int i = 0; line[i] != '\0'; i++)
            if (line[i] == '\n') 
                line[i] = '\0';
            
        char *h = strtok(line, " ");
        int f = 0;

        while (h != NULL) {
            if      (h[0] == '[' && h[1] == '\0') newArray(s, ++f);
            else if (h[0] == ']' && h[1] == '\0') f--;
            else if (f != 0) {
                if (addToArray(s, h, f) == 0);
                else {
                    STACK *x = s;
                    for (int i = 0; i < f; i++) 
                        x = x->stack[s->sp-1].info.typeArray;
            
                    func(x, h, table);
                }
            }
            else if (h[0] == '"') newString(s, h);
            else if (h[0] >= 'A' && h[0] <= 'Z' && h[1] == '\0') push(s, variables[h[0]-'A']);
            else if (h[0] == ':' && h[2] == '\0') assign(s,h[1], variables);
            else if (readType (s, h) == 0);
            else func(s, h, table);

            //psd(s);
            h = strtok(NULL, " ");
        }
    }
}



