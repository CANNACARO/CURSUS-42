/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:01:03 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/04/28 18:19:34 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	if (!s)
		return (NULL);
	p = malloc((int)len + 1);
	if (!p)
		return (NULL);
	i = start;
	while (i < (int)start + (int)len && (int)start < ft_strlen(s))
	{
		p[i - (int)start] = s[i];
		i++;
	}
	p[i - (int)start] = '\0';
	return (p);
}

/*int main()
{
	printf("%s",ft_substr("",5,10));
}*/
