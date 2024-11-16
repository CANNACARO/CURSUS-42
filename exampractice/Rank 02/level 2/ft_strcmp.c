#include <stdio.h>
#include <string.h>

int ft_strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*int main(void)
{
	const char s1[]= "abc";
	const char s2[]= "abc";

	printf("strcmp real: %d\n", strcmp(s1, s2));
	printf("ft_strcmp: %d", ft_strcmp(s1, s2));
	return (0);
}*/