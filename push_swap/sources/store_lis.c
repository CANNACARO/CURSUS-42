/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_lis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:40:42 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/20 14:51:43 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	store_lis_pos(t_stacks *stacks, t_lis *l_val)
{
	l_val->min_iter = 0;
	l_val->max_iter--;//aqui puedo quitarlo y en el bucle poner <, no <=
	while (l_val->min_iter <= l_val->max_iter)
	{
		if (l_val->len[l_val->min_iter] >= l_val->lis_len)
		{
			l_val->lis_len = l_val->len[l_val->min_iter];
			l_val->max_pos = l_val->min_iter;
		}
		l_val->min_iter++;
	}//len = 4 max_pos = 5
	l_val->lis = malloc(sizeof(int) * (l_val->lis_len));
	if (!l_val->lis)
		free_lis_error(l_val, stacks);
	l_val->max_iter = l_val->lis_len -1;
	while (l_val->max_iter >= 0)
	{
		l_val->lis[l_val->max_iter] = l_val->max_pos;
		l_val->max_pos = l_val->pos[l_val->max_pos];
		l_val->max_iter--;
	}
}

void	store_lis(t_lis *l_val)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	l_val->aux = l_val->a_copy;
	while (l_val->aux != NULL)
	{
		if (i == l_val->lis[j])
		{
			l_val->lis[j] = *((int *)l_val->aux->content);
			j++;
		}
		i++;
		l_val->aux = l_val->aux->next;
	}
}
