/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:55:58 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/18 11:02:14 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_structs(t_stacks *stacks, t_strtol *support)
{
	if (support)
		free(support);
	free_stack(stacks);
}

void	free_stack(t_stacks *stacks)
{
	if (stacks->sa)
		ft_lstclear(&stacks->sa, del_pointer);
	if (stacks->sb)
		ft_lstclear(&stacks->sb, del_pointer);
	free(stacks);
	ft_printf("Error\n");
	exit(1);
}

void	free_lis_error(t_lis *lis_values, t_stacks *stacks)
{
	free_lis(lis_values);
	free_stack(stacks);
}

void	free_lis(t_lis *lis_values)
{
	if (lis_values->len)
		free (lis_values->len);
	if (lis_values->pos)
		free (lis_values->pos);
	if (lis_values->lis)
		free (lis_values->lis);
	if (lis_values->a_copy)
		ft_lstclear(&lis_values->a_copy, NULL);
	free(lis_values);
}

void	end_short(t_stacks *stacks)
{
	if (stacks->sa)
		ft_lstclear(&stacks->sa, del_pointer);
	if (stacks->sb)
		ft_lstclear(&stacks->sb, del_pointer);
	free(stacks);
	exit(0);
}
