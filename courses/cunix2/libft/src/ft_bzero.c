#include "../libft.h"
 void ft_bzero(void *s, unsigned long n)
    {
        register char* ptr = s;
        for(unsigned long i = 0 ; i < n ; i++)
        {
            *ptr++ = 0;
        }
    }