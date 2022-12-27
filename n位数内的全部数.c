int main()
{
	int a = 0;
	scanf("%d", &a);
	int tmp = 1;
	for (int i = 0; i < a; i++)
	{
		tmp *= 10;
	}
	for (int i = 1; i <= tmp - 1; i++)
	{
		printf("%d ", i);
	}
	return 0;
}