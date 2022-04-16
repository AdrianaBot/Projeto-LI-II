#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "dispatchtable.h"

int main() {
    DispatchFunc *table[127];
    STACK *s = newStack();
    setupTable(table);

    char line[BUFSIZ];
    char h[BUFSIZ];

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        while (sscanf(line, "%s%[^\n]", h, line) == 2) { 
            int val;
            if (sscanf(h, "%d", &val) == 1)
                push (s, val);
            else
                func(s, h[0], table);
        }
        func(s, h[0], table);

        for (int i = 1; i <= s->sp; i++)
            printf ("%d", s->stack[i]);
        putchar('\n'); 
    }
    return 0;
}