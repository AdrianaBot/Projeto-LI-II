#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"


/**
 * @brief Definição da operação de soma (+).
 *  
 * @param s -> pointer da STACK 
 */
void soma(STACK* s) {
    ELEMENT x, y;

    DispatchType funcType[6][6];
    setupSumArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[x.type][y.type](s,x,y);
}

/**
 * @brief Definição da operação de soma (+) para Long.
 * 
 * @param s -> pointer da STACK 
 */
void somaLongLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong + y.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de soma (+) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void somaLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong + y.info.typeDouble;
    push (s, final); 
}

/**
 * @brief Definição da operação de soma (+) entre Lonbg e Char.
 * 
 * @param s -> pointer da STACK 
 */
void somaLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong + y.info.typeChar;
    push (s,final);
}

/**
 * @brief Definição da operação de soma (+) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void somaDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble + y.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de soma (+) entre Doubles.
 * 
 * @param s -> pointer da STACK 
 */
void somaDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble + y.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de soma (+) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void somaDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = x.info.typeDouble + y.info.typeChar;
    push(s, final);
}

/**
 * @brief Definição da operação de soma (+) entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void somaCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar + y.info.typeLong;
    push(s, final);
}

/**
 * @brief Definição da operação de soma (+) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void somaCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar + y.info.typeDouble;
    push(s,final);
}

/**
 * @brief Definição da operação de soma (+) Entre Char.
 * 
 * @param s -> pointer da STACK 
 */
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

/**
 * @brief Definição da operação de subtração (-).
 * 
 * @param s -> pointer da STACK 
 */
void subtracao(STACK *s){
    ELEMENT x, y;

    DispatchType funcType[4][4];
    setupSubArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[y.type][x.type] (s,y,x);
}

/**
 * @brief Definição da operação de subtração (-) entre Long.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong - y.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de subtração (-) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong - y.info.typeDouble;
    push (s, final); 
}

/**
 * @brief Definição da operação de subtração (-) entre Long e Char.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong - y.info.typeChar;
    push (s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble - y.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Double.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble - y.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de subtração (-) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = x.info.typeDouble - y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de subtração (-) Entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar - y.info.typeLong;
    push(s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar - y.info.typeDouble;
    push(s,final);
}

/**
 * @brief Definição da operação de subtração (-) entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void subtracaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar - y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de multiplicação(*).
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacao(STACK *s){
    ELEMENT x, y;

    DispatchType funcType[6][6];
    setupMulArray(funcType);


    pop(s,&x); 
    pop(s,&y);
    funcType[x.type][y.type] (s,x,y);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Long.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong * y.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de multiplicação(*) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong * y.info.typeDouble;
    push (s, final); 
}

/**
 * @brief Definição da operação de multiplicação(*) entre Long e Char.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong * y.info.typeChar;
    push (s,final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble * y.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Double.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble * y.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de multiplicação(*) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;            
    final.info.typeDouble = x.info.typeDouble * y.info.typeChar;
    push(s, final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar * y.info.typeLong;
    push(s, final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar * y.info.typeDouble;
    push(s, final);
}

/**
 * @brief Definição da operação de multiplicação(*) entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void multiplicacaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar * y.info.typeChar;
    push(s,final);
}
/*
void multiplicacaoLongArray(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT x;
    pop(s, &x);

}
*/
/**
 * @brief Definição da operação de divisão(/).
 * 
 * @param s -> pointer da STACK 
 */
void divisao(STACK *s){
    ELEMENT x, y;

    DispatchType funcType[4][4];
    setupDivArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[y.type][x.type] (s,y,x);
}

/**
 * @brief Definição da operação de divisão(/) entre Long.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoLongLong(STACK *s, ELEMENT x, ELEMENT y) {
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong / y.info.typeLong;
    push (s, final);
    }

/**
 * @brief Definição da operação de divisão(/) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeLong / y.info.typeDouble;
    push (s, final); 
}

/**
 * @brief Definição da operação de divisão(/) entre Long e Char.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeLong / y.info.typeChar;
    push (s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble / y.info.typeLong;
    push (s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Double.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeDouble / y.info.typeDouble;
    push(s,final);
} 

/**
 * @brief Definição da operação de divisão(/) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;           
    final.info.typeDouble = x.info.typeDouble / y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = x.info.typeChar / y.info.typeLong;
    push(s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = x.info.typeChar / y.info.typeDouble;
    push(s,final);
}

/**
 * @brief Definição da operação de divisão(/) entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void divisaoCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = x.info.typeChar / y.info.typeChar;
    push(s,final);
}

/**
 * @brief Definição da operação de exponenciação (#).
 * 
 * @param s -> pointer da STACK 
 */
void exponenciacao(STACK* s) {
    ELEMENT x, y;

    DispatchType funcType[4][4];
    setupExpArray(funcType);

    pop(s,&x); 
    pop(s,&y);
    funcType[y.type][x.type](s,y,x);
}

/**
 * @brief Definição da operação de soma (+) para Long.
 * 
 * @param s -> pointer da STACK 
 */
void expLongLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = pow (x.info.typeLong , y.info.typeLong);
    push (s, final);
    }

/**
 * @brief Definição da operação de soma (+) entre Long e Double.
 * 
 * @param s -> pointer da STACK 
 */
void expLongDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeLong , y.info.typeDouble);
    push (s, final); 
}

/**
 * @brief Definição da operação de soma (+) entre Lonbg e Char.
 * 
 * @param s -> pointer da STACK 
 */
void expLongChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = pow (x.info.typeLong , y.info.typeChar);
    push (s,final);
}

/**
 * @brief Definição da operação de soma (+) entre Double e Long.
 * 
 * @param s -> pointer da STACK 
 */
void expDoubleLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeDouble , y.info.typeLong);
    push (s,final);
}

/**
 * @brief Definição da operação de soma (+) entre Doubles.
 * 
 * @param s -> pointer da STACK 
 */
void expDoubleDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeDouble , y.info.typeDouble);
    push(s,final);
} 

/**
 * @brief Definição da operação de soma (+) entre Double e Char.
 * 
 * @param s -> pointer da STACK 
 */
void expDoubleChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;              
    final.info.typeDouble = pow (x.info.typeDouble , y.info.typeChar);
    push(s, final);  
}

/**
 * @brief Definição da operação de soma (+) entre Char e Long.
 * 
 * @param s -> pointer da STACK 
 */
void expCharLong(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = LONG;
    final.info.typeLong = pow (x.info.typeChar , y.info.typeLong);
    push(s, final);
}

/**
 * @brief Definição da operação de soma (+) entre Char e Double.
 * 
 * @param s -> pointer da STACK 
 */
void expCharDouble(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = DOUBLE;
    final.info.typeDouble = pow (x.info.typeChar , y.info.typeDouble);
    push(s,final);
}

/**
 * @brief Definição da operação de soma (+) Entre Char.
 * 
 * @param s -> pointer da STACK 
 */
void expCharChar(STACK *s, ELEMENT x, ELEMENT y){
    ELEMENT final;
    final.type = CHAR;
    final.info.typeChar = pow (x.info.typeChar , y.info.typeChar);
    push(s,final);
}