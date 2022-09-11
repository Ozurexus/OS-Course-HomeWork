#include <stdio.h>
#include <string.h>

char arr[256];
int main(void)
{
    printf("Enter a string of size at most 256: ");
    gets(arr);
    int i = 0;
    char c = "";
    while (c != '.' && i < strlen(arr))
    {
        i++;
        c = arr[i];
    }
    printf("\"");
    while (i > 0)
    {
        i--;
        putchar(arr[i]);
    }
    printf("\"");
    return 0;
}