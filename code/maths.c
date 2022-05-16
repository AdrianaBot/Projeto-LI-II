#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

void soma(STACK* s) {
    ELEMENT x, y;

    DispatchType funcType[6][6];
    setupSumArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[x.type][y.type](s,x,y);
}

void somaLongLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong + y.info.typeLong;
    push (s, final);
    }

void somaLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong + y.info.typeDouble;
    push (s, final); 
}

void somaLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong + y.info.typeChar;
    push (s,final);
}

void somaDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble + y.info.typeLong;
    push (s,final);
}

void somaDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble + y.info.typeDouble;
    push(s,final);
} 

void somaDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = x.info.typeDouble + y.info.typeChar;
    push(s, final);
}

void somaCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar + y.info.typeLong;
    push(s, final);
}

void somaCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar + y.info.typeDouble;
    push(s,final);
}

void somaCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar + y.info.typeChar;
    push(s,final);
}

void somaElemArray(STACK *s, ELEMENT x, ELEMENT y){
        
    y.info.typeArray->stack[y.info.typeArray->sp] = x;
    y.info.typeArray->sp++;

    push(s,y);
}

void somaArrayElem(STACK *s, ELEMENT x, ELEMENT y){
    newArray(s, 0);

    ELEMENT m;
    pop(s,&m);

    m.info.typeArray->stack[m.info.typeArray->sp] = y;
    m.info.typeArray->sp++;

    for (int i = 0; i < x.info.typeArray->sp; i++) {
        m.info.typeArray->stack[i+1] = x.info.typeArray->stack[i];
        m.info.typeArray->sp++;
    }
    push(s,m);
}

void somaArrayArray(STACK *s, ELEMENT x, ELEMENT y){
    int aux = y.info.typeArray->sp;
    for (int j = 0; j <  x.info.typeArray->sp; j++) {
        y.info.typeArray->stack[j + aux] = x.info.typeArray->stack[j];
        y.info.typeArray->sp++;
    }
    push(s,y);
}

void somaElemString(STACK *s, ELEMENT x, ELEMENT y){
    char a[BUFSIZ];
    ELEMENT converter;
    converter.type = STRING;
    converter.info.typeString = a;

    if (x.type == LONG)
        sprintf(converter.info.typeString,"%ld",x.info.typeLong);

    else if (x.type == DOUBLE)
        sprintf(converter.info.typeString,"%lf",x.info.typeDouble);

    else if (x.type == CHAR)
        sprintf(converter.info.typeString,"%c",x.info.typeChar);

    strcat(y.info.typeString, converter.info.typeString);
    push(s,y);
}

void somaStringElem(STACK *s, ELEMENT x, ELEMENT y){
    char a[BUFSIZ];
    ELEMENT converter;
    converter.type = STRING;
    converter.info.typeString = a;

    if (y.type == LONG)
        sprintf(converter.info.typeString,"%ld",y.info.typeLong);

    else if (y.type == DOUBLE)
        sprintf(converter.info.typeString,"%lf",y.info.typeDouble);

    else if (y.type == CHAR)
        sprintf(converter.info.typeString,"%c",y.info.typeChar);

    strcat(converter.info.typeString, x.info.typeString);
    push(s,converter);
}

void somaStringString(STACK *s, ELEMENT x, ELEMENT y){
    strcat(y.info.typeString, x.info.typeString);
    push(s,y);
}

void subtracao(STACK *s){
    ELEMENT x, y;

    DispatchType funcType[4][4];
    setupSubArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[y.type][x.type] (s,y,x);
}

void subtracaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong - y.info.typeLong;
    push (s, final);
    }

void subtracaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong - y.info.typeDouble;
    push (s, final); 
}

void subtracaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong - y.info.typeChar;
    push (s,final);
}

void subtracaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble - y.info.typeLong;
    push (s,final);
}

void subtracaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble - y.info.typeDouble;
    push(s,final);
} 

void subtracaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = x.info.typeDouble - y.info.typeChar;
    push(s,final);
}

void subtracaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar - y.info.typeLong;
    push(s,final);
}

void subtracaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar - y.info.typeDouble;
    push(s,final);
}

void subtracaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar - y.info.typeChar;
    push(s,final);
}

void multiplicacao(STACK *s){
    ELEMENT x, y;

    DispatchType funcType[6][6];
    setupMulArray(funcType);


    pop(s,&x); 
    pop(s,&y);
    funcType[x.type][y.type] (s,x,y);
}

void multiplicacaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong * y.info.typeLong;
    push (s, final);
    }

void multiplicacaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong * y.info.typeDouble;
    push (s, final); 
}

void multiplicacaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong * y.info.typeChar;
    push (s,final);
}

void multiplicacaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble * y.info.typeLong;
    push (s,final);
}

void multiplicacaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble * y.info.typeDouble;
    push(s,final);
} 

void multiplicacaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;            
    final.info.typeDouble = x.info.typeDouble * y.info.typeChar;
    push(s, final);
}

void multiplicacaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar * y.info.typeLong;
    push(s, final);
}

void multiplicacaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar * y.info.typeDouble;
    push(s, final);
}

void multiplicacaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar * y.info.typeChar;
    push(s,final);
}


void multiplicacaoBlockArray(STACK *s, ELEMENT x, ELEMENT y){
    while (y.info.typeArray->sp >= 2) {
        push(y.info.typeArray, x);
        notBitwise(y.info.typeArray);
    }
    push(s, y);
}

/*
void multiplicacaoLongArray(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT x;
    pop(s, &x);
}
*/

void divisao(STACK *s){
    ELEMENT x, y;

    DispatchType funcType[4][4];
    setupDivArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[y.type][x.type] (s,y,x);
}

void divisaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong / y.info.typeLong;
    push (s, final);
    }

void divisaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong / y.info.typeDouble;
    push (s, final); 
}

void divisaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong / y.info.typeChar;
    push (s,final);
}

void divisaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble / y.info.typeLong;
    push (s,final);
}

void divisaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble / y.info.typeDouble;
    push(s,final);
} 

void divisaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;           
    final.info.typeDouble = x.info.typeDouble / y.info.typeChar;
    push(s,final);
}

void divisaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar / y.info.typeLong;
    push(s,final);
}

void divisaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar / y.info.typeDouble;
    push(s,final);
}

void divisaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar / y.info.typeChar;
    push(s,final);
}

void exponenciacao(STACK* s) {
    ELEMENT x, y;

    DispatchType funcType[4][4];
    setupExpArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[y.type][x.type](s,y,x);
}

void expLongLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = pow (x.info.typeLong , y.info.typeLong);
    push (s, final);
    }

void expLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeLong , y.info.typeDouble);
    push (s, final); 
}

void expLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = pow (x.info.typeLong , y.info.typeChar);
    push (s,final);
}

void expDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeDouble , y.info.typeLong);
    push (s,final);
}

void expDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeDouble , y.info.typeDouble);
    push(s,final);
} 

void expDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = pow (x.info.typeDouble , y.info.typeChar);
    push(s, final);  
}

void expCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = pow (x.info.typeChar , y.info.typeLong);
    push(s, final);
}

void expCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeChar , y.info.typeDouble);
    push(s,final);
}

void expCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = pow (x.info.typeChar , y.info.typeChar);
    push(s,final);
}