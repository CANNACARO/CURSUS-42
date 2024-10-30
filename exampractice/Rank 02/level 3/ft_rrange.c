#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int len = end - start + 1;
	int i = 0;
	int *p;

	p = malloc(sizeof(int) * len);
	while (i < len)
	{
		p[i] = end;
		i++;
		end--;
	}
	return (p);
}

int 	main()
{
	int start = -5;
	int end = 3;
	int len = end - start + 1;
	int i = 0;
	int *p;

	p = ft_rrange(start, end);
	while (i < len)
	{
		printf("%d", p[i]);
		i++;
	}
	return (0);
}