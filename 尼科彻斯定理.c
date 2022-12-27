void nike(int n)
{
	for (int sum = 0,x = n * n - n + 1; sum <= n*n*n; x += 2, sum += x)
	{
		printf("%d", x);
		if (sum+x+2<=n*n*n)
		{
			printf("+");
		}
	}
}

int main()
{
	int tmp;
	while (scanf("%d", &tmp) != EOF)
	{
		nike(tmp);
		printf("\n");
	}
	return 0;
}