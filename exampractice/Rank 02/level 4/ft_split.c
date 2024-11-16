#include <stdlib.h>
#include <stdio.h>

char *fill_word(char *str, int i, int j)
{
	int cont = 0;
	char *word;
	while (j < i)
	{
		str[j] = word[cont];
		j++;
		cont++;
	}
	word[cont] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int n_words = 0;
	char **words;

	while (str[i])
	{
		while (str [i] && (str[i] == 9 || str[i] == 32 || str[i] == '\n'))
			i++;
		if (str[i] != '\0')
			n_words++;
		while (str[i] && str[i] != 9 && str[i] != 32 && str[i] != '\n')
			i++;
	}
	words = malloc(sizeof(char *) * (n_words + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == 9 || str[i] == 32 || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && str[i] != 9 && str[i] != 32 && str[i] != '\n')
			i++;
		if (j != i)
		{
			words[k] = malloc(sizeof(char) * (i - j + 1));
			words[k] = fill_word(str, i, j);
			k++;
		}
		words[k] = NULL;
	}
	return (words);
}