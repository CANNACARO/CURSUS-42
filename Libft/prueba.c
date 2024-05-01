/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:53 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/05/01 12:47:46 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int	j;
	int	s1_len;
	int str_size;
	int aux;
	int start_str;
	char *str;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	str_size = 0;
	aux = i;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break;
			}
			j++;
		}
		if (aux == i)
			break;
		aux = i;	
	}
	start_str = i;
	while (s1[i])
	{
		str_size++;
		i++;
	}
	i = s1_len - 1;
	aux = i;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if(s1[i] == set[j])
			{
				i--;
				str_size--;
				break;
			}
			j++;
		}
		if (aux == i)
			break;
		aux = i;	
	}
	if(str_size <= 0 || start_str >= s1_len)
		return (ft_strdup(""));
	
	str = malloc(sizeof(char) * (str_size + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (i < str_size)
	{
		str[i] = s1[start_str + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int count_trim(const char *set, char c)
{
	int	i;

	i = 0;
	while(set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}


char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int str_size;
	int start_str;
	char *str;

	i = 0;
	if (ft_strlen(s1) == 0)
        return (ft_strdup(""));
	while (count_trim(set,s1[i]))
		i++;		
	start_str = i;
	i = ft_strlen(s1) - 1;
	while (count_trim(set, s1[i]))
		i--;	
	str_size = i + 1 - start_str;
	if(str_size <= 0 || start_str >= ft_strlen(s1))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (str_size + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (i < str_size)
	{
		str[i] = s1[start_str + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int main(void)
{
	printf("%s", ft_strtrim("lorem ipsum dolor sit amet","te"));
}*/