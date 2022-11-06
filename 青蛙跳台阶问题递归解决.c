#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
 
int jump(int i)
{
	if (i <= 2)
	{
		return i;
	}
	else
	{
		return jump(i - 1) + jump(i - 2);
	}
}
 
int main()
{
	int i;
	printf("请输入青蛙跳的台阶数：\n");
	scanf("%d", &i);
	printf("有%d种跳法", jump(i));
	return 0;
}