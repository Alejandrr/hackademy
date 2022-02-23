#include <../include/test.h>
#include <stddef.h>
#include <malloc.h>
unsigned int my_strlen(const char* str){
	if(str == NULL )
		return 0;
	
	unsigned int currentIndex = 0;
	while(str[currentIndex] != '\0')
		currentIndex++;
	
	
	return currentIndex;
}
char* Memcpy(void* dest ,const void* src , unsigned int len){
	char* s1 = dest;
	const char* s2 = src;

	while (len!=0){
		*s1++ = *s2++;
		len--;
	}
	return dest ;

}
char *my_strcpy(char *dest, const char *src){
	
   
    Memcpy(dest , src , my_strlen(src)+1);
    return dest ;
	
}

