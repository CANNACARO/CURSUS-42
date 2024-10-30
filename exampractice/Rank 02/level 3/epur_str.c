#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i] == 9 || argv[1][i] == 32)
				i++;
		while (argv[1][i])
		{
			if (argv[1][i] == 9 || argv[1][i] == 32)
			{
				if((argv[1][i + 1] != 9) && (argv[1][i + 1] != 32) && argv[1][i + 1] != '\0')
				{
					write(1, " ", 1);
					i++;
				}
				else
					i++;
			}
			else
			{
				write (1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write (1, "\n", 1);
}