/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:37:18 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/20 13:59:10 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_lis_algorithm(t_lis *lis_values)
{
	lis_values->aux2 = lis_values->a_copy->next;
	while (lis_values->aux2 != NULL)
	{
		lis_values->aux = lis_values->a_copy;
		lis_values->min_iter = 0;
		while (lis_values->min_iter < lis_values->max_iter)
		{
			if (*((int *)lis_values->aux->content)
				< *((int *)lis_values->aux2->content)
				&& ((1 + lis_values->len[lis_values->min_iter])
				>= lis_values->len[lis_values->max_iter]))
			{
				lis_values->len[lis_values->max_iter] = 1
					+ lis_values->len[lis_values->min_iter];
				lis_values->pos[lis_values->max_iter] = lis_values->min_iter;
			}
			lis_values->aux = lis_values->aux->next;
			lis_values->min_iter++;
		}
		lis_values->aux2 = lis_values->aux2->next;
		lis_values->max_iter++;
	}
}

void	find_min(t_lis *l_val)
{
	l_val->aux = l_val->a_copy;
	l_val->min_value = *((int *)l_val->aux->content);
	while (l_val->aux->next != NULL)
	{
		if (*((int *)l_val->aux->next->content) < l_val->min_value)
			l_val->min_value = *((int *)l_val->aux->next->content);
		l_val->aux = l_val->aux->next;
	}
}

void	rot_lis(t_lis *l_val)
{
	t_list	*aux;
	t_list	*curr;

	while (*((int *)l_val->a_copy->content) != l_val->min_value)
	{
		aux = l_val->a_copy;
		l_val->a_copy = l_val->a_copy->next;
		curr = l_val->a_copy;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = aux;
		curr->next->next = NULL;
	}
}

void	find_lis(t_stacks *stacks, t_lis *lis_values)
{
	lis_values->a_copy = copy_list(stacks, stacks->sa);
	if (!lis_values->a_copy)
		free_stack(stacks);
	lis_values->len = malloc(sizeof(int) * stacks->size_sa);
	if (!lis_values->len)
		free_lis_error(lis_values, stacks);
	while (lis_values->count < stacks->size_sa)
	{
		lis_values->len[lis_values->count] = 1;
		lis_values->count++;
	}
	lis_values->pos = malloc(sizeof(int) * stacks->size_sa);
	if (!lis_values->pos)
		free_lis_error(lis_values, stacks);
	lis_values->count = 0;
	while (lis_values->count < stacks->size_sa)
	{
		lis_values->pos[lis_values->count] = -1;
		lis_values->count++;
	}
	find_min(lis_values);
	rot_lis(lis_values);
	find_lis_algorithm(lis_values);
	store_lis_pos(stacks, lis_values);
	store_lis(lis_values);
}
