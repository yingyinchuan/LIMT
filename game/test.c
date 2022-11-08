#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game.h"

void menu()
{
	printf("*****************\n");
	printf("** 1,play game **\n");
	printf("** 0,exit game **\n");
	printf("*****************\n");
}

void game()
{
	char arr[ROW][COL];
	char ret = 0;
	init_board(arr, ROW, COL);//��ʼ������
	print_board(arr, ROW, COL);//��ӡ����

	while (1)
	{
		player(arr, ROW, COL);//�������
		system("cls");
		print_board(arr, ROW, COL);
		ret = who_win(arr, ROW, COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		computer(arr, ROW, COL);//��������
		system("cls");
		print_board(arr, ROW, COL);
		ret = who_win(arr, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ\n");
	if (ret == '#')
		printf("����Ӯ\n");
	if (ret == 'Q')
		printf("ƽ����\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
}