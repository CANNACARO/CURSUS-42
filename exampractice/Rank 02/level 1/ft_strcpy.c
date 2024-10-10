
#include <stdio.h>
#include <string.h>

// s1 = dest, s2 = src
char *ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i]= '\0';
	return (s1);
}


int	main()
{
	char src[]="h";
	char dest[]= "que";
	strcpy(dest,src);

	printf("%s", dest);
	return (0);
}