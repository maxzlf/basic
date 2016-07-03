#include <stdio.h>

void vchar()
{
	char c = 0;
	while (++c > --c)
	{
		++c;
	}
	printf("max value of char %d\n", c);
	printf("min value of char %d\n", ++c);
	printf("size of char %d\n", sizeof(c));
}

void vshort()
{
	short s = 0;
	while (++s > --s)
	{
		++s;
	}
	printf("max value of short %d\n", s);
	printf("min value of short %d\n", ++s);
	printf("size of short %d\n", sizeof(s));
}

void vint()
{
	int v = 0;
	while (++v > --v)
	{
		++v;
	}
	printf("max value of int %d\n", v);
	printf("min value of int %d\n", ++v);
	printf("size of int %d\n", sizeof(v));
}

void vlong()
{
	printf("size of long long %d\n", sizeof(long double));
}

int main()
{
	printf("%d\n", 16);
  	return 0;
}
