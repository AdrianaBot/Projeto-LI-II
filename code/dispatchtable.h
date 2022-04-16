/**
 * @file dispatchtable.h
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís
 * @brief Header file for DispatchTable
 * @version 0.1
 * @date 2022-04-14
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "stack.h"

typedef void (*DispatchFunc) (STACK*);

void setupTable(DispatchFunc table[]);

int func(STACK *x, unsigned char c, DispatchFunc table[]);
