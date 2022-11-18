#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>

void delete(int arr[], int del, int length)
{
	int i = 0;
	int j = 0;
	while (i < length)
	{
		if (arr[i] != del)
		{
			arr[j++] = arr[i];
			//arr[i]==*(arr+i)数组是对元素地址的解引用，操作的都是实参
		}
		i++;
	}
	while (j < length)
	{
		arr[j] = NULL;
		j++;
	}
}

int main()
{
	int arr1[] = { 4,4,4,4,4,4,4,8,9,10 };
	int arr2[] = { 4,4,4,4,5,3,2,8,9,10 };
	int length = sizeof(arr1) / sizeof(arr1[0]);
	int del = NULL;
	int i = 0;
	int j = 0;
	int x = 0;
	scanf("%d", &del);
	for (i; i < length; i++ )
	{
		if (arr1[i] != del)
		{
			arr1[j++] = arr1[i];
		}
	}
	while (j < length)
	{
		arr1[j] = NULL;
		j++;
	}
	while (x < length)
	{
		printf("%d ", arr1[x++]);	
	}
	printf("\n");
	delete(arr2, del, length);
	x = 0;
	while (x < length)
	{
		printf("%d ", arr2[x++]);
	}
	printf("\n");
	return 0;
}