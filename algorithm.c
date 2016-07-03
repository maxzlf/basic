#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static void swap(char *a, char *b);
static int siteToInt(int a, int b, int c);
static int equalPair(int f[], int g[], int m, int n);
static int miniDist(int f[], int g[], int m, int n);
static int headTail(int f[], int n);
static void arms();
static long pow(long num, unsigned int n);
static long factl(long n, long m);
static long factlog(long n);
static void givenSum(long n);
static int palindrome(const char *str);
void revStr(char *str);
void lcs_length(char const *str1, char const *str2, int *map);
void print_lcs(char const *str1, char const *str2);

int main(int argc, char *argv[])
{
	print_lcs(argv[1], argv[2]);
	printf("\n");
	
  	return 0;
}

void print_lcs(char const *str1, char const *str2)
{
	assert(NULL != str1);
	assert(NULL != str2);

	int lenStr1 = strlen(str1);
	int lenStr2 = strlen(str2);
	int *map = (int *)malloc(lenStr1 * lenStr2 * sizeof(int));
	lcs_length(str1, str2, map);

	int i = lenStr1 -1, j = lenStr2 - 1;
	while (i >= 0 && j >= 0)
	{
		if (j > 0 && map[lenStr1*i + j] == map[lenStr1*i + j-1])
		{
			j--;
		} else if (i > 0 && map[lenStr1*i + j] == map[lenStr1*(i-1) + j])
		{
			i--;
		} else if (str1[i] == str2[j])
		{
			printf("%-2c", str1[i]);
			i--;
			j--;
		}
	}

	free(map);
}

void lcs_length(char const *str1, char const *str2, int *map)
{
	assert(NULL != str1);
	assert(NULL != str2);
	assert(NULL != map);

	int lenStr1 = strlen(str1);
	int lenStr2 = strlen(str2);

	int i, j;
	for (i = 0; i < lenStr1; i++)
	{
		for (j = 0; j < lenStr2; j++)
		{
			if (str1[i] == str2[j])
			{
				if (i > 0 && j > 0)
				{ 
					map[lenStr1*i + j] = map[lenStr1*(i-1) + j-1] + 1;
				} else 
				{
					map[lenStr1*i + j] = 1;
				}
			} else
			{
				if (i > 0 && j > 0)
				{
					map[lenStr1*i + j] = map[lenStr1*i + j-1] > map[lenStr1*(i-1) + j] ? map[lenStr1*i + j-1] : map[lenStr1*(i-1) + j];
				} else if (i == 0 && j > 0)
				{
					map[lenStr1*i + j] = map[lenStr1*i + j-1];
				} else if (i > 0 && j == 0)
				{
					map[lenStr1*i + j] = map[lenStr1*(i-1) + j];
				}
			}
		}
	}
}

void revStr(char *str)
{
	int left, right;
	for (left = 0, right = strlen(str) - 1; left <= right; left++, right--)
	{
		swap(&str[left], &str[right]);
	}
}

static int palindrome(const char *str)
{
	int length = strlen(str);
	int maxPalindrome = 0;

	int index;
	for (index = 0; (index >> 1) + 1 < length; index++)
	{
		int left, right, count;
		if (index & 0x01)
		{
			left = index >> 1;
			right = left + 1;
			count = 0;
		} else
		{
			left = right = index >> 1;
			count = -1;
		}
		for (; left >= 0 && right < length && str[left] == str[right]; left--, right++)
		{
			count += 2;
		}
		maxPalindrome = count > maxPalindrome? count : maxPalindrome;
	}
	return maxPalindrome;
}

static void givenSum(long n)
{
	long stub, index;
	stub = index = 1;

	while (index <= n/2+1)
	{
		long sum = (stub + index) / 2.0 * (index - stub + 1);
		if (sum < n) 
		{
			index++;
		}
		else if (sum > n) 
		{
			stub++;
		} else
		{
			printf("%ld ~ %ld\n", stub, index);
			index++;
		}
	}
}

static long factlog(long n)
{
	return factl(1, n);
}

static long factl(long n, long m)
{
	if (n == m) return n;
	return factl(n, (n+m)/2) * factl((n+m)/2 + 1, m);
}

static long pow(long num, unsigned int n)
{
    long temp = 1;

    while (n > 0)
    {
    	if ((n & 0x01ul) == 1)
    	{
    		temp *= num;
    	}
    	num *= num;
    	n >>= 1;
    }
    return temp;
}

static void arms()
{
	int a, b, c;
	for (a = 1; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
		{
			for (c = 0; c < 10; c++)
			{
				if ((a*a*a + b*b*b + c*c*c) == siteToInt(a, b, c))
				{
					printf("%d\n", siteToInt(a, b, c));
				}
			}
		}
	}
}

static int headTail(int f[], int n)
{
	int count, headSum, tailSum, head, tail;
	count = headSum = tailSum = 0; 
	head = 0; tail = n-1;

	headSum += f[head];
	tailSum += f[tail];
	while (head < n && tail >= 0)
	{
		if (headSum < tailSum)
		{
			headSum += f[++head];
		} else if (headSum > tailSum)
		{
			tailSum += f[--tail];
		} else
		{
			count++;
			headSum += f[++head];
			tailSum += f[--tail];
		}
	}
	return count;
}

static int equalPair(int f[], int g[], int m, int n)
{
	int count, mindex, nindex;
	count = mindex = nindex = 0;

	while (mindex < m && nindex < n)
	{
		if (f[mindex] < g[nindex])
		{
			mindex++;
		} else if (f[mindex] > g[nindex])
		{
			nindex++;
		} else 
		{
			count++;
			mindex++;
			nindex++;
		}
	}

	return count;
} 

static int miniDist(int f[], int g[], int m, int n)
{
	int dst, mindex, nindex;
	mindex = nindex = 0;
	dst = abs(f[m-1] - g[0]);

	while (mindex < m && nindex < n)
	{
		int tmp = abs(f[mindex] - g[nindex]);
		dst = tmp < dst? tmp : dst;
		if(f[mindex] <= g[nindex])
		{
			mindex++;
		} else
		{
			nindex++;
		}
	}
	return dst;
}

static void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

static int siteToInt(int a, int b, int c)
{
	return 100*a + 10*b + c;
}