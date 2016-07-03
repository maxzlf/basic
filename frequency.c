#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define IN  
#define OUT  

static const unsigned int LetterNumber = 26;
static const unsigned int WordSize = 16;

typedef struct tagWordCount
{
	char *word;
	unsigned long count;
}WordCount;

typedef struct tagHeapNode
{
	struct tagHeapNode *psLeft;
	struct tagHeapNode *psRight;
	WordCount wordCount;
}HeapNode;

static unsigned long letterFrequencys[LetterNumber];
static HeapNode *heapRoot = NULL;
static char buf[WordSize + 1];


void count();
void printHeap(HeapNode* node);
HeapNode* addHeap(HeapNode *node, char *word);
HeapNode* createNode(char *word);
int getLetter();
void testGetLetter();
char* getWordE();
int getWord(OUT char **word);
void testGetWord();
void clearBuf();
int isLetter(int c);
int wordCmp(char *word1, char *word2);

int main()
{
	count();
  	return 0;
}

void count()
{
	char *word;
	while ((word = getWordE()) != NULL)
	{
		HeapNode* node = addHeap(heapRoot, word);
		if (NULL != node && NULL == heapRoot)
		{
			heapRoot = node;
		}
	}
	printHeap(heapRoot);
}

void printHeap(HeapNode* node)
{
	if (NULL == node)
	{
		return;
	}
	printHeap(node->psLeft);
	printf("%-16s : %lu\n", node->wordCount.word, node->wordCount.count);
	printHeap(node->psRight);
}

HeapNode* addHeap(HeapNode *node, char *word)
{
	assert(NULL != word);

	if (NULL == node)
	{
		return createNode(word);
	}

	int result = wordCmp(word, node->wordCount.word);
	if (0 == result)
	{
		node->wordCount.count++;
		return NULL;
	} else if (result < 0)
	{
		HeapNode* leaftChild = addHeap(node->psLeft, word);
		if (NULL != leaftChild)
		{
			node->psLeft = leaftChild;
		}
		return NULL;
	} else
	{
		HeapNode* rightChild = addHeap(node->psRight, word);
		if (NULL != rightChild)
		{
			node->psRight = rightChild;
		}
		return NULL;
	}
}

HeapNode* createNode(char *word)
{
	assert(NULL != word);

	HeapNode *node = (HeapNode*)malloc(sizeof(HeapNode));
	node->psLeft = NULL;
	node->psRight = NULL;
	node->wordCount.word = word;
	node->wordCount.count = 1;

	return node;
}

int getLetter()
{
	int c = getchar();
	if (isalpha(c))
	{
		c = tolower(c);
		++letterFrequencys[c - 'a'];
	}

	return c;
}

void testGetLetter()
{
	int c;
	while ((c = getLetter()) != EOF)
		;

	int i;
	for (i = 0; i < sizeof(letterFrequencys)/sizeof(letterFrequencys[0]); i++)
	{
		printf("%c : %lu\n", i + 'a', letterFrequencys[i]);
	}
}

char* getWordE()
{
	char *word = NULL;
	while (getWord(&word) != EOF)
	{
		if (NULL != word)
		{
			break;
		}
	}
	return word;
}

int getWord(OUT char **word)
{
	assert(NULL != word);
	clearBuf();

	int length = 0;
	int letter;
	while (isLetter(letter = getLetter()))
	{
		int index = length < WordSize? length : WordSize - 1;
		buf[index] = letter;
		length++;
	}

	if (length > 0 && length <= WordSize)
	{
		*word = (char *)malloc(length + 1);
		memcpy(*word, buf, length);
		(*word)[length] = '\0';
	}
	return letter;
}

void testGetWord()
{
	char *word;
	while (getWord(&word) != EOF)
	{
		if (NULL != word)
		{
			printf("%s\n", word);
			word = NULL;
		}
	}
}

void clearBuf()
{
	memset(buf, 0, sizeof(buf));
}

int isLetter(int c)
{
	return isalpha(c) || isdigit(c) || '_' == c || '-' == c;
}

int wordCmp(char *word1, char *word2)
{
	assert(NULL != word1 && NULL != word2);
	while (*word1 == *word2 && *word1 != '\0')
	{
		word1++;
		word2++;
	}

	return *word1 - *word2;
}
