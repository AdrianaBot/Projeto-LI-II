#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "stack.h"

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
    if (sscanf(x.info.typeString,"%ld",&v) == 1) converter.info.typeLong = v; 

    push(s,converter);
    }
}

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
    double v;   
    if (sscanf(x.info.typeString,"%lf",&v) == 1) converter.info.typeDouble = v; 

    push(s,converter);
    }
}

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
    char v;   
    if (sscanf(x.info.typeString,"%c",&v) == 1)   converter.info.typeChar = v; 

    push(s,converter);
    }
}

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