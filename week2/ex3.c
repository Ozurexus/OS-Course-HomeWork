#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int convert(int x, int s, int t)
{
    if (s > 10 || s < 2 || t > 10 || t < 2)
    {
        printf("cannot convert!");
        exit(0);
        return 0;
    }
    int y = 0; // x converted from s to decimal
    int i = 0;
    int z = 0; // x converted from decimal to t
    int multiplier = 1;
    while (x > 0)
    {
        y += (x % 10) * multiplier;
        multiplier *= s;
        i++;
        x = x / 10;
    }
    i = 0;
    multiplier = 1;
    while (y > 0)
    {
        z += (y % t) * multiplier;
        y = y / t;
        i++;
        multiplier *= 10;
    }
    return z;
}
int main(int argc, char *argv[])
{
    printf("%lli\n", convert(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
}
