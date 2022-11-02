#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int a, b, c;
	scanf("%d", &c);
	for (a = 1; a <= c; a++)
	{
		for (b = 1; b <= a; b++)
		{
			printf("%d*%d=%d ", a, b, a * b);
		}
		printf("\n");
	}
		return 0;
}
int panduan(int x)
{
	for (int i = 1; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int x;
	for (x = 100; x <= 200; x++)
	{
		if (panduan(x))
			printf("%d ", x);
	}
	return 0;
}