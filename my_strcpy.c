char* my_strcpy(char* arr, const char* arry)
{
	char* oec = arr;
	while (*arr++ = *arry++);
	return oec;
}

int main()
{
	char arr[100];
	char arry[] = "abcdefjhijklmnopqrstuvwxyz";
	printf("%s\n", my_strcpy(arr, arry));
	return 0;
}