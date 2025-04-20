/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 10:25:29 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/19 17:34:16 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all_stacks(t_stacks *stacks, t_stacks *rev_stacks)
{
	if (rev_stacks->sa)
		ft_lstclear(&rev_stacks->sa, del_pointer);
	if (rev_stacks->sb)
		ft_lstclear(&rev_stacks->sb, del_pointer);
	free(rev_stacks);
	free_stack(stacks);
}

void	free_place(t_stacks *stacks, t_stacks *rev_stacks, t_place *place)
{
	if (place->moves)
		free(place->moves);
	if (place->aux_moves)
		free(place->aux_moves);
	free(place);
	free_all_stacks(stacks, rev_stacks);
}

void	end_long(t_stacks *stacks, t_stacks *rev_stacks, t_place *place)
{
	if (stacks->sa)
		ft_lstclear(&stacks->sa, del_pointer);
	if (stacks->sb)
		ft_lstclear(&stacks->sb, del_pointer);
	free(stacks);
	free(rev_stacks);
	if (place->moves)
		free(place->moves);
	if (place->aux_moves)
		free(place->aux_moves);
	free(place);
	exit(0);
}
