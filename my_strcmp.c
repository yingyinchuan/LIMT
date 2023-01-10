int my_strcmp(const char* str1,const char* str2)
{
	assert(str1 && str2);
	while (true)
	{
		if (*str1 == *str2 && (*str1 != 0 || *str2 != 0))
		{
			str1++, str2++;
		}
		else
		{
			return *str1 - *str2;
		}
	}
}