#include <stdio.h>
#include "dispatchtable.h"


void setupTable(){
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

int func(STACK *x, char c) {
    if(c > 126 || table[c] == NULL){
        return 1;
    }
    table[c](x);
    return 0;
}

