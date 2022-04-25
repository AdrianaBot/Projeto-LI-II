#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stack.h"

/*Indice da Stack
line 14 -> 51, STACK
lin 52 -> 752 ,MATH OPS
line 753 -> End, conversões.
*/



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



// MATHS

/**
 * @brief Definição da operação de soma (+).
 *  
 * @param s -> pointer da STACK 
 */
void soma(STACK* s, DispatchType somaArray[4][4]) {
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    somaArray[x.type][y.type](s,x,y);
}

/**
 * @brief Definição da operação de soma (+) para Long.
 * 
 * @param s -> pointer da STACK 
 */
void somaLongLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong + y.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de soma (+) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void somaLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong + y.info.typeDouble;
    push (s, final); 
}

/**
 * @brief Definição da operação de soma (+) entre Lonbg e Char.
 * 
 * @param s -> pointer da STACK 
 */
void somaLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong + y.info.typeChar;
    push (s,final);
}

/**
 * @brief Definição da operação de soma (+) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void somaDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble + y.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de soma (+) entre Doubles.
 * 
 * @param s -> pointer da STACK 
 */
void somaDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble + y.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de soma (+) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void somaDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = x.info.typeDouble + y.info.typeChar;
    push(s, final);
}

/**
 * @brief Definição da operação de soma (+) entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void somaCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar + y.info.typeLong;
    push(s, final);
}

/**
 * @brief Definição da operação de soma (+) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void somaCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar + y.info.typeDouble;
    push(s,final);
}

/**
 * @brief Definição da operação de soma (+) Entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void somaCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar + y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de subtração (-).
 * 
 * @param s -> pointer da STACK 
 */
void subtracao(STACK *s, DispatchType subtracaoArray[4][4]){
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    subtracaoArray[y.type][x.type] (s,y,x);
}

/**
 * @brief Definição da operação de subtração (-) entre Long.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong - y.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de subtração (-) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong - y.info.typeDouble;
    push (s, final); 
}

/**
 * @brief Definição da operação de subtração (-) entre Long e Char.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong - y.info.typeChar;
    push (s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble - y.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Double.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble - y.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de subtração (-) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = x.info.typeDouble - y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de subtração (-) Entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar - y.info.typeLong;
    push(s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar - y.info.typeDouble;
    push(s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar - y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de multiplicação(*).
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacao(STACK *s, DispatchType multiplicacaoArray[4][4]){
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    multiplicacaoArray[x.type][y.type] (s,x,y);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Long.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong * y.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de multiplicação(*) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong * y.info.typeDouble;
    push (s, final); 
}

/**
 * @brief Definição da operação de multiplicação(*) entre Long e Char.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong * y.info.typeChar;
    push (s,final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble * y.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Double.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble * y.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de multiplicação(*) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;            
    final.info.typeDouble = x.info.typeDouble * y.info.typeChar;
    push(s, final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar * y.info.typeLong;
    push(s, final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar * y.info.typeDouble;
    push(s, final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar * y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de divisão(/).
 * 
 * @param s -> pointer da STACK 
 */
void divisao(STACK *s, DispatchType divisaoArray[4][4]){
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    divisaoArray[y.type][x.type] (s,y,x);
}

/**
 * @brief Definição da operação de divisão(/) entre Long.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = y.info.typeLong / x.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de divisão(/) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = y.info.typeDouble / x.info.typeLong;
    push (s, final); 
}

/**
 * @brief Definição da operação de divisão(/) entre Long e Char.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = y.info.typeChar / x.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = y.info.typeLong / x.info.typeDouble;
    push (s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Double.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = y.info.typeDouble / x.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de divisão(/) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;           
    final.info.typeDouble = y.info.typeChar / x.info.typeDouble;
    push(s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = y.info.typeLong / x.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = y.info.typeDouble / x.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = y.info.typeChar / x.info.typeChar;
    push(s,final);
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
    final.info.typeLong = x.info.typeLong - 1;           
    pop(s,&x); 
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
 * @brief Definição da operação de exponenciação (#).
 * 
 * @param s -> pointer da STACK 
 */
void exponenciacao (STACK* s) {
    ELEMENT x,y,final;
    x.type = DOUBLE;
    x.info.typeDouble = 0;
    y.type = DOUBLE;
    y.info.typeDouble = 0;
    pop(s,&x);
    pop(s,&y);         
    final.info.typeDouble = pow (x.info.typeDouble,y.info.typeDouble);
   push(s, final);
}

/**
 * @brief Definição da operação de "e" (bitwise) para inteiros (&).
 * 
 * @param s -> pointer da STACK 
 */
void eBitwise (STACK* s) {
    ELEMENT x,y,final;
    x.type = LONG;
    x.info.typeLong = 0;
    y.type = LONG;
    y.info.typeLong = 0;
    pop(s,&x);
    pop(s,&y);
    final.info.typeLong = x.info.typeLong & y.info.typeLong;
    push(s,final);
}

/**
 * @brief Definição da operação de "ou" (bitwise) para inteiros (|).
 * 
 * @param s -> pointer da STACK 
 */
void ouBitwise (STACK* s) {
    ELEMENT x,y,final;
    x.type = LONG;
    x.info.typeLong = 0;
    y.type = LONG;
    y.info.typeLong = 0;
    pop(s,&x);
    pop(s,&y); 
    final.info.typeLong = x.info.typeLong | y.info.typeLong;
    push(s, final);
}

