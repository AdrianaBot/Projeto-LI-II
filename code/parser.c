/**
 * @file parser.c
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís; Flávio Sousa (a100715@alunos.uminho.pt);
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
#include "dispatchtable.h"



/**
 * @brief __readNewLine__ é a função de leitura do comando l - ler linha.
 * 
 * @param s 
 * @param table 
 */

void readNewLine(STACK *s, DispatchFunc table[]) {
    char line[BUFSIZ];
    char h[BUFSIZ];

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        int val;
        while (sscanf(line, "%s%[^\n]", h, line) == 2) { 
            if (sscanf(h, "%d", &val) == 1)
                push (s, val);
            else
                func(s, h[0], table);
        }
        if (sscanf(h, "%d", &val) == 1)
            push (s, val);
        else
            func(s, h[0], table);
    }
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

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        int v;
        char *h = strtok(line, " ");

        while (h != NULL) { 
            if (sscanf(h, "%d", &v) == 1)
                push(s, v);
            else if (h[0] == 'l')
                readNewLine(s, table);
            else
                func(s, h[0], table);

            h = strtok(NULL, " ");
        }
    }
}