int count_diff_bite(int n,int m)
{
	int l = n ^ m;
	int count = 0;
	while (l)
	{
		l = l & (l - 1);
		count++;
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