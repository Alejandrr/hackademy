#include "../libft.h"
 int ft_isalpha(int c)
    {
        if(c <= 122 && 97 <= c)
            return 1;
        else if (c <= 90 && 65 <= c)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }