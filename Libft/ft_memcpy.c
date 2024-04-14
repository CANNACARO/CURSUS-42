/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:21:19 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/04/14 17:17:37 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t count;
	char	*str_dest;
	const char	*str_src;

	count = 0;
	str_dest = dst;
	str_src = src;
	while (count < n)
	{
		str_dest[count] = str_src[count];
		count++;
	}
	return (dst);
}

int	main(void)
{
	char	source[]= "hola";
	char	destiny[]= "adiossss";

	printf("%s",ft_memcpy(destiny,source,5));
}
