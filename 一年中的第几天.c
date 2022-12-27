int main()
{
	int year, month, day;
	scanf("%d %d %d", &year, &month, &day);
	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	for (int i = 0; i < month; i++)
	{
		sum += arr[i];
	}
	sum += day;
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month >= 3)
	{
		sum += 1;
	}
	printf("%d", sum);
	return 0;
}