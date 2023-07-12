#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void count(char word[265], char letter)
{
    int counter = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == letter)
        {
            counter++;
        }
    }
    printf("%c:%d", letter, counter);
}
void countAll(char word[256])
{
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower((char)word[i]);
    }
    for (int i = 0; i < strlen(word); i++)
    {
        count(word, word[i]);
        if (i != strlen(word) - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}
int main(int argc, char* argv[])
{
    countAll(argv[1]);
}
