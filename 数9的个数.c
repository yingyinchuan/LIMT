#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			j++;//��λ��9������
		}
		if (i / 10 == 9)
		{
			j++;//ʮλ��9�ĸ���
		}
	}
	return 0;
}
