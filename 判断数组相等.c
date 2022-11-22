int main()
{
	int n, m;
	int arr[n][m];//变长数组
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d ", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int input;
		for (int j = 0; j < m; j++)
		{
			scanf("%d ", &input);
			if (input != arr[i][j])
				printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}