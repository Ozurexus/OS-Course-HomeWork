#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t size)
{
    if (ptr == NULL)
    {
        return malloc(size);
    }
    else if (size == 0)
    {
        free(ptr);
        return NULL;
    }
    else
    {
        void *newptr = malloc(size);
        memcpy(newptr, ptr, size);
        free(ptr);
        return newptr;
    }
}

int main()
{
    int *arr1 = (int *)malloc(5 * sizeof(int));
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;

    int *arr2 = (int *)my_realloc(arr1, 12 * sizeof(int));
    arr2[5] = 6;
    arr2[6] = 7;
    arr2[7] = 8;
    arr2[8] = 9;
    arr2[9] = 10;
    for (int i = 0; i < 12; i++)
    {
        printf("%d ", arr2[i]);
    }
    char *arr3 = (char *)malloc(10 * sizeof(char));
    arr3[0] = 'a';
    arr3[1] = 'b';
    arr3[2] = 'c';
    arr3[3] = 'd';
    arr3[4] = 'e';
    arr3[5] = 'f';
    arr3[6] = 'g';
    arr3[7] = 'h';
    arr3[8] = 'i';
    arr3[9] = 'j';
    char *arr4 = (char *)my_realloc(arr3, 5 * sizeof(char));
    for (int i = 0; i < 5; i++)
    {
        printf("%c ", arr4[i]);
    }
    return 0;
}
