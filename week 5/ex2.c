#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>
struct Thread
{
    pthread_t id;
    int i;
    char message[256];
};
void *PrintHello(void *thread_id)
{
    struct Thread *tid = (struct Thread *)thread_id;
    printf("%s, id: #%ld.\n", tid->message,tid->id);
    pthread_exit(NULL);
}
int main()
{
    int n;
    scanf("%d", &n);
    struct Thread threads[n];
    for (int i = 0; i < n; i++)
    {
        threads[i].i = i;
        sprintf(threads[i].message, "Hello from thread %d", i);
        pthread_t thread = pthread_create(&threads[i].id, NULL, PrintHello, (void *)&threads[i]);
        printf("Thread %d is created\n", i);
        usleep(1);
    }
    for (int j = 0; j < n; j++)
    {
        pthread_join(threads[j].id, NULL);
    }

    return EXIT_SUCCESS;
}