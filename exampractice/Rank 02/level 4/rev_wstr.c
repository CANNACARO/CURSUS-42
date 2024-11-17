#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	if (argc == 2)
	{
		int i = 0;
		int j = 0;
		int k = 0;
		int z;
		int aux = 0;
		int word_count = 0;
		char **words;
		
		while (argv[1][i])
		{
			if (argv[1][i] == 32)
				word_count++;
			i++;
		}
		word_count++;
		words = malloc(sizeof(char*) * (word_count + 1));
		i = 0;
		while (argv[1][i])
		{
			while (argv[1][i] && argv[1][i] != 32)
				i++;
			j = i;
			words[k] = malloc(sizeof(char) * (j - aux + 1));
			i = aux;
			z = 0;
			while (i < j)
			{
				words[k][z] = argv[1][i];
				z++;
				i++;
			}
			words[k][z] = '\0';
			i = j;
			if (argv[1][i] == 32)
				i++;
			aux = i;
			k++;
		}
		words[k] = NULL;
		//hasta aqui he guardado todas las palabras, ahora tengo que recorrer
		//el array al reves e imprimir las palabras de atras hacia delante	
		word_count--;
		while (word_count >= 0)
		{
			z = 0;
			while(words[word_count][z])
			{
				write(1, &words[word_count][z], 1);
				z++;
			}
			if (word_count != 0)
				write(1, " ", 1);
			word_count--;
		}
	}
	write (1, "\n", 1);	
}
