/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:42:06 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/09/28 10:15:40 by jcaro-lo         ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	if (s1 != NULL && *s1 != '\0')
		my_free ((void *) s1);
	return (p);
}

size_t	checkstack(char *stack)
{
	size_t	i;

	i = 0;
	if (!stack)
		return (0);
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

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
