#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int i,j,tmp;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
			printf("%d ", i);

	}
	return 0;
}
