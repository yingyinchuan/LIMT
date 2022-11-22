int main()
{
	int k;
	int c;
	int flag = 1;
	scanf("%d ", &k);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &c);
			if ((j < i) && (c != 0))
				flag = 0;
		}
	}
	if (flag)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}