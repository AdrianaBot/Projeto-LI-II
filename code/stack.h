/**
 * @file stack.h
 * @author Adriana Frazão (you@domain.com); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt);
 * @brief Este ficheiro possibilita o uso do stack.c noutros módulos.
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#define MAX 1000


/**
* @brief Defenição da Stack
*/
typedef struct {
    int stack[MAX];
    int sp;
} STACK;

/**
* @brief Utilização da Stack 
*/


STACK *new_stack();
void push(STACK *s, int elem);
int pop(STACK *s);
