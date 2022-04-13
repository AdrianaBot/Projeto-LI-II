
#include <stdio.h>
#include <math.h>

/**
 * @brief Definição da operação de soma (+).
 * 
 */
int soma(int x, int y) {
    //receber a stack e dar push de x e y 
    return x + y;
}

/**
 * @brief Definição da operação de subtração (-).
 * 
 */
int subtracao(int x, int y) {
    return x - y;
}

/**
 * @brief Definição da operação de multiplicação (*).
 * 
 */
int multiplicacao(int x, int y) {
    return x * y;
}

/**
 * @brief Definição da operação de divisão (/).
 * 
 */
int divisao (int x, int y) {
    return x / y;
}

/**
 * @brief Definição da operação de decrementação ( ( ).
 * A decrementação diminui o inteiro em 1.
 */
int decrementacao (int x) {
    return x--;
}

/**
 * @brief Definição da operação de incrementação ( ) ).
 * A incrementação aumenta em 1 valor.
 */
int incrementacao (int x) {
    return x++;
}

/**
 * @brief Definição da operação de módulo (%).
 * O módulo é o resto da divisão inteira de x por y.
 */
int modulo (int x, int y) {
    return x % y;
}

/**
 * @brief Definição da operação de exponenciação (#).
 * 
 */
int exponenciacao (int x, int y) {
    return pow(x,y);
}

/**
 * @brief Definição da operação de "e" (bitwise) para inteiros (&).
 * 
 */
int eBitwise (int x, int y) {
    return x & y;
}

/**
 * @brief Definição da operação de "ou" (bitwise) para inteiros (|).
 * 
 */
int ouBitwise (int x, int y) {
    return x | y;
}

/**
 * @brief Definição da operação de "xor" (bitwise) para inteiros (^).
 * O xor é o ou exclusivo.
 */
int xorBitwise (int x, int y) {
    return x ^ y;
}

/**
 * @brief Definição da operação de "not" (bitwise) para inteiros (~).
 * 
 */
int notBitwise (int x) {
    return ~x;
}

