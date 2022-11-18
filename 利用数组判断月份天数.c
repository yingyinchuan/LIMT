int get_days_of_month(int y, int m)
{
    int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int day = days[m];
    if ((m == 2) && (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)))
    {
        day++;
    }
    return day;
}

int main()
{
	int n,m;
	scanf("%d %d", &n,&m);
    printf("%d", get_days_of_month(n, m));
	return 0;
}