/**
 * @file parser.h
 * @author Adriana Frazão (https://github.com/AdrianaBot); Eduardo José Gonçalves dos Reis (a100819@alunos.uminho.pt); José Luís; Flávio Sousa (a100715@alunos.uminho.pt);
 * @brief Header file for perser
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "dispatchtable.h"

void parser(STACK *s, DispatchFunc table[]);