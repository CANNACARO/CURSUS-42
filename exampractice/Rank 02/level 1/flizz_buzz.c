#include <unistd.h>

void	ft_putnbr(int n)
{
	char c = 'x';

	if (n > 9)
	{
		ft_putnbr(n/10);
		n = n % 10;
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write (1, &c, 1);
	}
}

int main(void)
{
	int i = 1;
	

	while (i <= 100)
	{
		if (i % 3 == 0)
		{
			write(1, "fizz", 4);
			if (i % 5 == 0)
				write(1, "buzz", 4);
		}
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
		{
			ft_putnbr(i);
		}
		write(1, "\n", 1);
		i++;
	}
	
}