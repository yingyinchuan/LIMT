int binaryNumOF1(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

int main()
{
	int i; scanf("%d", &i);
	if (binaryNumOF1(i) == 1)
	{
		printf("是");
	}
	else
	{
		printf("不是");
	}
	return 0;
}