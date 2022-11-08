#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game.h"

void init_board(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void print_board(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void player(char arr[ROW][COL], int row, int col)
{
	printf("玩家下棋\n");
	while (1)
	{
		printf("输入坐标\n");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col && arr[x - 1][y - 1] == ' ')
		{
			arr[x - 1][y - 1] = '*';
			break;
		}
		else
		{
			printf("输入错误\n");
		}
	}
}

void computer(char arr[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (x > 0 && x <= row && y > 0 && y <= col && arr[x - 1][y - 1] == ' ')
		{
			arr[x - 1][y - 1] = '#';
			break;
		}
	}
}

static int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char who_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断三行
	for (i = 0; i < row; i++)
	{
		char flag = 1;
		for (int j = 0; j < row; j++)
		{
			if (board[i][j] != board[i][0] || board[i][0] == ' ')
			{
				flag = 0;
			}
		}
		if (flag)
		{
			return board[i][0];
		}
	}
	//判断三列
	for (i = 0; i < col; i++)
	{
		char flag = 1;
		for (int j = 0; j < col; j++)
		{
			if (board[j][i] != board[0][i] || board[0][i] == ' ')
			{
				flag = 0;
			}
		}
		if (flag)
		{
			return board[0][i];
		}
	}
	//对角线
	if (1)
	{
		char flag = 1;
		for (int i = 0; i < col; i++)
		{
			if (board[i][i] != board[0][0] || board[0][0] == ' ')
			{
				flag = 0;
			}
		}
		if (flag)
		{
			return board[0][0];
		}
	}
	if (1)
	{
		char flag = 1;
		for (int i = 0; i < col; i++)
		{
			if (board[i][col - 1 - i] != board[0][col - 1] || board[0][col - 1] == ' ')
			{
				flag = 0;
			}
		}
		if (flag)
		{
			return board[0][col - 1];
		}
	}
	//平局
	if (is_full(board, row, col) == 1)
	{
		return 'Q';
	}
	return 'C';
}
