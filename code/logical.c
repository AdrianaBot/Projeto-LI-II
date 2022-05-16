#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

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

void xorBitwise (STACK* s) {
    ELEMENT x,y,final;
    x.type = LONG;
    y.type = LONG;
     
    pop(s,&x);
    pop(s,&y);
    final.info.typeLong = x.info.typeLong ^ y.info.typeLong;
    push(s,final);
}

void notBitwise (STACK* s) {
    ELEMENT x,final;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s, &x);

    if (x.type == LONG) {
        final.info.typeLong = ~ x.info.typeLong;
        push(s, final);
    }
    else if (x.type == ARRAY) {
        for (int i = 0; i < x.info.typeArray->sp; i++)
            push(s, x.info.typeArray->stack[i]);
    }
    else if (x.type == BLOCK) {
        char *a = strdup(x.info.typeString);

        DispatchFunc table[226] = {0}; 
        setupTable(table);

        ELEMENT variables[26] = {0};
        setupVar(variables);

        int f = 0;
        char *h = strtok(a, " ");

        while (h != NULL) {
            if (h[0] == '{' || h[0] == '}');
            else if (h[0] >= 'A' && h[0] <= 'Z' && h[1] == '\0') push(s, variables[h[0]-'A']);
            else if (h[0] == ':' && h[2] == '\0') assign(s,h[1], variables, f);
            else if (((h[0] < 48 || h[0] > 57) && h[1] == '\0') || (h[0] == 'e' && h[2] == '\0')) func(s, h, table, f);
            else readType (s, h); 

            h = strtok(NULL, " ");
        }
    }
    
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
    else if (x.type == LONG && y.type == STRING){
        ELEMENT a = {
            .type = CHAR,
            .info.typeChar = y.info.typeString[x.info.typeLong]
        };
        push(s,a);
    }
    else push(s,f); 
}

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

    else if (y.type == ARRAY && x.type == LONG)
        for (int i = 0;i < x.info.typeLong;i++){
         push(s,y.info.typeArray->stack[i]);    
        }
    else if (x.type == STRING && y.type == STRING && (strcmp(x.info.typeString, y.info.typeString) > 0)) push(s,v);
    else push(s,f); 
}

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

    else if (y.type == ARRAY && x.type == LONG)
        for (int i = x.info.typeLong;i < y.info.typeArray->sp;i++){
         push(s,y.info.typeArray->stack[i]);    
        }
    
    else if (x.type == STRING && y.type == STRING && (strcmp(x.info.typeString, y.info.typeString) < 0)) push(s,v);
    
    else push(s,f); 
}

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

void eShortcut (STACK *s) {
    ELEMENT x, y;

    pop(s,&x);
    pop(s,&y);

    if ((y.info.typeLong || y.info.typeDouble) == 0) {
        push(s,y);
    }
    else push(s,x);

}

void ouShortcut (STACK *s) {
    ELEMENT x,y;

    pop(s,&x);
    pop(s,&y);

    if ((y.info.typeLong || y.info.typeDouble) == 0) {
        push(s,x);
    }
    else push(s,y);
}

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
    else if (x.type == STRING && y.type == STRING) {
        
        if (strcmp(x.info.typeString, y.info.typeString) < 0)
            push(s,x);
        else 
            push(s,y);
    }
}

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
    else if (x.type == STRING && y.type == STRING) {
        
        if (strcmp(x.info.typeString, y.info.typeString) > 0)
            push(s,x);
        else 
            push(s,y);
    }
}

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

