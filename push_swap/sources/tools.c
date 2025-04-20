/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:04:37 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/20 11:20:40 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check_and_add_node(t_stacks *stacks, t_list *new, int num, t_strtol *support)
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
			{
				ft_lstclear(&new, del_pointer);
				free_structs(stacks, support);
			}
			curr = curr ->next;
		}
		if (*((int *)curr->content) == num)
		{
			ft_lstclear(&new, del_pointer);
			free_structs(stacks, support);
		}
		curr -> next = new;
	}
	stacks->size_sa++;
}

void	check_sort(t_stacks *stacks)
{
	t_list	*curr;

	curr = stacks->sa;
	while (curr->next != NULL)
	{
		if (*((int *)curr->next->content) < *((int *)curr->content))
			return ;
		curr = curr->next;
	}
	ft_printf("The list is already sorted\n");
	end_short(stacks);
}

void	print_istruction(t_stacks *stacks, void (*f)(t_stacks *), char *instr)
{
	f (stacks);
	ft_printf("%s", instr);
	//check_sort(stacks);
}

t_list	*copy_list(t_stacks *stacks, t_list *lst)
{
	t_list	*curr_orig;
	t_list	*copy;
	t_list	*new_node;

	copy = malloc(sizeof(t_list));
	if (!copy)
		free_stack(stacks);
	copy->content = lst->content;
	copy->next = NULL;
	curr_orig = lst->next;
	while (curr_orig != NULL)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&copy, NULL);
			return (NULL);
		}
		new_node->content = curr_orig->content;
		new_node->next = NULL;
		ft_lstadd_back(&copy, new_node);
		curr_orig = curr_orig->next;
	}
	return (copy);
}
