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
    if (h[0] >= 'a' && h[0] <= 'z' && h[1] == '\0') {
        ELEMENT a = {
            .type = CHAR, 
            .info.typeChar = h[0],
        };
        push(s,a);
        return;
    }
    char* endptr;
    long num = strtol(h,&endptr,10);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = LONG, 
            .info.typeLong = num,
        };
        push(s,a);
        return;
    }
    double b = strtod(h,&endptr);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = DOUBLE, 
            .info.typeDouble = b,
        };
        push(s,a);
        return;
    }
    ELEMENT a;
    a.type = STRING; 
    strcpy (a.info.typeString, h);
    push(s,a);
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
    DispatchType funcType5[4][4];

    ELEMENT variables[26] = {0};
    setupVar(variables);

    setupSumArray(funcType1);
    setupSubArray(funcType2);
    setupMulArray(funcType3);
    setupDivArray(funcType4);
    setupExpArray(funcType5);

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '\n') {
                line[i] = '\0';
            }
        }
        char *h = strtok(line, " ");

        while (h != NULL) {
            if      (h[0] == '+' && h[1] == '\0') soma(s, funcType1);
            else if (h[0] == '-' && h[1] == '\0') subtracao(s, funcType2);
            else if (h[0] == '*' && h[1] == '\0') multiplicacao(s, funcType3);
            else if (h[0] == '/' && h[1] == '\0') divisao(s, funcType4);
            else if (h[0] == '#' && h[1] == '\0') exponenciacao(s, funcType5);
            else if (h[0] == 'l' && h[1] == '\0') readline(s);
            else if (h[0] >= 'A' && h[0] <= 'Z' && h[1] == '\0') push(s, variables[h[0]-'A']);
            else if (h[0] == ':' && h[2] == '\0') assign(s,h[1], variables);
            else if (func(s, h, table) == 0);
            else readType (s, h);

            psd(s);
            h = strtok(NULL, " ");
        }
    }
}

