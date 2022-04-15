/**
 * @file stack.h
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís
 * @brief Este ficheiro possibilita o uso do stack.c noutros módulos.
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#ifndef STACK_H
#define STACK_H

#include <stdio.h>


/**
* @brief Definição da Stack
*/

typedef struct {
    int stack[BUFSIZ];
    int sp;
} STACK;


/**
* @brief Utilização da Stack 
*/

STACK *newStack();

int push(STACK *s, int elem);

int pop(STACK *s, int* x);

void soma(STACK *s);

void subtracao(STACK *s);

void multiplicacao(STACK *s);

void divisao(STACK *s);

void decrementacao(STACK *s);

void incrementacao(STACK *s);

void modulo(STACK *s);

void exponenciacao(STACK *s);

void eBitwise(STACK *s);

void ouBitwise(STACK *s);

void xorBitwise(STACK *s);

void notBitwise(STACK *s);

#endif

