#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

//CONVERSÕES


/**
 * @brief convToLong converte tipos para Long.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para Long.
 * 
 * @param s -> pointer da STACK 
 */
void convToLong(STACK *s){
    ELEMENT x, converter;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);
    converter.type = LONG;
    
    
    if (x.type == LONG){
    converter.info.typeLong = x.info.typeLong; 
    push (s,converter);
    }

    else if  (x.type == DOUBLE){
    converter.info.typeLong=x.info.typeDouble;
    push (s,converter);
    }

    else if (x.type == CHAR){
    converter.info.typeLong=x.info.typeChar;
    push(s,converter);
    }

    else if (x.type == STRING){
    long v;   
    char h[BUFSIZ] = "";
    if (sscanf(h,"%ld",&v) == 1) converter.info.typeLong = v; 

    push(s,converter);
    }
}
/**
 * @brief convToDouble converte tipos para Double.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para Double.
 * 
 * @param s -> pointer da STACK 
 */
void convToDouble(STACK *s){
    ELEMENT x, converter;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);
    converter.type = DOUBLE;
    
    if (x.type == LONG){
    converter.info.typeDouble = x.info.typeLong; 
    push (s,converter);
    }

    else if  (x.type == DOUBLE){
    converter.info.typeDouble = x.info.typeDouble;
    push (s,converter);
    }
    else if (x.type == CHAR){
    converter.info.typeDouble = x.info.typeChar;
    push(s,converter);
    }

    else if (x.type == STRING){
    char h[BUFSIZ] = ""; 
    double v;   
    
    
    if (sscanf(h,"%lf",&v) == 1) converter.info.typeDouble = v; 

    push(s,converter);
    }
}

/**
 * @brief convToChar converte tipos para Char.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para Char.
 * 
 * @param s -> pointer da STACK 
 */
void convToChar(STACK *s){
    
    ELEMENT x, converter;
    x.type = LONG;
    x.info.typeLong = 0;
    pop(s,&x);
    converter.type = CHAR;

    if (x.type == LONG){

    converter.info.typeChar = x.info.typeLong; 
    push (s,converter);
    }

    else if  (x.type == DOUBLE){
    converter.info.typeChar = x.info.typeDouble;
    push (s,converter); 
    }
    else if (x.type == CHAR){
    converter.info.typeChar = x.info.typeChar;
    push(s,converter);
    }

    else if (x.type == STRING){
    char h[BUFSIZ] = ""; 
    long v;   
    
    if (sscanf(h,"%ld",&v) == 1)    converter.info.typeChar = v; 

    push(s,converter);
    }
}

/**
 * @brief convToString converte tipos para String.
 * 
 * Esta função recebe um elemento de qualquer tipo e converte esse mesmo 
 * elemento para String.
 * 
 * @param s -> pointer da STACK 
 */
void convToString(STACK *s){
    ELEMENT x, converter;
    x.type = LONG;
    pop(s,&x);
    converter.type = STRING;

    if (x.type == LONG){
    sprintf(converter.info.typeString,"%ld",x.info.typeLong);
    push (s,converter);
    }

    else if (x.type == DOUBLE){
    sprintf(converter.info.typeString,"%lf",x.info.typeDouble);
    push (s,converter);
    }

    else if (x.type == CHAR){
    sprintf(converter.info.typeString,"%c",x.info.typeChar);
    push(s,converter);
    }   
}

