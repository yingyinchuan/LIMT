void* my_memmove(void* dest, void* src, size_t n)
{
	assert(dest && src);
	void* p = dest;
	if (dest < src)
	{
		while (n--)
		{
			*((char*)dest) = *((char*)src);
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (n--)
		{
			((char*)dest)[n] = ((char*)src)[n];
		}
	}
	return p;
}