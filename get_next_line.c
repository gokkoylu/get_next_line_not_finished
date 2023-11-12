#include "get_next_line.h"


//strjoin
//strdup
//strlcat
//son okuma \0 mu kontrol edecek fonksiyon (strlen evolved)
//stringchr
//ggwp

char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (0);
    while (*s)
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }

    if (c == '\0')
        return (char *)s;

    return (0);
}


int ft_next(char *string)
{
    int i;

    i = 0;
    while (string[i] && (string[i] != '\n' || string[i] != '\0'))
        i++;
    return i;
}

char *ft_line(char *string)
{
    int i;

    i = 0;
    while (string[i] != '\n')
        i++;
    i = i + 1;
    ft_memmove(string, &string[i], ft_strlen(string) - i + 1);
    string[ft_strlen(string)] = '\0';
    return (string);
}

char *get_next_line(int fd)
{
    int lines_read;
    static char *big_stash;
    char *line;
    char *temp_stash;
    char *small_stash;
    int len;

    if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
        return NULL;
    small_stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while ((lines_read = read(fd, small_stash, BUFFER_SIZE)) > 0)
    {
        line = NULL;
        small_stash[lines_read] = '\0';
        temp_stash = ft_strjoin(big_stash, small_stash);

        if (big_stash)
            free(big_stash);
        big_stash = temp_stash;
        //so far no seg faults
        if (ft_strchr(big_stash, 10) != NULL)
        {
            len = ft_next(big_stash);
            line = malloc(len + 1);
            ft_strlcpy(line, big_stash, len + 1);
            big_stash = ft_line(big_stash);
            free(small_stash);
            small_stash = NULL;
            return (line);
        }
    }
    if (lines_read == 0 && big_stash && *big_stash)
    {
        line = ft_strdup(big_stash);
        free(big_stash);
        big_stash = NULL;
        free(small_stash);
        small_stash = NULL;

        return (line);
    }
    if (lines_read == -1)
    {
            free(small_stash);
            small_stash = NULL;
            free(big_stash);
            big_stash = NULL;
            return NULL;
    }
    free(small_stash);
            small_stash = NULL;
            free(big_stash);
            big_stash = NULL;
            return NULL;
}

int main()
{
    int fd;
    char *line;
    int ret;

    fd = open("sample.txt", O_RDONLY);
    if (fd == -1)
        return 1;


    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}