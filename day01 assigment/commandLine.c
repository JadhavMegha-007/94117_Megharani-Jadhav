#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x, y, i = 0;
    int z[10];

    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    x = atoi(argv[1]);

    while (x != 0)
    {
        y = x / 2;
        z[i] = x % 2;
        x = y;
        i++;
    }

    printf("Binary: ");
    do
    {
        printf("%d", z[i - 1]);
        i--;
    } while (i != 0);

    return 0;
}