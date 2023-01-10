int my_memcmp(const void* prt1,const void* prt2,size_t num)
{
	assert(prt1 && prt2);
	char* cp = (char*)prt1;
	char* sp = (char*)prt2;
	while (num--)
	{
		if (*cp == *sp)
		{
			cp++, sp++;
		}
		else
		{
			return *cp - *sp;
		}
	}
}