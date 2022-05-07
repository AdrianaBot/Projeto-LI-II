#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"


/**
 * @brief Definição da operação de "e" (bitwise) para inteiros (&).
 * 
 * @param s -> pointer da STACK 
 */
void eBitwise (STACK* s) {
    ELEMENT x,y,final;
    x.type = LONG;
    x.info.typeLong = 0;
    y.type = LONG;
    y.info.typeLong = 0;
    pop(s,&x);
    pop(s,&y);
    final.info.typeLong = x.info.typeLong & y.info.typeLong;
    push(s,final);
}

/**
 * @brief Definição da operação de "ou" (bitwise) para inteiros (|).
 * 
 * @param s -> pointer da STACK 
 */
void ouBitwise (STACK* s) {
    ELEMENT x,y,final;
    x.type = LONG;
    x.info.typeLong = 0;
    y.type = LONG;
    y.info.typeLong = 0;
    pop(s,&x);
    pop(s,&y); 
    final.info.typeLong = x.info.typeLong | y.info.typeLong;
    push(s, final);
}

/**
 * @brief Definição da operação de "xor" (bitwise) para inteiros (^).
 * O xor é o ou exclusivo.
 * 
 * @param s -> pointer da STACK 
 */
void xorBitwise (STACK* s) {
    ELEMENT x,y,final;
    x.type = LONG;
    y.type = LONG;
     
    pop(s,&x);
    pop(s,&y);
    final.info.typeLong = x.info.typeLong ^ x.info.typeLong;
    push(s,final);
}

/**
 * @brief Definição da operação de "not" (bitwise) para inteiros (~).
 * 
 * @param s -> pointer da STACK 
 */
void notBitwise (STACK* s) {
    ELEMENT x,final;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s, &x);

    if (x.type == ARRAY) {
        push(s,x);
    } 
    final.info.typeLong = ~ x.info.typeLong;
    push(s, final);
}


void igual (STACK *s) {
    ELEMENT x, y;
    ELEMENT v = {
        .type = LONG, 
        .info.typeLong = 1,
    };
    ELEMENT f = {
        .type = LONG, 
        .info.typeLong = 0,
    };
    
    pop(s,&x);
    pop(s,&y);

    if (x.type == LONG && y.type == LONG && x.info.typeLong == y.info.typeLong) push(s,v);
    else if (x.type == LONG && y.type == DOUBLE && (double) x.info.typeLong == y.info.typeDouble) push(s,v);
    else if (x.type == LONG && y.type == CHAR && x.info.typeLong == (long) y.info.typeChar) push(s,v);

    else if (x.type == DOUBLE && y.type == LONG && x.info.typeDouble == (double) y.info.typeLong) push(s,v);
    else if (x.type == DOUBLE && y.type == DOUBLE && x.info.typeDouble == y.info.typeDouble) push(s,v);
    else if (x.type == DOUBLE && y.type == CHAR && x.info.typeDouble == (double) y.info.typeChar) push(s,v);

    else if (x.type == CHAR && y.type == LONG && (long) x.info.typeChar == y.info.typeLong) push(s,v);
    else if (x.type == CHAR && y.type == DOUBLE && (double) x.info.typeChar == y.info.typeDouble) push(s,v);
    else if (x.type == CHAR && y.type == CHAR && x.info.typeChar == y.info.typeChar) push(s,v);

    else if (x.type == STRING && y.type == STRING && (strcmp(x.info.typeString, y.info.typeString) == 0)) push(s,v);
    
    else if (x.type == LONG && y.type == ARRAY){
        push(s,y.info.typeArray->stack[x.info.typeLong]);
    }
    else push(s,f); 
}

/**
 * @brief Função menor
 * 
 * Compara 2 elementos e devolve 1 caso o primeiro seja menor do que o segundo.
 * 
 * @param s 
 */
void menor (STACK *s) {
    ELEMENT x, y;
    ELEMENT v = {
        .type = LONG, 
        .info.typeLong = 1,
    };
    ELEMENT f = {
        .type = LONG, 
        .info.typeLong = 0,
    };
    
    pop(s,&x);
    pop(s,&y);

    if (x.type == LONG && y.type == LONG && x.info.typeLong > y.info.typeLong) push(s,v);
    else if (x.type == LONG && y.type == DOUBLE && x.info.typeLong > y.info.typeDouble) push(s,v);
    else if (x.type == LONG && y.type == CHAR && x.info.typeLong > y.info.typeChar) push(s,v);

    else if (x.type == DOUBLE && y.type == LONG && x.info.typeDouble > y.info.typeLong) push(s,v);
    else if (x.type == DOUBLE && y.type == DOUBLE && x.info.typeDouble > y.info.typeDouble) push(s,v);
    else if (x.type == DOUBLE && y.type == CHAR && x.info.typeDouble > y.info.typeChar) push(s,v);

    else if (x.type == CHAR && y.type == LONG && x.info.typeChar > y.info.typeLong) push(s,v);
    else if (x.type == CHAR && y.type == DOUBLE && x.info.typeChar > y.info.typeDouble) push(s,v);
    else if (x.type == CHAR && y.type == CHAR && x.info.typeChar > y.info.typeChar) push(s,v);

    else if (y.type == ARRAY && x.type == LONG){
        for (int i = 0;i < x.info.typeLong;i++){
         push(s,y.info.typeArray->stack[i]);    
        }
    }
    else push(s,f); 
}

/**
 * @brief Função maior
 * 
 * Compara 2 elementos e devolve 1 caso o primeiro seja maior do que o segundo.
 * 
 * @param s 
 */
void maior (STACK *s) {
    ELEMENT x, y;
    ELEMENT v = {
        .type = LONG, 
        .info.typeLong = 1,
    };
    ELEMENT f = {
        .type = LONG, 
        .info.typeLong = 0,
    };
    
    pop(s,&x);
    pop(s,&y);

    if (x.type == LONG && y.type == LONG && x.info.typeLong < y.info.typeLong) push(s,v);
    else if (x.type == LONG && y.type == DOUBLE && x.info.typeLong < y.info.typeDouble) push(s,v);
    else if (x.type == LONG && y.type == CHAR && x.info.typeLong < y.info.typeChar) push(s,v);

    else if (x.type == DOUBLE && y.type == LONG && x.info.typeDouble < y.info.typeLong) push(s,v);
    else if (x.type == DOUBLE && y.type == DOUBLE && x.info.typeDouble < y.info.typeDouble) push(s,v);
    else if (x.type == DOUBLE && y.type == CHAR && x.info.typeDouble < y.info.typeChar) push(s,v);

    else if (x.type == CHAR && y.type == LONG && x.info.typeChar < y.info.typeLong) push(s,v);
    else if (x.type == CHAR && y.type == DOUBLE && x.info.typeChar < y.info.typeDouble) push(s,v);
    else if (x.type == CHAR && y.type == CHAR && x.info.typeChar < y.info.typeChar) push(s,v);

    else if (y.type == ARRAY && x.type == LONG){
        for (int i = x.info.typeLong;i < y.info.typeArray->sp;i++){
         push(s,y.info.typeArray->stack[i]);    
        }
    }
    
    else push(s,f); 
}

/**
 * @brief Função de negação lógica (!): devolve o valor booleano oposto à declaração inicial
 * 
 * @param s 
 */
void nao (STACK *s) {
    ELEMENT x;
    ELEMENT v = {
        .type = LONG, 
        .info.typeLong = 1,
    };
    ELEMENT f = {
        .type = LONG, 
        .info.typeLong = 0,
    };

    pop(s, &x);

    if (x.type == LONG && x.info.typeLong)
        push(s,f);
    else if (x.type == DOUBLE && x.info.typeDouble)
        push(s,f);
    else if (x.type == CHAR && x.info.typeChar)
        push(s,f);
    else 
        push(s,v);
}
/**
 * @brief Função de conjunção lógica com shortcut (e&): caso o primeiro elemento seja falso (0), já não verifica o segundo e dá, portanto, o primeiro. Caso contrário, dá o segundo.
 * @param s 
 */
void eShortcut (STACK *s) {
    ELEMENT x, y;

    pop(s,&x);
    pop(s,&y);

    if ((y.info.typeLong || y.info.typeDouble) == 0) {
        push(s,y);
    }
    else push(s,x);

}

/**
 * @brief Função de disjunção lógica com shortcut (e|): caso o primeiro seja verdadeiro (diferente de 0), já não verifica o segundo e dá, portanto, o primeiro. Caso contrário, dá o segundo.
 * 
 * @param s 
 */
void ouShortcut (STACK *s) {
    ELEMENT x,y;

    pop(s,&x);
    pop(s,&y);

    if ((y.info.typeLong || y.info.typeDouble) == 0) {
        push(s,x);
    }
    else push(s,y);
}

/**
 * @brief Função que coloca o menor de dois valores na stack (e<).
 * 
 * @param s 
 */

void menorDoisValores (STACK *s) {
    ELEMENT x,y;

    pop(s,&x);
    pop(s,&y);

    if (x.type == LONG && y.type == LONG) {
    
        if (x.info.typeLong < y.info.typeLong)
            push(s,x);
        else 
            push(s,y);
    }
    else if (x.type == DOUBLE && y.type == DOUBLE) {
        
        if (x.info.typeDouble < y.info.typeDouble)
            push(s,x);
        else 
            push(s,y);
    }
    else if (x.type == LONG && y.type == DOUBLE) {
       
        if (x.info.typeLong < y.info.typeDouble)
            push(s,x);
        else 
            push(s,y);
    }
    else if (x.type == DOUBLE && y.type == LONG) {
            
        if (x.info.typeDouble < y.info.typeLong) 
            push(s,x);
        else 
            push(s,y);
    }
}



/**
 * @brief Função que coloca o maior de dois valores na stack (e>).
 * 
 * @param s 
 */

void maiorDoisValores (STACK *s) {
    ELEMENT x,y;

    pop(s,&x);
    pop(s,&y);

    if (x.type == LONG && y.type == LONG) {
    
        if (x.info.typeLong > y.info.typeLong)
            push(s,x);
        else 
            push(s,y);
    }
    else if (x.type == DOUBLE && y.type == DOUBLE) {
        
        if (x.info.typeDouble > y.info.typeDouble)
            push(s,x);
        else 
            push(s,y);
    }
    else if (x.type == LONG && y.type == DOUBLE) {
       
        if (x.info.typeLong > y.info.typeDouble)
            push(s,x);
        else 
            push(s,y);
    }
    else if (x.type == DOUBLE && y.type == LONG) {
            
        if (x.info.typeDouble > y.info.typeLong) 
            push(s,x);
        else 
            push(s,y);
    }
}



/**
 * @brief Função if-then-else (se-então-de_outra_forma) (?) que, caso o primeiro elemento seja verdade (if), devolve o segundo (then). Caso contrário, dá o terceiro (else).
 * 
 * @param s 
 */
void ifThenElse (STACK *s) {
    ELEMENT x,y,z;

    pop(s,&x);
    pop(s,&y);
    pop(s,&z);
    if (z.type == LONG) {
        if (z.info.typeLong)
            push(s,y);
        else 
            push(s,x);
    }
    else if (z.type == DOUBLE) {
        if (z.info.typeDouble)
            push(s,y);
        else 
            push(s,x);
    }
}

//ll