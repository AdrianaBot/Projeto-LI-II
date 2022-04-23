/**
 * @file dispatchtable.h
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís; Flávio Sousa (a100715@alunos.uminho.pt);
 * @brief Header file for DispatchTable
 * @version 0.1
 * @date 2022-04-14
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include "stack.h"

typedef void (*DispatchFunc) (STACK*);

typedef void (DispatchType) (STACK, ELEMENT, ELEMENT);

void setupTable(DispatchFunc table[]);

int func(STACK *x, char c, DispatchFunc table[]);