#include <fcntl.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    FILE *output = fopen("ex3.txt", "w");
    int arr[256] = {0};
    int flag;
    if (fd == -1)
    {
        return EXIT_FAILURE;
    }
    while (1)
    {
        flag = 1;
        struct input_event ie;
        read(fd, &ie, sizeof(ie));
        if (ie.type == 1 && ie.value == 1)
        {
            arr[ie.code] = 1;
        }
        else if (ie.type == 1 && ie.value == 0)
        {
            arr[ie.code] = 0;
        }
        if (arr[KEY_P] == 1 && arr[KEY_E] == 1)
        {
            for (int i = 0; i < 256; i++)
            {
                if (arr[i] == 1 && (i != KEY_P && i != KEY_E))
                {
                    flag = 0;
                    printf("\n%d\n", i);
                    fflush(stdout);
                    break;
                }
            }
            if (flag == 1)
            {
                fprintf(output, "I passed the Exam!\n");
                printf("I passed the Exam!\n");
            }
        }
        if (arr[KEY_C] == 1 && arr[KEY_A] == 1 && arr[KEY_P] == 1)
        {
            for (int i = 0; i < 256; i++)
            {
                if (arr[i] == 1 && i != KEY_C && i != KEY_A && i != KEY_P)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                fprintf(output, "Get some cappuccino!\n");
                printf("Get some cappuccino!\n");
            }
        }
        if (arr[KEY_C] == 1 && arr[KEY_U] == 1 && arr[KEY_S] == 1 && arr[KEY_T] == 1)
        {
            for (int i = 0; i < 256; i++)
            {
                if (arr[i] == 1 && i != KEY_C && i != KEY_U && i != KEY_S && i != KEY_T)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                fprintf(output, "This is a custom shortcut!\n");
                printf("This is a custom shortcut!\n");
            }
        }
        fflush(output);
    }
    return 0;
}