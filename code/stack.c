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
#include <math.h>
#include "stack.h"


/**
 * @brief Definição da operação de soma (+).
 *  
 */
void soma(STACK* s) {
    int x = 0;
    int y = 0;
    pop(s,&x); 
    pop(s,&y); 
    push(s, x + y);
}

/**
 * @brief Definição da operação de subtração (-). 
 */
void subtracao(STACK* s) {
    int x = 0;
    int y = 0; 
    pop(s,&x);
    pop(s,&y); 
    push(s, y - x);
}

/**
 * @brief Definição da operação de multiplicação (*).
 */
void multiplicacao(STACK* s) {
    int x = 0;
    int y = 0;
    pop(s,&x);
    pop(s,&y); 
    push(s, x * y);
}

/**
 * @brief Definição da operação de divisão (/).
 */
void divisao(STACK* s) {
    int x = 0;
    int y = 0;
    pop(s,&x);
    pop(s,&y);
    push(s, y / x);
}

/**
 * @brief Definição da operação de decrementação ( ( ).
 * A decrementação diminui o inteiro em 1.
 */
void decrementacao (STACK* s) {
    int x = 0;
    pop(s,&x); 
    push(s, --x);
}

/**
 * @brief Definição da operação de incrementação ( ) ).
 * A incrementação aumenta em 1 valor.
 */
void incrementacao (STACK* s) {
    int x = 0;
    pop(s,&x); 
    push(s, ++x);
}

/**
 * @brief Definição da operação de módulo (%).
 * O módulo é o resto da divisão inteira de x por y.
 */
void modulo (STACK* s) {
    int x = 0; 
    int y = 0;
    pop(s,&x);
    pop(s,&y); 
    push(s, y % x);
}

/**
 * @brief Definição da operação de exponenciação (#).
 * 
 */
void exponenciacao (STACK* s) {
    int x = 0;
    int y = 0;
    pop(s,&x);
    pop(s,&y);
    push(s, pow (y, x));
}

/**
 * @brief Definição da operação de "e" (bitwise) para inteiros (&).
 * 
 */
void eBitwise (STACK* s) {
    int x = 0;
    int y = 0;
    pop(s,&x);
    pop(s,&y);
    push(s, x & y);
}

/**
 * @brief Definição da operação de "ou" (bitwise) para inteiros (|).
 * 
 */
void ouBitwise (STACK* s) {
    int x = 0;
    int y = 0;
    pop(s,&x);
    pop(s,&y); 
    push(s, x | y);
}

/**
 * @brief Definição da operação de "xor" (bitwise) para inteiros (^).
 * O xor é o ou exclusivo.
 */
void xorBitwise (STACK* s) {
    int x = 0;
    int y = 0;
    pop(s,&x);
    pop(s,&y);
    push(s, x ^ y);
}

/**
 * @brief Definição da operação de "not" (bitwise) para inteiros (~).
 * 
 */
void notBitwise (STACK* s) {
    int x = 0;
    pop(s, &x); 
    push(s, ~x);
}

STACK *newStack (){
    return (STACK *) malloc(sizeof(STACK));
}

/**
* @brief Função Push
*
* @return faz push a um número (caso dê erro, retorna 1) 
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
* @return faz pop a um número (caso dê erro, retorna 1) 
*/

int pop(STACK *s, int *x){
    if (s->sp == 0) return 1;   
    *x = s->stack[s->sp];
    s->sp--;
    return 0;
}