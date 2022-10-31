#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int i,j,tmp;
	int a[10]={14,32,54,45,35,53,55,24,55,86};
	printf("原始数据:\n");
	for(i=0;i<10;i++)
	printf("%d ", a[i]);
	for (i = 0; i < 10 - 1; i++)
	{
		for (j = 0; j < 10 - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	printf("\n修改后的数据:\n");
	for (i = 0; i < 10; i++)
	printf("%d ", a[i]);
	return 0;
}
