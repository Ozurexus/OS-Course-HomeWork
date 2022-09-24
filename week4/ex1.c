#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
int main(void)
{
    pid_t child_a, child_b;
    child_a = fork();
    int t = clock();
    if (child_a == 0)
    {
        printf("Hello from %d, child of %d. Time needed: %d milliseconds.\n", getpid(), getppid(), t);
    }
    else
    {
        child_b = fork();
        if (child_b == 0)
        {
            printf("Hello from %d, child of %d. Time needed: %d milliseconds.\n", getpid(), getppid(), t);
        }
        else
        {
            printf("Hello from %d, child of %d. Time needed: %d milliseconds.\n", getpid(), getppid(), t);
        }
    }
    return EXIT_SUCCESS;
}
