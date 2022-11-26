#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    FILE *output = fopen("ex2.txt", "w");
    if (fd == -1)
    {
        return EXIT_FAILURE;
    }
    while (1)
    {
        struct input_event ie;
        read(fd, &ie, sizeof(ie));
        if (ie.type == 1 && ie.value == 1)
        {
            fprintf(output, "PRESSED 0x%04x (%d)\n", ie.code, ie.code);
        }
        else if (ie.type == 1 && ie.value == 0)
        {
            fprintf(output, "RELEASED 0x%04x (%d)\n", ie.code, ie.code);
        }
        fflush(output);
    }
    return 0;
}