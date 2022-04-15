#include <stdio.h>
#include "stack.h"
#include "dispatchtable.h"


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
    if(c > 126 || table[c] == NULL){
        return 1;
    }
    table[c](x);
    return 0;
}

int main() {
  STACK x = (STACK) { .sp = 0 };
}
