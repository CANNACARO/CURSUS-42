#include <stdio.h>

int	max(int* tab, unsigned int len)
{
	int result;
	unsigned int i;
	
	result = 0;
	i = 1;
	if (len == 0)
	{
		return (result);
	}
	result = tab[0];
	while (i < len)
	{
		if (tab[i] > result)
			result = tab[i];
		i++;
	}
	return (result);
}

/*int main()
{
	int tab[] = {4,4,7,2,14,1,7,8};
	unsigned int len;
	
	len = 8;
	printf("%d", max(tab, len));
	return (0);
}*/
