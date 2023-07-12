#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    void *ptr[10];
    int mem = 500 * 1024 * 1024; // since I have 16 gbs of ram, I allocated 500 mb each second for testing to see any changes in si so
    for (int i = 0; i < 10; i++) // also I saved top output into ex3.txt
    {
        ptr[i] = malloc(mem);
        if (ptr[i] != NULL)
            memset(ptr[i], 0, mem);
        sleep(1);
    }
    for (int i = 0; i < 10; i++)
        free(ptr[i]);
    return 0;
}