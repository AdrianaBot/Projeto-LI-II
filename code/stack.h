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

<<<<<<< HEAD
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
=======
typedef enum ops{ INT, DOUBLE, CHAR, STR} OPS;

typedef struct ESTRUTURA{    
    OPS type;
    union tipo{             
        int x,y;
        double d;               //Shit, it don't work so well...check this later
        char c;
        char str[10];
    }tipo;
}estrutura;




>>>>>>> 79ea54c (something)

/**
* @brief Definição da Stack
*/

<<<<<<< HEAD
typedef struct {
    ELEMENT stack[BUFSIZ];
=======
typedef struct{
    estrutura stack[BUFSIZ];
>>>>>>> 79ea54c (something)
    int sp;
}STACK;


/**
* @brief Inicialização da Stack
*/

STACK *newStack();
/**
 * @brief Função de push.
 * 
<<<<<<< HEAD
 * A função "push" "empurra" um elemento para o fundo da stack.
 * 
=======
 * A função de push vai **empurrar** qualquer que seja o valor que estamos a trabalhar
 * para dentro da stack
 * s
>>>>>>> 79ea54c (something)
 * @param s 
 * @param elem 
 * @return int 
 */
int push(STACK *s, OPS elem);

<<<<<<< HEAD
int push(STACK *s, ELEMENT elem);

=======
>>>>>>> 79ea54c (something)
/**
 * @brief Função de pop
 * 
 * A função "pop" retira o elemento no topo da stack e devolve/guarda o seu valor.
 * 
 * @param s 
 * @param x 
 * @return int
 */
int pop(STACK *s, OPS *x);

<<<<<<< HEAD
int pop(STACK *s, ELEMENT* x);

=======
>>>>>>> 79ea54c (something)
/**
 * @brief Função da soma
 * 
 * A função "soma" dá a adição de dois números.
 * 
 * @param s 
 */

void soma(STACK *s);

/**
 * @brief Função de subtração
 * 
 * A função "subtracao" dá a subtração de dois números.
 * 
 * @param s
 */
void subtracao(STACK *s);

/**
 * @brief Função de multiplicação
 * 
 * A função "multiplicacao" dá o produto entre dois números.
 * 
 * @param s 
 */

void multiplicacao(STACK *s);

/**
 * @brief Função de divisão
 * 
 * A função "divisao" dá o quociente entre dois números.
 * 
 * @param s 
 */


void divisao(STACK *s);

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

<<<<<<< HEAD
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
void nesimo (STACK *s, int* x, int n);

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



=======



void convToInt(STACK *s);

void convToDouble(STACK *s);

void convToChar (STACK *s);

void convToString(STACK *s);


>>>>>>> 79ea54c (something)
#endif

