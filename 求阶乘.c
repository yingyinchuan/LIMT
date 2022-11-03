#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int X(int i)
{
	int sum=1,n=1;
	for (; n <= i; n++)
	{
		sum *= n;
	}
	return sum;
}
int x(int i)
{
	if (i == 1)
		return 1;
	else
		return i * x(i-1);
}
int main()
{
	int i;
	scanf("%d", &i);
	printf("%d,%d\n", x(i), X(i));
	return 0;
}