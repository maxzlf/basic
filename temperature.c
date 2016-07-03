#include <stdio.h>

float f2c(float f) 
{
	return (f - 32.0)*(5.0/9.0);
}

int main()
{
  float temperatures[16] = {1, 20, 40, 60, 80, 100,
  						  120, 140, 160, 180, 200,
  						  220, 240, 260, 280, 300};
  int index;
  for (index = 0; index < 16; index++)
  {
  	printf("%6.2f", temperatures[index]);
  	printf("\t");
  	printf("%6.2f\n", f2c(temperatures[index]));
  }

  return 0;
}

