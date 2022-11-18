int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int i;
	int count = 0;
	while (scanf("%d ", &i) != EOF)
	{
		//if (i > 0)
			count += i;
	}
	printf("%d", count);
	return 0;
}