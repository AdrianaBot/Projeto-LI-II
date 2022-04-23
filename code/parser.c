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
        strcpy(x.info.typeString, h);
    }
    push(s, x);
}


/**
 * @brief readline function
 * 
 * Lê uma linha
 * 
 * @param s 
 */
void readline(STACK *s) {
    char line[BUFSIZ];
    char h[BUFSIZ];

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        while (sscanf(line, "%s%[^\n]", h, line) == 2) { 
            readType(s, h);
        }
        readType(s, h);
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
    DispatchType funcType1[4][4];
    DispatchType funcType2[4][4];
    DispatchType funcType3[4][4];
    DispatchType funcType4[4][4];


setupSumArray(funcType1);
setupSubArray(funcType2);
setupMulArray(funcType3);
setupDivArray(funcType4);

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        char *h = strtok(line, " ");

        while (h != NULL) {
            if(h[0] == '+') soma(s, funcType1);
            else if (h[0] == '-') subtracao(s, funcType2);
            else if (h[0] == '*') multiplicacao(s, funcType3);
            else if (h[0] == '/') divisao(s, funcType4);
            else if (h[0] == 'l') readline(s);
            else if (func(s, h[0], table) == 0);
                else
                    readType (s, h);

            h = strtok(NULL, " ");
        }
    }
}

