int n(int x, int i, int weight)
{

	if (x == 1)
		return i;
	else
		return i + weight * n(x - 1, i, weight);
}

int main()
{
	int i;
	int item = 0;
	int Sn = 0;
	int weight = 1;
	scanf("%d", &i);
	int y = i;
	while (y)
	{
		item++;
		y /= 10;
	}
	while (item)
	{
		weight *= 10;
		item--;
	}
	printf("%d\n", weight);
	for (int x = 1; x <= 5; x++)
	{
		printf("%d+", n(x,i,weight));
		Sn += n(x,i,weight);
	}
	printf("\n");
	printf("=%d\n", Sn);
	return 0;
}