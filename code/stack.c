#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"


// STACK

STACK *newStack (){
    return calloc(sizeof(STACK),1);
}

int push (STACK *s, ELEMENT elem){
    if (s->sp == BUFSIZ) abort();
    s->stack[s->sp] = elem;
    s->sp++;
    return 0;
}

int pop(STACK *s, ELEMENT *x){
    if (s->sp == 0) return 1;    
    s->sp--;   
    *x = s->stack[s->sp];
    return 0;
}

void readType (STACK* s, char *h) {
    if (h[0] >= 'a' && h[0] <= 'z' && h[1] == '\0') {
        ELEMENT a = {
            .type = CHAR, 
            .info.typeChar = h[0],
        };
        push(s,a);
        return;
    }
    char* endptr;
    long num = strtol(h,&endptr,10);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = LONG, 
            .info.typeLong = num,
        };
        push(s,a);
        return;
    }
    double b = strtod(h,&endptr);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = DOUBLE, 
            .info.typeDouble = b,
        };
        push(s,a);
        return;
    }
}

void newArray (STACK* s, int f){

    for (int i = 1; i < f; i++) 
        s = s->stack[s->sp-1].info.typeArray;

    ELEMENT a = {
        .type = ARRAY,
        .info.typeArray = newStack()
    };
    push(s,a);
}

void size(STACK* s){ 
    ELEMENT m;
    m.type = LONG;
    m.info.typeArray = NULL;
    pop(s,&m);

    if (m.type == ARRAY){
        ELEMENT x = {
            .type = LONG,
            .info.typeLong = m.info.typeArray->sp
        };
        push(s,x); 
    }  
    else if (m.type == STRING){
        ELEMENT x = {
            .type = LONG,
            .info.typeLong = strlen(m.info.typeString)
        };
        push(s,x); 
    }   
    else if (m.type == LONG){
        ELEMENT x = {
            .type = ARRAY,
            .info.typeArray = newStack()
        };  
        for (int i = 0; i < m.info.typeLong ;i++){
            ELEMENT a = {
                .type = LONG, 
                .info.typeLong = i,
            };
            x.info.typeArray->stack[x.info.typeArray->sp] = a;
            x.info.typeArray->sp++;
        } 
        push(s,x);    
    }
}

void addToArray(STACK* s, char h[], int f) {

    for (int i = 1; i < f; i++) 
        s = s->stack[s->sp-1].info.typeArray;

    ELEMENT m;
    pop(s,&m);

    if (h[0] >= 'a' && h[0] <= 'z' && h[1] == '\0') {
        ELEMENT a = {
            .type = CHAR, 
            .info.typeChar = h[0],
        };
        m.info.typeArray->stack[m.info.typeArray->sp] = a;
        m.info.typeArray->sp++;
        push(s,m);
        return;
    }
    char* endptr;
    long num = strtol(h,&endptr,10);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = LONG, 
            .info.typeLong = num,
        };
        m.info.typeArray->stack[m.info.typeArray->sp] = a;
        m.info.typeArray->sp++;
        push(s,m);
        return;
    }
    double b = strtod(h,&endptr);
    if (*endptr == '\0') {
        ELEMENT a = {
            .type = DOUBLE, 
            .info.typeDouble = b,
        };
        m.info.typeArray->stack[m.info.typeArray->sp] = a;
        m.info.typeArray->sp++;
        push(s,m);
        return;
    }
}

void printArray(STACK* s, int n) {
    ELEMENT a = s->stack[n];

    for (int i = 0; i < a.info.typeArray->sp; i++) {
        ELEMENT x = a.info.typeArray->stack[i];
        if (x.type == LONG) printf ("%ld", x.info.typeLong);
        else if (x.type == DOUBLE) printf ("%g", x.info.typeDouble);
        else if (x.type == CHAR) printf ("%c", x.info.typeChar);
        else if (x.type == STRING) printf ("%s", x.info.typeString);
        else if (x.type == BLOCK) printf ("%s", x.info.typeString);
        else if (x.type == ARRAY) printArray(a.info.typeArray,i);
    }
}

void newString(STACK *s, char h[], int f) {
    for (int i = 1; i < f; i++) 
        s = s->stack[s->sp-1].info.typeArray;

    //h[strlen(h)-1] = '\0';
    char *a = strdup(h);
    ELEMENT x = {
        .type = STRING, 
        .info.typeString = ++a
    };
    if (f != 0) {
        ELEMENT m;
        pop(s,&m);

        m.info.typeArray->stack[m.info.typeArray->sp] = x;
        m.info.typeArray->sp++;
        push(s,m);
    }
    else push(s,x);
}

void newBlock(STACK *s, char h[], int f) {
    for (int i = 1; i < f; i++) 
        s = s->stack[s->sp-1].info.typeArray;

    char *a = strdup(h);
    ELEMENT x = {
        .type = BLOCK, 
        .info.typeString = a
    };
    if (f != 0) {
        ELEMENT m;
        pop(s,&m);

        m.info.typeArray->stack[m.info.typeArray->sp] = x;
        m.info.typeArray->sp++;
        push(s,m);
    }
    else push(s,x);
}

void decrementacao (STACK* s) {
    ELEMENT x,final;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);

    if (x.type == LONG) {
        final.type = LONG;
        final.info.typeLong = x.info.typeLong - 1;
    }
    else if (x.type == CHAR) {
        final.type = CHAR;
        final.info.typeChar = x.info.typeChar - 1;
    }
    else if (x.type == ARRAY){

        final = x.info.typeArray->stack[0];
        for (int i = 0; i < x.info.typeArray->sp;i++){
            x.info.typeArray->stack[i] = x.info.typeArray->stack [i + 1];
        }
        x.info.typeArray->sp--;
        push(s,x);
    }
    else if (x.type == STRING){
        final.type = CHAR;
        final.info.typeChar = x.info.typeString[0];

        x.info.typeString++;
        push(s,x);
    }
    push (s,final);
}

