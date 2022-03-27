#include "../libft.h"
void *ft_memset(void *destination, int c, unsigned long lenght)
{
    if(lenght > 0)
    {
        register  char* ptr = destination;
        do
        {
            *ptr++ = (char)c;
        }
        while (--lenght != 0);
    }
    return destination;
}