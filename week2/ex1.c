#include <stdio.h>
#include <float.h>
#include <limits.h>
int main(void)
{
    int a = INT_MAX;
    unsigned short int b = USHRT_MAX;
    signed long int c = LONG_MAX;
    float d = FLT_MAX;
    double e = DBL_MAX;
    printf("int: size - %d, value - %d\n", (sizeof(a)), a);
    printf("unsigned short int: size - %d, value - %d\n", (sizeof(b)), b);
    printf("signed long int: size - %d, value - %li\n", (sizeof(c)), c);
    printf("float: size - %d, value - %f\n", (sizeof(d)), d);
    printf("double: size - %d, value - %lf\n", (sizeof(e)), e);
    return 0;
}
