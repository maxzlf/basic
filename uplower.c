#include <stdio.h>
#include <ctype.h>
#include <string.h>

void toLower();
void toUpper();

int main(int argc, char *argv[])
{
	printf("%s\n", argv[0]);
	if (0 == strcmp(argv[0], "./tolower"))
	{
		toLower();
	} else if (0 == strcmp(argv[0], "./toupper"))
	{
		toUpper();
	}
	return 0;
}

void toLower()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		if (isalpha(c))
		{
			c = tolower(c);
		}
		putchar(c);
	}
}

void toUpper()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		if (isalpha(c))
		{
			c = toupper(c);
		}
		putchar(c);
	}	
}
