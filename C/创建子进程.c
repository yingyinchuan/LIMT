#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // 使用fork创建新进程
    pid_t pid = fork();

    if (pid < 0) {
        // 创建进程失败
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // 在子进程中执行命令
        char *command = "ls";
        char *args[] = {"ls", "-l", NULL};

        // 使用exec函数族执行命令
        execvp(command, args);

        // 如果exec函数族执行失败，打印错误信息
        perror("exec failed");
        exit(EXIT_FAILURE);
    } else {
        // 在父进程中等待子进程结束
        waitpid(pid, NULL, 0);
        printf("父进程执行完毕\n");
    }

    return 0;
}