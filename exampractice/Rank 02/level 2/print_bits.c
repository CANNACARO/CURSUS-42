#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;
	int pos;

	i = 0;
	while (i < 8)
	{
		pos = (octet >> (7 - i)) & 1;
		if (pos == 1)
			write(1, "1", 1);
		else if (pos == 0)
			write(1, "0", 1);
		i++;
	}
}
int main()
{
	unsigned char c;

	c = 2;
	print_bits(c);
}