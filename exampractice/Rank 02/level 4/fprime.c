#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
	int number;
	int i = 2;

	if (argc == 2)
	{
		number = atoi(argv[1]);
		if (number == 1)
			printf("%d",number);
		while (number != 1)
		{
			if(number % i == 0)
			{
				printf("%d",i);
				number = number / i;
				if (number != 1)
					printf("*");
			}
			else
				i++;
		}	
	}
	printf("\n");
}
