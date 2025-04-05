/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:37:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/05 16:48:22 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stacks *stacks)
{
	t_list	*aux;
	t_list	*curr;
	
	if (!stacks->sa || !stacks->sa->next)
		return ;
	curr = stacks->sa;
	while (curr->next->next != NULL)
		curr = curr->next;
	curr->next->next = stacks->sa;
	aux = curr->next;
	curr->next= NULL;
	stacks->sa = aux;
}

void	rrb(t_stacks *stacks)
{
	t_list	*aux;
	t_list	*curr;
	
	if (!stacks->sb || !stacks->sb->next)
		return ;
	curr = stacks->sb;
	while (curr->next->next != NULL)
		curr = curr->next;
	curr->next->next = stacks->sb;
	aux = curr->next;
	curr->next= NULL;
	stacks->sb = aux;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
