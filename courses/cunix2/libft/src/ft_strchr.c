#include "../libft.h"
const char *ft_strchr(const char *s,char c)
{
    unsigned int  index = 0;
    while (s[index] != '\0')
    {
        if(s[index] == c)
        {
            break;
        }
        index++;
    }
    return c == s[index] ? (char*)(s+index) : 0;
}