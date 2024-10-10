
#include <stdio.h>
#include <string.h>
int	main()
{
	char src[]="hola que ase";
	char dest[3];
	strcpy(dest,src);

	printf("%s", dest);
	return (0);
}