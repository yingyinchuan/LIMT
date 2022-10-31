#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)//列循环
	{
		for (j = 1; j <= i; j++)//行循环
		{
			printf("%d*%d=%d  ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}
