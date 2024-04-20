/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:53 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/04/20 11:18:05 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
//#include <bsd/string.h>
size_t ft_strlen(const char *s);
void ft_memcpy(void *dst, const void *src, size_t n);
/*size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		idx;
	size_t		count;

	idx = 0;
	count = 0;
	if (!dest || !src)
		return (0);
	while (src[count])
		count++;
	while (src[idx] && idx + 1 < size)
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (size)
		dest[idx] = '\0';
	return (count);
}*/


int	main(void)
{
	char src[]= "hola";
	char *dest;
	int x;
	
	//x = ft_strlcpy(dest, src, 0);
	memmove(dest,src, 7);
	printf("%s",dest);
}

/*memmove original me lanza un error al poner el numero de caracteres mayor al de la fuente
prueba.c:22:9: error: ‘__builtin_memcpy’ reading 6 bytes from a region of size 5 [-Werror=stringop-overread]
   22 |         memmove(dest, src, 6);
   
   Mi ft_strlcpy hace segfault (core dumped) cuando pon size = 0
   
   
   */
