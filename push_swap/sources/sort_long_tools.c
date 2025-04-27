/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:10:49 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/27 12:20:26 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_no_lis(t_stacks *stacks, t_lis *l_val)
{
	while (l_val->count < l_val->lis_len)
	{
		if (*((int *)stacks->sa->content) == l_val->lis[l_val->count])
		{
			print_istruction(stacks, ra, "ra\n");
			check_sort_long(stacks, l_val);
			l_val->count++;
		}
		else
			print_istruction(stacks, pb, "pb\n");
	}
	l_val->count = 0;
	while (l_val->count < l_val->act_first_pos)
	{
		if (*((int *)stacks->sa->content) == l_val->lis[l_val->count])
		{
			print_istruction(stacks, ra, "ra\n");
			check_sort_long(stacks, l_val);
			l_val->count++;
		}
		else
			print_istruction(stacks, pb, "pb\n");
	}
	while (*((int *)stacks->sa->content) != l_val->act_first_val)
		print_istruction(stacks, pb, "pb\n");
}

void	place_numbers(t_stacks *stacks)
{
	t_stacks	*rev_stacks;
	t_place		*place;

	rev_stacks = malloc(sizeof(t_stacks));
	if (!rev_stacks)
		free_stack(stacks);
	init_stacks(rev_stacks);
	place = malloc(sizeof(t_place));
	if (!place)
		free_all_stacks(stacks, rev_stacks);
	init_place(place);
	place->moves = malloc(sizeof(int) * 2);
	if (!place->moves)
		free_place(stacks, rev_stacks, place);
	place->aux_moves = malloc(sizeof(int) * 2);
	if (!place->aux_moves)
		free_place(stacks, rev_stacks, place);
	place_numbers2(stacks, rev_stacks, place);
}

void	place_numbers2(t_stacks *stacks, t_stacks *rev_stacks, t_place *place)
{
	while (stacks->sb != NULL)
	{
		rev_stacks->sa = copy_list(stacks, stacks->sa);
		if (!rev_stacks->sa)
			free(place);
		rev_stacks->sb = copy_list(stacks, stacks->sb);
		if (!rev_stacks->sb)
			free(place);
		ft_lstreverse(&rev_stacks->sa);
		ft_lstreverse(&rev_stacks->sb);
		place->iter_sb = stacks->sb;
		place->iter_rev_sb = rev_stacks->sb;
		place->cnt_b = 0;
		place->moves[0] = 0;
		place->moves[1] = 0;
		place->max_iter_b = ft_lstsize(stacks->sb);
		if (place->max_iter_b % 2 == 0)
			place->max_iter_b--;
		iter_b(stacks, rev_stacks, place);
		ft_lstclear(&rev_stacks->sa, NULL);
		ft_lstclear(&rev_stacks->sb, NULL);
		place_numbers3(stacks, place);
	}
	place_numbers4(stacks, rev_stacks, place);
}

void	place_numbers3(t_stacks *stacks, t_place *place)
{
	rot_both(stacks, place);
	rot_a(stacks, place);
	rot_b(stacks, place);
	print_istruction(stacks, pa, "pa\n");
}

void	place_numbers4(t_stacks *stacks, t_stacks *rev_stacks, t_place *place)
{
	place->iter_sa = stacks->sa;
	place->min_val = *((int *)place->iter_sa->content);
	while (place->iter_sa != NULL)
	{
		if (*((int *)place->iter_sa->content) < place->min_val)
			place->min_val = *((int *)place->iter_sa->content);
		place->iter_sa = place->iter_sa->next;
	}
	while (*((int *)stacks->sa->content) != place->min_val)
		print_istruction(stacks, ra, "ra\n");
	end_long(stacks, rev_stacks, place);
}
