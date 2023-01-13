#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void mune()
{
	printf("*****************************\n");
	printf("****** 1,add     2,del  *****\n");
	printf("****** 3,search  4,show *****\n");
	printf("****** 5,mod     6,sort *****\n");
	printf("****** 0,exit  (6δ����)*****\n");
	printf("*****************************\n");
}

int init(contact* p)
{
	assert(p);
	p->sz = 0;
	memset(p->data, 0, sizeof(p->data));
	return 0;
}

int exit(contact* p)
{
	printf("�˳�ͨѶ¼ϵͳ\n");
	return 0;
}

int add(contact* p)
{
	assert(p);
	if ((p->sz) >= 99)
	{
		printf("ͨѶ¼�������޷�����\n");
		return 0;
	}
	else
	{
		printf("����������->");
		scanf("%s", p->data[p->sz].name);
		printf("����������->");
		scanf("%d", &(p->data[p->sz].age));
		printf("���������->");
		scanf("%s", p->data[p->sz].phone);
		p->sz++;
	}
	return 0;
}

int del(contact* p)
{
	assert(p);
	printf("������Ҫɾ������ϵ������:>");
	char name[20];
	scanf("%s", name);
	int ret = findname(p, name);
	if (ret!=-1)
	{
		char arr1[20] = { 0 };
		char arr2[12] = { 0 };
		int i = 0;
		for (i = ret; i < p->sz - 1; i++)
		{
			p->data[i].age = p->data[i + 1].age;
			strcpy(p->data[i].name, p->data[i + 1].name);
			strcpy(p->data[i].phone, p->data[i + 1].phone);
		}
		p->data[p->sz - 1].age = 0;
		strcpy(p->data[p->sz - 1].name, arr1);
		strcpy(p->data[p->sz - 1].phone, arr2);
		p->sz--; printf("��ɾ����ϵ��\n");
	}
	else
	{
		printf("�����ڸ���ϵ��\n");
	}
	return 0;
}

int search(contact* p)
{
	assert(p);
	printf("������Ҫ���ҵ���ϵ������:>");
	char name[20];
	scanf("%s", name);
	int pos = findname(p, name);
	if (pos != -1)
	{
		printf("�ҵ���:\n����:%s\n����:%d\n�绰:%s\n",
			p->data[pos].name,
			p->data[pos].age,
			p->data[pos].phone);
	}
	else
	{
		printf("û���ҵ�����ϵ��\n");
	}
	return 0;
}

int show(contact* p)
{
	assert(p);
	if (p->sz)
	{
		printf("%-20s    %s    %-12s\n", "����", "����", "�绰");
		int i;
		for (i = 0; i < p->sz; i++)
		{
			printf("%-20s    %-3d    %-12s\n",
				p->data[i].name,
				p->data[i].age,
				p->data[i].phone);
		}
	}
	else
	{
		printf("��δ�����ϵ��\n");
	}

	return 0;
}

int mod(contact* p)
{
	assert(p);
	printf("������Ҫ��������ϵ������:>");
	char name[20];
	scanf("%s", name);
	int ret = findname(p, name);
	if (ret!=-1)
	{
		trim(p, ret);
	}
	else
	{
		printf("�����ڸ���ϵ��\n");
	}
	return 0;
}

int sort(contact* p)
{
	return 0;
}

int findname(contact* p, char* name)
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

int trim(contact* p, int ret)
{
	enum Trim
	{
		finish = 0,
		name = 1,
		age = 2,
		phonenumber = 3
	};
	int code;
	do
	{
		printf("\n");
		printf("����������ѡ��:> 1\n");
		printf("����������ѡ��:> 2\n");
		printf("�绰������ѡ��:> 3\n");
		printf("���������ѡ��:> 0\n");
		printf("\n");
		printf("��ѡ��:>");scanf("%d", &code);
		printf("\n");
		switch (code)
		{
		case name:
			printf("�������޸�:>");
			scanf("%s", p->data[ret].name);
			printf("�����ɹ�\n");
			break;
		case age:
			printf("�������޸�:>");
			scanf("%d", &p->data[ret].age);
			printf("�����ɹ�\n");
			break;
		case phonenumber:
			printf("�������޸�:>");
			scanf("%s", p->data[ret].phone);
			printf("�����ɹ�\n");
			break;
		case finish:
			printf("������޸�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (code);
	return 0;
}