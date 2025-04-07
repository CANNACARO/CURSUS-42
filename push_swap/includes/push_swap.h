/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:13:25 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/07 20:31:38 by jcaro-lo         ###   ########.fr       */
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

/*It store values to manage positions and sort values*/
typedef struct s_sort
{
	int		curr_pos;
	int		min_pos;
	int		to_end;
	int		min_value;
	t_list	*lst;
}	t_sort;

//FREE PROGRAM

/*it frees the struct t_strtol and send an error message*/
void		free_structs(t_stacks *stacks, t_strtol *support);
/*It frees the struct that store both stacks and send an error message*/
void		free_stack(t_stacks *stacks);
/*It frees the struct that store both stacks before to end the program*/
void		end_program(t_stacks *stacks);

//INIT

/*It initiates the struct t_sstrtol*/
void		init_support_strtol(t_strtol *support);
/*It initiates the struct t_stacks*/
void		init_stacks(t_stacks *stacks);

//PUSH SWAP

/*It converts a string into integers*/
int			ft_strtol(t_stacks *stacks, t_strtol *support, char *str);
/*It creates a node and fill it with vaulues*/
t_list		*fill_node(t_stacks *stacks, int value);
/*It converts the arguments into a linked list*/
t_stacks	*parse_data(t_stacks *stacks, char *str[]);

//TOOLS

/*It cheks if the number is repeated and add the node into the linked list*/
void		ft_check_and_add_node(t_stacks *stacks, t_list *new, int num);
void		check_sort(t_stacks *stacks);
void		print_istruction(t_stacks *stacks,
				void (*f)(t_stacks *), char *instr);

//INSTRUCTIONS

/*It changes the position of the first two elements of stack a*/
void		sa(t_stacks *stacks);
/*It changes the position of the first two elements of stack b*/
void		sb(t_stacks *stacks);
/*sa and sb*/
void		ss(t_stacks *stacks);
/*It moves the fitst element of stack b to the first element of stack a*/
void		pa(t_stacks *stacks);
/*It moves the fitst element of stack a to the first element of stack b*/
void		pb(t_stacks *stacks);

//INSTRUCTIONS 2

/*It moves one position up all the elements of stack a,
 sending the first to the last position*/
void		ra(t_stacks *stacks);
/*It moves one position up all the elements of stack b,
 sending the first to the last position*/
void		rb(t_stacks *stacks);
/*ra and rb*/
void		rr(t_stacks *stacks);

//INSTRUCTIONS 3

/*It moves one position down all the elements of stack a,
 sending the last to the first position*/
void		rra(t_stacks *stacks);
/*It moves one position down all the elements of stack a,
 sending the last to the first position*/
void		rrb(t_stacks *stacks);
/*rra and rrb*/
void		rrr(t_stacks *stacks);

//SORT LIST

/*It sorts a given list of numbers*/
void		sort_list(t_stacks *stacks);
/*It sorts a list with three numbers*/
void		sort_three(t_stacks *stacks);
/*It pass two elemnts from stack a to stack b*/
void		divide_four_five(t_stacks *stacks, t_sort s_values);
/*It sorts a list with four or five numbers*/
void		sort_four_five(t_stacks *stacks);

#endif