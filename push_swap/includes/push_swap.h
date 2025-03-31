/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:13:25 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/31 21:03:56 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;*/

typedef struct s_stacks
{
	t_list	*sa;
	t_list	*sb;
	int		size_sa;
	int		size_sb;
}	t_stacks;

typedef struct s_strtol
{
	int		i;
	int		j;
	long	sign;
	long	res;
}	t_strtol;

//free_program

void	free_structs(t_stacks *stacks, t_strtol *support);
void	free_stack(t_stacks *stacks);

//init

void	init_support_strtol(t_strtol *support);
void	init_stacks(t_stacks *stacks);

//push swap

int		ft_strtol(t_stacks *stacks, t_strtol *support, char *str);
t_list	*fill_node(t_stacks *stacks, int value);
void	parse_data(t_stacks *stacks, char *str[]);

#endif