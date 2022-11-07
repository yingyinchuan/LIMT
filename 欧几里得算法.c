#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else
	{
		int r = a % b;
		return GCD(b, r);
	}
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", GCD(a, b));
	return 0;
}