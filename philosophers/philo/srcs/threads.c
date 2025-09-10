/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:35:55 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/10 16:58:15 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_threads(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->philo_nb)
	{
		if (pthread_create(&data->philos[i].th, NULL, &philo_routine, data) != 0)
		{
			while (j < i)
			{
				pthread_join(data->philos[j].th, NULL);
				j++;
			}
			return (clear_program(data));
		}
		i++;
	}
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	
	i = 0;
	while (i < data->philo_nb)
	{
		if(pthread_join(data->philos[i].th, NULL) != 0)
		{
			destroy_mutex(data);
			return (clear_program(data));
		}
		i++;
	}
	return (0);
}
int	init_forks_mutex(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (j < i)
			{
				pthread_mutex_destroy(&data->forks[i]);
				j++;
			}
			return (error_msg(data, ERR_MUTEX_INIT));
		}
		i++;
	}
	return (0);
}

int	init_mutex(t_data *data)
{
	int	i;
	
	i = 0;
	if (init_forks_mutex(data))
		return (1);
	if (pthread_mutex_init(&data->write, NULL) != 0)
	{
		while (i < data->philo_nb)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		return (error_msg(data, ERR_MUTEX_INIT));
	}
	return (0);
}

int	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&data->write) != 0)
		return (1);
	return (0);
}
