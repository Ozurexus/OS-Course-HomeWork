#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    struct dirent *d;
    struct stat *s;
    int counter = 0;
    int occurences;
    int *inodes = malloc(sizeof(int) * 512);
    char **names = malloc(sizeof(char) * 512);
    DIR *directory = opendir("tmp");
    FILE *file = fopen("ex4.txt", "w");
    fprintf(file, "File - Hard Links\n");
    while ((d = readdir(directory)) != 0)
    {
        stat(d->d_name, s);
        names[counter] = d->d_name;
        inodes[counter] = d->d_ino;
        counter++;
    }
    for (int i = 0; i < counter; i++)
    {
        occurences = 0;
        for (int j = 0; j < counter; j++)
        {
            if (inodes[i] == inodes[j])
                occurences++;
        }
        if (occurences >= 2 && strcmp(names[i], ".") != 0 && strcmp(names[i], "..") != 0)
        {
            fprintf(file, "%s - ", names[i]);
            for (int j = 0; j < counter; j++)
            {
                if (inodes[i] == inodes[j] && names[i] != names[j])
                    fprintf(file, "%s ", names[j]);
            }
            fprintf(file, "\n");
        }
    }
    closedir(directory);
    return 0;
}
