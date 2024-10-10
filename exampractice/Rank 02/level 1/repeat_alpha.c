
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int j;
	int rep;

	i = 0;
	rep = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			j = 0;
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				rep = argv[1][i] - 'A';
				while(j <= rep)
				{
					write(1, &argv[1][i], 1);
					j++;
				}
			}
			j = 0;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				rep = argv[1][i] - 'a';
				while(j <= rep)
				{
					write(1, &argv[1][i], 1);
					j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
}