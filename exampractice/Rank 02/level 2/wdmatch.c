#include <unistd.h>

int main (int argc, char *argv[])
{
	int i = 0;
	int j;
	int k = 0;
	
	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = k;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					k = j + 1;
					break ;
				}
				j++;
			}
			if (argv[2][j] == '\0')
			{
				break;
			}
			i++;
		}
		if (argv[1][i] == '\0')
		{
			i = 0;
			while (argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
}