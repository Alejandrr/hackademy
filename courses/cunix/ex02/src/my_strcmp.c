#include "../include/test.h"
#include <stddef.h>
int my_strcmp(char* s1,char* s2){
    if(s1 == NULL  || s2 == NULL)
        return 0 ;

    
    unsigned int currentIndex = 0 ;

    do{
        
        if(s1[currentIndex]!=s2[currentIndex])
            return (int)s1[currentIndex] - (int)s2[currentIndex];
    	currentIndex++;    
    }while(s1[currentIndex]!='\0');
    return 0;
}
