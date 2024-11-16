#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int nbr)
{
	int aux = nbr;
	int i = 0;
	char *str;
	if (nbr == 0)
	{
		str = malloc(sizeof(char) * 1);
		str[i]= '0';
		str[i + 1] = '\0';
		return (str);
	}
	if (aux > 0)
	{
		while (aux != 0)
		{
			i++;
			aux = aux / 10;
		}
		str = malloc(sizeof(char) * (i + 1));
		str[i] = '\0';
		while (i > 0)
		{
			i--;
			str[i] = nbr % 10 + '0';
			nbr = nbr / 10;
		}
	}
	if (aux < 0)
	{
		if (aux == -2147483648)
		{
			str = malloc(sizeof(char) * 12);
			str  = "-2147483648";
			return (str);
		}
		
		aux = aux * (-1);
		nbr = aux;
		while (aux != 0)
		{
			i++;
			aux = aux / 10;
		}
		str = malloc(sizeof(char) * (i + 2));
		i++;
		str[i] = '\0';
		while (i > 0)
		{
			i--;
			str[i] = nbr % 10 + '0';
			nbr = nbr / 10;
		}
		str[i] = '-';
	}
	return (str);
}

int main()
{
	int n = 1474836;

	printf("%s", ft_itoa(n));
	return (0);
}