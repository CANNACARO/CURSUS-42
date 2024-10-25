#include <unistd.h>

unsigned char swap_bits(unsigned char octet)
{
	int i = 0;
	char result;
	char aux;
	
	result = octet << 4;
	aux = octet >> 4;
	result = (result) | (aux);
	return (result);
}

int main()
{
	unsigned char c = '2';
	unsigned char swap= swap_bits(c);
	write(1, &swap, 1);
}