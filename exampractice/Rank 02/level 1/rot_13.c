#include <unistd.h>

int main(int argc, char *argv[])
{
	char c = '0';
	int i  =0;

	if (argc == 2)
	{
		while(argv[1][i])
		{
			c = argv[1][i];
			if ((argv[1][i] >= 'A' && argv[1][i] <= 'M') || 
			(argv[1][i] >= 'a' && argv[1][i] <= 'm'))
				c = c + 13;
			else if ((argv[1][i] >= 'N' && argv[1][i] <= 'Z') || 
			(argv[1][i] >= 'n' && argv[1][i] <= 'z'))
				c = c - 13;
			write(1, &c, 1);
			i++;
		}
	}
	else
		write(1, "\n",1);
}