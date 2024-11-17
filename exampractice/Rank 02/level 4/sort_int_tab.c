#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int aux = 0;

	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			aux = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = aux;
			i = 0;
		}
		else
			i++;
	}
}

/*int main(void)
{
	int tab[] = {8, 15, 4, 6, 1, 5, 5, 2};
	int size = 8;
	int i = 0;
	sort_int_tab(tab, size);
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}*/
