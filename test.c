#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#line 100
#define ISODD(n) ((n)&0x01)
typedef int (*func)();

typedef struct tagType
{
	int c;
	long l;
}Type;

typedef union una
{
	char c;
	Type type;
}UNA;

typedef struct bitstruct
{
    long a : 2;
    long   : 62;
    long e : 1;
}BITS;





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

void systemT(int argc, char *argv[])
{
	int count = atoi(argv[1]);
	char buf[32];
	sprintf(buf, "./a.out %d", ++count);
	printf("%s\n", buf);

	if (count >= 100)
	{
		return;
	}

	system(buf);
	printf("%s\n", buf);
  	return;
}

void randomInt(int array[], unsigned int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		array[i] = rand() % 20 - 10;
	}
}

void printArray(int array[], unsigned int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%-4d", array[i]);
	}
	printf("\n");
}
