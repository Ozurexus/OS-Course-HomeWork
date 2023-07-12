#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(void)
{
    int i;
    char command[128];
    printf("Welcome to my shell.\nType \"exit\"  to exit shell.\n");
    while (1)
    {
        printf("Enter the command: ");
        fgets(command, 128, stdin);
        if (strcmp(command, "exit\n") == 0)
        {
            return EXIT_SUCCESS;
        }
        else if (system(NULL))
        {
            pid_t child = fork();
            if (child == 0)
            {
                i = system(command);
                break;
            }
        }
    }
    return EXIT_SUCCESS;
}