#include "../libft.h"
unsigned long ft_strnlen(const char *str, unsigned long maxlen)
{
	if(str == NULL)
    {
		return 0;
    }
	unsigned int currentIndex = 0;
	while(str[currentIndex] != '\0'&& currentIndex != maxlen)
    {
		currentIndex++;
    }
	return currentIndex;

}