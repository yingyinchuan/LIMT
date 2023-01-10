char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* sp = NULL;
	char* cp = NULL;
	int n = 0;
	while ((cp = str2) && (sp = str1 + n++))
	{
		if (strlen(sp) < strlen(cp))
			return NULL;
		char* p = sp;
		while (true)
		{
			if (*sp == *cp)
				sp++, cp++;
			else
				break;
			if (!*cp)
				return p;
		}
	}
}