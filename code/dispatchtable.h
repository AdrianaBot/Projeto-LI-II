/**
 * @file dispatchtable.h
 * @author documentas Eduardo pwease ʕ•ᴥ•ʔ obrigada de nada
 * @brief Header file for DispatchTable
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "stack.h"

typedef void (*DispatchFunc) (STACK*);

void setupTable();

int func(STACK *x, char c, DispatchFunc table[]);
