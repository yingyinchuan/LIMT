#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<math.h>
int main()
{
	int i, j;
	int flag;
	for (i = 100; i <= 200; i+=2)//��һ��ѭ�����г�100��200֮�������
	{
		flag = 1;//�Ƿ�Ϊ�����ı��
		for (j = 1; j <= sqrt(i); j++)//�ڶ���ѭ�����Գ����жϸ����Ƿ�Ϊ����
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d ", i);//��ӡ����
	}
}
