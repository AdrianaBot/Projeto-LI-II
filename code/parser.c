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

void readType (STACK* s, char h[]) {
    ELEMENT x;
    long l; double d; char c;

    if (sscanf(h, "%ld", &l) == 1) {
        x.type = LONG;
        x.info.typeLong = l;
    }
    else if (sscanf(h, "%lf", &d) == 1) {
        x.type = DOUBLE;
        x.info.typeDouble = d;
    }
    else if (sscanf(h, "%c", &c) == 1) {
        x.type = CHAR;
        x.info.typeChar = c;
    }
    else {
        x.type = STRING;
        strcpy(x.info.typeString , h);
    }
    push(s, x);
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
            if (func(s, h[0], table) == 0);
            else
                readType (s, h);

            h = strtok(NULL, " ");
        }
    }
}