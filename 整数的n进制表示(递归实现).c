void print(int i,int j)
{
	if (i / j != 0)
	{
		print(i / j, j);
	}
	printf("%d", i % j);
}

int main()
{
	int n,m;
	scanf("%d %d", &n,&m);
    print(n,m);
	return 0;
}