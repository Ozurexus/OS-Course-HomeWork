#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int f1[2];
    int f2[2];
    char input[100];
    pid_t p;
    if (pipe(f1) == -1 || pipe(f2) == -1)
    {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }
    scanf("%s", input);
    p = fork();
    if (p < 0)
    {
        fprintf(stderr, "fork Failed");
        return 1;
    }
    else if (p > 0)
    {
        char output[100];
        close(f1[0]);
        write(f1[1], input, strlen(input) + 1);
        close(f1[1]);
        wait(NULL);
        close(f2[1]);
        read(f2[0], output, 100);
        printf("Message: %s\n", output);
        close(f2[0]);
    }
    else
    {
        close(f1[1]);
        char output[100];
        read(f1[0], output, 100);
        close(f1[0]);
        close(f2[0]);
        write(f2[1], output, strlen(output) + 1);
        close(f2[1]);
        exit(0);
    }
}
