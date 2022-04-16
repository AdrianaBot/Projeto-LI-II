#include "parser.h"

/**
 * @brief Parser
 * 
 * A função,quando executada, identifica qual a operação que deverá ser aplicada. 
 * Caso não seja uma operação, simplesmente adiciona à stack.
 * 
 * @param s -> pointer da stack
 * @param c -> array de characteres
 */

void parser(STACK *s, DispatchFunc table) {
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
}

