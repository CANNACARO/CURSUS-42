/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:42:06 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/09/15 14:21:11 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	count;

	str = s;
	count = 0;
	while (count < n)
	{
		str[count] = '\0';
		count++;
	}
}

char	*ft_strchr(const char *s, size_t c)
{
	const char	*str_occur;
	size_t			i;

	if (!s)
		return (NULL);
	str_occur = "";
	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
		{
			str_occur = &s[i];
			return ((char *)str_occur);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		str_occur = &s[i];
		return ((char *)str_occur);
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	return (p);
}

// checkstack() looks for a '\n' in the middle of the buffer
size_t	checkstack(char *stack)
{
	size_t	i;

	i = 0;
	while (stack[i] != '\0')
	{
		if (stack[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
