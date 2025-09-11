/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:28:24 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/11 16:42:36 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_time_to_die(t_data *data)
{
	int			i;
	uint64_t	now;

	i = 0;
	now = get_time();
	while (i < data->philo_nb)
	{
		if (now - data->philos[i].time_to_die > data->death_t)
		{
			pthread_mutex_lock(&data->sv_mutex);
			data->sim_on = 0;
			pthread_mutex_unlock(&data->sv_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*sv_routine(void *arg)
{
	t_data 	*data;

	data = (t_data *) arg;
	while (1)
	{
		if (check_time_to_die(data))
			return (NULL);
		if(data->food_nb >= 0)
		{
			if (data->has_eaten == data->philo_nb)
			{
				pthread_mutex_lock(&data->sv_mutex);
				data->sim_on = 0;
				pthread_mutex_unlock(&data->sv_mutex);
				return (NULL);
			}
		}
		usleep(1000);
	}
}

void	*philo_routine(void *arg)
{
	t_data 	*data;

	data = (t_data *) arg;
	
	
	
	return (arg); // de momento he puesto esto para que no me de error al compilar
}
