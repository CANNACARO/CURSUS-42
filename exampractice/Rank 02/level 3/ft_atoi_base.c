#include <stdio.h>


/*int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}*/

void *to_lower(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

void ft_strcpy(char *old, char *new)
{
	int i = 0;
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = '\0';
}
int get_digit(char c)
{
	int x;
	if (c >= '0' && c <= '9')
	{
		x = (c - '0');
		printf ("%d\n", x);
		return (x);
	}
	else if (c >= 'a' && c <= 'f')
	{	
		x = (c - 'a' + 10);
		return (x);
	}
	else 
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	char	all_base[]="0123456789abcdef";
	char	base[17];
	char 	new_str[100];
	int		i = 0;
	int		digit;
	int		result= 0;
	int		sign = 1;

	while (i < str_base)
	{
		base[i] = all_base[i];
		i++;
	}
	base[i] = '\0';
	ft_strcpy((char *)str, new_str);
	to_lower(new_str);
	i = 0;
	if (new_str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (new_str[i])
	{
		digit = get_digit(new_str[i]);
		if (digit == -1)
			break;
		result = result * str_base + digit;
		i++;
	}
	return (result * sign);
}

int main()
{
	int x = ft_atoi_base("DDD", 0);
	printf("%d", x);
}