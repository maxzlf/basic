#include <stdio.h>

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void allOrder(char* const array, int head, int tail)
{
	if (head >= tail)
	{
		printf("%s\n", array);
		return;
	}
	int i;
	for (i = head; i <= tail; i++)
	{
		int j, skip = 0;
		for (j = i - 1; j >= head; j--)
		{
			if (array[j] == array[i])
			{
				skip = 1;
				break;
			}
		}
		if (skip) continue;

		swap(&array[head], &array[i]);
		allOrder(array, head+1, tail);
		swap(&array[head], &array[i]);
	}
}


int main(int argc, char *argv[])
{
	allOrder(argv[1], 0, strlen(argv[1]) - 1);
  	return 0;
}
