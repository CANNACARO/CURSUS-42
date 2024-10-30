#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while(str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int is_prime(int n)
{
	int i = 2;
	if (n <= 1)
		return (0);
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++; 
	}
	return (1);
}

void put_nbr(int n)
{
	char digit;
		
	if (n >= 10)
		put_nbr(n/10);
	digit = n % 10 + '0';
	write (1, &digit, 1);
}


int main(int argc, char *argv[])
{
	if (argc != 2 || argv[1][0] == '-' || argv[1][0] == '0')
	{
		write (1, "0", 1);
		write (1, "\n", 1);
		return (0);
	}
	else
	{
		int n = ft_atoi(argv[1]);
		int i =0;
		int sum = 0;
		while (i <= n)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
		put_nbr(sum);
		write (1, "\n", 1);
	}
}