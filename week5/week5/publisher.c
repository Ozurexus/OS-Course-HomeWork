#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int fd;
    char *myfifo = "/tmp/ex1";
    mkfifo(myfifo, 0666);
    fd = open(myfifo, O_WRONLY);
    char c[1024];
    while (1)
    {
        scanf("%s", c);
        for (int i = 0; i < n; i++)
        {
            write(fd, c, sizeof(c));
            sleep(1);
        }

        if (strcmp(c, "exit") == 0)
        {
            printf("Exiting\n");
            break;
        }
    }
    close(fd);
    unlink(myfifo);
    return 0;
}