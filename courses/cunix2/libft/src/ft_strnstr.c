#include "../libft.h"
char *ft_strnstr(const char *s, const char *find, unsigned long slen)
{
    char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = ft_strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (ft_strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
       /* int i;
        unsigned long needle_len;
        if ((needle_len = ft_strnlen(needle, len) <= 0))
        {
                return (char *)haystack;
        }                
        for (i=0; i<=(int)(len-needle_len); i++)
        {                              
                if ((haystack[0] == needle[0]) && (0 == ft_strncmp(haystack, needle, needle_len)))
                {
                        return (char *)haystack;
                }
                haystack++;
        }
        return NULL;*/
}