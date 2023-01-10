char* my_strcat(char* dest, const char* src)
{
	char* p = dest;
	while (*p)
	{
		p++;
	}
	bool flag = true;
	while (flag)
	{
		*p = *src;
		if (*src == 0)
		{
			flag = !flag;
		}
		p++, src++;
	}
	return dest;
}