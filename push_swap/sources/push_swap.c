/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:05:11 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/31 21:01:45 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strtol(t_stacks *stacks, t_strtol *support, char *str)
{
	support->res = 0;
	support->sign = 1;
	if (str[support->j] == '+' || str[support->j] == '-')
	{
		if (str[support->j] == '-')
			support->sign = support->sign * -1;
		support->j++;
	}
	if (str[support->j] == '+' || str[support->j] == '-'
		|| ft_is_space(str[support->j]))
		free_structs(stacks, support);
	while (str[support->j])
	{
		if (str[support->j] < '0' || str[support->j] > '9')
			break ;
		support->res = str[support->j] - 48 + support->res * 10;
		support->j++;
	}
	support->res *= support->sign;
	if ((!ft_is_space(str[support->j]) && str[support->j])
		|| support->res > INT_MAX || support->res < INT_MIN)
		free_structs(stacks, support);
	return ((int)(support->res));
}

t_list	*fill_node(t_stacks *stacks, int value)
{
	int		*stored_value;
	t_list	*lst;

	stored_value = malloc(sizeof(int));
	if (!stored_value)
		free_stack(stacks);
	*stored_value = value;
	lst = ft_lstnew(stored_value);
	if (!lst)
	{
		free(stored_value);
		free_stack(stacks);
	}
	return (lst);
}

void	parse_data(t_stacks *stacks, char *str[])
{
	t_strtol	*support_strtol;
	t_list		*lst;
	int			num;

	support_strtol = malloc(sizeof(t_strtol));
	if (!support_strtol)
		free_stack(stacks);
	init_support_strtol(support_strtol);
	while (str[support_strtol->i])
	{
		support_strtol->j = 0;
		while (str[support_strtol->i][support_strtol->j])
		{
			while (ft_is_space(str[support_strtol->i][support_strtol->j]))
				support_strtol->j++;
			num = ft_strtol(stacks, support_strtol, str[support_strtol->i]);
			lst = fill_node(stacks, num);
			ft_lstadd_back(&(stacks->sa), lst);
			if (str[support_strtol->i][support_strtol->j])
				support_strtol->j++;
		}
		support_strtol->i++;
	}
	free(support_strtol);
}

int	main(int argc, char *argv[])
{
	t_stacks	*stacks;

	if (argc < 2)
		exit(0);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	init_stacks(stacks);
	parse_data(stacks, argv);
	/*tengo que comprobar si hay números repetidos,
	 ver si lo hago durante el parseo o despues,
	 tal vez lo pueda hacer mientras compruebo
	 si la lista esta ordenada*/
	t_list *node;
	node = stacks->sa;
	while(node != NULL)
	{
		ft_printf("%d\n", *((int*)node->content));
		node = node->next;
	}
	return(0);
}
