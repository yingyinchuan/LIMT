typedef struct stu
{
	char name[20];
	int age;
	int num;
}x;

int cmp(const void* a,const void* b)
{
	return ((x*)a)->num - ((x*)b)->num;
}

void my_qsort(void* s, int n, int m, int(*cmp)(const void* a, const void* b))
{
	char* p = (char*)s;
	char tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (cmp(p + j * m, p + (j + 1) * m) > 0)
			{
				int k = 0;
				while (k < m)
				{
					tmp = (p + j * m)[k];
					(p + j * m)[k] = (p + (j + 1) * m)[k];
					(p + (j + 1) * m)[k] = tmp;
					k++;
				}
			}
		}
	}
}
int main()
{
	struct stu xyz[3] = 
	{
		{"zhangsan",20,67},
		{"lisi",41,46},
		{"wangwu",32,77}
	};
	my_qsort(xyz, sizeof(xyz) / sizeof(xyz[0]), sizeof(xyz[0]), cmp);
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", xyz[i].name);
	}
	return 0;
}