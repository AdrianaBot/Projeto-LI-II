/**
 * @file stack.c
<<<<<<< HEAD
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); Flávio Sousa (a100715@alunos.uminho.pt);
=======
 * @author Adriana Frazão (you@domain.com); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt);
>>>>>>> 79ea54c (something)
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
 * @param s -> Pointer da Stack
 */
void soma(STACK* s){
    estrutura num1;    
    estrutura num2;
    OPS x,y;
    
    num1.tipo.x = pop(s,&x);  // have no fucking clue.  You have to change these
    num2.tipo.x = pop(s,&y); 
    
    push(s ,num1 + num2); // double + double != Int + Int
}

/**
 * @brief Definição da operação de subtração (-).
 * 
 * @param s -> Pointer da Stack 
 */

void subtracao(STACK* s){
    estrutura num1;
    estrutura num2;
    estrutura t;
    estrutura t2;
    pop(s,&num1.tipo.x);
    pop(s,&num2.tipo.x); 
    push(s, num1.tipo.x - num2.tipo.x);
}

/**
 * @brief Definição da operação de multiplicação (*).
 * 
 * @param s -> Pointer da Stack
 */
void multiplicacao(STACK* s) {
    estrutura num1;
    estrutura num2;
    
    pop(s,&num1);
    pop(s,&num2); 
    push(s, num1.tipo.x * num2.tipo.x);
}

/**
 * @brief Definição da operação de divisão (/).
 * 
 * @param s -> Pointer da Stack
 */
void divisao(STACK* s) {
    estrutura num1; //x
    estrutura num2; //y
    
    pop(s,&num1);
    pop(s,&num2);
    push(s,num2.tipo.x / num1.tipo.x);
}

/**
 * @brief Definição da operação de decrementação ( ( ).
 * A decrementação diminui o inteiro em 1.
 * 
 * @param s -> Pointer da Stack
 */
void decrementacao (STACK* s) {
    estrutura num1;
    pop(s,&num1); 
    push(s, --num1.tipo.x);
}

/**
 * @brief Definição da operação de incrementação ( ) ).
 * A incrementação aumenta em 1 valor.
 * 
 * @param s -> Pointer da Stack
 */
void incrementacao (STACK* s) {
    estrutura num1;
    pop(s,&num1); 
    push(s, ++num1.tipo.x);
}

/**
 * @brief Definição da operação de módulo (%).
 * O módulo é o resto da divisão inteira de x por y.
 * 
 * @param s -> Pointer da Stack
 */
void modulo (STACK* s) {
    estrutura num1;
    estrutura num2;
    
    pop(s,&num1);
    pop(s,&num2); 
    push(s, num2.tipo.x % num1.tipo.x);
}

/**
 * @brief Definição da operação de exponenciação (#).
 * 
 * @param s -> Pointer da Stack
 */
void exponenciacao (STACK* s) {
    estrutura num1;
    estrutura num2;
    pop(s,&num1);
    pop(s,&num2);
    push(s, pow (num2.tipo.x, num1.tipo.x));
}

/**
 * @brief Definição da operação de "e" (bitwise) para inteiros (&).
 * 
 * @param s -> Pointer da Stack
 * 
 */
void eBitwise (STACK* s) {
    estrutura num1;
    estrutura num2;
    pop(s,&num1);
    pop(s,&num2);
    push(s, num1.tipo.x & num2.tipo.x);
}

/**
 * @brief Definição da operação de "ou" (bitwise) para inteiros (|).
 * 
 * @param s -> Pointer da Stack
 */
void ouBitwise (STACK* s) {
    estrutura num1;
    estrutura num2;
    pop(s,&num1);
    pop(s,&num2); 
    push(s, num1.tipo.x | num2.tipo.x);
}

/**
 * @brief Definição da operação de "xor" (bitwise) para inteiros (^).
 * O xor é o ou exclusivo.
 * 
 * @param s -> Pointer da Stack
 */
