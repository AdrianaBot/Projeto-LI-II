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

#include <stdio.h>
#include <string.h>
#include "dispatchtable.h"
#include "parser.h"
#include "stack.h"


/**
 * @brief Dispatch table.
 * 
 * Esta função criada terá o propósito de tornar a escolha
 * da operação o mais eficiente possivel.
 * 
 */


void setupTable(DispatchFunc table[]){
    table['+'] = soma;
    table['-'] = subtracao;
    table['*'] = multiplicacao;
    table['/'] = divisao;
    table['('] = decrementacao;
    table[')'] = incrementacao;
    table['%'] = modulo;
    table['#'] = exponenciacao;
    table['&'] = eBitwise;
    table['|'] = ouBitwise;
    table['^'] = xorBitwise;
    table['~'] = notBitwise;
    table['i'] = convToInt;
    table['f'] = convToDouble;
    table['c'] = convToChar;
    table['s'] = convToString;

}

DispatchFunc funcType[4][4]; //isto tem de se inicializar na main

/**
 * @brief Setup Array para a Soma
 * 
 * @param funcType 
 */
void setupSumArray(DispatchFunc funcType[4][4]) {
    funcType[LONG][LONG] = somaLongLong;
    funcType[LONG][DOUBLE] = somaLongDouble;
    funcType[LONG][CHAR] = somaLongChar;
    //funcType[LONG][STRING] = somaLongString;
    funcType[DOUBLE][LONG] = somaDoubleLong;
    funcType[DOUBLE][DOUBLE] = somaDoubleDouble;
    funcType[DOUBLE][CHAR] = somaDoubleChar;
    //funcType[DOUBLE][STRING] = somaDoubleString;
    funcType[CHAR][LONG] = somaCharLong;
    funcType[CHAR][DOUBLE] = somaCharDouble;
    funcType[CHAR][CHAR] = somaCharChar;
    //funcType[CHAR][STRING] = somaCharString;
    //funcType[STRING][LONG] = somaStringLong;
    //funcType[STRING][DOUBLE] = somaStringDouble;
    //funcType[STRING][CHAR] = somaStringChar;
    //funcType[STRING][STRING] = somaStringString;
}

/**
 * @brief Setup Array para a Subtração
 * 
 * @param funcType 
 */
void setupSubArray(DispatchFunc funcType[4][4]) {
    funcType[LONG][LONG] = subtracaoLongLong;
    funcType[LONG][DOUBLE] = subtracaoLongDouble;
    funcType[LONG][CHAR] = subtracaoLongChar;
    //funcType[LONG][STRING] = subtracaoLongString;
    funcType[DOUBLE][LONG] = subtracaoDoubleLong;
    funcType[DOUBLE][DOUBLE] = subtracaoDoubleDouble;
    funcType[DOUBLE][CHAR] = subtracaoDoubleChar;
    //funcType[DOUBLE][STRING] = subtracaoDoubleString;
    funcType[CHAR][LONG] = subtracaoCharLong;
    funcType[CHAR][DOUBLE] = subtracaoCharDouble;
    funcType[CHAR][CHAR] = subtracaoCharChar;
    //funcType[CHAR][STRING] = subtracaoCharString;
    //funcType[STRING][LONG] = subtracaoStringLong;
    //funcType[STRING][DOUBLE] = subtracaoStringDouble;
    //funcType[STRING][CHAR] = subtracaoStringChar;
    //funcType[STRING][STRING] = subtracaoStringString;
}

/**
 * @brief Setup Array para a Multiplicação
 * 
 * @param funcType 
 */
void setupMulArray(DispatchFunc funcType[4][4]) {
    funcType[LONG][LONG] = multiplicacaoLongLong;
    funcType[LONG][DOUBLE] = multiplicacaoLongDouble;
    funcType[LONG][CHAR] = multiplicacaoLongChar;
    //funcType[LONG][STRING] = multiplicacaoLongString;
    funcType[DOUBLE][LONG] = multiplicacaoDoubleLong;
    funcType[DOUBLE][DOUBLE] = multiplicacaoDoubleDouble;
    funcType[DOUBLE][CHAR] = multiplicacaoDoubleChar;
    //funcType[DOUBLE][STRING] = multiplicacaoDoubleString;
    funcType[CHAR][LONG] = multiplicacaoCharLong;
    funcType[CHAR][DOUBLE] = multiplicacaoCharDouble;
    funcType[CHAR][CHAR] = multiplicacaoCharChar;
    //funcType[CHAR][STRING] = multiplicacaoCharString;
    //funcType[STRING][LONG] = multiplicacaoStringLong;
    //funcType[STRING][DOUBLE] = multiplicacaoStringDouble;
    //funcType[STRING][CHAR] = multiplicacaoStringChar;
    //funcType[STRING][STRING] = multiplicacaoStringString;
}

/**
 * @brief Setup Array para a Divisão
 * 
 * @param funcType 
 */
void setupDivArray(DispatchFunc funcType[4][4]) {
    funcType[LONG][LONG] = divisaoLongLong;
    funcType[LONG][DOUBLE] = divisaoLongDouble;
    funcType[LONG][CHAR] = divisaoLongChar;
    //funcType[LONG][STRING] = divisaoLongString;
    funcType[DOUBLE][LONG] = divisaoDoubleLong;
    funcType[DOUBLE][DOUBLE] = divisaoDoubleDouble;
    funcType[DOUBLE][CHAR] = divisaoDoubleChar;
    //funcType[DOUBLE][STRING] = divisaoDoubleString;
    funcType[CHAR][LONG] = divisaoCharLong;
    funcType[CHAR][DOUBLE] = divisaoCharDouble;
    funcType[CHAR][CHAR] = divisaoCharChar;
    //funcType[CHAR][STRING] = divisaoCharString;
    //funcType[STRING][LONG] = divisaoStringLong;
    //funcType[STRING][DOUBLE] = divisaoStringDouble;
    //funcType[STRING][CHAR] = divisaoStringChar;
    //funcType[STRING][STRING] = divisaoStringString;
}

int func(STACK *x, char c, DispatchFunc table[]) {
    if(c > 126 /*|| table[c] == NULL*/){
        return 1;
    }

    table[c](x);
    return 0;
}