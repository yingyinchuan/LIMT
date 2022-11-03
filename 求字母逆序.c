#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
void print(char* arr)
{
	if (*arr == '\0')
		printf("%c", *arr);
	else
		print(arr + 1);
		printf("%c", *arr);
}

int main()
{
	char arr[] = "abcdefghijklmnopqrstuvwxyz";
	print(arr);
	return 0;
}