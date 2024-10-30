#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j;
	int k = 0;;

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
					break;
				}
				j++;
			}
			if (argv[2][j] == '\0')
				write (1, "0", 1);
			i++;
		}
		if (argv[1][i] == '\0' && argv[2][j] != '\0')
			write(1, "1", 1);
	}
	write (1, "\n", 1);
}