#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

int main()
{
	int input;
	int (*choose[7])(contact * p) = { exit,add,del,search,show,mod,sort };//����ָ������
	contact cp;
	init(&cp);//��ʼ��
	do
	{
		mune();//����˵�
		printf("������Ҫѡ���ѡ��->");
		int c = scanf("%d", &input);
		if (input < 6 && input >= 0)//�����ж�
		{
			choose[input](&cp);//��������
		}
		else
		{
			printf("�������������ѡ��:>\n");
		}
	} while (input);
	return 0;
}