/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:23:23 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/13 11:31:46 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	if (init_mutex2(data))
		return (1);
	return (0);
}

int	init_mutex2(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&data->sv_mutex, NULL) != 0)
	{
		while (++i < data->philo_nb)
			pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->write);
		return (error_msg(data, ERR_MUTEX_INIT));
	}
	i = -1;
	if (pthread_mutex_init(&data->philo_full, NULL) != 0)
	{
		while (++i < data->philo_nb)
			pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->write);
		pthread_mutex_destroy(&data->sv_mutex);
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
	if (pthread_mutex_destroy(&data->sv_mutex) != 0)
		return (1);
	if (pthread_mutex_destroy(&data->philo_full) != 0)
		return (1);
	return (0);
}
