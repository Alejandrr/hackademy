#include "../libft.h"
void* ft_memcpy(void *dst, const void *src, unsigned long lenght)
{
        if(lenght != 0)
        {
                register memptr_t pDestination , pSource;
                pDestination.uLong = dst;
                pSource.uLong = (unsigned long*)src;
                ft_div_t count ;
                count = ft_div( lenght , sizeof(long));
                for (unsigned long i = 0; i < (unsigned long)count.quot; i++)
                {
                       *pDestination.uLong++ = *pSource.uLong++;
                }
                if(count.rem > 0)
                {
                        pDestination.uChar = (unsigned char*)pDestination.uLong;
                        pSource.uChar = (unsigned char*)pSource.uLong;
                        for(int i = 0 ; i < count.rem ; i++)
                        {
                                *pDestination.uChar++ = *pSource.uChar++;
                        }
                }
                
        }        
        return dst;
}