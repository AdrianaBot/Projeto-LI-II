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
#include <string.h> 

void setupTable(DispatchFunc table[]){
    table['+'] = soma;
    table['-'] = subtracao;
    table['*'] = multiplicacao;
    table['/'] = divisao;
    table['#'] = exponenciacao;
    table['('] = decrementacao;
    table[')'] = incrementacao;
    table['%'] = modulo;
    table['&'] = eBitwise;
    table['|'] = ouBitwise;
    table['^'] = xorBitwise;
    table['~'] = notBitwise;
    table['i'] = convToLong;
    table['f'] = convToDouble;
    table['c'] = convToChar;
    table['s'] = convToString;
    table['l'] = readline;
    table['_'] = duplicacao;
    table[';'] = pop2;
    table['\\'] = troca;
    table['@'] = roda;
    table['$'] = copia;
    table['='] = igual;
    table['<'] = menor;
    table['>'] = maior;
    table['!'] = nao;
    table[139] = eShortcut;
    table[225] = ouShortcut;
    table[161] = menorDoisValores;
    table[163] = maiorDoisValores;
    table['?'] = ifThenElse;
    table[','] = size;
    table['t'] = funcT;
}

int func(STACK *x, char* c, DispatchFunc table[], int f) {
    for (int i = 1; i <= f; i++) 
        x = x->stack[x->sp-1].info.typeArray;

    if (c[1] == '\0') {
        unsigned char a = c[0];
        
        if(a > 126 || table[a] == 0) {
            return 1;
        }

        table[a](x);
    }
    else {
        unsigned char b = c[0] + c[1];

        if (b > 225 || table[b] == 0) {
            return 1;
        }
        table[b](x);
    }
    return 0;
}


void setupSumArray(DispatchType funcType[6][6]) {
    funcType[LONG][LONG] = somaLongLong;
    funcType[LONG][DOUBLE] = somaLongDouble;
    funcType[LONG][CHAR] = somaLongChar;
    funcType[DOUBLE][LONG] = somaDoubleLong;
    funcType[DOUBLE][DOUBLE] = somaDoubleDouble;
    funcType[DOUBLE][CHAR] = somaDoubleChar;
    funcType[CHAR][LONG] = somaCharLong;
    funcType[CHAR][DOUBLE] = somaCharDouble;
    funcType[CHAR][CHAR] = somaCharChar;
    funcType[LONG][ARRAY] = somaElemArray;
    funcType[DOUBLE][ARRAY] = somaElemArray;
    funcType[CHAR][ARRAY] = somaElemArray;
    funcType[ARRAY][LONG] = somaArrayElem;
    funcType[ARRAY][DOUBLE] = somaArrayElem;
    funcType[ARRAY][CHAR] = somaArrayElem;
    funcType[ARRAY][ARRAY] = somaArrayArray;
    funcType[LONG][STRING] = somaElemString;
    funcType[DOUBLE][STRING] = somaElemString;
    funcType[CHAR][STRING] = somaElemString;
    funcType[STRING][LONG] = somaStringElem;
    funcType[STRING][DOUBLE] = somaStringElem;
    funcType[STRING][CHAR] = somaStringElem;
    funcType[STRING][STRING] = somaStringString;
}


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

void setupMulArray(DispatchType funcType[6][6]) {
    funcType[LONG][LONG] = multiplicacaoLongLong;
    funcType[LONG][DOUBLE] = multiplicacaoLongDouble;
    funcType[LONG][CHAR] = multiplicacaoLongChar;
    funcType[DOUBLE][LONG] = multiplicacaoDoubleLong;
    funcType[DOUBLE][DOUBLE] = multiplicacaoDoubleDouble;
    funcType[DOUBLE][CHAR] = multiplicacaoDoubleChar;
    funcType[CHAR][LONG] = multiplicacaoCharLong;
    funcType[CHAR][DOUBLE] = multiplicacaoCharDouble;
    funcType[CHAR][CHAR] = multiplicacaoCharChar;
    funcType[BLOCK][ARRAY] = multiplicacaoBlockArray;
}

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

void setupExpArray(DispatchType funcType[4][4]) {
    funcType[LONG][LONG] = expLongLong;
    funcType[LONG][DOUBLE] =expLongDouble;
    funcType[LONG][CHAR] = expLongChar;
    funcType[DOUBLE][LONG] = expDoubleLong;
    funcType[DOUBLE][DOUBLE] = expDoubleDouble;
    funcType[DOUBLE][CHAR] = expDoubleChar;
    funcType[CHAR][LONG] = expCharLong;
    funcType[CHAR][DOUBLE] = expCharDouble;
    funcType[CHAR][CHAR] = expCharChar;
}

void setupVar(ELEMENT var[]) {
    var['A'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 10,
    };
    var['B'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 11,
    };
    var['C'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 12,
    };
    var['D'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 13,
    };
    var['E'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 14,
    };
    var['F'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 15,
    };
    var['N'-'A'] = (ELEMENT) {
        .type = CHAR, 
        .info.typeChar = '\n',
    };
    var['S'-'A'] = (ELEMENT) {
        .type = CHAR, 
        .info.typeChar = ' ',
    };
    var['X'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 0,
    };
    var['Y'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 1,
    };
    var['Z'-'A'] = (ELEMENT) {
        .type = LONG, 
        .info.typeLong = 2,
    };
}