/**
 * @file mathoperations.c
 * @author Adriana Frazão (you@domain.com); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt);
 * @brief Este ficheiro irá correr a stack, incluindo as defenições do pop e do push.
 * @version 0.1
 * @date 2022-04-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK *newStack (){
    return (STACK *) malloc(sizeof(STACK));
}

/**
* @brief Função Push
*
* @return faz push a um numero (caso dê erro retorna 1) 
*/


int push (STACK *s,int elem){
    if (s->sp == BUFSIZ) return 1;
    s->sp++;
    s->stack[s->sp] = elem;
    return 0;
}

/**
* @brief Função Pop:
*
* @return faz pop a um numero (caso dê erro retorna 1) 
*/

int pop(STACK *s, int *x){
    if (s->sp == 0) return 1;   
    *x = s->stack[s->sp];
    s->sp--;
    return 0; 
}