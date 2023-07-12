#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Directory;
struct File;
int IDcount = 0;
struct File
{
    int id;
    char name[64];
    int size;
    char data[1024];
    struct Directory *directory;
};
struct Directory
{
    int nf;
    int nd;
    struct File *files[10];
    struct Directory *directories[8];
    char path[2048];
};
typedef struct Directory Directory;
typedef struct File File;

void create_file(File *file, const char *name)
{
    file->id = IDcount;
    IDcount++;
    strcpy(file->name, name);
    strcpy(file->data, "");
    file->size = 0;
}
void create_directory(Directory *dir, const char *name)
{
    dir->nd = 0;
    dir->nf = 0;
    strcpy(dir->path, "/");
    strcat(dir->path, name);
}
void show_dir(Directory *dir)
{
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++)
    {
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");

    for (int i = 0; i < dir->nd; i++)
    {
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}
void show_file(File *file)
{
    printf("%s ", file->name);
}
void show_file_detailed(File *file)
{
    printf("\nFILE %s\n", file->name);
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}
void add_to_file(File *file, const char *content)
{
    strcpy(file->data, content);
    file->size = strlen(file->data) + 1;
}
void append_to_file(File *file, const char *content)
{
    strcat(file->data, content);
    file->size = strlen(file->data) + 1;
}
void pwd_file(File *file)
{
    printf("The path for the %s file is %s/%s\n", file->name, file->directory->path, file->name);
}
void add_file(File *file, Directory *dir)
{
    if (dir && file)
    {
        dir->files[dir->nf] = file;
        file->directory = dir;
        dir->nf++;
    }
}
void add_dir(Directory *dir1, Directory *dir2)
{
    if (dir1 && dir2)
    {
        strcat(dir1->path, dir2->path);
        dir2->directories[dir2->nd] = dir1;
        dir2->nd++;
    }
}
int main()
{
    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";
    Directory home, bin, root;
    create_directory(&home, "home");
    create_directory(&bin, "bin");
    create_directory(&root, "root");
    File bash, ex31, ex32;
    create_file(&bash, "bash");
    create_file(&ex31, "ex31");
    create_file(&ex32, "ex32");
    add_dir(&home, &root);
    add_dir(&bin, &root);
    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32, &home);
    add_to_file(&ex31, &content1);
    add_to_file(&ex32, &content3);
    add_to_file(&bash, &content4);
    append_to_file(&ex31, content2);
    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);
    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);
    return EXIT_SUCCESS;
}