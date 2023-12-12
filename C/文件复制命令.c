#include <stdio.h>
#include <stdlib.h>

void copyFile(const char *source, const char *destination)
{
    FILE *sourceFile = fopen(source, "rb");           // 以二进制读取模式打开源文件
    FILE *destinationFile = fopen(destination, "wb"); // 以二进制写入模式创建目标文件

    if (sourceFile == NULL || destinationFile == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0)
    {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);
}

int main()
{
    const char *sourceFile = "source.txt";
    const char *destinationFile = "destination.txt";

    copyFile(sourceFile, destinationFile);

    return 0;
}