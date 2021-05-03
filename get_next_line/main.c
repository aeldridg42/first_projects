#include "get_next_line.h"

int get_next_line(int fd, char **line);

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
    // while (1)
    // {

    // }
}