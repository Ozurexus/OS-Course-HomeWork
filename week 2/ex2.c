#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i = 0;
    char c = ' ';
    while (c != '.' && i < strlen(argv[1]))
    {
        i++;
        c = argv[1][i];
    }
    printf("\"");
    while (i > 0)
    {
        i--;
        putchar(argv[1][i]);
    }
    printf("\"\n");
    return 0;
}
