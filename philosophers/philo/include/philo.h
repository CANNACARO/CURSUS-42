/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:38:21 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/13 12:44:07 by jcaro-lo         ###   ########.fr       */
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
	struct s_data	*data;		// Array to struct data
	int				id;			// Number assigned to a philosopher
	int				arr_pos;	// Actual position on the array philos
	int				eat_number;	// NUmber of times the philosopher has eaten
	/*int				is_dead;*/	
	uint64_t		time_to_die;/* It gets the time at the start of 
									the simulation and it is recalculated 
									when the philosopher eats*/
	pthread_t		th;			// Thread for each philosopher
}	t_philo;

typedef struct s_data
{
	int				philo_nb;	// Number of philosophers
	int				food_nb;	// Number of times each philo must eat
	int				sim_on;		/* Flag to tell if the simulation must
									 go on or be stopped.Its value is 
									0 if any philosopher die*/
	int				has_eaten;	/*Number of philosophers that have eaten
									 the number of times stablished*/
	uint64_t		death_t;	/* Time the philosofer has to eat 
									before he dies of starvation(ms)*/
	uint64_t		eat_t;		// Time the philosofer is eating (ms)
	uint64_t		sleep_t;	// Time the philosofer is sleeping (ms)
	uint64_t		start_t;	// Time in which the simulation starts
	t_philo			*philos;	// Array to struct t_philos
	pthread_t		sv;			// Thread supervisor
	pthread_mutex_t	*forks;		// Array of mutex to simulate the fork took
	pthread_mutex_t	write;		// Mutex to protect the message printed
	pthread_mutex_t	sv_mutex;	// Mutex for the supervisor routine
	pthread_mutex_t	philo_full;	// Mutex to protect has_eaten variable
}	t_data;

typedef enum e_action
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_action;

// MAIN

/*Driver function*/
int			main(int argc, char *argv[]);
/*It checks the number of arguments and if they are all digits*/
int			check_input(int argc, char **argv);
/*It creates and join the threads.It also initiates and destroy mutexes*/
int			start_threads(t_data *data);
/*It prints every philosopher is thinking before starting the routine*/
void		first_think_msg(t_data *data);

// INIT STRUCTS

/*It initiates the structure data*/
int			init_data(t_data *data, int argc, char **argv);
/*It initiates the structure philos inside data*/
void		init_philo(t_data *data);

// THREADS

/*It creates all the threads with the function pthread_create*/
int			create_threads(t_data *data);
/*It has the loop to ceate all the philosophers threads*/
int			create_philo_threads(t_data *data);
/*It joins all the threads with the funciont pthread_join*/
int			join_threads(t_data *data);

// MUTEX

/*It initiates the mutexes that simulate the forks*/
int			init_forks_mutex(t_data *data);
/*It initiates all the mutexes*/
int			init_mutex(t_data *data);
/*Second part of init mutex*/
int			init_mutex2(t_data *data);
/*It destroy all the mutexes*/
int			destroy_mutex(t_data *data);

// ROUTINES

/*Part of the supervisor that checks if the 
	philosopher has reached the time to die*/
int			check_time_to_die(t_data *data);
/*Supervisor routine*/
void		*sv_routine(void	*arg);
/*Routine for the philosophers (eat, sleep, think)*/
void		*philo_routine(void *arg);
/*It checks if  the supervisor routine has set the 
	simulation tu 0. If it is 0 it ends the 
	philosopher thread in order to end the simulation*/
int			check_sim(t_data *data);

// ACTIONS

// EATING ACTION

/*It simulates the eating action*/
int			eating_act(t_philo *philo);
/*Second part of eating action*/
int			eating_act2(t_philo *philo, uint64_t now, uint64_t timestamp);
/*It locks the mutexes that simulate the forks*/
int			lock_forks(t_philo *philo, uint64_t timestamp);
/*It unlocks the mutexes that simulate the forks*/
void		unlock_forks(t_philo *philo);

// UTILS

/*It converts a string composed of digits into an int*/
int			ft_atoi(const char *str);
/*Function to get the result of gettimeofday() in miliseconds*/
uint64_t	get_time(void);
/*Function to make usleep more precise*/
void		ft_usleep(uint64_t t);
/*It prints any change of a philosopher state*/
void		print_state(t_philo	*philo, t_action action, uint64_t timestamp);

// FREE RESOURCES

/*It frees the allocated memory on the main structure of the program*/
void		free_data(t_data *data);
/*Function for printing an error occurred and free the memory*/
int			error_msg(t_data *data, char *str);
/*It uses funciton free_data() and destroy the mutexes*/
int			clear_program(t_data *data);

#endif