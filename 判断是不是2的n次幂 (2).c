int main()
{
	int n; scanf("%d", &n);
	if ((n&(n-1)) == 0)
	{
		printf("是");
	}
	else
	{
		printf("不是");
	}
	return 0;
}