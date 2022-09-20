#include <stdio.h>
#include <stdlib.h>
int foo(int age)
{
    int result;
    result = 2022 - age;
    return result;
}
int main(void)
{
    const int x = 10;
    const int *q = &x;
    const int *const p = calloc(x, sizeof(int) * 5);
    int *const p2 = p;
    printf("Memory addresses:\n%p, %p, %p, %p, %p", p, p + 1, p + 2, p + 3, p + 4);
    printf("\nEnter students' ages:\n");
    scanf("%d\n%d\n%d\n%d\n%d", p, p + 1, p + 2, p + 3, p + 4);
    for (int i = 0; i < 5; i++)
    {
        *(p2 + i) = foo(*(p + i));
        printf("%d   ", *(p2 + i));
    }
    return EXIT_SUCCESS;
}