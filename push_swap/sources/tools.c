/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:04:37 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/03 18:49:41 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_and_add_node(t_stacks *stacks, t_list *new, int num)
{
	t_list	*curr;

	if (stacks->sa == NULL)
		stacks->sa = new;
	else
	{
		curr = stacks->sa;
		while (curr -> next != NULL)
		{
			if (*((int *)curr->content) == num)
				free_stack(stacks);
			curr = curr ->next;
		}
		if (*((int *)curr->content) == num)
			free_stack(stacks);
		curr -> next = new;
	}/*Aquí podría contar y actualizar la varible size_sa*/
}
