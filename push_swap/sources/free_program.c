/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:55:58 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/07 19:36:40 by jcaro-lo         ###   ########.fr       */
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

void	end_program(t_stacks *stacks)
{
	if (stacks->sa)
		ft_lstclear(&stacks->sa, del_pointer);
	if (stacks->sb)
		ft_lstclear(&stacks->sb, del_pointer);
	free(stacks);
	exit(1);
}
