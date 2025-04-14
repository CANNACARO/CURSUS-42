/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:57:31 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/14 18:51:40 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = *((int *)stacks->sa->content);
	second = *((int *)stacks->sa->next->content);
	third = *((int *)stacks->sa->next->next->content);
	if (first > second && second < third && first < third)
		print_istruction(stacks, sa, "sa\n");
	if (first > second && second > third && first > third)
	{
		print_istruction(stacks, sa, "sa\n");
		print_istruction(stacks, rra, "rra\n");
	}
	if (first > second && second < third && first > third)
		print_istruction(stacks, ra, "ra\n");
	if (first < second && second > third && first < third)
	{
		print_istruction(stacks, sa, "sa\n");
		print_istruction(stacks, ra, "ra\n");
	}
	if (first < second && second > third && first > third)
		print_istruction(stacks, rra, "rra\n");
}

void	divide_four_five(t_stacks *stacks, t_sort s_values)
{
	while (stacks->size_sa > 3)
	{
		s_values.lst = stacks->sa;
		s_values.min_value = *((int *)s_values.lst->content);
		while (s_values.lst->next != NULL)
		{
			s_values.curr_pos++;
			if (*((int *)s_values.lst->content) < s_values.min_value)
			{
				s_values.min_value = *((int *)s_values.lst->content);
				s_values.min_pos = s_values.curr_pos;
			}
			s_values.lst = s_values.lst->next;
		}
		s_values.to_end = s_values.curr_pos - s_values.min_pos;
		while (*((int *)stacks->sa->content) != s_values.min_value)
		{
			if (s_values.curr_pos - 1 <= s_values.to_end + 1)
				print_istruction(stacks, ra, "ra\n");
			else
				print_istruction(stacks, rra, "rra\n");
		}
		print_istruction(stacks, pb, "pb\n");
	}
}

void	sort_four_five(t_stacks *stacks)
{
	t_sort	s_values;

	s_values.curr_pos = 0;
	s_values.min_pos = 0;
	s_values.to_end = 0;
	divide_four_five(stacks, s_values);
	sort_three(stacks);
	print_istruction(stacks, pa, "pa\n");
	print_istruction(stacks, pa, "pa\n");
}

void	sort_long(t_stacks *stacks)
{
	t_lis	*lis_values;
	
	lis_values = malloc(sizeof(t_lis));
	if (!lis_values)
		free_stack(stacks);
	init_lis(lis_values);
	find_lis(stacks, lis_values);
	t_list *node;
	node = lis_values->a_copy;
	while(node != NULL)
	{
		ft_printf("%d\n", *((int*)node->content));
		node = node->next;
	}

	/*Aqui tengo que liberar lis_values al final*/
}

void	sort_list(t_stacks *stacks)
{
	if (stacks->size_sa == 2)
		print_istruction(stacks, sa, "sa\n");
	else if (stacks->size_sa == 3)
		sort_three(stacks);
	else if (stacks->size_sa > 3 && stacks->size_sa <= 5)
		sort_four_five(stacks);
	else
		sort_long(stacks);
	
}
