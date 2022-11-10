#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define NUM 20

void initboard(char arr[ROWS][COLS], int row, int col, char set);

void display(char arr[ROWS][COLS], int row, int col);

void setmine(char arr[ROWS][COLS], int row, int col);

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

int get_mine_num(char mine[ROWS][COLS], int x, int y);
