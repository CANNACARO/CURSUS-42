/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:13:05 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/13 17:51:28 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stacks *stacks)
{
	t_list	*aux;
	t_list	*curr;

	if (!stacks->sa || !stacks->sa->next)
		return ;
	aux = stacks->sa;
	stacks->sa = stacks->sa->next;
	curr = stacks->sa;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = aux;
	curr->next->next = NULL;
}

void	rb(t_stacks *stacks)
{
	t_list	*aux;
	t_list	*curr;

	if (!stacks->sb || !stacks->sb->next)
		return ;
	aux = stacks->sb;
	stacks->sb = stacks->sb->next;
	curr = stacks->sb;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = aux;
	curr->next->next = NULL;
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}


