#include <stdio.h>
#include "mathoperations.h"
#include "stack.h"

/**
 * @brief Dispatch table
 * 
 * @param x 
 * @param c 
 */

void func (STACK *x, char c) { //converter o carater num índice 
    int i;
    typedef int (*pointer) (STACK *x);
    pointer table[] = 
    {
        soma, subtracao, multiplicacao, divisao, decrementacao, incrementacao, modulo, exponenciacao, eBitwise, ouBitwise, xorBitwise, notBitwise,
    };
    table[i] (x);
}

