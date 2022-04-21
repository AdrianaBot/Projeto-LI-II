/**
 * @file stack.h
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís; Flávio Sousa (a100715@alunos.uminho.pt);
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
/**
 * @brief Função de push.
 * 
 * A função de push vai "empurrar" qualquer que seja o valor que estamos a trabalhar
 * para dentro da stack
 * 
 * @param s 
 * @param elem 
 * @return int 
 */

int push(STACK *s, int elem);
/**
 * @brief Função de pop
 * 
 * Esta função acaba por dar "pop" (**tecnicamente retira**) um valor da stack.
 * 
 * @param s 
 * @param x 
 * @return int
 */

int pop(STACK *s, int* x);
/**
 * @brief Função da soma
 * 
 * A função da soma vai aplicar a soma de um numero.
 * 
 * @param s 
 */

void soma(STACK *s);
/**
 * @brief Função de subtracao
 * 
 * A função da subtração vai aplicar a subtração de um numero.
 * 
 * @param s
 */

void subtracao(STACK *s);
/**
 * @brief Função de multiplicação
 * 
 * A função da multiplicação vai aplicar a multiplicação de um numero.
 * 
 * @param s 
 */

void multiplicacao(STACK *s);
/**
 * @brief Função de divisão
 * 
 * A função da divisão vai aplicar a divisão de um numero.
 * 
 * @param s 
 */

void divisao(STACK *s);
/**
 * @brief Função de decrementação
 *
 * A função de decrementação vai decrementar um numero.
 * 
 * @param s 
 */

void decrementacao(STACK *s);
/**
 * @brief Função de incrementação
 * 
 * A função de incrementacao vai incrementar um numero.
 * 
 * @param s 
 */

void incrementacao(STACK *s);
/**
 * @brief Função do modulo
 * 
 * A função do modulo vai aplicar o modulo a um numero.
 * 
 * @param s 
 */

void modulo(STACK *s);
/**
 * @brief Função de exponenciação
 * 
 * A função da exponenciacao vai aplicar a exponencial de um certo valor.
 * 
 * @param s 
 */
void exponenciacao(STACK *s);

/**
 * @brief Função lógica "e"
 * 
 * Esta função eBitwise vai aplicar o modelo lógico de conjunção entre dois valores
 * 
 * @param s 
 */

void eBitwise(STACK *s);
/**
 * @brief Função lógica "ou"
 * 
 * Esta função ouBitwise vai aplicar o modelo lógico da disjunção entre dois valores
 * 
 * @param s 
 */
void ouBitwise(STACK *s);
/**
 * @brief Função lógica xor
 * 
 * Esta função xorBitwise vai aplicar o modelo logico exclusivo entre dois valores
 * Ou seja, só um deles terá que ser verdadeiro (logicamente) para ser aplicável.
 * 
 * @param s 
 */
void xorBitwise(STACK *s);
/**
 * @brief notBitwise
 * 
 * A função notBitwise vai aplicar o modelo lógico da negação a qualquer valor.
 * 
 * @param s 
 */
void notBitwise(STACK *s);

/**
 * @brief duplica
 * 
 * A função duplica vai duplicar 1 valor;
 * 
 * @param s
 */
void duplica(STACK *s);

/**
 * @brief swap
 * 
 * A função swap troca 2 valores;
 * 
 * @param s
 */
void swap(STACK *s);

/**
 * @brief roda3elementos
 * 
 * A função roda3elementos roda 3 elementos no topo da stack.
 * 
 * @param s
 */
void roda3elementos(STACK *s);

/**
 * @brief popp
 * 
 * A função popp faz um pop do elemento.
 * 
 * @param s
 */
void popp(STACK *s);

/**
 * @brief copy
 * 
 * A função copy copia o n-ésimo elemento para o topo da stack.
 * 
 * @param s
 */
//void copy(STACK *s);

#endif

