#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0, i2 = 0, i3 = 0;
    char arr[100];
    arr[0] = '\0';

    if (argc != 3) {
        write(1, "\n", 1);
        return 0;
    }
    while(argv[1][i])
    {
        while (arr[i3] != '\0' && arr[i3] != argv[1][i])
            i3++;
        if (arr[i3] == '\0')
        {
            arr[i3] = argv[1][i];
            arr[++i3] = '\0';
        }
        i3 = 0;
        ++i;
    }
    while(argv[2][i2])
    {
        while (arr[i3] != '\0' && arr[i3] != argv[2][i2])
            i3++;
        if (arr[i3] == '\0')
        {
            arr[i3] = argv[2][i2];
            arr[++i3] = '\0';
        }
        i3 = 0;
        ++i2;
    }
    while(arr[i3])
        write(1, &arr[i3++], 1);
    write(1, "\n", 1);
    return 0;
}