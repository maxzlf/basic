#include <stdio.h>

int main()
{
	printf("%d\n", EOF);
	int c;
  	while ((c = getchar()) != EOF) {
  		putchar(c);
  	}

  	return 0;
}
