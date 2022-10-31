#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<math.h>
int main()
{
	int i, j;
	int flag;
	for (i = 100; i <= 200; i+=2)//第一层循环，列出100到200之间的整数
	{
		flag = 1;//是否为素数的标记
		for (j = 1; j <= sqrt(i); j++)//第二层循环，试除法判断该数是否为素数
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d ", i);//打印素数
	}
}
