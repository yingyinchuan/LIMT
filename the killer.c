int main()
{
	char killer = 'A';
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			break;
		}
	}
	printf("凶手是:%c", killer);
	return 0;
}