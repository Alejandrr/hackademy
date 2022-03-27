#include "../libft.h"
ft_div_t ft_div(int numerator, int denominator)
{
    ft_div_t result;
    result.quot = numerator / denominator;
    result.rem = numerator % denominator; 
    return result; 
}