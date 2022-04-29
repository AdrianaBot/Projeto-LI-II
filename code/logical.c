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
    final.info.typeLong = ~ x.info.typeLong;
    push(s, final);
}


void igual (STACK *s) {
    ELEMENT x, y;
    ELEMENT f, v, v1;
    f.info.typeLong = 0;
    v.info.typeLong = 1;
    v1.info.typeDouble = 1.0;


    pop(s,&x);
    pop(s,&y);

    if(x.type == CHAR && y.type == CHAR && x.info.typeChar == y.info.typeChar) push(s,v);
    
    else if(x.type == DOUBLE && y.type == DOUBLE && x.info.typeDouble == y.info.typeDouble) push(s,v1); 
    else if (x.type == DOUBLE && y.type == LONG && x.info.typeDouble == y.info.typeLong) push (s,v);
    else if (x.type == LONG && y.type == DOUBLE && x.info.typeLong == y.info.typeDouble) push(s,v);
    else if(x.type == LONG &&   y.type == LONG && x.info.typeLong == y.info.typeLong) push(s,v);
    else if(x.type == STRING && y.type == STRING && x.info.typeString == y.info.typeString) push(s,v);  
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
    ELEMENT f, v, v1;
    f.info.typeLong = 0;
    v.info.typeLong = 1;
    v1.info.typeDouble = 1.0;

    pop(s,&x);
    pop(s,&y);

    
    if(x.type == DOUBLE && y.type == DOUBLE && x.info.typeDouble > y.info.typeDouble) push(s,v1); 
    else if (x.type == LONG && y.type == DOUBLE && x.info.typeLong > y.info.typeDouble) push(s,v);
    else if (x.type == DOUBLE && y.type == LONG && x.info.typeDouble > y.info.typeLong) push(s,v);
    else if(x.type == LONG && y.type == LONG && x.info.typeLong > y.info.typeLong) push(s,v);
    else if(x.type == CHAR && y.type == CHAR && x.info.typeChar > y.info.typeChar) push(s,v);
    
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
    ELEMENT f, v, v1;
    f.info.typeLong = 0;
    v.info.typeLong = 1;
    v1.info.typeDouble = 1.0;

    pop(s,&x);
    pop(s,&y);

    
    if(x.type == DOUBLE && y.type == DOUBLE && x.info.typeDouble < y.info.typeDouble) push(s,v1); 
    else if (x.type == LONG && y.type == DOUBLE && x.info.typeLong < y.info.typeDouble) push(s,v);
    else if (x.type == DOUBLE && y.type == LONG && x.info.typeDouble < y.info.typeLong) push(s,v);
    else if(x.type == LONG && y.type == LONG && x.info.typeLong < y.info.typeLong) push(s,v);
    else if(x.type == CHAR && y.type == CHAR && x.info.typeChar < y.info.typeChar) push(s,v);
    
    else push(s,f); 
}

/**
 * @brief Função de negação lógica (!): devolve o valor booleano oposto à declaração inicial
 * 
 * @param s 
 */
void nao (STACK *s) {
    ELEMENT x, f, v;
    f.info.typeLong = 0;
    v.info.typeLong = 1;

    pop(s, &x);


    if ((x.info.typeLong || x.info.typeDouble) == 0) {
        push(s,v);
    }
    else push(s,f);
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
    ELEMENT x,y,final;

    pop(s,&x);
    pop(s,&y);

    if (x.type == LONG && y.type == LONG) {
    
        if (x.info.typeLong < y.info.typeLong) final.info.typeLong = x.info.typeLong;
        
        else final.info.typeLong = y.info.typeLong;  
        
        push(s,final);
    }
    else if (x.type == DOUBLE && y.type == DOUBLE) {
        
        if (x.info.typeDouble < y.info.typeDouble) final.info.typeDouble = x.info.typeDouble;
            
        else final.info.typeDouble = y.info.typeDouble; 
        
        push(s,final);
    }
    else if (x.type == LONG && y.type == DOUBLE) {
       
        if (x.info.typeLong < y.info.typeLong) final.info.typeDouble = x.info.typeDouble;
        
        else final.info.typeDouble = y.info.typeDouble;  
        push(s,final);
    }
    else if (x.type == DOUBLE && y.type == LONG) {
            
        if (x.info.typeDouble < y.info.typeLong) final.info.typeDouble = x.info.typeDouble;
            
        else final.info.typeLong = y.info.typeLong;
  
        push(s,final);
    }
}



/**
 * @brief Função que coloca o maior de dois valores na stack (e>).
 * 
 * @param s 
 */

void maiorDoisValores (STACK *s) {
    ELEMENT x,y,final;

    pop(s,&x);
    pop(s,&y);

    if (x.type == LONG && y.type == LONG) {
    
        if (x.info.typeLong > y.info.typeLong) final.info.typeLong = x.info.typeLong;
        
        else final.info.typeLong = y.info.typeLong;
    
    push(s,final);
    }
    else if (x.type == DOUBLE && y.type == DOUBLE) {
        
        if (x.info.typeDouble>y.info.typeDouble) final.info.typeDouble = x.info.typeDouble;

        else final.info.typeDouble = y.info.typeDouble;
        
        push(s,final);
    }
    else if (x.type == LONG && y.type == DOUBLE) {
       
        if (x.info.typeLong > y.info.typeDouble) final.info.typeDouble = x.info.typeDouble;
        
        else final.info.typeDouble = y.info.typeDouble;
        
        push(s,final);
    }
    else if (x.type == DOUBLE && y.type == LONG) {
            
        if (x.info.typeDouble > y.info.typeLong) final.info.typeDouble = x.info.typeDouble;
            
        else final.info.typeLong = y.info.typeLong; 
        
        push(s,final);
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

    if ((z.info.typeLong || z.info.typeDouble) == 0) {
        push(s,x);
    }
    else push(s,y);
}