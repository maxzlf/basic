#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RIGHT    1
#define DOWN     2
#define LEFT     3
#define UP       4

void snakeMatrix(unsigned int n)
{
	if (0 == n) return;
	int msize = n*n * sizeof(unsigned int);
	unsigned int *matrix = (unsigned int*)malloc(msize);
	memset(matrix, 0, msize);

	int count = 1;
	int direction = RIGHT;
	int i = 0, j = 0;
	while (count <= n*n && 0 == matrix[i*n + j])
	{
		matrix[i*n + j] = count++;

		if (RIGHT == direction)
		{
			if ((j+1) >= n || 0 != matrix[i*n + j+1])
			{
				direction = DOWN;
				i++;
			} else
			{
				j++;
			}
		} else if (DOWN == direction)
		{
			if ((i+1) >= n || 0 != matrix[(i+1)*n + j])
			{
				direction = LEFT;
				j--;
			} else
			{
				i++;
			}
		} else if (LEFT == direction)
		{
			if (j <= 0 || 0 != matrix[i*n + j-1])
			{
				direction = UP;
				i--;
			} else
			{
				j--;
			}
		} else if (UP == direction)
		{
			if (i <= 0 || 0 != matrix[(i-1)*n + j])
			{
				direction = RIGHT;
				j++;
			} else
			{
				i--;
			}
		}
	}

	int index;
	for (index = 0; index < n*n; index++)
	{
		printf("%4d", matrix[index]);
		if (0 == (index+1)%n)
		{
			printf("\n");
		}
	}

	free(matrix);
}

int main(int argc, char *argv[])
{
	if (2 != argc)
	{
		printf("usage : snake n\n");
		return 0;
	}
	snakeMatrix(atoi(argv[1]));
	return 0;
}

