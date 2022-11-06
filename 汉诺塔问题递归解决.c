#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
 
int f(int i)
{
	if (i == 1)
		return 1;
	else
		return 1 + 2 * f(i - 1);
}
 
int main()
{
	int i;
	printf("请输入圆盘的个数：\n");
	scanf("%d", &i);
	printf("需要移动%d次\n", f(i));
	return 0;
}