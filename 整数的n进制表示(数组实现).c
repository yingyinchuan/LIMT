int main()
{
	int i, j;
	int arr[20];
	int flag = 1;
	int x = 0;
	scanf("%d", &i, &j);
	while (flag)
	{
		if (i / j == 0)//需要判断一次真假要执行一次的写法
		{
			flag = 0;
		}
		arr[x++] = i % j;
		i /= j;
	}
	for (--x; x >= 0; x--)
	{
		printf("%d", arr[x]);
	}
	return 0;
}