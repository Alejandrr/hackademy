#include "../include/test.h"
#include <stddef.h>
#include <malloc.h>
#define ANSII_DIGIT_START  48
#define ANSII_DIGIT_END    57


int my_atoi(const char *nptr){
    if(nptr == NULL)
        return 0;
    int negative = 1; 
    int result = 0, 
        currentIndex = 0;
    if(nptr[currentIndex]=='-'){
        currentIndex++;
        negative*=-1;
    }
    while(nptr[currentIndex] != '\0'){
       
        int ANSII = (int)nptr[currentIndex++];
        if(ANSII>=ANSII_DIGIT_START && ANSII<=ANSII_DIGIT_END){
            result*=10;
            result+=ANSII-ANSII_DIGIT_START;
        }else {
            break;
        }
    }
    result *=negative;

    return result ; 
}
