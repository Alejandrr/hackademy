#include "../libft.h"
#include "stdio.h"
#include "unistd.h"
char** ft_strsplit(const char* str ,const char delim)
{
    char** result;
    unsigned int WCounter = 0, word_len = 0,word = 0;
    register const char* str_iter = str , *pWord =NULL;
    if(!str||str[0]=='\0')
    {
        result =(char**)malloc(sizeof(char*));
        result[0]=NULL;
        return result;
    }
    do
    {
        if(*str_iter != delim && !pWord)
        {
            pWord = str_iter;
            WCounter++;
        }
        if(pWord && (*str_iter == delim || *str_iter == '\0') )
        {
            pWord = NULL;
        }
    }
    while(*++str_iter != '\0');
    str_iter = str;
    pWord = NULL;
    result = (char**)malloc(sizeof(char*)*(WCounter+1));
    if(WCounter)
    {
        do
        {
            if(*str_iter != delim && !pWord)
            {
                word_len = 0;
                pWord = str_iter;
            }
            else
            {
                word_len++;
            }
            if(pWord &&(*str_iter == delim || *str_iter == '\0'))
            {
                if(word_len) {
                    result[word] = (char *) malloc(sizeof(char) * (word_len + 1));
                    if (result[word]) {
                        ft_memcpy(result[word], pWord, word_len);
                        result[word++][word_len] = '\0';
                        pWord = NULL;
                    }
                }
            }
        }
        while(*str_iter++ != '\0');
    }

    result[WCounter] = 0;
    return result;

}