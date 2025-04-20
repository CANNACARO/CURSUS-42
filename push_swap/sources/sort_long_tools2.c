/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:43:43 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/20 17:42:41 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot_a(t_stacks *stacks, t_place *place)
{
	while (place->moves[0] != 0)
	{
		if (place->moves[0] > 0)
		{
			print_istruction(stacks, ra, "ra\n");
			place->moves[0]--;
		}
		else
		{
			print_istruction(stacks, rra, "rra\n");
			place->moves[0]++;
		}
	}
}

void	rot_b(t_stacks *stacks, t_place *place)
{
	while (place->moves[1] != 0)
	{
		if (place->moves[1] > 0)
		{
			print_istruction(stacks, rb, "rb\n");
			place->moves[1]--;
		}
		else
		{
			print_istruction(stacks, rrb, "rrb\n");
			place->moves[1]++;
		}
	}
}

void	rot_both(t_stacks *stacks, t_place *place)
{
	if ((place->moves[0] * place->moves[1]) > 0)
	{
		if (place->moves[0] > 0)
		{
			while (place->moves[0] > 0 && place->moves[1] > 0)
			{
				print_istruction(stacks, rr, "rr\n");
				place->moves[0]--;
				place->moves[1]--;
			}
		}
		else
		{
			while (place->moves[0] < 0 && place->moves[1] < 0)
			{
				print_istruction(stacks, rrr, "rr\n");
				place->moves[0]++;
				place->moves[1]++;
			}
		}
	}
}

void	iter_b(t_stacks *stacks, t_stacks *rev_stacks, t_place *place)
{
	while (place->cnt_b <= place->max_iter_b / 2)
	{
		place->iter_sa = stacks->sa;
		place->iter_rev_sa = rev_stacks->sa;
		place->cnt_a = 0;
		place->max_iter_a = ft_lstsize(stacks->sa);
		place->aux_moves[0] = -1;
		place->aux_moves[1] = place->cnt_b;
		iter_a(stacks, rev_stacks, place, *((int *)place->iter_sb->content));
		place->cnt_a = 0;
		update_moves(place);
		place->iter_sa = stacks->sa;
		place->iter_rev_sa = rev_stacks->sa;
		place->aux_moves[0] = -1;
		place->aux_moves[1] = (place->cnt_b * -1) - 1;
		iter_a(stacks, rev_stacks, place,
			*((int *)place->iter_rev_sb->content));
		update_moves(place);
		place->iter_sb = place->iter_sb->next;
		place->iter_rev_sb = place->iter_rev_sb->next;
		place->cnt_b++;
	}
}

void	iter_a(t_stacks *stacks,
	t_stacks *rev_stacks, t_place *place, int value)
{
	while (place->cnt_a < place->max_iter_a / 2)
	{
		if (value < *((int *)place->iter_sa->content)
			&& value > *((int *)place->iter_rev_sa->content)
			&& place->cnt_a == 0)
			place->aux_moves[0] = 0;
		if (value > *((int *)place->iter_sa->content)
			&& value < *((int *)place->iter_sa->next->content))
			place->aux_moves[0] = place->cnt_a + 1;
		if (value < *((int *)place->iter_rev_sa->content)
			&& value > *((int *)place->iter_rev_sa->next->content))
			place->aux_moves[0] = place->cnt_a * (-1) - 1;
		place->iter_sa = place->iter_sa->next;
		place->iter_rev_sa = place->iter_rev_sa->next;
		place->cnt_a++;
	}
	if (place->aux_moves[0] == -1)
	{
		find_max_pos(stacks, rev_stacks, place);
		place->aux_moves[0] = place->max_pos;
	}
}
