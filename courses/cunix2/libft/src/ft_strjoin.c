#include "../libft.h"
char* ft_strjoin(const char* str1,const char* str2)
{       
    char* result = NULL;
    unsigned long len = ft_strlen(str1)+ft_strlen(str2) ;
    result = (char*)malloc(sizeof(char)*(len + 1));
    ft_memcpy(result,str1,ft_strlen(str1));
    ft_memcpy(result+ft_strlen(str1),str2,ft_strlen(str2));
    result[len] = '\0';
    return result;
}