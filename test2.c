#include <stdio.h>
#line 100

int main()
{
	printf("%-5s : %-5d\n", __FILE__, __LINE__);
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%-5s : %-5d\n", __FILE__, __LINE__);
	}
	printf("%-5s : %-5d\n", __FILE__, __LINE__);

	return 0;
}