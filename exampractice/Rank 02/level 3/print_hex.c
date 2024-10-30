#include <unistd.h>

int ft_atoi(char *str)
{
	int i = 0;
	int result= 0;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

void print_hex(int n)
{
	char hexa[] = "0123456789abcdef";
	
	if (n >= 16)
		print_hex(n/16);
	write(1, &hexa[n%16], 1);
}

int main(int argc, char *argv[])
{
	int n = 0;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		print_hex(n);
	}
	write(1, "\n", 1);
	return (0);
}