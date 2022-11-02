#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int left, right, mid, key, flag = 0;
	int arr[10]={21,76,47,89,35,67,65,86,35,28};
	int i, j, tmp;
	for (i = 0; i < 10 - 1; i++)
	{
		for (j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	left = 0, right = 9;
	printf("请输入要查找的数据：\n");
	scanf("%d", &key);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (key == arr[mid])
		{
			flag = 1;
			break;
		}
		else if (key > arr[mid])
		{
			left = mid + 1;
		}
		else if (key < arr[mid])
		{
			right = mid - 1;
		}
	}
	if (flag)
	{
		printf("找到了，下标是：%d ", mid);
	}
	else
	{
		printf("没有找到");
	}
	return 0;
}