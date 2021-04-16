#include <stdlib.h>

int     ft_memcmp(const void *s1, const void *s2, size_t n);
int     ft_tolower(int c);
int     ft_toupper(int c);
int     ft_isascii(int c);
int     ft_isdigit(int c);
int     ft_isalpha(int c);
int     ft_isalnum(int c);
int     ft_isprint(int c);
void    *ft_memset (void *destination, int c, size_t n);
void    ft_bzero(void *s, size_t n);
size_t  ft_strlen(const char *s);
size_t  ft_strlcpy (char * restrict dst, const char * restrict src, size_t size);
size_t  ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void    *memmove(void *dst, const void *src, size_t len);