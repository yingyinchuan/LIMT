int main()
{
	int n = 0;
	int d = 0;
	while (scanf("%d %d", &n, &d) != EOF)
	{
		printf("%d\n", ((2 * 2 + (n - 1) * d) * n) / 2);
	}
	return 0;
}