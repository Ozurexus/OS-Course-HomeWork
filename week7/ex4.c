#include <stdio.h>
#include <stdlib.h>

void *my_realloc(void *ptr, int size)
{
    if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL)
    {
        return malloc(size);
    }
    void *new_ptr = malloc(size);
    if (new_ptr == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        ((char *)new_ptr)[i] = ((char *)ptr)[i];
    }
    free(ptr);
    return new_ptr;
}

int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = my_realloc(arr, 20 * sizeof(int));
    for (int i = 10; i < 20; i++)
    {
        arr[i] = i + 1;
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
