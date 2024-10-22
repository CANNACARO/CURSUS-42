#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	int j;
	int k;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			k = 0;
			while (j < i)
			{
				if (argv[1][i] == argv[1][j])
				{
					i++;
					break;
				}
				j++;
			}
			if(argv[1][i] == '\0')
				break;
			while (argv[2][k])
			{
				if (argv[1][i] == argv[2][k])
				{
					write (1, &argv[1][i], 1);
					break ;
				}
				k++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
}