#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "dispatchtable.h"
#include "parser.h"

int main() {
    DispatchFunc table[127];
    STACK *s = newStack();
    setupTable(table);

    parser(s, table);
    for (int i = 1; i <= s->sp; i++)
        printf ("%d", s->stack[i]);
    putchar('\n'); 
    return 0;
}