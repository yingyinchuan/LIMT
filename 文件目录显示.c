#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void listFiles(const char *path)
{
    DIR *directory = opendir(path);

    if (directory == NULL)
    {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;

    while ((entry = readdir(directory)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(directory);
}

int main()
{
    const char *path = "."; // 当前目录

    listFiles(path);

    return 0;
}