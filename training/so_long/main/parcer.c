#include "../main.h"

int check_lenght(char **argv)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(argv[1][i])
    {
        if(argv[1][i] == '\n')
            ++count;
        ++i;
    }
    return(count);
}

int parser(char **argv, t_map map)
{
    char *line;
    int fd;
    int i;
    int check;

    fd = open(argv[1], O_RDONLY);
    i = 0;
    check = 1;
    map.map = (char **)malloc(sizeof(char *) * (check_lenght(argv) + 2));
    while(check)
    {
        check = get_next_line(fd, &line);
        if (check == -1)
            return (-1);
        map.map[i++] = line;
        free(line);
    }
    map.map[i++] = line;
    map.map[i] = NULL;
    return 0;
}