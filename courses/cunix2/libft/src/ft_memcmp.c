#include "../libft.h"
int ft_memcmp(const void * memptr1, const void * memptr2, unsigned long lenght)
{   
        if(lenght != 0)
        {
                register const unsigned char* p1 = memptr1,
                                            * p2 = memptr2;
                do
                {
                      if(*p1++ != *p2++)
                      {
                              return(*--p1 - *--p2);
                      }
                } 
                while (--lenght > 0);
        }
        return 0;
}