#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t j;

	i = 0;
	while (reject[i])
	{
		j = 0;
		while (s[j])
		{
			if (reject[i] == s[j])
				return (j);
			j++;
		}
		i++;
	}
	return (j);
}

int main()
{
	char s[]="Esto es una prueba";
	char reject[]="x";

	printf("strcspn real: %zu\n", strcspn(s, reject));
	printf("ft_strcspn: %zu", ft_strcspn(s, reject));
	return (0);
}