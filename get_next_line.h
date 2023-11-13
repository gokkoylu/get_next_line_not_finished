#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE  41
#endif
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int ft_strlen(char const *str);
void *ft_memmove(void *dest, const void *src, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *get_next_line(int fd);
char *ft_line(char *string);
int ft_next(char *string);
char *ft_strchr(const char *s, int c);


#endif