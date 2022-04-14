#include <stdio.h>
#include "mathoperations.h"
#include "stack.h"

void func (int x, int a, int b) {
    int i;
    typedef int (*pointer) (STACK *x);
    pointer table[] = 
    {
        soma, subtracao, multiplicacao, divisao, decrementacao, incrementacao, modulo, exponenciacao, eBitwise, ouBitwise, xorBitwise, notBitwise,
    };
    table[i] (x);
}

