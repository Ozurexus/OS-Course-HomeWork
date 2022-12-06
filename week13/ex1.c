#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *input;
    if (argc != 2)
    {
        printf("Incorrect number of arguments, exiting.\n");
        return 1;
    }
    input = fopen(argv[1], "r");
    char tmp[1024];
    int *E = malloc(sizeof(int) * 1024);
    int *A = malloc(sizeof(int) * 1024);
    int resources = 0;
    int counter = 0;
    int test[1024];
    fscanf(input, "%[^\n]", tmp); // scan the first line
    for (char *tok = strtok(tmp, " "); tok; tok = strtok(NULL, " "))
    { // parse the first line by spaces
        E[resources] = atoi(tok);
        resources++;
    }
    E = realloc(E, resources * sizeof(int)); // resize the array to the number of resources
    for (int i = 0; i < resources; i++)
        fscanf(input, "%d", &A[i]);
    A = realloc(A, resources * sizeof(int));
    while (!feof(input)) // scan the rest of the file
    {
        fscanf(input, "%s", tmp);
        test[counter] = atoi(tmp);
        counter++;
    }
    int processes = (counter - 1) / (2 * resources);
    int C[processes][resources], R[processes][resources]; // allocate the matrices
    for (int i = 0; i < processes; i++)                   // fill the matrices
    {
        for (int j = 0; j < resources; j++)
        {
            C[i][j] = test[i * resources + j];
            R[i][j] = test[i * resources + j + processes * resources];
        }
    }
    int sum = 0;
    for (int i = 0; i < resources; i++)
    {
        for (int j = 0; j < processes; j++)
        {
            sum += C[j][i];
        }
        if (sum > E[i])
        {
            printf("The sum of the C columns is greater than the E columns, exiting.\n");
            return 1;
        }
        else if (sum != A[i] + E[i])
        {
            printf("The sum of the C columns is not equal to the sum of the A and E columns, exiting.\n");
            return 1;
        }
        sum = 0;
    }
    int arr[processes];
    int flag;
    memset(arr, 0, processes * sizeof(int)); // initialize the array to 0
    while (1)
    {
        flag = 0;
        for (int i = 0; i < processes; i++)
        {
            if (arr[i] == 0)
            {
                int j;
                for (j = 0; j < resources; j++)
                {
                    if (R[i][j] > A[j])
                        break;
                }
                if (j == resources)
                {
                    for (int k = 0; k < resources; k++)
                        A[k] += C[i][k];
                    arr[i] = 1;
                    flag = 1;
                }
            }
        }
        if (!flag)
            break;
    }
    int deadlock = 0;
    for (int i = 0; i < processes; i++)
    {
        if (!arr[i])
        {
            deadlock = 1;
            printf("Process %d is deadlocked\n", i);
        }
    }
    if (!deadlock)
        printf("No deadlock detected\n");
    free(E);
    free(A);
    fclose(input);
    return 0;
}
