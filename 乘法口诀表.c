#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)//��ѭ��
	{
		for (j = 1; j <= i; j++)//��ѭ��
		{
			printf("%d*%d=%d  ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}
