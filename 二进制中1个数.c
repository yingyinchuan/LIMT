int binaryNumOF1(int n)
{
	int count;
	while (n)
	{
		if (n % 2 != 0)
		{
			count++;
		}
		n /= 2;
	}
	return 0;
}