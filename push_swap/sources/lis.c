/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:37:18 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/14 20:52:07 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*It stores the position of the numbers contained in the LIS in array *lis*/
void	store_lis_pos(t_stacks *stacks,t_lis *l_val)
{
	l_val->min_iter = -1;
	while (++l_val->min_iter <= l_val->max_iter)
	{
		if (l_val->len[l_val->min_iter] > l_val->lis_len)
		{
			l_val->lis_len = l_val->len[l_val->min_iter];
			l_val->max_pos = l_val->min_iter;
		}
	}
	l_val->lis = malloc(sizeof(int)* l_val->lis_len);
	if(!l_val->lis)
		free_lis_error(stacks, l_val);
	l_val->lis_len--;
	while (l_val->lis_len >= 0)
	{
		l_val->lis[l_val->lis_len] = l_val->max_pos;
		l_val->max_pos = l_val->pos[l_val->max_pos];
		l_val->lis_len--;
	}
}


/*It has the algorithm to find the lis*/
void	find_lis_algorithm(t_lis *lis_values)
{
	lis_values->aux2 = lis_values->a_copy->next;
	while (lis_values->aux2->next != NULL)
	{
		lis_values->aux = lis_values->a_copy;
		lis_values->min_iter = 0;
		while (lis_values->min_iter < lis_values->max_iter)
		{
			if (*((int *)lis_values->aux->content) < *((int *)lis_values->aux->next->content))
			{
				lis_values->len[lis_values->max_iter] = 1 + lis_values->len[lis_values->min_iter];
				lis_values->pos[lis_values->max_iter] = lis_values->min_iter;
			}
			lis_values->aux = lis_values->aux->next;
			lis_values->min_iter++;
		}
		lis_values->aux2 = lis_values->aux2->next;
		lis_values->max_iter++;
	}
}

/*It finds the min value on the copy of the stack a*/
void	find_min(t_lis *l_val)
{
	l_val->aux = l_val->a_copy;
	l_val->min_value = *((int *)l_val->aux->content);
	while (l_val->aux->next != NULL)
	{
		if ( *((int *)l_val->aux->next->content) < l_val->min_value)
			l_val->min_value = *((int *)l_val->aux->next->content);
		l_val->aux = l_val->aux->next;
	}
}

/*It rotates the copy of the stack a till the min value is on top*/
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

/*Starts findind longest increasing subsequence (it mostly initiates values)*/
void	find_lis(t_stacks *stacks, t_lis *lis_values)
{
	lis_values->a_copy = copy_list(stacks, stacks->sa);
	lis_values->len = malloc(sizeof(int) * stacks->size_sa);
	if(!lis_values->len)
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
	/*Hasta aquí esta bien*/
	find_lis_algorithm(lis_values);
	store_lis_pos(stacks, lis_values);
	/*Ahora tendria que iterar sobre la lista a_copy y guardar los numeros que forman
	 el lis pisando los valores de las posiciones por los valores de los numeros
	 que hay en la lista en esas posiciones*/
}
