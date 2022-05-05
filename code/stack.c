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
    if (s->sp == 0) return 1;    
    s->sp--;   
    *x = s->stack[s->sp];
    return 0;
}

//ARRAY

// it don't work ... it aint broke, it just wont bussssst

void pushin (STACK *s){
    ELEMENT m;
    pop(s,&m);

    if (m.type == ARRAY){
        
        for (int i = 0; i < m.info.typeArray.size;i++){
           ELEMARRAY a = m.info.typeArray.array[i];
           if (a.typeA == LONG){
                
                ELEMENT x = {
                    .type = LONG,
                    .info.typeLong = a.infoA.typeLongA
                };
               push(s, x);}
           else if (a.typeA == CHAR){
            
               ELEMENT x = {
                   .type = CHAR,
                   .info.typeChar = a.infoA.typeCharA
               };
               push(s,x);
           } 
         else if (a.typeA == DOUBLE){
               
               ELEMENT x = {
                   .type = DOUBLE,
                   .info.typeDouble = a.infoA.typeDoubleA
               };
               push(s,x);
           }
        }



        }


    }





/**
 * @brief NewArray é uma função que cria novos arrays.
 * 
 * @param s -> Pointer da Stack
 */

void newArray (STACK* s){
    ELEMENT a = {
        .type = ARRAY
    };
    push(s,a);
}

/**
 * @brief size será a função respetiva ao character (,) que procura
 * o tamanho de um array/string e da-nos o seu tamanho ou o range.
 * 
 * 
 * @param s -> pointer da Stack 
 */

void size(STACK* s){ 
    ELEMENT m;
    pop(s,&m);

    if (m.type == ARRAY){
        ELEMENT x = {
            .type = LONG,
            .info.typeLong = m.info.typeArray.size
        };
        push(s,x); 
    }    
    else if (m.type == LONG){
        ELEMENT x = {
            .type = ARRAY
        };  
        for (int i = 0; i < m.info.typeLong ;i++){
             ELEMARRAY a = {
                .typeA = LONG, 
                .infoA.typeLongA = i,
            };
            x.info.typeArray.array[x.info.typeArray.size] = a;
            x.info.typeArray.size++;
        } 
        push(s,x);    
    }
}

/**
 * @brief addToArray é uma função que adiciona um elemento de qualquer tipo para um Array!
 * 
 * @param s -> pointer da Stack 
 * @param h 
 */
void addToArray(STACK* s, char h[]) {
    ELEMENT m;
    pop(s,&m);

    if (h[0] >= 'a' && h[0] <= 'z' && h[1] == '\0') {
        ELEMARRAY a = {
            .typeA = CHAR, 
            .infoA.typeCharA = h[0],
        };
        m.info.typeArray.array[m.info.typeArray.size] = a;
        m.info.typeArray.size++;
        push(s,m);
        return;
    }
    char* endptr;
    long num = strtol(h,&endptr,10);
    if (*endptr == '\0') {
        ELEMARRAY a = {
            .typeA = LONG, 
            .infoA.typeLongA = num,
        };
        m.info.typeArray.array[m.info.typeArray.size] = a;
        m.info.typeArray.size++;
        push(s,m);
        return;
    }
    double b = strtod(h,&endptr);
    if (*endptr == '\0') {
        ELEMARRAY a = {
            .typeA = DOUBLE, 
            .infoA.typeDoubleA = b,
        };
        m.info.typeArray.array[m.info.typeArray.size] = a;
        m.info.typeArray.size++;
        push(s,m);
        return;
    }
}



/**
 * @brief printArray é uma função que mostra o array
 * 
 * @param s -> pointer da stack
 * @param n -> É a posição do Array na STACK
 */

void printArray(STACK* s, int n) {
    ELEMENT a = s->stack[n];

    for (int i = 0; i < a.info.typeArray.size; i++) {
        ELEMARRAY x = a.info.typeArray.array[i];
        if (x.typeA == LONG) printf ("%ld", x.infoA.typeLongA);
        else if (x.typeA == DOUBLE) printf ("%g", x.infoA.typeDoubleA);
        else if (x.typeA == CHAR) printf ("%c", x.infoA.typeCharA);
    }
}

void newString(STACK *s) {
     ELEMENT x = {
            .type = ARRAY, 
        };
        push(s,x);
}

void printString (STACK* s, int n) {
    ELEMENT a = s->stack[n];

    for (int i  = 0; i < a.info.typeArray.size; i++) {
        ELEMARRAY x = a.info.typeArray.array[i];
        printf("%c", x.infoA.typeCharA);

    }
}

// Operacoes  com a Stack
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

/**
 * @brief readline function
 * 
 * Lê uma linha
 * 
 * @param s 
 */
void readline(STACK *s) {
    char line[BUFSIZ];

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        ELEMENT a;
        a.type = STRING;
        strcpy (a.info.typeString, line);
        push(s,a);
    }
}


void psd (STACK *s) {
     for (int i = 0; i < s->sp; i++) {
        ELEMENT x = s->stack[i];

        if (x.type == LONG) printf ("l: %ld ", x.info.typeLong);
        else if (x.type == DOUBLE) printf ("f: %lf ", x.info.typeDouble);
        else if (x.type == CHAR) printf ("c: %c ", x.info.typeChar);
        else if (x.type == STRING) printf ("s: '%s' ", x.info.typeString); 
    }
    putchar('\n'); 
}