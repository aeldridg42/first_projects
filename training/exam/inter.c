#include <unistd.h>

int main(int argc, char **argv)
{
    char arr[100];
    int n = 0, n2 = 3, n3 = 0;

    arr[0] = '\0';
    if (argc != 3) {
        write(1, "\n", 1);
        return (0);
    }
    while(argv[1][n])
    {
        n2 = 0;
        while (argv[2][n2])
        {
            if (argv[1][n] == argv[2][n2])
            {
                while (arr[n3] != '\0' && arr[n3] != argv[2][n2])
                    n3++;
                if (arr[n3] == '\0') {
                    arr[n3++] = argv[1][n];
                    arr[n3++] = '\0';
                }
                n3 = 0;
            }
            ++n2;
        }
        ++n;
    }
    n3 = 0;
    while (arr[n3])
    {
        write(1, &arr[n3], 1);
        n3++;
    }
    write(1, "\n", 1);
    return (0);
}