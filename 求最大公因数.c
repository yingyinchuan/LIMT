#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int a, b, c, d, e;
	scanf("%d %d", &a, &b);
	while (c = a % b)//辗转相除法
	{
		a = b;
		b = c;
	}
	printf("\n%d \n", b);
	scanf("%d %d", &d, &e);//辗转相减法
	while (d != e)
	{
		if (d > e)
			d = d - e;
		if (e > d)
			e = e - d;
	}
	printf("\n%d \n", d);
	return 0;
}
