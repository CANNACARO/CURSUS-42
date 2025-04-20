/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:54:11 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/20 16:41:38 by jcaro-lo         ###   ########.fr       */
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

void	init_lis(t_lis *l_val)
{
	l_val->len = NULL;
	l_val->pos = NULL;
	l_val->lis = NULL;
	l_val->count = 0;
	l_val->min_value = 0;
	l_val->min_iter = 0;
	l_val->max_iter = 1;
	l_val->lis_len = 0;
	l_val->max_pos = 0;
	l_val->act_first_pos = -1;
	l_val->act_first_val = 0;
	l_val->a_copy = NULL;
	l_val->aux = NULL;
	l_val->aux2 = NULL;
}

void	init_place(t_place *place)
{
	place->moves = NULL;
	place->aux_moves = NULL;
	place->min_val = 0;
	place->max_val = 0;
	place->max_val_right = 0;
	place->max_val_rev = 0;
	place->max_pos = -1;
	place->max_pos_right = -1;
	place->max_pos_rev = -1;
	place->max_iter_a = 0;
	place->max_iter_b = 0;
	place->cnt_b = 0;
	place->cnt_b = 0;
	place->iter_sa = NULL;
	place->iter_sb = NULL;
	place->iter_rev_sa = NULL;
	place->iter_rev_sb = NULL;
}
