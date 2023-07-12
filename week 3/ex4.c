#include <stdio.h>
#include <math.h>
void *AddInt(const int *a, const int *b)
{
    int *c = a;
    *c = *a + *b;
    return a;
}
void *addDouble(const double *a, const double *b)
{
    double *c = a;
    *c = *a + *b;
    return a;
}
void *mulInt(const int *a, const int *b)
{
    int *c = a;
    *c = *a * *b;
    return a;
}
void *mulDouble(const double *a, const double *b)
{
    double *c = a;
    *c = *a * *b;
    return a;
}
void *meanInt(const double *a, const int *b)
{
    double *c = a;
    *c = (*a + *b) / 2;
    return a;
}
void *meanDouble(const double *a, const double *b)
{
    double *c = a;
    *c = (*a + *b) / 2;
    return a;
}
void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *))
{
    double *init = initial_value;
    if (size == sizeof(int))
    {
        int *arr = base;
        for (int i = 0; i < n; i++)
        {
            init = opr(init, arr + i);
        }
    }
    else
    {
        double *arr = base;
        for (int i = 0; i < n; i++)
        {
            init = opr(init, arr + i);
        }
    }
    return init;
}
int main()
{
    int a[5] = {2, 4, 6, 8, 10};
    double b[5] = {2.5, 3.5, 4, 6.5, 10};
    int initSumInt = 0;
    double initSumDouble = 0;
    double initMulDouble = 1;
    int initMulInt = 1;
    double initMeanInt = 0;
    double initMeanDouble = 0;
    printf("Sum of ints: %d\n", *((int *)aggregate(a, sizeof(int), 5, &initSumInt, &AddInt)));
    printf("Multiplication of ints: %d\n", *((int *)aggregate(a, sizeof(int), 5, &initMulInt, &mulInt)));
    printf("Mean of ints: %f\n\n", *((double *)aggregate(a, sizeof(int), 5, &initMeanInt, &meanInt)));
    printf("Multiplication of doubles: %f\n", *((double *)aggregate(b, sizeof(double), 5, &initMulDouble, &mulDouble)));
    printf("Sum of doubles: %f\n", *((double *)aggregate(b, sizeof(double), 5, &initSumDouble, &addDouble)));
    printf("Mean of doubles: %f\n", *((double *)aggregate(b, sizeof(double), 5, &initMeanDouble, &meanDouble)));
    return 0;
}