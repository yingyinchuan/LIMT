int main()
{
	int num;
	scanf("%d", &num);
	int x = num / 2 + 1;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= x - i; j++)
		{
			printf("  ");
		}
		for (int k = 1; k <= (i * 2 - 1); k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for (int i = x - 1; i >= 1; i--)
	{
		for (int j = 1; j <= x - i; j++)
		{
			printf("  ");
		}
		for (int k = 1; k <= (i * 2 - 1); k++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}