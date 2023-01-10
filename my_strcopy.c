void my_strcopy(char* str1,const char* str2)
{
	assert(str1 && str2);
	bool flag = true;
	while (flag)
	{
		*str1 = *str2;
		if (!(*str1 && *str2))
		{
			flag = !flag;
		}
		str1++, str2++;
	}
}