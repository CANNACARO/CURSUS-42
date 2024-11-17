#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		int i = 0;
		int j = 0;
		int k = 0;
		int z = 0;
		int n_words = 0;
		char **words;
		while (argv[1][i])
		{
			while (argv[1][i] && (argv[1][i] == 9 || argv[1][i] == 32))
				i++;
			if (argv[1][i] != '\0')
				n_words++;
			while (argv[1][i] && argv[1][i] != 9 && argv[1][i] != 32)
				i++;
		}
		words = malloc(sizeof(char *) * (n_words + 1));
		i = 0;
		while (argv[1][i])
		{
			while (argv[1][i] && (argv[1][i] == 9 || argv[1][i] == 32))
				i++;
			j = i;
			while (argv[1][i] && argv[1][i] != 9 && argv[1][i] != 32)
				i++;
			if (j != i)
			{
				words[k] = malloc(sizeof(char) * (i - j + 1));
				z = 0;
				while (j < i)
				{
					words[k][z] = argv[1][j];
					j++;
					z++;
				}
				words[k][z] = '\0';
				k++;
			}
		}
		words[k] = NULL;
		if (n_words > 0)
		{
			k = 1;
			while (k < n_words)
			{
				z = 0;
				while (words[k][z])
				{
					write(1, &words[k][z], 1);
					z++;
				}
				write (1 , " ", 1);
				k++;
			}
			z = 0;
			while (words[0][z])
			{
				write(1, &words[0][z], 1);
				z++;
			}
		}
	}
	write (1, "\n", 1);
}
