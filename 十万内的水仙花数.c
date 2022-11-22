int power(long int k, int n)
{
	long int tmp = 1;
	while (n)
	{
		tmp *= k;
		n--;
	}
	return tmp;
}

int main()
{
	for (long int i = 0; i < 100000; i++)
	{
		int n = 0;
		long int j = i;
		while (j)//计算数字位数
		{
			j /= 10;
			n++;
		}
		long int k = i;
		long int sum = 0;
		while (k)
		{
			sum += power(k % 10, n);
			k /= 10;
		}
		if (sum == i)//判断是否为水仙花数
		{
			printf("%d\n", i);
		}
	}
	
	return 0;
}