#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int i, j = 1;
	int a[10];
	for (i = 0; i < 10; i++)
	{
		scanf("%d",&a[i]);
	}
	for (i = 0; i < 10; i++)
	{
		if (j < a[i])//������ֵ�洢����
		{
			j = a[i];
		}
	}
	printf("���ֵ�ǣ�%d ", j);
	return 0;
}
