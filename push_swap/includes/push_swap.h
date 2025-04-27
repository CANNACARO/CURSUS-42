/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 10:13:25 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/27 12:26:33 by jcaro-lo         ###   ########.fr       */
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

/*It store the data necessary to place the elements of b
	in the correct order in a*/
typedef struct s_place
{
	int		*moves;
	int		*aux_moves;
	int		min_val;
	int		max_val;
	int		max_val_right;
	int		max_val_rev;
	int		max_pos;
	int		max_pos_right;
	int		max_pos_rev;
	int		max_iter_a;
	int		max_iter_b;
	int		cnt_a;
	int		cnt_b;
	int		aux;
	t_list	*iter_sa;
	t_list	*iter_sb;
	t_list	*iter_rev_sa;
	t_list	*iter_rev_sb;
}	t_place;

/*It store values to manage positions and sort values*/
typedef struct s_sort
{
	int		curr_pos;
	int		min_pos;
	int		to_end;
	int		min_value;
	t_list	*lst;
}	t_sort;

/*Structure that store information to support
the search of lis (longest increasing subsequence)*/
typedef struct s_lis
{
	int		*len; //It stores the cumulative length
	int		*pos; //It stores the pos of the previous value of len
	int		*lis; //It stores the LIS of *a_copy
	int		count;
	int		min_iter;
	int		max_iter;
	int		min_value;
	int		lis_len;
	int		max_pos; //Position of the maximum value of array *len
	int		act_first_pos; /*Position of the actual first element of LIS
	 						on array *lis (the element that would be the 
							first without *a_copy)*/
	int		act_first_val;//Value contained at act_first_pos
	t_list	*a_copy;
	t_list	*aux;
	t_list	*aux2;
}	t_lis;

//FREE PROGRAM

/*it frees the struct t_strtol and send an error message*/
void		free_structs(t_stacks *stacks, t_strtol *support);
/*It frees the struct that store both stacks and send an error message*/
void		free_stack(t_stacks *stacks);
/*It frees the struct that store both stacks before to end the program*/
void		end_short(t_stacks *stacks);
/*It frees resources t_lis struct and t_stacks in case of error*/
void		free_lis_error(t_lis *lis_values, t_stacks *stacks);
/*It frees t_lis struct*/
void		free_lis(t_lis *lis_values);

//FREE PROGRAM 2

/*It frees original t_stacks and its reverse copy*/
void		free_all_stacks(t_stacks *stacks, t_stacks *rev_stacks);
/*It frees place and free_all_stacks  in case of error*/
void		free_place(t_stacks *stacks, t_stacks *rev_stacks, t_place *place);
/*It frees all resources and ends the program 
	when the number of elements is higher than five*/
void		end_long(t_stacks *stacks, t_stacks *rev_stacks, t_place *place);

//INIT

/*It initiates the struct t_sstrtol*/
void		init_support_strtol(t_strtol *support);
/*It initiates the struct t_stacks*/
void		init_stacks(t_stacks *stacks);
/*It initiates the sturct t_lis*/
void		init_lis(t_lis *l_val);
/*It initiates the struct t_place*/
void		init_place(t_place *place);

//PUSH SWAP

/*It converts a string into integers*/
int			ft_strtol(t_stacks *stacks, t_strtol *support, char *str);
/*It creates a node and fill it with vaulues*/
t_list		*fill_node(t_stacks *stacks, int value);
/*It converts the arguments into a linked list*/
t_stacks	*parse_data(t_stacks *stacks, char *str[]);

//TOOLS

/*It checks if the number is repeated and add the node into the linked list*/
void		ft_check_and_add_node(t_stacks *stacks,
				t_list *new, int num, t_strtol *support);
/*It checks if the list if already sorted*/
void		check_sort(t_stacks *stacks);
/*It checks if a lon list if already sorted*/
void		check_sort_long(t_stacks *stacks, t_lis *l_val);
/*It run the instruction function an print it*/
void		print_istruction(t_stacks *stacks,
				void (*f)(t_stacks *), char *instr);
/*It creates a copy of a list contained in stacks*/
t_list		*copy_list(t_stacks *stacks, t_list *lst);

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
/*It sorts a list with more than five numbers*/
void		sort_long(t_stacks *stacks);

//LIS

/*Starts findind longest increasing subsequence (it mostly initiates values)*/
void		find_lis(t_stacks *stacks, t_lis *lis_values);
/*It rotates the copy of the stack a till the min value is on top*/
void		rot_lis(t_lis *l_val);
/*It finds the min value on the copy of the stack a*/
void		find_min(t_lis *l_val);
/*It has the algorithm to find the lis*/
void		find_lis_algorithm(t_lis *lis_values);

//STORE LIS

/*It stores the position of the numbers contained in the LIS*/
void		store_lis_pos(t_stacks *stacks, t_lis *l_val);
/*It stores the numbers of the LIS*/
void		store_lis(t_lis *l_val);

// SORT LONG TOOLS

/*It pushes the numbers that are not contained on the LIS to stack b*/
void		push_no_lis(t_stacks *stacks, t_lis *l_val);
/*It place the numbers of b in the correct order of a
	 (It mostly initiates variables)*/
void		place_numbers(t_stacks *stacks);
/*Continuation of place_numbers*/
void		place_numbers2(t_stacks *stacks,
				t_stacks *rev_stacks, t_place *place);
/*Continuation of place numbers2*/
void		place_numbers3(t_stacks *stacks, t_place *place);
/*Continuation of place numbers3*/
void		place_numbers4(t_stacks *stacks,
				t_stacks *rev_stacks, t_place *place);

//SORT LONG TOOLS 2

/*It rotates stack a, right or reverse, the neccessary times to reach
	the position in which element of b should be pushed to a*/
void		rot_a(t_stacks *stacks, t_place *place);
/*It rotates stack b, right or reverse, the neccessary times to reach
	the position in which element of b should b pushed to a*/
void		rot_b(t_stacks *stacks, t_place *place);
/*It rotates both stacks at the same time the number of times
	they can ber rotates at the same time*/
void		rot_both(t_stacks *stacks, t_place *place);
/*It iterates over b right and reverse*/
void		iter_b(t_stacks *stacks, t_stacks *rev_stacks, t_place *place);
/*It iterates over a right and reverse*/
void		iter_a(t_stacks *stacks,
				t_stacks *rev_stacks, t_place *place, int value);

//SORT LONG TOOLS 3

/*It find the position of the first number of the LIS in sa original*/
void		find_act_first_pos(t_stacks *stacks, t_lis *l_val);
/*It finds the max position of a, in case that the element checked to
	be pushed is the maximum of both stacks and there is no range
	in a*/
void		find_max_pos(t_stacks *stacks,
				t_stacks *rev_stacks, t_place *place);
/*Continuation of find_max_pos*/
void		find_max_pos2(t_stacks *stacks, t_place *place);
/*Continuation of find_max_pos2*/
void		find_max_pos3(t_place *place);
/*It updates the array moves in case of be on a better case 
	than the case before*/
void		update_moves(t_place *place);

#endif