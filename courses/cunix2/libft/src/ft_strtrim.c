#include "../libft.h"
char* ft_strtrim(const char* str)
{
    char* result = NULL;
    unsigned long len = ft_strlen(str);
    const  char* wsc = " \t\n";
    const  char* strBeg=str,*strEnd=str+len-1;
    for (;*strBeg != '\0'; strBeg++)
    {
        if (ft_strchr(wsc,*strBeg) == 0)
        {
            break;
        }
        len--;
    }
    if(len > 0)
    {
        for (;len != 0;--strEnd)
        {
            if (ft_strchr(wsc,*strEnd) == 0)
            {
                break;
            }
            len--;
        }
    }
    result = (char*)malloc(sizeof(char) * (len + 1));
    if(result)
    {
        ft_memcpy(result,strBeg,len );
        result[len] = '\0';
    }
    return result;
}