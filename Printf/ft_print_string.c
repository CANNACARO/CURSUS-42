/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:28:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/07/13 17:03:48 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		ft_print_char(s[i]);
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char *test;

	test = "0x";
	//ft_print_string(test);
	//printf("%s",test);
	printf("\n%d", ft_print_string(test));
}*/