#define MAX 1000


// defenição da Stack.
typedef struct {
    int stack[MAX];
    int sp;
} STACK;

STACK *new_stack();
void push(STACK *s, int elem);
int pop(STACK *s);
