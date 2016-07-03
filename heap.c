#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

static const unsigned int HEAP_SIZE = 1024;

typedef struct tagHeap
{
	unsigned int current;
	unsigned int capacity;
	unsigned int root;
	int heap[HEAP_SIZE];
}Heap;

static Heap heap;


int isEmpty(Heap *psHeap)
{
	assert(NULL != psHeap);
	return psHeap->current <= psHeap->root;
}

int isFull(Heap *psHeap)
{
	assert(NULL != psHeap);
	return psHeap->current >= psHeap->capacity;
}

void insert(Heap *psHeap, int number)
{
	assert(NULL != psHeap);
	if (isFull(psHeap))
	{
		return;
	}

	unsigned int hole = psHeap->current;

	while (hole > psHeap->root && number < psHeap->heap[hole/2])
	{
		psHeap->heap[hole] = psHeap->heap[hole/2];
		hole /= 2;
	}

	psHeap->heap[hole] = number;
	(psHeap->current)++;
}

int deleteMin(Heap *psHeap)
{
	assert(NULL != psHeap && !isEmpty(psHeap));

	unsigned int hole = psHeap->root;
	int result = psHeap->heap[hole];

	while (hole*2 < psHeap->current)
	{
		if (hole*2 + 1 < psHeap->current && psHeap->heap[hole*2] > psHeap->heap[hole*2 + 1])
		{
			psHeap->heap[hole] = psHeap->heap[hole*2 + 1];
				hole  = hole*2 + 1;
		} else
		{
			psHeap->heap[hole] = psHeap->heap[hole*2];
			hole *= 2;
		}
	}

	(psHeap->current)--;
	psHeap->heap[hole] = psHeap->heap[psHeap->current];

	return result;
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		return 0;
	}
	int size = atoi(argv[1]);
	int scope = atoi(argv[2]);

	srand(time(NULL));
	heap.current = 1;
	heap.root = 1;
	heap.capacity = HEAP_SIZE;

	int i;
	for (i = 0; i < size; i++)
	{
		insert(&heap, rand()%scope - scope/2);
	}

	while (!isEmpty(&heap))
	{
		printf("%-4d ", deleteMin(&heap));
	}
	printf("\n");
  	return 0;
}
