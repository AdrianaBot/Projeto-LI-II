#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

STACK *newStack () {
    return (STACK *) malloc(sizeof(STACK));
}

/**
 * @brief Função Push:     
 */
int push (STACK *s,int elem){
    if (s->sp == BUFSIZ) return 1;
    s->sp++;
    s->stack[s->sp] = elem;
    return 0;
}
<<<<<<< HEAD
}
=======
>>>>>>> fd7d384c96bfb7788b25660aec49a42ff8618c59

/**
* @brief Função Pop:
*/

int pop(STACK *s, int *x){
    if (s->sp == 0) return 1;   
    *x = s->stack[s->sp];
    s->sp--;
    return 0; 
}