/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:38:21 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/10 17:03:17 by jcaro-lo         ###   ########.fr       */
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
# include <sys/time.h>


# define ERR_ALLOC "Allocation ERROR\n"
# define ERR_INPUT "The input contains a not number argument\n"
# define ERR_INPUT_NUMBER "The number of arguments is not correct\n"
# define ERR_TH_CREATE "Error at creating the thread\n"
# define ERR_TH_JOIN "Error at joining the thread\n"
# define ERR_MUTEX_INIT "Error at initiating the mutex\n"
# define ERR_MUTEX_DESTROY "Error at destroyint the mutex\n"

typedef struct s_philo
{
	struct s_data	*data;	// Array to struct data
	int				id;		// Number assigned to a philosopher
	pthread_t		th;		// Thread for each philosopher
}	t_philo;

typedef struct s_data
{
	int				philo_nb;	// Number of philosophers
	int				food_nb;	// Number of times each philo must eat
	uint64_t		death_t;	// Time to die (ms)
	uint64_t		eat_t;		// Time to eat (ms)
	uint64_t		sleep_t;	// Time to sleep (ms)
	uint64_t		start_t;	// Time in which the simulation starts
	t_philo			*philos;	// Array to struct t_philos
	pthread_mutex_t	*forks;		// Array of mutex to simulate the fork took
	pthread_mutex_t	write;		// Mutex to protect the message printed
}	t_data;


// MAIN

/*Driver function*/
int			main(int argc, char *argv[]);
/*It checks the number of arguments and if they are all digits*/
int			check_input(int argc, char **argv);
/*It initiates the structure data*/
int			init_data(t_data *data, int argc, char **argv);
/*It initiates the structure philos inside data*/
void		init_philo(t_data *data);
/*It creates and join the threads.It also initiates and destroy mutexes*/
int			start_threads(t_data *data);


void*		philo_routine(void *arg);


// THREADS

int create_threads(t_data *data);

int	join_threads(t_data *data);

int	init_forks_mutex(t_data *data);

int	init_mutex(t_data *data);

int	destroy_mutex(t_data *data);


// UTILS


/*It converts a string composed of digits into an int*/
int			ft_atoi(const char *str);

uint64_t 	get_time();

void		ft_usleep(int t);

// FREE RESOURCES

/*It clear all the resources of the program*/
void		free_data(t_data *data);

int			error_msg(t_data *data, char *str);

int			clear_program(t_data *data);

#endif