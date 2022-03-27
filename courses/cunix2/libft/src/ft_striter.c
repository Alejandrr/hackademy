#include "../libft.h"
void ft_striter(char* str ,void (*f)(char* c))
{
        if(!str[0] || str[0]=='\0')
        {
                return;
        }
        for(unsigned int i = 0; str[i] != '\0' ; i++)
        {
                f(&str[i]);
        } 
}