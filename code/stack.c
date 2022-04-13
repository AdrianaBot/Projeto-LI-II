#include <stdio.h>
#include "stack.h"

STACK *new_stack() {
    return (STACK *) malloc(sizeof(STACK));
}

/**
 * @brief Função Push     
 */

void push (STACK *s,int elem){
    do{
    s->stack[s->sp]=elem;
    s->sp++;
    }while(s->sp >= MAX);
}
/**
* @brief Função Pop.
*/
int pop(STACK *s){
    
    int ret = s->stack[s->sp];
    s->sp--;
    return ret;
}


    