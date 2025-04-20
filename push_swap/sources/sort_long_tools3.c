/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_tools3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:47:00 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/20 20:14:44 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_max_pos(t_stacks *stacks, t_stacks *rev_stacks, t_place *place)
{
	int	i;

	i = 0;
	place->iter_sa = stacks->sa;
	place->iter_rev_sa = rev_stacks->sa;
	place->max_val_right = *((int *)place->iter_sa->content);
	place->max_pos_right = 1;
	while (i < stacks->size_sa / 2)
	{
		if (*((int *)place->iter_sa->next->content)
			> place->max_val_right)
		{
			place->max_pos_right++;
			place->max_val_right = *((int *)place->iter_sa->next->content);
		}
		place->iter_sa = place->iter_sa->next;
		i++;
	}
	find_max_pos2(stacks, place);
	if (place->max_val_right > place->max_val_rev)
		place->max_pos = place->max_pos_right;
	else
		place->max_pos = place->max_pos_rev;
}

void	find_max_pos2(t_stacks *stacks, t_place *place)
{
	int	i;

	i = 0;
	place->max_pos_rev = 0;
	place->max_val_rev = *((int *)place->iter_rev_sa->content);
	while (i < stacks->size_sa / 2)
	{
		if (*((int *)place->iter_rev_sa->next->content)
			> place->max_val_rev)
		{
			place->max_pos_rev--;
			place->max_val_rev = *((int *)place->iter_rev_sa->next->content);
		}
		place->iter_rev_sa = place->iter_rev_sa->next;
		i++;
	}
}

void	update_moves(t_place *place)
{
	if (place->cnt_b == 0 && place->cnt_a == 0)
	{
		place->moves[0] = place->aux_moves[0];
		place->moves[1] = place->aux_moves[1];
	}
	else if ((ft_abs(place->aux_moves[0]) + ft_abs(place->aux_moves[1]))
		< (ft_abs(place->moves[0]) + ft_abs(place->moves[1])))
	{
		place->moves[0] = place->aux_moves[0];
		place->moves[1] = place->aux_moves[1];
	}
}
