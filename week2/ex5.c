#include <stdio.h>
int tribonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
    {
        return 1;
    }
    int i = 2;
    int t1 = 0;
    int t2 = 1;
    int t3 = 1;
    int t = 0;
    while (i < n)
    {
        t = t1 + t2 + t3;
        t1 = t2;
        t2 = t3;
        t3 = t;
        i++;
    }
    return t;
}
int main(void)
{
    int answer = tribonacci(4);
    int answer2 = tribonacci(36);
    printf("Tribonacci of 4: %d\nTribonacci of 36: %d", answer, answer2);
    return 0;
}