void xorBitwise (STACK* s) {
    estrutura num1;
    estrutura num2;
    pop(s,&num1);
    pop(s,&num2);
    push(s, num1.tipo.x ^ num2.tipo.x);
}

/**
 * @brief Definição da operação de "not" (bitwise) para inteiros (~).
 * 
 * @param s -> Pointer da Stack
 */
void notBitwise (STACK* s) {
    estrutura num1;
    pop(s, &num1); 
    push(s, ~num1.tipo.x);
}



void convToInt (STACK *s){
    estrutura num1;
    pop(s, &num1);
    int l = num1.tipo.x;
    push(s, l);
}

void convToDouble (STACK *s){
    estrutura num1;
    pop(s ,&num1);
    double l = num1.tipo.x;
    push (s, l);
}

void convToChar (STACK *s){
    estrutura num1;
    pop(s,&num1);
    char l= num1.tipo.x;
    push (s,l);
}

void convToString (STACK *s){
    estrutura num1;
    char str[10];
    pop(s,&num1);
    sprintf(str,"%d", num1.tipo.x);
    push(s, &str);
}


STACK *newStack (){
    return (STACK *) malloc(sizeof(STACK));
}

/**
* @brief Função Push
*
* @return faz push a um número (caso dê erro, retorna 1) 
*/

<<<<<<< HEAD
int push (STACK *s, ELEMENT elem){
=======
int push (STACK *s,estrutura elem){
>>>>>>> 79ea54c (something)
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

<<<<<<< HEAD
int pop(STACK *s, ELEMENT *x){
=======
int pop(STACK *s, estrutura *x){
>>>>>>> 79ea54c (something)
    if (s->sp == 0) return 1;   
    *x = s->stack[s->sp];
    s->sp--;
    return 0;
}


<<<<<<< HEAD
/**
 * @brief Definição da operação de soma (+).
 *  
 */
void soma(STACK* s) {
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y); 

    if (x.type == LONG && y.type == LONG) {
        ELEMENT final;
        final.type = LONG;

        final.info.typeLong = x.info.typeLong + y.info.typeLong;
        push (s, final);
    }
    if (x.type == LONG && y.type == DOUBLE) {
        ELEMENT final;
        final.type = DOUBLE;

        final.info.typeDouble = x.info.typeLong +  y.info.typeDouble;
        push (s, final);
    }
    if (x.type == DOUBLE && y.type == LONG) {
        ELEMENT final;
        final.type = DOUBLE;

        final.info.typeDouble = x.info.typeDouble + y.info.typeLong;
        push (s, final);
    }
    if (x.type == DOUBLE && y.type == DOUBLE) {
        ELEMENT final;
        final.type = DOUBLE;

        final.info.typeDouble = x.info.typeDouble + y.info.typeDouble;
        push (s, final);
    }
    if (x.type == LONG && y.type == CHAR) {
        ELEMENT final;
        final.type = LONG;

        final.info.typeLong = x.info.typeLong + y.info.typeChar;
        push (s, final);
    }
    if (x.type == DOUBLE && y.type == CHAR) {
        ELEMENT final;
        final.type = DOUBLE;

        final.info.typeDouble = x.info.typeDouble + y.info.typeChar;
        push (s, final);
    }
    if (x.type == CHAR && y.type == LONG) {
        ELEMENT final;
        final.type = LONG;

        final.info.typeLong = x.info.typeChar + y.info.typeLong;
        push (s, final);
    }
    if (x.type == CHAR && y.type == DOUBLE) {
        ELEMENT final;
        final.type = DOUBLE;

        final.info.typeDouble = x.info.typeChar + y.info.typeDouble;
        push (s, final);
    }
    if (x.type == CHAR && y.type == CHAR) {
        ELEMENT final;
        final.type = LONG;

        final.info.typeLong = x.info.typeChar + y.info.typeChar;
        push (s, final);
    }
    /* string - double;
    string - long;
    long - string;
    double - string;
    char - string;
    string - char;
    char - char; */
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
=======
>>>>>>> 79ea54c (something)

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

