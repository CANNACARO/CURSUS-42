#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
	int len = end - start + 1;
	int i = 0;
	int *p;

	p = malloc(sizeof(int) * len);
	while (i < len)
	{
		p[i] = start;
		i++;
		start++;
	}
	return p;
}

int main()
{
	int start = -2;
	int end = 8;
	int *p;
	int i = 0;
	int len = end - start + 1;

	p = ft_range(start, end);
	while (i < len)
	{
		printf("%d, ", p[i]);
		i++;
	}
	return (0);
}