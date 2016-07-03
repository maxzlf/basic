#include <stdio.h>
#include <stdlib.h>

static int g_iVal = 0;

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int add()
{
	return g_iVal++;
}

int dec()
{
	return g_iVal--;
}


int main()
{
	printf("%d\n", add() * dec()C);

  	return 0;
}
