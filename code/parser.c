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

int count(char *line, char *h) {
    int f = 0, b = 0, c = 1, i;

    for (i = 0; i < (int)strlen(line); i++) {
        if (line[i] == ' ' && f == 0 && b == 0) {h[i] = '\0'; return c;}
        else if (line[i] == '"' && f != 0) {h[i] = '\0'; return c+1;}
        else if (line[i] == '"') f++;
        else if (line[i] == '}' && b != 0) {h[i] = line[i]; h[i+1] = '\0'; return c+1;}
        else if (line[i] == '{') b++;
        h[i] = line[i];
        c++;
    }
    h[i] = '\0';
    return c;
}

void parser(STACK *s) {
    char *line = malloc(BUFSIZ*sizeof(char));

    DispatchFunc table[226] = {0}; 
    setupTable(table);

    ELEMENT variables[26] = {0};
    setupVar(variables);

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        for (int i = 0; line[i] != '\0'; i++)
            if (line[i] == '\n') 
                line[i] = '\0';
        
        int f = 0;
        
        int c,t = strlen(line);
        char *h = malloc(BUFSIZ*sizeof(char));

        c = count(line, h);
        line += c;

        while (t > 0) {
            if      (h[0] == '[' && h[1] == '\0') newArray(s, ++f);
            else if (h[0] == ']' && h[1] == '\0') f--;
            else if (h[0] == '"') newString(s, h, f);
            else if (h[0] == '{') newBlock(s, h, f);
            else if (f != 0) {
                if (((h[0] < 48 || h[0] > 57) && h[1] == '\0') || (h[0] == 'e' && h[2] == '\0')) func(s, h, table, f);
                else if (h[0] >= 'A' && h[0] <= 'Z' && h[1] == '\0') push(s, variables[h[0]-'A']);
                else if (h[0] == ':' && h[2] == '\0') assign(s,h[1], variables, f);
                else addToArray(s, h, f);
            }
            else if (h[0] >= 'A' && h[0] <= 'Z' && h[1] == '\0') push(s, variables[h[0]-'A']);
            else if (h[0] == ':' && h[2] == '\0') assign(s,h[1], variables, f);
            else if (((h[0] < 48 || h[0] > 57) && h[1] == '\0') || (h[0] == 'e' && h[2] == '\0')) func(s, h, table, f);
            else readType (s, h); 


            psdebugger(s);
            t -= c;
            c = count(line, h);
            line += c;
        }
    }
}