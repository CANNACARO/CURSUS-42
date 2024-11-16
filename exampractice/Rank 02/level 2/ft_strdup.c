#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i;
	//int src_len;
	char *srt_cpy;

	i = 0;
	//src_len = 0;
	while (src[i])
		i++;
	srt_cpy = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		srt_cpy[i] = src[i];
		i++;
	}
	srt_cpy[i] = '\0';
	return (srt_cpy);
}

int main()
{
	printf("strdup real: %s\n", strdup("jose"));
	printf("ft_strdup: %s", ft_strdup("jose"));
}