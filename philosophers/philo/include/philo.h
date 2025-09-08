/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:38:21 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/08 18:46:31 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>
# include <stdlib.h>


# define ERR_ALLOC "Allocation ERROR\n"
# define ERR_INPUT "The input contains a not number argument\n"
# define ERR_INPUT_NUMBER "The number of arguments is not correct\n"

typedef struct s_philo
{
	struct s_data	*data;	// Array to struct data
	pthread_t		th;		// Thread for each philosopher
}	t_philo;

typedef struct s_data
{
	int				philo_nb;	// Number of philosophers
	int				food_nb;	// Number of times each philo must eat
	uint64_t		death_t;	// Time to die (ms)
	uint64_t		eat_t;		// Time to eat (ms)
	uint64_t		sleep_t;	// Time to sleep (ms)
	t_philo			*philos;	// Array to struct t_philos
	pthread_mutex_t	*forks;		// Array of mutex to simulate the fork took
}	t_data;


// MAIN

/*Driver function*/
int		main(int argc, char *argv[]);
/*It checks the number of arguments and if they are all digits*/
int		check_input(int argc, char **argv);
/*It initiates the structure data*/
int		init_data(t_data *data, int argc, char **argv);
/*It initiates the structure philos inside data*/
void	init_philo(t_data *data);

// UTILS

/*It clear all the resources of the program*/
void	clear_program(t_data *data);
/*It converts a string composed of digits into an int*/
int		ft_atoi(const char *str);


#endif