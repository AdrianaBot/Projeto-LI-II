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
}

int func(STACK *x, char c, DispatchFunc table[]) {
    /*
    if(c > 126 || table[c] == NULL){
        return 1;
    }*/
    if (c == 'l') {
        int a;
        scanf("%d", &a);
        push(x, a);
        return 0;
    }
    
    table[(int) c](x);
    return 0;
}

