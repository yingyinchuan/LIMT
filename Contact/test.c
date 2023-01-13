#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

int main()
{
	int input;
	int (*choose[7])(contact * p) = { exit,add,del,search,show,mod,sort };//函数指针数组
	contact cp;
	init(&cp);//初始化
	do
	{
		mune();//输出菜单
		printf("请输入要选择的选项->");
		int c = scanf("%d", &input);
		if (input < 6 && input >= 0)//输入判断
		{
			choose[input](&cp);//函数调用
		}
		else
		{
			printf("输入错误请重新选择:>\n");
		}
	} while (input);
	return 0;
}