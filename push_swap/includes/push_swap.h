/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:13:25 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/03 19:02:21 by jcaro-lo         ###   ########.fr       */
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

/*Struct to store stacks a and b and its sizes*/
typedef struct s_stacks
{
	t_list	*sa;
	t_list	*sb;
	int		size_sa;
	int		size_sb;
}	t_stacks;

/*Struct to store the data of the function ft_strtol*/
typedef struct s_strtol
{
	int		i;
	int		j;
	long	sign;
	long	res;
}	t_strtol;

//free_program

/*it frees the struct t_strtol*/
void	free_structs(t_stacks *stacks, t_strtol *support);
/*It frees the struct that store both stacks*/
void	free_stack(t_stacks *stacks);

//init

/*It initiates the struct t_sstrtol*/
void	init_support_strtol(t_strtol *support);
/*It initiates the struct t_stacks*/
void	init_stacks(t_stacks *stacks);

//push swap

/*It converts a string into integers*/
int		ft_strtol(t_stacks *stacks, t_strtol *support, char *str);
/*It creates a node and fill it with vaulues*/
t_list	*fill_node(t_stacks *stacks, int value);
/*It converts the arguments into a linked list*/
void	parse_data(t_stacks *stacks, char *str[]);

//tools

/*It cheks if the number is repeated and add the node into the linked list*/
void	ft_check_and_add_node(t_stacks *stacks, t_list *new, int num);

#endif