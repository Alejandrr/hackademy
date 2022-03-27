#include "../libft.h"
const char *ft_strstr(const char *haystack, const char *needle)
{
        const unsigned long len = ft_strlen(needle);
        do
        {
                if(!ft_memcmp(haystack,needle,len))
                {
                        return haystack;
                }      
        }
        while(*haystack++);
        return 0; 
}