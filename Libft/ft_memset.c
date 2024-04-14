/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:43:41 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/04/14 09:05:13 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *s;
	size_t count;

	s = b;
	count = 0;
	while (count < len)
	{
		s[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
