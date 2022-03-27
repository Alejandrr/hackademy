#include "../libft.h"
int ft_toupper(int c)
    {
        if(!ft_isalpha(c))
        {
            return c;
        }
        return c - 32;
    }
    int ft_tolower(int c)
    {
        if(!ft_isalpha(c))
        {
            return c;
        }
        return c + 32;
    }