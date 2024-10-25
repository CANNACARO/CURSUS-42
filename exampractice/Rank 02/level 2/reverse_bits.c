
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 0;
	unsigned char	result;
	result = 0;
	
	while (i < 8)
	{
		result = (result << 1) | ((octet >> i) & 1);
		i++;
	}
	return result;
}

int main()
{
	unsigned char c = '2';
	unsigned char rev= reverse_bits(c);
	write(1, &rev, 1);
}