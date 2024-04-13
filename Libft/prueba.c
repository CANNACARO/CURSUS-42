/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:53 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/04/13 19:28:52 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strlen(const char *s);

int	main(void)
{
	const char	*str;
	int			x;
	int			y;

	str = "donde vas ramoon?, arremonta que te llevo";
	x = strlen(str);
	y = ft_strlen(str);
	printf("real: %d, mio: %d \n", x, y);
}
