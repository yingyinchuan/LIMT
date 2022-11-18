int main()
{
	int i;
	int arr[20];
	int flag = 1;
	int x = 0;
	scanf("%d", &i);
	while (flag)
	{
		if (i / 6 == 0)//需要判断一次真假要执行一次的写法
		{
			flag = 0;
		}
		arr[x] = i % 6;
		x++;
		i /= 6;
	}
	for (int j = x - 1; j >= 0; j--)
	{
		printf("%d", arr[j]);
	}
	return 0;
}