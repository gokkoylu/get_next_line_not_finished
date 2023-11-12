#include "get_next_line.h"

int ft_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    d = dest;
    s = src;

    if (d == s || n == 0)
        return dest;
    
    if (d > s && d < s + n)
    {
        d = d + n;
        s = s + n;
        while (n)
        {
            d--;
            s--;
            *d = *s;
            n--;
        }
    }
    else
    {
        while (n)
        {
            *d = *s;
            d++;
            s++;
            n--;
        }
    }

    return (dest);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    i = 0;
    j = 0;
    int len_s1 = 0;
    int len_s2 = 0;
    if (s1)
        len_s1 = ft_strlen(s1);
    if (s2) 
        len_s2 = ft_strlen(s2);
    int total_len = len_s1 + len_s2;

    char *res = malloc(total_len + 1);
    if (!res) 
        return NULL;

    if (!s1 && !s2) 
    {
        free(res);
        return NULL;
    }

    if (s1)
    {
        while (i < len_s1)
        {
            res[i] = s1[i];
            i++;
        }
    }
    if (s2)
    {
        while (j < len_s2)
        {
            res[i + j] = s2[j];
            j++;
        }
    }
    res[i + j] = '\0';

    return res;
}

char *ft_strdup(const char *s)
{
    char *res;
    size_t s_len;

    if (!s)
        return (0);
    s_len = ft_strlen(s);
    res = malloc((s_len + 1) * sizeof(char));
    if (!res)
    {
        errno = ENOMEM;
        return (0);
    }
    ft_strlcpy(res, s, s_len + 1);
    return (res);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    while (i < size - 1 && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }

    if (size > 0)
        dst[i] = '\0';
    
    while (src[i] != '\0')
        i++;
    
    return (i);
}