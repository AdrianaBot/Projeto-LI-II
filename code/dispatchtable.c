/**
 * @file stack.h
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís
 * @brief Este ficheiro possibilita o uso do stack.c noutros módulos.
 * @version 0.1
 * @date 2022-04-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

#include "stack.h"

/**
 * @brief Dispatch table.
 * 
 * Esta função criada terá o propósito de tornar a escolha
 * da operação o mais eficiente possivel.
 * 
 */
void setupTable(DispatchFunc table[]){
    table['('] = decrementacao;
    table[')'] = incrementacao;
    table['%'] = modulo;
    table['#'] = exponenciacao;
    table['&'] = eBitwise;
    table['|'] = ouBitwise;
    table['^'] = xorBitwise;
    table['~'] = notBitwise;
    table['i'] = convToLong;
    table['f'] = convToDouble;
    table['c'] = convToChar;
    table['s'] = convToString;
    table['_'] = duplicacao;
    table[';'] = pop2;
    table['\\'] = troca;
    table['@'] = roda;
    table['$'] = copia;

}


/**
 * @brief Setup Array para a Soma
 * 
 * @param funcType 
 */
void setupSumArray(DispatchType funcType[4][4]) {
    funcType[LONG][LONG] = somaLongLong;
    funcType[LONG][DOUBLE] = somaLongDouble;
    funcType[LONG][CHAR] = somaLongChar;
    funcType[DOUBLE][LONG] = somaDoubleLong;
    funcType[DOUBLE][DOUBLE] = somaDoubleDouble;
    funcType[DOUBLE][CHAR] = somaDoubleChar;
    funcType[CHAR][LONG] = somaCharLong;
    funcType[CHAR][DOUBLE] = somaCharDouble;
    funcType[CHAR][CHAR] = somaCharChar;
}

/**
 * @brief Setup Array para a Subtração
 * 
 * @param funcType 
 */
void setupSubArray(DispatchType funcType[4][4]) {
    funcType[LONG][LONG] = subtracaoLongLong;
    funcType[LONG][DOUBLE] = subtracaoLongDouble;
    funcType[LONG][CHAR] = subtracaoLongChar;
    funcType[DOUBLE][LONG] = subtracaoDoubleLong;
    funcType[DOUBLE][DOUBLE] = subtracaoDoubleDouble;
    funcType[DOUBLE][CHAR] = subtracaoDoubleChar;
    funcType[CHAR][LONG] = subtracaoCharLong;
    funcType[CHAR][DOUBLE] = subtracaoCharDouble;
    funcType[CHAR][CHAR] = subtracaoCharChar;
}

/**
 * @brief Setup Array para a Multiplicação
 * 
 * @param funcType 
 */
void setupMulArray(DispatchType funcType[4][4]) {
    funcType[LONG][LONG] = multiplicacaoLongLong;
    funcType[LONG][DOUBLE] = multiplicacaoLongDouble;
    funcType[LONG][CHAR] = multiplicacaoLongChar;
    funcType[DOUBLE][LONG] = multiplicacaoDoubleLong;
    funcType[DOUBLE][DOUBLE] = multiplicacaoDoubleDouble;
    funcType[DOUBLE][CHAR] = multiplicacaoDoubleChar;
    funcType[CHAR][LONG] = multiplicacaoCharLong;
    funcType[CHAR][DOUBLE] = multiplicacaoCharDouble;
    funcType[CHAR][CHAR] = multiplicacaoCharChar;
}

/**
 * @brief Setup Array para a Divisão
 * 
 * @param funcType 
 */
void setupDivArray(DispatchType funcType[4][4]) {
    funcType[LONG][LONG] = divisaoLongLong;
    funcType[LONG][DOUBLE] = divisaoLongDouble;
    funcType[LONG][CHAR] = divisaoLongChar;
    funcType[DOUBLE][LONG] = divisaoDoubleLong;
    funcType[DOUBLE][DOUBLE] = divisaoDoubleDouble;
    funcType[DOUBLE][CHAR] = divisaoDoubleChar;
    funcType[CHAR][LONG] = divisaoCharLong;
    funcType[CHAR][DOUBLE] = divisaoCharDouble;
    funcType[CHAR][CHAR] = divisaoCharChar;
}

int func(STACK *x, unsigned char c, DispatchFunc table[]) {
    if(c > 126 || table[c] == 0){
        return 1;
    }

    table[c](x);
    return 0;
}