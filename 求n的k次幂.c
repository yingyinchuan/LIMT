#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	unsigned int n, k;
	scanf("%d,%d", &n, &k);
	printf("%d的%d次幂是：%lld", n, k, power(n, k));
	return 0;
}