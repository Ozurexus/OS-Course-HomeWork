#include <stdio.h>
int main(void)
{
    int i;
    while (i < 4)
    {
        printf("\nChoose the pattern:\n 1 for half of triangle, 2 for arrow, 3 for rectangle or 4 to exit\n");
        scanf("%d", &i);
        if (i == 1)
            printf("*\n**\n***\n****\n*****\n******");
        if (i == 2)
            printf("*\n**\n***\n****\n***\n**\n*");
        if (i == 3)
            for (int j = 0; j < 7; j++)
            {
                printf("*******\n");
            }
    }
    return 0;
}