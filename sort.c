#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define leftChild(i) (2*(i) + 1)

typedef struct tagLinkNode
{
	long number;
	struct tagNum* psNext;
}SLinkNode;

void mergeSort(int array[], unsigned int head, unsigned int tail);
void heapSort(int array[], unsigned int n);
void percDown(int array[], unsigned int i, unsigned int n);
void bubbleSort(int array[], unsigned int n);
void insertionSort(int array[], unsigned int n);
void selectionSort(int array[], unsigned int n);
void shellSort(int array[], unsigned int n);
void quickSort(int array[], unsigned int head, unsigned int tail);
void printArray(int array[], unsigned int n);
void swap(int *a, int *b);
void randomInt(int array[], unsigned int n, unsigned int scope);
int divideFind(int *array, int size, int num);

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		return 0;
	}

	int size = atoi(argv[1]);
	int scope = atoi(argv[2]);
	int *array = (int *)malloc(size * sizeof(int));
	randomInt(array, size, scope);

	quickSort(array, 0, size-1);
	printArray(array, size);
	printf("index : %d\n", divideFind(array, size, atoi(argv[3])));
  	return 0;
}

static double maxprod(double array[], int size)
{
	double max;
}

static int divideFind(int *array, int size, int num)
{
	int head = 0;
	int tail = size - 1;
	int middle;
	int index = -1;

	while (head <= tail)
	{
		middle = (head + tail) / 2;
		if (array[middle] == num)
		{
			index = middle;
			break;
		} else if (array[middle] > num)
		{
			tail = middle - 1;
		} else
		{
			head = middle + 1;
		}
	}
	return index;
}

void mergeSort(int array[], unsigned int head, unsigned int tail)
{
	assert(NULL != array);
	if (head >= tail) return;

	unsigned int leftHead = head;
	unsigned int leftTail = (head + tail) / 2;
	unsigned int rightHead = leftTail + 1;
	unsigned int rightTail = tail;

	mergeSort(array, leftHead, leftTail);
	mergeSort(array, rightHead, rightTail);

	unsigned int left = leftHead;
	unsigned int right = rightHead;
	while (right <= rightTail)
	{
		if (array[right] <= array[left])
		{
			int temp = array[right];
			unsigned int i;
			for (i = right; i > left; i--)
			{
				array[i] = array[i-1];
			}
			array[left] = temp;
			right++;
		}
		left++;
	}
}

void percDown(int array[], unsigned int i, unsigned int n)
{
    int tmp, child;
    for (tmp = array[i]; leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if (child < n - 1 && array[child + 1] > array[child])
            child++;
        if (array[child] > tmp)
            array[i] = array[child];
        else
            break;
    }
    array[i] = tmp;
}
 
void heapSort(int array[], unsigned int n)
{
    int i;
    for (i = n/2; i >= 0; i--)
        percDown(array, i, n);
    for (i = n-1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        percDown(array, 0, i);
    }
}

void bubbleSort(int array[], unsigned int n)
{
    assert(NULL != array);
    int i;
    for (i = n-1; i >= 0; i--)
    {
    	int flag = 1;
        int j;
        for (j = 0; j < i; j++)
        {
            if (array[j] > array[j+1])
            {
            	flag = 0;
                swap(&array[j], &array[j+1]);
            }
        }
        if (flag) break;
    }
}

void insertionSort(int array[], unsigned int n)
{
	assert(NULL != array);
	int i;
	for (i = 1; i < n; i++)
	{
		int temp = array[i];
		int j;
		for (j = i-1; j >= 0 && array[j] > temp; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = temp;
	}
}

void selectionSort(int array[], unsigned int n)
{
	assert(NULL != array);

	int i;
	for (i = 0; i < n; i++)
	{
		int j;
		for (j = i+1; j < n; j++)
		{
			if (array[i] > array[j])
			{
				swap(&array[i], &array[j]);
			}
		}
	}
}

void shellSort(int array[], unsigned int n)
{
    assert(NULL != array);
    assert(n >= 0);

    int increment;
    for (increment = n/2; increment > 0; increment /= 2)
    {
    	int i;
        for (i = increment; i < n; i++)
        {
        	int temp = array[i];
      		int j;
            for (j = i; j >= increment && array[j-increment] > temp; j -= increment)
            {
                array[j] = array[j - increment];
            }
            array[j] = temp;
        }
    }
}

void quickSort(int array[], unsigned int head, unsigned int tail)
{
	assert(NULL != array);
	if (head >= tail)
	{
		return;
	}

	swap(&array[(head+tail)/2], &array[head]);
	unsigned i, last = head;
	for (i = head + 1; i <= tail; i++)
	{
		if (array[i] < array[head])
		{
			swap(&array[i], &array[++last]);
		}
	}
	swap(&array[head], &array[last]);

	quickSort(array, head, last > head? last-1 : last);
	quickSort(array, last < tail? last+1 : last, tail);
}

void printArray(int array[], unsigned int n)
{
	assert(NULL != array);
	assert(n >= 0);

	int index;
	for (index = 0; index < n; index++)
	{
		printf("%-5d ", array[index]);
		if ((index+1)%32 ==0)
		{
			printf("\n");
		}
	}
	printf("\n");
}

void swap(int *a, int *b)
{
	assert(NULL != a);
	assert(NULL != b);

	int temp = *a;
	*a = *b;
	*b = temp;
}



SLinkNode* createLinkNode(long number)
{
	SLinkNode* psNode = (SLinkNode*)malloc(sizeof(SLinkNode));
	psNode->number = number;
	psNode->psNext = NULL;
	return psNode;
}

SLinkNode* addNodeToLink(SLinkNode* psHead, SLinkNode* psNode)
{
	if (NULL == psHead)
	{
		psNode->psNext = NULL;
		return psNode;
	}

	if (NULL == psNode)
	{
		return psHead;
	}

	SLinkNode *psBefor = NULL;
	SLinkNode *psAfter = psHead;
	while (NULL != psAfter && psAfter->number < psNode->number)
	{
		psBefor = psAfter;
		psAfter = psAfter->psNext;
	}

	if (NULL == psBefor)
	{
		psNode->psNext = psAfter;
		return psNode;
	} else
	{
		psNode->psNext = psAfter;
		psBefor->psNext = psNode;
		return psHead;
	}
}

void deleteLink(SLinkNode *psHead)
{
	SLinkNode *psTemp, *psCurrent = psHead;
	while (NULL != psCurrent)
	{
		psTemp = psCurrent;
		psCurrent = psTemp->psNext;
		free(psTemp);
	}
}

unsigned int getNDigitOfNum(unsigned int number, unsigned int n)
{
	assert(n > 0);

	unsigned int i;
	for (i = 1; i < n; i++)
	{
		number /= 10;
	}
	return number % 10;
}

void randomInt(int array[], unsigned int n, unsigned int scope)
{
	srand(time(NULL));
	int i;
	for (i = 0; i < n; i++)
	{
		array[i] = rand() % (scope*2) - scope;
	}
}




