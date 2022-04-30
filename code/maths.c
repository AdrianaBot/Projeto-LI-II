#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stack.h"


/**
 * @brief Definição da operação de soma (+).
 *  
 * @param s -> pointer da STACK 
 */
void soma(STACK* s, DispatchType somaArray[4][4]) {
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    somaArray[x.type][y.type](s,x,y);
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

/**
 * @brief Definição da operação de subtração (-).
 * 
 * @param s -> pointer da STACK 
 */
void subtracao(STACK *s, DispatchType subtracaoArray[4][4]){
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    subtracaoArray[y.type][x.type] (s,y,x);
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
void multiplicacao(STACK *s, DispatchType multiplicacaoArray[4][4]){
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    multiplicacaoArray[x.type][y.type] (s,x,y);
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

/**
 * @brief Definição da operação de divisão(/).
 * 
 * @param s -> pointer da STACK 
 */
void divisao(STACK *s, DispatchType divisaoArray[4][4]){
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    divisaoArray[y.type][x.type] (s,y,x);
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
void exponenciacao(STACK* s, DispatchType expArray[4][4]) {
    ELEMENT x, y;
    pop(s,&x); 
    pop(s,&y);
    expArray[y.type][x.type](s,y,x);
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