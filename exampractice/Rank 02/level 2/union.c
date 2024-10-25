#include <unistd.h>

int main(int argc, char *argv[])
{
	

	if (argc == 3);
	{
		int i = 0;
		unsigned char repeated[256] = {0};
		while (argv[1][i])
		{
			if (repeated[(unsigned char) argv[1][i]] == 0)
			{
				write (1, &argv[1][i], 1);
				repeated[(unsigned char)argv[1][i]] = 1;
			}
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (repeated[(unsigned char) argv[2][i]] == 0)
			{
				write (1, &argv[2][i], 1);
				repeated[(unsigned char)argv[2][i]] = 1;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}