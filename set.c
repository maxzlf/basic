#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef int BOOL;
#define TRUE  1u
#define FALSE 0u

typedef union tagUSet
{
	char  bytes[32];
	short words[16];
	int   ints[8];
} USet;

#define SET_SIZE (sizeof(USet)*8)

void clearSet(USet *set)
{
	if (NULL == set) return;
	int i;
	for (i = 0; i < sizeof(USet)/sizeof(int); i++)
	{
		set->ints[i] = 0;
	}
}

void setBit(USet *set, unsigned int bit)
{
	assert(NULL != set);
	assert(bit < SET_SIZE);

	int m = bit / 8;
	int n = bit % 8;
	char c = 0x01;
	c <<= 7 - n;

	set->bytes[m] |= c;
}

BOOL getBit(USet const *set, unsigned int bit)
{
	assert(NULL != set);
	assert(bit < SET_SIZE);

	int m = bit / 8;
	int n = bit % 8;
	char c = 0x01;
	c <<= 7 - n;

	BOOL bret =  (0 == (set->bytes[m] & c)) ? FALSE : TRUE;
	return bret;
}

void andBit(USet *result, USet const *set1, USet const *set2)
{
	assert(NULL != result && NULL != set1 && NULL != set2);

	int i;
	for (i = 0; i < sizeof(USet); i++)
	{
		result->bytes[i] = set1->bytes[i] & set2->bytes[i];
	}
}

void orBit(USet *result, USet const *set1, USet const *set2)
{
	assert(NULL != result && NULL != set1 && NULL != set2);

	int i;
	for (i = 0; i < sizeof(USet); i++)
	{
		result->bytes[i] = set1->bytes[i] | set2->bytes[i];
	}
}

int commonChar(char const *str1, char const *str2)
{
	USet set1, set2, setRet;
	clearSet(&set1);
	clearSet(&set2);
	clearSet(&setRet);
	int count = 0;

	int i;
	for (i = 0; i < strlen(str1); i++)
	{
		setBit(&set1, (unsigned char)str1[i]);
	}
	for (i = 0; i < strlen(str2); i++)
	{
		setBit(&set2, (unsigned char)str2[i]);
	}

	andBit(&setRet, &set1, &set2);
	int j;
	for (j = 0; j < SET_SIZE; j++)
	{
		if (getBit(&setRet, j))
		{
			count++;
			printf("%-4c", (char)j);
		}
	}
	return count;
}


int main(int argc, char *argv[])
{
	if (commonChar(argv[1], argv[2]) > 0)
	{
		printf("\n");
	}
}
