
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

// 定义消息结构体
struct msg_buffer
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msg_id;

    // 创建消息队列
    key = ftok("/tmp", 'a'); // 生成一个唯一的key
    msg_id = msgget(key, 0666 | IPC_CREAT);

    if (msg_id == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // 发送消息
    struct msg_buffer message;
    message.msg_type = 1;
    strcpy(message.msg_text, "Hello, Message Queue!");
    if (msgsnd(msg_id, &message, sizeof(message), 0) == -1)
    {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", message.msg_text);

    // 接收消息
    struct msg_buffer received_message;
    if (msgrcv(msg_id, &received_message, sizeof(received_message), 1, 0) == -1)
    {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("Message received: %s\n", received_message.msg_text);

    // 控制消息队列
    if (msgctl(msg_id, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Message queue deleted.\n");

    return 0;
}