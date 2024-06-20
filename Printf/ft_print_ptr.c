/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:13:12 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/06/20 11:17:06 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_print_char(char c);
int	ft_print_string(char *s);

static int	count_char(unsigned long long value)
{
	int	sum;

	sum = 0;
	while (value != 0)
	{
		value = value / 16;
		sum++;
	}
	return (sum);
}

static void	ft_conv_hexa(unsigned long long value)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (value >= 16)
	{
		ft_conv_hexa(value / 16);
		ft_conv_hexa(value % 16);
	}
	else
	{
		ft_print_char(base[value]);
	}
}

int	ft_print_ptr(void *ptr)
{
	int	size;

	size = 0;
	size += ft_print_string("0x");
	if (ptr == 0)
		size += ft_print_char('0');
	else
	{
		ft_conv_hexa((unsigned long long) ptr);
		size += count_char((unsigned long long) ptr);
	}
	return (size);
}

/*int	main(void)
{
	char c;
	char *point;
	point = &c;

	printf("\n%d",ft_print_ptr((void *) point));
}*/
