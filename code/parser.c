#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "dispatchtable.h"

/**
 * @brief A função executa identifica qual a operação que deverá ser aplicada. 
 * Caso não o seja, simplesmente adiciona à stack.
 * 
 * @param s 
 * @param c 
 */

void executa (STACK *s, char c[]) {
    if      (c[0] == '+') soma(s);
    else if (c[0] == '-') subtracao(s);
    else if (c[0] == '*') multiplicacao(s);
    else if (c[0] == '/') divisao(s);
    else if (c[0] == '(') decrementacao(s);
    else if (c[0] == ')') incrementacao(s);
    else if (c[0] == '%') modulo(s);
    else if (c[0] == '#') exponenciacao(s);
    else if (c[0] == '&') eBitwise(s);
    else if (c[0] == '|') ouBitwise(s);
    else if (c[0] == '^') xorBitwise(s);
    else if (c[0] == '~') notBitwise(s);
    else {
        int val;
        sscanf(c, "%d", &val);
        push (s, val);
    }
}

