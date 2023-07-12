#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir("/");
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] == '.')
            continue;
        printf("%s ", entry->d_name);
    }
    printf("%s", "\n");
    closedir(dir);
    return 0;
}