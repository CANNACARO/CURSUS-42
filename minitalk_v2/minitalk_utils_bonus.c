/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:39:37 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/15 19:30:41 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = str[i] - 48 + res * 10;
		i++;
	}
	res = res * sign;
	return (res);
}

void	ft_putnbr(char *s, int n, int size)
{
	int	i;

	i = 0;
	s[i] = '0';
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	while (size - 1 >= i)
	{
		if (n < 0)
		{
			s[size - 1] = -(n % 10) + '0';
		}
		else
		{
			s[size - 1] = n % 10 + '0';
		}
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		str_size;
	char	*str;
	int		nbr;

	nbr = n;
	str_size = 0;
	if (nbr < 0)
		str_size++;
	if (nbr == 0)
		str_size++;
	while (nbr != 0)
	{
		str_size++;
		nbr = nbr / 10;
	}
	str = malloc(sizeof(char) * (str_size + 1));
	if (!str)
		return (NULL);
	ft_putnbr(str, n, str_size);
	str[str_size] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*point;
	size_t	i;

	i = 0;
	point = malloc(ft_strlen(s1) + 1);
	if (!point)
		return (NULL);
	while (s1[i])
	{
		point[i] = s1[i];
		i++;
	}
	point[i] = '\0';
	return (point);
}
