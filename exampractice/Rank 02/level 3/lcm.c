#include <stdio.h>

unsigned int	hcf(unsigned int a, unsigned int b)
{
	unsigned int	max;
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
	return (max);
}


unsigned int	lcm(unsigned int a, unsigned int b)
{
	int 	product = a * b;
	unsigned int	result;
	if (a == 0 || b == 0)
		return (0);
	result = product / hcf(a, b);
	return (result);
}

int main()
{
	unsigned int x;

	x = lcm(7, 30);
	printf("%d", x);
	return (0);
}




