#ifndef PARSER_H
#define PARSER_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"



void parser(STACK *s, DispatchFunc table[]);

#endif