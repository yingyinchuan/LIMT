void invert(int arr[], int sz)
{
	int* arry = (int*)malloc(sz * sizeof(int));
	for (int k = 0, i = 0, j = sz - 1; k < sz; k++)
	{
		if (arr[k] % 2 != 0)
		{
			arry[i++] = arr[k];
		}
		else
		{
			arry[j--] = arr[k];
		}
	}
	for (int i = 0; i < sz; i++)
	{
		arr[i] = arry[i];
	}
	free(arry);
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	invert(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}