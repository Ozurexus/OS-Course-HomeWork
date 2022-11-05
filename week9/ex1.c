#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) // check if the user entered the correct number of arguments
    {
        printf("Wrong number of arguments\n");
        return 1;
    }
    int frames = atoi(argv[1]), page, faults = 0, hits = 0, found, min, minIndex;
    unsigned int *page_table = (unsigned int *)malloc(frames * sizeof(int));
    unsigned int *age_table = (unsigned int *)malloc(999 * sizeof(int)); // 999 is the max number of pages
    FILE *input = fopen("Lab 09 input.txt", "r");
    for (int i = 0; i < frames; i++)
        page_table[i] = 0;
    for (int i = 0; i < 999; i++)
        age_table[i] = 0;
    while (fscanf(input, "%d", &page) != EOF) // while there is a new page to read
    {
        found = 0; // flag to check if the page is found in the page table
        for (int i = 0; i < frames; i++)
        {
            if (page == page_table[i]) // the page is found
            {
                hits++;
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            faults++;
            for (int i = 0; i < frames; i++)
            {
                if (page_table[i] == 0) // there is an empty frame in the page table
                {
                    page_table[i] = page;
                    found = 1;
                    break;
                }
            }
            if (found == 0) // there is no empty frames in the page table
            {
                min = __INT_MAX__; // the max value of an int
                minIndex = 0;
                for (int i = 0; i < frames; i++)
                {
                    if (age_table[page_table[i]] < min)
                    {
                        min = age_table[page_table[i]];
                        minIndex = i;
                    }
                }
                page_table[minIndex] = page;
            }
        }
        for (int i = 0; i < 999; i++) // aging the pages
            age_table[i] >>= 1;
        age_table[page] |= 1 << 31; // we will use 32 bits for saving the age
    }
    printf("Hits: %d, Misses: %d, Hit/Miss Ratio: %f\n", hits, faults, (float)hits / faults); // output for number of frames equal to 10,50 and 100 is also saved to the output.txt file
    free(page_table);
    free(age_table);
    fclose(input);
    return 0;
}
