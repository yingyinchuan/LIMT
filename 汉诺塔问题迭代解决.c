#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
 
int f(int i)
{
	int tmp = 1;
	for (int j = 1; j <= i; j++)
	{
		tmp *= 2;
	}
	return tmp - 1;
}
 
int main()
{
	int i;
	printf("请输入圆盘的个数：\n");
	scanf("%d", &i);
	printf("需要移动%d次\n", f(i));
	return 0;
}