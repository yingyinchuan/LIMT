void* my_memcpy(void* destin, void* source, unsigned int n)
{
	assert(destin && source);
	void* p = destin;
	while (n--)
	{
		*((char*)destin) = *((char*)source);
		destin = (char*)destin + 1;
		source = (char*)source + 1;
	}
	return p;
}