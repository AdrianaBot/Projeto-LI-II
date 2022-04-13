
#include <stdio.h>
#include <math.h>
#include "stack.h"

/**
 * @brief Definição da operação de soma (+).
 * 
 */


void soma(STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, x + y);
}

/**
 * @brief Definição da operação de subtração (-).
 * 
 */
void subtracao(STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, y - x);
}

/**
 * @brief Definição da operação de multiplicação (*).
 * 
 */
void multiplicacao(STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, x * y);
}

/**
 * @brief Definição da operação de divisão (/).
 * 
 */
void divisao(STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, y / x);
}

/**
 * @brief Definição da operação de decrementação ( ( ).
 * A decrementação diminui o inteiro em 1.
 */
void decrementacao (STACK* s) {
    int x = pop(s); 
    push(s, --x);
}

/**
 * @brief Definição da operação de incrementação ( ) ).
 * A incrementação aumenta em 1 valor.
 */
void incrementacao (STACK* s) {
    int x = pop(s); 
    push(s, ++x);
}

/**
 * @brief Definição da operação de módulo (%).
 * O módulo é o resto da divisão inteira de x por y.
 */
void modulo (STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, y % x);
}

/**
 * @brief Definição da operação de exponenciação (#).
 * 
 */
void exponenciacao (STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, pow (y, x));
}

/**
 * @brief Definição da operação de "e" (bitwise) para inteiros (&).
 * 
 */
void eBitwise (STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, x & y);
}

/**
 * @brief Definição da operação de "ou" (bitwise) para inteiros (|).
 * 
 */
void ouBitwise (STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, x | y);
}

/**
 * @brief Definição da operação de "xor" (bitwise) para inteiros (^).
 * O xor é o ou exclusivo.
 */
void xorBitwise (STACK* s) {
    int x = pop(s), y = pop(s); 
    push(s, x ^ y);
}

/**
 * @brief Definição da operação de "not" (bitwise) para inteiros (~).
 * 
 */
void notBitwise (STACK* s) {
    int x = pop(s); 
    push(s, ~x);
}

