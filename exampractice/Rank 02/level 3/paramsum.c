#include <unistd.h>

/*char *ft_itoa(unsigned int n)
{
	char str[100];
	int multip = 1;
	int count = n/10;
	int to_write;
	int k = 0;

	while (count != 0)
	{
		count = count / 10;
		multip *= 10;
	}
	while (multip <= 1)
	{
		to_write = n / multip;
		n = n - (to_write * multip);
		multip = multip / 10;
		str[k] = to_write + '0';
		k++;
	}
	str[k]= '\0';
	return (str);
}*/

int main(int argc, char *argv[])
{
	int i = -1;
	char c;
	int multip = 1;
	int count;
	int to_write;

	if (argc ==1)
		i++;
	else
	{
		i++;
		while(argv[i])
		{
			i++;
		}
		i--;
	}
	count = i / 10;
	while (count != 0)
	{
		count = count / 10;
		multip *= 10;
	}
	while (multip >= 1)
	{
		to_write = i / multip;
		i = i - (to_write * multip);
		multip = multip / 10;
		c = to_write + '0';
		write(1, &c, 1);
	}
	write (1, "\n", 1);
	return (0);
}