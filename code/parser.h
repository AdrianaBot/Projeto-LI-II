#ifndef EDUARDO
#define EDUARDO


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
 * @brief Parser
 * 
 * @param s 
 * @param table 
 */
void parser(STACK *s, DispatchFunc table[]);
