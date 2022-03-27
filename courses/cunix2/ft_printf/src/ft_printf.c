#include <malloc.h>
#include <stddef.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h> 
#include "libft.h"
#include "test.h"


int  ft_special_output(const char *fmt, va_list args)
{
    const void *arg;
    short prefix = (*fmt == '+') ? *++fmt : 0 ;
    int width = 0;
    short jump = 0, fZero = 0, fSpace = 0 ;
    /*
    flag&width catch
    */
    if (*fmt == 32)
    {
        fmt++;
        jump++;
        fSpace = 1;
    }
    if (ft_isdigit(*fmt))
    {
        char *tmp = (char *) malloc(sizeof(char) * 11);
        unsigned  int i;
        if (*fmt == '0')
        {
            fZero = 1;
            fmt++;
            jump++;
        }
        for (i = 0; ft_isdigit(*fmt); fmt++, i++)
        {
            tmp[i] = *fmt;
            jump++;
        }
        tmp[i] = '\0';
        width = my_atoi(tmp);
        free(tmp);
    }
    /*
    */
    switch (*fmt)
    {
        case '%':
        {
            write(1, "%", 1);
            break;
        }
        case 'c':
        {
            int c  = va_arg(args, int);
            for (int i = 0; i < width - 1 ; i++)
            {
                write(1, " ", 1);
            }
            write(1, &c, 1);
            break;
        }
        case 's':
        {
            arg = va_arg(args, const char *);
            int len = width - ((arg == 0x0) ? 6 : ft_strlen(arg));
            for (int i = 0; i < len; i++)
            {
                write(1, " ", 1);
            }
            if (arg == 0x0)
            {
                write(1, "(null)", 6);
            }
            else
            {
                write(1, arg, ft_strlen((char *)arg));
            }
            break;
        }
        case 'i':
        case 'd':
        {
            int  val = va_arg(args, int);
            char *path = my_itoa(val);
            int len = width - ft_strlen(path);
            if (prefix)
            {
                if (val >= 0)
                {
                    write(1, "+", 1);
                    --len;
                }
                fmt++;
                jump++;
            }
            else if (fSpace && val >= 0)
            {
                write(1, " ", 1);
                --len;
            }
            if (width)
            {
                if (fZero)
                {
                    if (val < 0)
                    {
                        write(1, "-", 1);
                        val = abs(val);
                        free(path);
                        path = my_itoa(val);

                    }
                    for (int i = 0; i < len; i++)
                    {
                        write(1, "0", 1);
                    }
                }
                else
                {
                    for (int i = 0; i < len; i++)
                    {
                        write(1, " ", 1);
                    }
                }
            }

            write(1, path, ft_strlen(path));
            free(path);
            break;
        }

        default:
        {

        }
    }
    return jump;
}
void ft_printf(const char *fmt, ...)
{
    va_list args;
    int arg_count = 0;
    register const char *fmt_iter = fmt;
    va_start(args, fmt);
    do
    {
        if (*fmt_iter != '%')
        {
            write(1, fmt_iter, 1);
        }
        else
        {
            int jump = ft_special_output(++fmt_iter, args);
            while (jump-- > 0)
            {
                fmt_iter++;
            }
        }
    }
    while (*++fmt_iter != 0);
    va_end(args);
}


