#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"


// STACK

STACK *newStack (){
    return calloc(sizeof(STACK),1);
}

/**
* @brief Função Push
*
* @param s -> pointer da STACK 
*
* @return faz push a um número (caso dê erro, retorna 1) 
*/

int push (STACK *s, ELEMENT elem){
    if (s->sp == BUFSIZ) abort();
    s->stack[s->sp] = elem;
    s->sp++;
    return 0;
}

/**
* @brief Função Pop:
*
* @param s -> pointer da STACK 
*
* @return faz pop a um número (caso dê erro, retorna 1) 
*/

int pop(STACK *s, ELEMENT *x){
    if (s->sp == 0) abort();    
    s->sp--;   
    *x = s->stack[s->sp];
    return 0;
}


/**
 * @brief Definição da operação de decrementação ( ( ).
 * A decrementação diminui o inteiro em 1.
 * 
 * @param s -> pointer da STACK 
 */
void decrementacao (STACK* s) {
    ELEMENT x,final;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);
    final.info.typeLong = x.info.typeLong - 1;           
    push(s, final);
}

/**
 * @brief Definição da operação de incrementação ( ) ).
 * A incrementação aumenta o inteiro em 1.
 * 
 * @param s -> pointer da STACK 
 */
void incrementacao (STACK* s) {
    ELEMENT x,final;
    x.type = LONG;
    x.info.typeLong = 0;                              
    pop(s,&x);
    final.info.typeLong = x.info.typeLong + 1;                    
    push(s,final);
}

/**
 * @brief Definição da operação de módulo (%).
 * O módulo é o resto da divisão inteira de x por y.
 * 
 * @param s -> pointer da STACK 
 */
void modulo (STACK* s) {
    ELEMENT x, y,final; 
    x.type = LONG;
    x.info.typeLong = 0;
    y.type = LONG;
    y.info.typeLong = 0;
    pop(s,&x);
    pop(s,&y); 
    final.info.typeLong = y.info.typeLong % x.info.typeLong;    
    push(s,final);
}



/**
 * @brief Definição da operação de duplicação (_).
 * 
 * @param s -> pointer da STACK 
 */
 
void duplicacao (STACK* s){
    ELEMENT x;
    x.info.typeLong = 0;
    pop(s, &x);
    push(s, x);                     
    push(s, x);
}

/**
 * @brief Definição da operação de troca de dois elementos no topo da stack (\).
 * 
 * @param s -> pointer da STACK 
 */
void troca (STACK* s) {
    ELEMENT x,y;
    x.info.typeLong = 0;
    y.info.typeLong = 0;
    pop(s, &x);
    pop(s, &y);
    push(s, x);
    push(s, y);
}


/**
 * @brief Definição da operação de rodagem de três elementos no topo da stack (@).
 *
 * @param s -> pointer da STACK 
 */
void roda (STACK* s) {
    ELEMENT x,y,z;
    x.info.typeLong = 0;
    y.info.typeLong = 0;
    z.info.typeLong = 0;
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
 * @param s -> pointer da STACK 
 */
void nesimo(STACK *s, ELEMENT* x, long n){                                      
    *x = s->stack[s->sp - n - 1];   
}

/**
 * @brief Definição da operação de cópia do n-ésimo elemento para o topo da stack, no qual 0 é o topo da stack (n $, em que n é a posição na stack).
 * 
 * @param s -> pointer da STACK 
 */
void copia (STACK* s) {
    ELEMENT n;
    n.info.typeLong = 0;                                              
    pop(s, &n);
    ELEMENT x;
    x.type = LONG;
    x.info.typeLong = 0;              
    nesimo(s, &x, n.info.typeLong);           
    push(s, x);  
}


/**
 * @brief Definição da operação de pop sem salvaguarda de valores (;).
 *  
 * @param s -> pointer da STACK 
 */
void pop2(STACK *s) {
    ELEMENT x;
    x.info.typeLong = 0;
    pop(s, &x);
}   

void assign(STACK *s,char c,ELEMENT var[]){
    ELEMENT x;
    x.info.typeLong = 0;
    pop(s,&x);
    var[c-'A'] = x;
    push(s,x);
}



void psd (STACK *s) {
     for (int i = 0; i < s->sp; i++) {
        ELEMENT x = s->stack[i];

        if (x.type == LONG) printf ("l: %ld ", x.info.typeLong);
        else if (x.type == DOUBLE) printf ("f: %.1lf ", x.info.typeDouble);
        else if (x.type == CHAR) printf ("c: %c ", x.info.typeChar);
        else if (x.type == STRING) printf ("s: '%s' ", x.info.typeString); 
    }
    putchar('\n'); 
}
