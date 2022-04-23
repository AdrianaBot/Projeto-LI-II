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
 * @brief Definição e conversão de tipos.
 * 
 */
typedef enum {
    LONG, 
    DOUBLE, 
    CHAR, 
    STRING 
} VARTYPE;

typedef struct {
    VARTYPE type;
    union {
        long typeLong;
        double typeDouble;
        char typeChar; 
        char typeString[BUFSIZ]; 
    } info;
} ELEMENT;

/**
* @brief Definição da Stack
*/

typedef struct {
    ELEMENT stack[BUFSIZ];
    int sp;
} STACK;

/**
* @brief Utilização da Stack 
*/

STACK *newStack();
/**
 * @brief Função de push.
 * 
 * A função "push" "empurra" um elemento para o fundo da stack.
 * 
 * @param s 
 * @param elem 
 * @return int 
 */

int push(STACK *s, ELEMENT elem);

/**
 * @brief Função de pop
 * 
 * A função "pop" retira o elemento no topo da stack e devolve/guarda o seu valor.
 * 
 * @param s 
 * @param x 
 * @return int
 */

int pop(STACK *s, ELEMENT* x);

/**
 * @brief Função da soma
 * 
 * A função "soma" dá a adição de dois números.
 * 
 * @param s 
 */

void soma (STACK *s);
void somaLongLong(STACK *s);
void somaLongDouble(STACK *s);
void somaLongChar(STACK *s);
void somaDoubleDouble(STACK *s);
void somaDoubleLong(STACK *s);
void somaDoubleChar(STACK *s);
void somaCharChar(STACK *s);
void somaCharDouble(STACK *s);
void somaCharLong (STACK *s);
/**
 * @brief Função de subtração
 * 
 * A função "subtracao" dá a subtração de dois números.
 * 
 * @param s
 */

void subtracao(STACK *s);
void subtracaoLongLong(STACK *s);
void subtracaoLongDouble(STACK *s);
void subtracaoLongChar(STACK *s);
void subtracaoDoubleDouble(STACK *s);
void subtracaoDoubleLong(STACK *s);
void subtracaoDoubleChar(STACK *s);
void subtracaoCharChar(STACK *s);
void subtracaoCharDouble(STACK *s);
void subtracaoCharLong (STACK *s);;

/**
 * @brief Função de multiplicação
 * 
 * A função "multiplicacao" dá o produto entre dois números.
 * 
 * @param s 
 */

void multiplicacao(STACK *s);
void multiplicacaoLongLong(STACK *s);
void multiplicacaoLongDouble(STACK *s);
void multiplicacaoLongChar(STACK *s);
void multiplicacaoDoubleDouble(STACK *s);
void multiplicacaoDoubleLong(STACK *s);
void multiplicacaoDoubleChar(STACK *s);
void multiplicacaoCharChar(STACK *s);
void multiplicacaoCharDouble(STACK *s);
void multiplicacaoCharLong (STACK *s);

/**
 * @brief Função de divisão
 * 
 * A função "divisao" dá o quociente entre dois números.
 * 
 * @param s 
 */
void divisao(STACK *s);
void divisaoLongLong(STACK *s);
void divisaoLongDouble(STACK *s);
void divisaoLongChar(STACK *s);
void divisaoDoubleDouble(STACK *s);
void divisaoDoubleLong(STACK *s);
void divisaoDoubleChar(STACK *s);
void divisaoCharChar(STACK *s);
void divisaoCharDouble(STACK *s);
void divisaoCharLong (STACK *s);

/**
 * @brief Função de decrementação
 *
 * A função "decrementacao" decrementa um número em um valor. 
 * 
 * @param s 
 */

void decrementacao(STACK *s);

/**
 * @brief Função de incrementação
 * 
 * A função "incrementacao" incrementa um número em um valor.
 * 
 * @param s 
 */

void incrementacao(STACK *s);

/**
 * @brief Função do modulo
 * 
 * A função "modulo" dá o resto da divisão inteira entre dois números.
 * 
 * @param s 
 */

void modulo(STACK *s);

/**
 * @brief Função de exponenciação
 * 
 * A função "exponenciacao" dá a exponencial de um valor.
 * 
 * @param s 
 */
void exponenciacao(STACK *s);

/**
 * @brief Função lógica "e" - conjunção
 * 
 * A função "eBitwise" vai aplicar o modelo lógico de conjunção entre dois valores.
 * 
 * @param s 
 */

void eBitwise(STACK *s);

/**
 * @brief Função lógica "ou" - disjunção 
 * 
 * A função "ouBitwise" aplica o modelo lógico da disjunção entre dois valores.
 * 
 * @param s 
 */
void ouBitwise(STACK *s);

/**
 * @brief Função lógica "xor" - disjunção exclusiva 
 * 
 * A função "xorBitwise" vai aplicar o modelo lógico exclusivo entre dois valores,
 * ou seja, só um deles terá que ser verdadeiro (logicamente) para ser aplicável.
 * 
 * @param s 
 */
void xorBitwise(STACK *s);

/**
 * @brief Função lógica "not" - negação
 * 
 * A função "notBitwise" vai aplicar o modelo lógico da negação a qualquer valor.
 * 
 * @param s 
 */
void notBitwise(STACK *s);

/**
 * @brief Função de duplicação
 * 
 * A função "duplicacao" duplica o valor do 1º elemento.
 * 
 * @param s
 */
void duplicacao(STACK *s);

/**
 * @brief Função de troca
 * 
 * A função "troca" troca os dois elementos no topo da stack.
 * 
 * @param s
 */
void troca(STACK *s);

/**
 * @brief Função de rodagem
 * 
 * A função "roda" roda os três elementos no topo da stack.
 * 
 * @param s
 */
void roda(STACK *s);

/**
 * @brief Função auxiliar para a função "copia"
 * 
 * A função "nesimo" 
 */
void nesimo (STACK *s, ELEMENT* x, int n);

/**
 * @brief Função de cópia
 * 
 * A função "copia" copia o n-ésimo elemento para o topo da stack.
 * 
 * @param s
 */
void copia(STACK *s);

/**
 * @brief Função de pop (sem devolução de valor)
 * 
 * A função "pop2" retira o elemento do topo da stack sem guardar o seu valor, contrariamente à "pop" que retira o elemento e guarda o seu valor.
 * 
 * @param s
 */
void pop2(STACK *s);

/**
 * @brief Função convtoLong
 * 
 * A função converte um valor para Long
 * 
 * @param s 
 */
void convToLong(STACK *s);

/**
 * @brief Função convToDouble
 * 
 * A função converte um valor para Double
 * 
 * @param s 
 */
void convToDouble(STACK *s);

/**
 * @brief Função convToChar
 * 
 * A função converte um valor para Char
 * 
 * @param s 
 */
void convToChar(STACK *s);

/**
 * @brief Função convToString
 * 
 * A função converte um valor para String
 * 
 * @param s 
 */
//void convToString(STACK *s);

#endif