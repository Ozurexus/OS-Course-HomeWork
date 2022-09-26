#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
// 268357 correct answer
int dotprod(int u[], int v[], int start, int end)
{
    int result = 0;
    for (int i = start; i < end; i++)
    {
        result += u[i] * v[i];
    }
    return result;
}

int main(void)
{
    FILE *read, *write;
    read = fopen("temp.txt", "r");
    write = fopen("temp.txt", "w");
    int u[120];
    int v[120];
    int n;
    printf("Please enter n: ");
    scanf("%d", &n);
    int m = 120 / n;
    if (n != 2 && n != 4 && n != 6 && n != 8 && n != 10)
    {
        printf("Wrong Input!");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 120; i++)
    {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++)
    {
        pid_t child = fork();
        if (child == 0)
        {
            fprintf(write, "%d\n", dotprod(u, v, i * m, (i + 1) * m));
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }
    int temporary;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        fscanf(read, "%d\n", &temporary);
        result += temporary;
    }

    printf("%d\n", result);
    return EXIT_SUCCESS;
}