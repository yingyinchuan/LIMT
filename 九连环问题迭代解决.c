int F(int n)
{
	int count = 1;
	int sum = 0;
	if (n % 2 == 0)
	{
		for (int i = 1; i <= n + 1; i++)
		{
			count *= 2;
		}
		sum = (count - 2) / 3;
	}
	else
	{
		for (int i = 1; i <= n + 1; i++)
		{
			count *= 2;
		}
		sum = (count - 1) / 3;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("不允许一起卸下前两个环：%d 次\n", F(n));
	return 0;
}
