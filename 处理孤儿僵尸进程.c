#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    // 进程同步：互斥锁
    printf("进程同步：互斥锁\n");

    pid_t sync_pid = fork();

    if (sync_pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (sync_pid == 0)
    {
        // 子进程
        printf("子进程执行\n");

        // 这里可以放一些需要同步的代码，比如使用互斥锁

        printf("子进程执行完毕\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        // 父进程等待子进程结束
        waitpid(sync_pid, NULL, 0);
        printf("父进程执行完毕\n");
    }

    // 孤儿进程
    printf("\n孤儿进程\n");

    pid_t orphan_pid = fork();

    if (orphan_pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (orphan_pid == 0)
    {
        // 子进程
        printf("子进程执行\n");
        sleep(2); // 让父进程先结束

        printf("子进程执行完毕\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("父进程执行完毕\n");
        // 不等待子进程，子进程会变成孤儿进程
    }

    // 僵尸进程
    printf("\n僵尸进程\n");

    pid_t zombie_pid = fork();

    if (zombie_pid < 0)
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (zombie_pid == 0)
    {
        // 子进程
        printf("子进程执行\n");
        printf("子进程执行完毕\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        // 父进程不等待子进程
        printf("父进程执行完毕\n");
    }

    // 等待一段时间，让子进程成为僵尸进程
    sleep(5);

    // 父进程主动等待子进程，回收子进程资源
    waitpid(zombie_pid, NULL, 0);
    printf("父进程执行完毕\n");

    return 0;
}