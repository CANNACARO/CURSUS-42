#include <unistd.h>
#include <stdio.h>

char *ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	char tmp;

	while (str[i])
		i++;
	i--;
	while (i > j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i--;
		j++;
	}
	return (str);
}

/*int main()
{
	char str[] = "calor";

	printf("%s", ft_strrev(str));
	return(0);
}*/