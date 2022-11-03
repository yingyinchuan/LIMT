#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int Fic(int i)
{
	int a=1, b=1, c=1;
	while (i>2)
	{
		c = a + b;
		a = b;
		b = c;
		i--;
	}
	return c;
}

int fic(int i)
{
	if (i <= 2)
		return 1;
	else
		return fic(i - 1) + fic(i - 2);
}

int main()
{
	int i, j;
	while(scanf("%d", &i))
	printf("%-2d %-2d\n", fic(i),Fic(i));
	return 0;
}