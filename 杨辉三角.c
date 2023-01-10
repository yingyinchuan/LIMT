int main()
{
	int num;
	scanf("%d", &num);
	int arr[100][100] = { 0 };
	for (int i = 0; i < num; i++)
	{
		arr[i][0] = 1;
	}
	for (int i = 1; i < num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}