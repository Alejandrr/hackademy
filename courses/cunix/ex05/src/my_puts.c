#include "../include/test.h"
#include "stdio.h"
#include "unistd.h"


int my_puts(const char *s){
    if(s == NULL )
		return 0;
	
	unsigned int currentIndex = 0;
	while(s[currentIndex] != '\0')
		currentIndex++;
	
	
    write(1,s,currentIndex);
    write(1,"\n",1);
    return currentIndex;
}