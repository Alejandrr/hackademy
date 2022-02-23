#include "test.h"

unsigned int my_strlen(char* str){
	if(str == NULL)
		return 0;
	
	unsigned int currentIndex = 0;
	while(str[currentIndex]!= '\0')
		currentIndex++;
	
	
	return currentIndex+1;
}
