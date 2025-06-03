#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
static int	ft_putnbr(int n)
{
	char	c;
	int count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_print_string("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n/10);
	c = n % 10 + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

static int ft_puthex(unsigned int n)
{
	char *hex = "0123456789abcdef";
	int count = 0;

	if (n >= 16)
		count += ft_puthex(n/16);
	write(1, &hex[n%16], 1);
	count++;
	return (count);
}

int ft_printf(const char *str, ...)
{
	int size;
	int count;
	va_list arg;

	size = 0;
	count = 0;
	va_start(arg, str);
	while (str[count])
	{
		if (str[count] == '%' && str[count + 1])
		{
			count++;
			if (str[count] == 's')
				size += ft_print_string(va_arg(arg, char *));
			else if (str[count] == 'd')
				size += ft_putnbr(va_arg(arg, int));
			else if (str[count] == 'x')
				size += ft_puthex(va_arg(arg, unsigned int));
			else if (str[count] == '%')
			{
				write(1, "%", 1);
				size++;
			}
			else
			{
				write(1, "%", 1);
				write(1, &str[count], 1);
				size += 2;
			}
		}
		else
		{
			write(1, &str[count], 1);
			size++;
		}
		count++;
	}
	va_end(arg);
	return (size);
}

int main()
{
ft_printf("Hola %s\n", NULL);
ft_printf("Numero: %d\n", -123);
ft_printf("Hex: %x\n", 255);
ft_printf("Literal: %%\n");
printf("Literal: %%\n");
}