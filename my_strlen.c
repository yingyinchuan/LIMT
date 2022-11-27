int my_strlen(char* arr)
{
	char* oec = arr;
	while (*arr++);
	return arr - oec - 1;
}

int main()
{
	char arr[] = "abcdefjhijklmnopqrstuvwxyz";
	printf("%d", my_strlen(arr));
	return 0;
}
