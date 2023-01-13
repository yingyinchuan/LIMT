#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void mune()
{
	printf("*****************************\n");
	printf("****** 1,add     2,del  *****\n");
	printf("****** 3,search  4,show *****\n");
	printf("****** 5,mod     6,sort *****\n");
	printf("****** 0,exit  (6未开发)*****\n");
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
	printf("退出通讯录系统\n");
	return 0;
}

int add(contact* p)
{
	assert(p);
	if ((p->sz) >= 99)
	{
		printf("通讯录以满，无法输入\n");
		return 0;
	}
	else
	{
		printf("请输入姓名->");
		scanf("%s", p->data[p->sz].name);
		printf("请输入年龄->");
		scanf("%d", &(p->data[p->sz].age));
		printf("请输入号码->");
		scanf("%s", p->data[p->sz].phone);
		p->sz++;
	}
	return 0;
}

int del(contact* p)
{
	assert(p);
	printf("请输入要删除的联系人姓名:>");
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
		p->sz--; printf("已删除联系人\n");
	}
	else
	{
		printf("不存在该联系人\n");
	}
	return 0;
}

int search(contact* p)
{
	assert(p);
	printf("请输入要查找的联系人姓名:>");
	char name[20];
	scanf("%s", name);
	int pos = findname(p, name);
	if (pos != -1)
	{
		printf("找到了:\n姓名:%s\n年龄:%d\n电话:%s\n",
			p->data[pos].name,
			p->data[pos].age,
			p->data[pos].phone);
	}
	else
	{
		printf("没有找到该联系人\n");
	}
	return 0;
}

int show(contact* p)
{
	assert(p);
	if (p->sz)
	{
		printf("%-20s    %s    %-12s\n", "姓名", "年龄", "电话");
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
		printf("尚未添加联系人\n");
	}

	return 0;
}

int mod(contact* p)
{
	assert(p);
	printf("请输入要修正的联系人姓名:>");
	char name[20];
	scanf("%s", name);
	int ret = findname(p, name);
	if (ret!=-1)
	{
		trim(p, ret);
	}
	else
	{
		printf("不存在该联系人\n");
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
		printf("姓名修正请选择:> 1\n");
		printf("年龄修正请选择:> 2\n");
		printf("电话修正请选择:> 3\n");
		printf("完成修正请选择:> 0\n");
		printf("\n");
		printf("请选择:>");scanf("%d", &code);
		printf("\n");
		switch (code)
		{
		case name:
			printf("请输入修改:>");
			scanf("%s", p->data[ret].name);
			printf("修正成功\n");
			break;
		case age:
			printf("请输入修改:>");
			scanf("%d", &p->data[ret].age);
			printf("修正成功\n");
			break;
		case phonenumber:
			printf("请输入修改:>");
			scanf("%s", p->data[ret].phone);
			printf("修正成功\n");
			break;
		case finish:
			printf("已完成修改\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (code);
	return 0;
}