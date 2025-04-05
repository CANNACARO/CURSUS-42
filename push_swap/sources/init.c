/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:54:11 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/05 11:02:27 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_support_strtol(t_strtol *support)
{
	support->i = 1;
	support->j = 0;
	support->res = 0;
	support->sign = 1;
}

void	init_stacks(t_stacks *stacks)
{
	stacks->sa = NULL;
	stacks->sb = NULL;
	stacks->size_sa = 0;
	stacks->size_sb = 0;
}
