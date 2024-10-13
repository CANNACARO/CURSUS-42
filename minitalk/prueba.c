#include <unistd.h>
int main()
{
	int x = 65;
	char c = (char)x;
	write(1, &c, 1);
	return (0);
}