#include <stdio.h>
#include "../libft/libft.h"
#include "get_next_line.h"

int main()
{
    char *text;
    int fd;

    fd = open("text.txt", O_RDONLY);
    while (get_next_line(fd, &text))
    {
        printf ("%s\n\n", text);
        free (text);
    }
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
    // get_next_line(fd, &text);
    // printf ("%s\n\n", text);
    // free (text);
}