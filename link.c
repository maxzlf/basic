#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct tagNode
{
	struct tagNode* psNext;
	int value;
} SNode;

SNode* createNode(int value)
{
	SNode *psNode = (SNode*)malloc(sizeof(SNode)); 
	psNode->psNext = NULL;
	psNode->value = value;
	return psNode;
}

SNode* createLink(int values[], const unsigned int n)
{
	SNode *psHead = NULL;
	SNode *psParent = NULL;

	int i;
	for (i = 0; i < n; i++)
	{
		SNode *psNode = createNode(values[i]);
		if (0 == i)
		{
			psHead = psNode;
		}
		if (NULL != psParent)
		{
			psParent->psNext = psNode;

		}
		psParent = psNode;
	}
	return psHead;
}

void printLink(SNode *psHead)
{
	SNode *psCurrent = psHead;

	while (NULL != psCurrent)
	{
		printf("%-3d", psCurrent->value);
		psCurrent = psCurrent->psNext;
	}
	printf("\n");
}

SNode* revLink(SNode *psLink)
{	
	SNode *psParent = NULL;
	SNode *psCurrent = psLink;
	SNode *psChild;

	while (NULL != psCurrent)
	{
		psChild = psCurrent->psNext;
		psCurrent->psNext = psParent;
		psParent = psCurrent;
		psCurrent = psChild;
	}
	return psParent;
}

int main()
{
	int values[] = {2, 20, 34, 12, 35};
	SNode *psHead = createLink(values, sizeof(values)/sizeof(int));
	psHead = revLink(psHead);
	printLink(psHead);
	return 0;
}