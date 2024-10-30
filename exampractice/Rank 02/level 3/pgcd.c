#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned int max;
	unsigned int a;
	unsigned int b;
	
	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a > b)
			max = a;
		else
			max = b;
		while (max >= 1)
		{
			if ((a % max == 0) && (b % max == 0))
				break;
			max--;
		}
		printf("%d", max);
	}
	printf("\n");
	return (0);
}