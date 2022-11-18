int F_2(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return 2 * F_2(n - 2) + 1 + F_2(n - 1);
	}
}

int F(int n)
{
	if (n == 2)
	{
		return 1;
	}
	else
	{
		return 2 * F(n - 2) + 1 + F(n - 1);
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	printf("允许一起卸下前两个环：%d 次\n", F(n));
	printf("不允许一起卸下前两个环：%d 次\n", F_2(n));
	return 0;
}