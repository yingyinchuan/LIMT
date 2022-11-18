int main()
{
	int i, j;
	scanf("%d %d", &i, &j);
	int arr[i][j];
	int x;
	for (int n = 0; n < i; n++)
	{
		for (int m = 0; m < j; m++)
		{
			scanf("%d ", &x);
			arr[n][m] = x;
		}
	}
	for (int n = 0; n < j; n++)
	{
		for (int m = 0; m < i; m++)
		{
			printf("%d ", arr[m][n]);
		}
		printf("\n");
	}
	return 0;
}