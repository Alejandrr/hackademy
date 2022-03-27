#ifndef LIBFT_H
#define LIBFT_H
#include <stddef.h>
#include <malloc.h>
    typedef struct ft_divide 
    {
        int quot;
        int rem; // ostacha
    }ft_div_t;
    typedef union ft_memptr
    {
         unsigned long* uLong;
         unsigned char* uChar;
    }memptr_t;
    ft_div_t ft_div(int numerator, int denominator);
    int ft_abs(int num);
    unsigned long ft_strlen(const char *s);
    unsigned long ft_strnlen(const char *s, unsigned long maxlen);
    int ft_strncmp(const char *s1, const char *s2, unsigned long n);
    const char *ft_strstr(const char *haystack, const char *needle);
    char *ft_strnstr(const char *big, const char *little ,unsigned long len);
    int ft_memcmp( const void * memptr1, const void * memptr2, unsigned long num );
    void *ft_memset (void *destination, int c, unsigned long lenght);
    void *ft_memcpy(void *dst, const void *src, unsigned long n);
    void ft_bzero(void *s, unsigned long n);
    const char *ft_strchr(const char *s, char c);
    int ft_isalpha(int c);
    int ft_isascii(int c);
    int ft_isdigit(int c);
    int ft_toupper(int c);
    int ft_tolower(int c);
    void ft_striter(char* str ,void (*f)(char* c));
    char* ft_strtrim(const char* str);
    char** ft_strsplit(const char* str ,const char delim);
    char* ft_strjoin(const char* str1,const char* str2);
#endif 








