int count_diff_bite(int n,int m)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((n >> i) & 1) != ((m >> i) & 1))
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n,m;
	scanf("%d %d", &n,&m);
	int count = count_diff_bite(n, m);
	printf("%d\n", count);
	return 0;
}