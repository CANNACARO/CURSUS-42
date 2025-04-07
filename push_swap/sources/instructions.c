/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 20:07:50 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/06 12:09:52 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stacks *stacks)
{
	t_list	*aux1;
	t_list	*aux2;

	if (!stacks->sa || !stacks->sa->next)
		return ;
	aux1 = stacks->sa;
	aux2 = stacks->sa->next;
	aux1->next = aux2->next;
	aux2->next = aux1;
	stacks->sa = aux2;
}

void	sb(t_stacks *stacks)
{
	t_list	*aux1;
	t_list	*aux2;

	if (!stacks->sb || !stacks->sb->next)
		return ;
	aux1 = stacks->sb;
	aux2 = stacks->sb->next;
	aux1->next = aux2->next;
	aux2->next = aux1;
	stacks->sb = aux2;
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks *stacks)
{
	t_list	*aux;

	if (!stacks->sb)
		return ;
	aux = stacks->sb;
	stacks->sb = stacks->sb->next;
	aux->next = stacks->sa;
	stacks->sa = aux;
	stacks->size_sa++;
	stacks->size_sb--;
}

void	pb(t_stacks *stacks)
{
	t_list	*aux;

	if (!stacks->sa)
		return ;
	aux = stacks->sa;
	stacks->sa = stacks->sa->next;
	aux->next = stacks->sb;
	stacks->sb = aux;
	stacks->size_sa--;
	stacks->size_sb++;
}
