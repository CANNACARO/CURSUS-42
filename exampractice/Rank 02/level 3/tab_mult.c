#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void ft_putnbr(int n)
{
	char c;

	if (n > 9)
		ft_putnbr(n/10);
	c = n % 10 + '0';
	write(1, &c, 1);
}



int main (int argc, char *argv[])
{
	int i = 1;
	int number;
	
	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		number = ft_atoi(argv[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write (1, " x ", 3);
			ft_putnbr(number);
			write (1, " = ", 3);
			ft_putnbr (i*number);
			write (1, "\n", 1);
			i++;
		}
	}
	return (0);
}






