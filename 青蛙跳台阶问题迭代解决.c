#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
 
int jump(int i)
{
	int a = 1;
	int b = 2;
	int c = 3;
	if (i <= 2)
	{
		return i;
	}
	else
	{
		while (i > 2)//为什么这里的判断条件是这样？
		//因为最开始的俩数是固定的不是相加得到的，所以我们求n个数只需要n-2次相加
		//1,2,3(第3个数,第1次相加),5(第4个数,第2次相加),8(第5个数,第3次相加)
		//所以第n个数是由n-2次相加得到的(完美)
		{
			c = a + b;
			a = b;
			b = c;
			i--;
		}
		return c;
	}
}
 
int main()
{
	int i;
	printf("请输入青蛙跳的台阶数：\n");
	scanf("%d", &i);
	printf("有%d种跳法", jump(i));
	return 0;
}