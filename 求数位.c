#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>

int print(int x)
{
	if (x <= 9)
		return x;
	else
	{
		printf("%d ", print(x / 10));
		return x % 10;
	}
}


int main()
{
	int x;
	scanf("%d", &x);
	printf("%d ", print(x));
	return 0;
}
long long int power(int n, int k)
{
	if (k == 0)
		return 1;
	else
		return n * power(n, k - 1);
}