#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int j;
	const char *pointer;

	i = 0;
	while (s2[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s1[j] == s2[i])
			{
				pointer = &s1[j];
				return ((char*)pointer);
			}
			j++;
		}
		i++;
	}
	pointer = NULL;
	return ((char*)pointer);
}

/*int main()
{
	char s[]= "Esto es una prueba";
	char accept[]= "xnd";
	
	printf("strpbrk real: %s\n",strpbrk(s,accept));
	printf("ft_strpbrk: %s",ft_strpbrk(s,accept));
	return (0);
}*/