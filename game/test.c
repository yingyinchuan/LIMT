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
	init_board(arr, ROW, COL);//初始化棋盘
	print_board(arr, ROW, COL);//打印棋盘

	while (1)
	{
		player(arr, ROW, COL);//玩家下棋
		system("cls");
		print_board(arr, ROW, COL);
		ret = who_win(arr, ROW, COL);//判断输赢
		if (ret != 'C')
		{
			break;
		}
		computer(arr, ROW, COL);//电脑下棋
		system("cls");
		print_board(arr, ROW, COL);
		ret = who_win(arr, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢\n");
	if (ret == '#')
		printf("电脑赢\n");
	if (ret == 'Q')
		printf("平局啦\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
}