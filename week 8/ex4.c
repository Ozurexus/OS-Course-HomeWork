#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
    void *ptr[10];
    struct rusage rs;
    int mem = 10 * 1024 * 1024;
    for (int i = 0; i < 10; i++)
    {
        ptr[i] = malloc(mem);
        if (ptr[i] != NULL)
            memset(ptr[i], 0, mem);
        getrusage(RUSAGE_SELF, &rs);
        printf("Maximum Resident Set Size: %ld\n", rs.ru_maxrss);
        sleep(1);
    }
    for (int i = 0; i < 10; i++)
    {
        free(ptr[i]);
    }
    return 0;
}
