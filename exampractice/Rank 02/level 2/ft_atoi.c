#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	while (str[i] == 9 || str[i] == 32) //quiza haya que poner del 9 al 13
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (result);
		else
			result = result*10 + str[i] - 48;
		i++;
	}
	return (result);
}
/*int main (void)
{
	char str[]="    	 	00045jasdlkñf";
	int x;
	int y;
	x=atoi(str);
	y=ft_atoi(str);
	printf("atoi real: %d\n",x);
	printf("ftatoi real: %d\n",x);
	return (0);
}*/