#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
int main()
{
    int fd;
    char *myfifo = "/tmp/ex1";
    char buf[1024];
    fd = open(myfifo, O_RDONLY);
    while (1)
    {
        read(fd, buf, 1024);
        printf("Received: %s\n", buf);
        if (strcmp(buf, "exit") == 0)
        {
            printf("Exiting\n");
            break;
        }
    }
    close(fd);
    return 0;
}