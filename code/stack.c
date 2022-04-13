#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK *newStack () {
    return (STACK *) malloc(sizeof(STACK));
}

/**
 * @brief Função Push:     
 */
void push (STACK *s,int elem){
if (s->sp == MAX) return 1;
else {
    s->sp++;
    s->stack[s->sp] = elem;
return 0;
}
}

/**
* @brief Função Pop:
*/

int pop(STACK *s){
if (s->sp == 0) return 0;
else {
    int ret = s->stack[s->sp];
    s->sp--;
    return ret;
} 
}