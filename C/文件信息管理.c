#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertInfo(const char *filename, const char *info)
{
    FILE *file = fopen(filename, "a"); // 以追加模式打开文件

    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s\n", info);

    fclose(file);
}

void deleteInfo(const char *filename, const char *target)
{
    FILE *tempFile = fopen("temp.txt", "w"); // 创建一个临时文件
    FILE *file = fopen(filename, "r");

    if (tempFile == NULL || file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strstr(line, target) == NULL)
        {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);             // 删除原文件
    rename("temp.txt", filename); // 重命名临时文件为原文件名
}

int main()
{
    const char *filename = "example.txt";

    // 插入信息
    insertInfo(filename, "New Information 1");
    insertInfo(filename, "New Information 2");

    // 删除信息
    deleteInfo(filename, "New Information 1");

    return 0;
}