void incrementacao (STACK* s) {
    ELEMENT x,final;
    x.type = LONG;
    x.info.typeLong = 0;                              
    pop(s,&x);
    if (x.type == LONG) {
        final.type = LONG;
        final.info.typeLong = x.info.typeLong + 1;
    }
    else if (x.type == CHAR) {
        final.type = CHAR;
        final.info.typeChar = x.info.typeChar + 1;
    }
    else if (x.type == ARRAY){
        final = x.info.typeArray->stack[x.info.typeArray->sp - 1];
        x.info.typeArray->sp--;
        push (s,x);
    }
    else if (x.type == STRING){
        final.type = CHAR;
        final.info.typeChar = x.info.typeString[strlen(x.info.typeString)-1];

        x.info.typeString[strlen(x.info.typeString)-1] = '\0';
        push (s,x);
    }
    push(s,final);
}

void modulo (STACK* s) {
    ELEMENT x, y,final; 
    x.type = LONG;
    x.info.typeLong = 0;
    y.type = LONG;
    y.info.typeLong = 0;
    pop(s,&x);
    pop(s,&y); 
    if (x.type == LONG){
        final.info.typeLong = y.info.typeLong % x.info.typeLong;    
        push(s,final);
    }
    else if (x.type == BLOCK && y.type == STRING) {
        int i;
        char aux[BUFSIZ];
        ELEMENT ch;
        ch.info.typeChar = 0;

        for(i = 0; i < (int)strlen(y.info.typeString)-1; i++) {
            ELEMENT c = {
                .type = CHAR,
                .info.typeChar = y.info.typeString[i]
            };
            push(s,c);
            push(s,x);
            notBitwise(s);
            
            pop(s, &ch);
            aux[i] = ch.info.typeChar;

        }
        aux[i] = '\0';

        ELEMENT st = {
            .type = STRING,
            .info.typeString = strdup(aux)
        };
        push(s,st);
    }
    else if (x.type == BLOCK && y.type == ARRAY) {
        int i;
        //ELEMENT ch;
        //ch.info.typeChar = 0;

        for(i = 0; i < y.info.typeArray->sp; i++) {
            push(s,y.info.typeArray->stack[i]);
            push(s,x);
            notBitwise(s);
            
            //pop(s, &ch);
            //y.info.typeArray->stack[i] = ch;
        }
        //push(s, y);
    }
}

void duplicacao (STACK* s){
    ELEMENT x;
    x.info.typeLong = 0;
    pop(s, &x);
    push(s, x);                     
    push(s, x);
}

void troca (STACK* s) {
    ELEMENT x,y;
    x.info.typeLong = 0;
    y.info.typeLong = 0;
    pop(s, &x);
    pop(s, &y);
    push(s, x);
    push(s, y);
}

void roda (STACK* s) {
    ELEMENT x,y,z;
    x.info.typeLong = 0;
    y.info.typeLong = 0;
    z.info.typeLong = 0;
    pop(s, &x);
    pop(s, &y);
    pop(s, &z);
    push(s, y);
    push(s, x);
    push(s, z);
}

void nesimo(STACK *s, ELEMENT* x, long n){                                      
    *x = s->stack[s->sp - n - 1];   
}


void copia (STACK* s) {
    ELEMENT n;
    n.info.typeLong = 0;                                              
    pop(s, &n);
    ELEMENT x;
    x.type = LONG;
    x.info.typeLong = 0;              
    nesimo(s, &x, n.info.typeLong);           
    push(s, x);  
}



void pop2(STACK *s) {
    ELEMENT x;
    x.info.typeLong = 0;
    pop(s, &x);
}   

void assign(STACK *s,char c,ELEMENT var[], int f){
    for (int i = 1; i <= f; i++) 
        s = s->stack[s->sp-1].info.typeArray;

    ELEMENT x;
    x.info.typeLong = 0;
    pop(s,&x);
    var[c-'A'] = x;
    push(s,x);
}


void readline(STACK *s) {
    char line[BUFSIZ];

    if (fgets (line, BUFSIZ, stdin) != NULL) {
        ELEMENT a;
        a.type = STRING;
        a.info.typeString = line;
        //strcpy (a.info.typeString, line);
        push(s,a);
    }
}

void funcT(STACK *s) {
    char line[BUFSIZ];
    char aux[BUFSIZ];
    while (fgets (line, BUFSIZ, stdin) != NULL) {
            strcat(aux,line);
    }
    ELEMENT a;
    a.type = STRING;
    a.info.typeString = strdup(aux);
    push(s,a);
}

void psdebugger (STACK *s) {
     for (int i = 0; i < s->sp; i++) {
        ELEMENT x = s->stack[i];

        if (x.type == LONG) printf ("l: %ld ", x.info.typeLong);
        else if (x.type == DOUBLE) printf ("f: %lf ", x.info.typeDouble);
        else if (x.type == CHAR) printf ("c: %c ", x.info.typeChar);
        else if (x.type == STRING) printf ("s: '%s' ", x.info.typeString); 
        else if (x.type == BLOCK) printf ("b: '%s' ", x.info.typeString); 
        else if (x.type == ARRAY) {printf ("a: "); printArray(s,i); putchar(' ');} 
    }
    putchar('\n'); 
}