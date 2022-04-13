#ifndef STACK_H
#define STACK_H

#define MAX 100

// defenição da Stack.
typedef struct {
    int stack[MAX];
    int sp;
} STACK;

STACK *newStack();
void push(STACK *s, int elem);
int pop(STACK *s);


void soma(STACK *s);

void subtracao(STACK *s);

void multiplicacao(STACK *s);

void divisao(STACK *s);

void decrementacao(STACK *s);

void incrementacao(STACK *s);

void modulo(STACK *s);

void exponenciacao(STACK *s);

void eBitwise(STACK *s);

void ouBitwise(STACK *s);

void xorBitwise(STACK *s);

void notBitwise(STACK *s);

#endif