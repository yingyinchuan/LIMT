#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game2.h"

void menu()
{
	printf("****************************\n");
	printf("******** 1,play game *******\n");
	printf("******** 0,exit game *******\n");
	printf("****************************\n");
	
}

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	display(show, ROW, COL);
	setmine(mine, ROW, COL);
	//display(mine, ROW, COL);
	findmine(mine, show, ROW, COL);

}

void test()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("欢迎来到扫雷游戏\n请选择以上选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default :
			printf("输入错误\n重新输入\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}