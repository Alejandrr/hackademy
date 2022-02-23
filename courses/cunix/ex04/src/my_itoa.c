#include "../include/test.h"
#include "stddef.h"
#include "malloc.h"
#include <stdio.h>
#define ANSII_DIGIT_START 48
int abs(int number){
    if(number<0)
        return number *-1;
    else
        return number;
}
char* my_itoa(int nmb){
    char* result;
    int len = 1 , index = 0,base =1 , IsNegative= 0,digit =0,number = abs(nmb); 
    
    if(nmb<0){
        IsNegative=1;
    }
    while(number/base > 10){
        base*=10;
        len++;
    }

    result = (char*)malloc(sizeof(char)*(IsNegative+len+1));
    
    if(IsNegative)
        result[index++]='-';
    while(len--!=0){
        digit = number/base;
        result[index++]=(char)(digit+ANSII_DIGIT_START);
        number-=digit*base;
        base/=10;
    }
    result[index++]='\0';
    return  result;
}
