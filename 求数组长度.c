#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int my_strlen(char arr[])
{
	return (sizeof(arr) / sizeof(arr[0])-1);
}

int me_strlen(char* arr)
{
	if (*arr == '\0')
		return 0;
	else
		return 1 + me_strlen(arr + 1);
}

int main()
{
	char arr[] = "bit";
	printf("长度为：%d,%d", my_strlen(arr), me_strlen(arr));
		return 0;
}