/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:35:19 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/12 18:50:47 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**get_gnl_stack(void)
{
	static char	*stack[4096] = {NULL};

	return (stack);
}

void	clear_gnl_stack(void)
{
	char	**stack;
	int		i;

	stack = get_gnl_stack();
	i = 0;
	while (i < 4096)
	{
		free(stack[i]);
		stack[i] = NULL;
		i++;
	}
}
