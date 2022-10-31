#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int i, j;
	for (i = 1000; i <= 2000; i += 4)
	{
		if (i % 4 == 0)
		{
			if (i % 100 != 0)
				printf("%d ", i);
		}
		if (i % 400 == 0)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