/**
 * @brief Definição da operação de "xor" (bitwise) para inteiros (^).
 * O xor é o ou exclusivo.
 * 
 * @param s -> pointer da STACK 
 */
void xorBitwise (STACK* s) {
    ELEMENT x,y,final;
    x.type = LONG;
    y.type = LONG;
     
    pop(s,&x);
    pop(s,&y);
    final.info.typeLong = x.info.typeLong ^ x.info.typeLong;
    push(s,final);
}

/**
 * @brief Definição da operação de "not" (bitwise) para inteiros (~).
 * 
 * @param s -> pointer da STACK 
 */
void notBitwise (STACK* s) {
    ELEMENT x,final;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s, &x); 
    final.info.typeLong = ~ x.info.typeLong;
    push(s, final);
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
    *x = s->stack[n - 1];   
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
    nesimo(s, &x, n.info.typeLong);           // IDK IF THIS IS OK!
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

void pushA (STACK *s){
    ELEMENT x;
    x.info.typeLong = 10;
    push(s,x);
}

void pushB (STACK *s){
    ELEMENT x;
    x.info.typeLong = 11;
    push(s,x);
}

void pushC (STACK *s){
    ELEMENT x;
    x.info.typeLong = 12;
    push(s,x);
}

void pushD (STACK *s){
    ELEMENT x;
    x.info.typeLong = 13;
    push(s,x);
}

void owushE (STACK *s){
    ELEMENT x;
    x.info.typeLong = 14;
    push(s,x);
}

void pushF (STACK *s){
    ELEMENT x;
    x.info.typeLong = 15;
    push(s,x);
}

void pushN (STACK *s){
    ELEMENT x;
    x.info.typeChar = '\n';
    push(s,x);
}

void pushS (STACK *s){
    ELEMENT x;
    x.info.typeChar = ' ';
    push(s,x);
}

void pushX(STACK *s){
    ELEMENT x;
    x.info.typeLong = 0;
    push (s,x);
}

void pushY(STACK *s){
    ELEMENT x;
    x.info.typeLong = 1;
    push(s,x);
}

void pushZ(STACK *s){
    ELEMENT x;
    x.info.typeLong = 2;
    push(s,x);
}

//CONVERSÕES


/**
 * @brief convToLong converte tipos para Long.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para Long.
 * 
 * @param s -> pointer da STACK 
 */
void convToLong(STACK *s){
    ELEMENT x, converter;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);
    converter.type = LONG;
    
    
    if (x.type == LONG){
    converter.info.typeLong = x.info.typeLong; 
    push (s,converter);
    }

    else if  (x.type == DOUBLE){
    converter.info.typeLong=x.info.typeDouble;
    push (s,converter);
    }

    else if (x.type == CHAR){
    converter.info.typeLong=x.info.typeChar;
    push(s,converter);
    }

    else if (x.type == STRING){
    long v;   
    char h[BUFSIZ];
    if (sscanf(h,"%ld",&v) == 1) converter.info.typeLong = v; 

    push(s,converter);
    }
}
/**
 * @brief convToDouble converte tipos para Double.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para Double.
 * 
 * @param s -> pointer da STACK 
 */
void convToDouble(STACK *s){
    ELEMENT x, converter;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);
    converter.type = DOUBLE;
    
    if (x.type == LONG){
    converter.info.typeDouble = x.info.typeLong; 
    push (s,converter);
    }

    else if  (x.type == DOUBLE){
    converter.info.typeDouble = x.info.typeDouble;
    push (s,converter);
    }
    else if (x.type == CHAR){
    converter.info.typeDouble = x.info.typeChar;
    push(s,converter);
    }

    else if (x.type == STRING){
    char h[BUFSIZ]; 
    double v;   
    
    
    if (sscanf(h,"%lf",&v) == 1) converter.info.typeDouble = v; 

    push(s,converter);
    }
}

/**
 * @brief convToChar converte tipos para Char.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para Char.
 * 
 * @param s -> pointer da STACK 
 */
void convToChar(STACK *s){
    ELEMENT x, converter;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);
    converter.type = CHAR;

    if (x.type == LONG){

    converter.info.typeChar = x.info.typeLong; 
    push (s,converter);
    }

    else if  (x.type == DOUBLE){
    converter.info.typeChar = x.info.typeDouble;
    push (s,converter); 
    }
    else if (x.type == CHAR){
    converter.info.typeChar = x.info.typeChar;
    push(s,converter);
    }

    else if (x.type == STRING){
    char h[BUFSIZ]; 
    long v;   
    
    
    if (sscanf(h,"%ld",&v) == 1)    converter.info.typeChar = v; 

    push(s,converter);
    }
}

/**
 * @brief convToString converte tipos para String.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para String.
 * 
 * @param s -> pointer da STACK 
 */
void convToString(STACK *s){
    ELEMENT x, converter;
    x.type = LONG;
    pop(s,&x);
    converter.type = STRING;

    if (x.type == LONG){
    sprintf(converter.info.typeString,"%ld",x.info.typeLong);
    push (s,converter);
    }

    else if (x.type == DOUBLE){
    sprintf(converter.info.typeString,"%lf",x.info.typeDouble);
    push (s,converter);
    }

    else if (x.type == CHAR){
    sprintf(converter.info.typeString,"%c",x.info.typeChar);
    push(s,converter);
    }   
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

