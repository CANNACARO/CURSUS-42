#include <string.h>
#include <unistd.h>
#include <stdio.h>

size_t ft_strspn(const char *s, const char *accept)
{
	size_t i;
	size_t j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (accept[j] != s[i])
			{
				j++;
				continue ;
			}
			else
				break;
		}
		if (accept[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}

int main ()
{
	char s[] = "This is the maaan!";
	char accept[]= "Th jk";

	printf("Real strspn: %zu\n", strspn(s, accept));
	printf("ft_strspn: %zu", ft_strspn(s, accept));
	return (0);
}