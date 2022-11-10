#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game2.h"


void initboard(char arr[ROWS][COLS], int row, int col, char set)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = set;
		}
	}
}

void display(char arr[ROWS][COLS],int row,int col)
{
	printf("----------------------\n");
	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("----------------------\n");

}

void setmine(char arr[ROWS][COLS], int row, int col)
{
	int count = NUM;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}

	
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	while (win < (row * col - NUM))
	{
		printf("请输入要排除的坐标:>\n每输入一个数字敲击一次空格\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= 9 && y > 0 && y <= 9)
		{
			if (show[x][y] != '*')
			{
				printf("重复输入，请重新输入\n");
				continue;
			}
			if (mine[x][y] != '1')
			{
				show[x][y] = get_mine_num(mine, x, y) + '0';
				system("cls");
				display(show, row, col);
				win++;
				if (win == (row * col - NUM))
				{
					system("cls");
					printf("扫雷成功！\n");
					break;
				}

			}
			else
			{
				system("cls");
				printf("你被炸死了！\n");
				display(mine, row, col);
				break;
			}
		}
		else
		{
			printf("坐标非法\n重新输入\n");
		}
	}
}

int get_mine_num(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] +
		mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
}