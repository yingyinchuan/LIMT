void print(int n)
{
	//奇数位
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	//偶数位
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

int main()
{
	int n,m;
	scanf("%d", &n);
	print(n);
	return 0;
}