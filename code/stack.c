/**
 * @file stack.c
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); Flávio Sousa (a100715@alunos.uminho.pt);
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
 * A incrementação aumenta o inteiro em 1.
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

/**
 * @brief Definição da operação de duplicação (_).
 * 
 */
 
void duplicacao (STACK* s) {
    int x = 0;
    pop(s, &x);
    push(s, x);
    push(s, x);
}

/**
 * @brief Definição da operação de troca de dois elementos no topo da stack (\).
 * 
 */
void troca (STACK* s) {
    int x = 0, y = 0;
    pop(s, &x);
    pop(s, &y);
    push(s, x);
    push(s, y);
}


/**
 * @brief Definição da operação de rodagem de três elementos no topo da stack (@).
 *
 */
void roda (STACK* s) {
    int x = 0, y = 0, z = 0;
    pop(s, &x);
    pop(s, &y);
    pop(s, &z);
    push(s, y);
    push(s, x);
    push(s, z);
}

/**
 * @brief Definição de uma função auxiliar para a função "copia"
 * 
 */
void nesimo (STACK *s, int* x, int n) {
    *x = s->stack[n - 1];
}

/**
 * @brief Definição da operação de cópia do n-ésimo elemento para o topo da stack, no qual 0 é o topo da stack (n $, em que n é a posição na stack).
 * 
 */
void copia (STACK* s) {
    int n = 0;
    pop(s, &n);
    int x;
    nesimo(s, &x, n);
    push(s, x);  
}

/**
 * @brief Definição da operação de pop sem salvaguarda de valores (;).
 *  
 */
void pop2(STACK *s) {
    int x = 0;
    pop(s, &x);
}

