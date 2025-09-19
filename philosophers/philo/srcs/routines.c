/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:28:24 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/19 12:15:16 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_time_to_die(t_data *data)
{
	int			i;
	uint64_t	last_meal;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_lock(&data->philos[i].l_meal);
		last_meal = data->philos[i].last_meal;
		pthread_mutex_unlock(&data->philos[i].l_meal);
		if (get_time() - last_meal > (uint64_t)data->death_t)
		{
			pthread_mutex_lock(&data->sv_mutex);
			data->sim_on = 0;
			pthread_mutex_unlock(&data->sv_mutex);
			print_state(&data->philos[i], DIE);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*sv_routine(void *arg)
{
	t_data	*data;
	int		has_eaten;

	data = (t_data *) arg;
	while (1)
	{
		if (check_time_to_die(data))
			return (NULL);
		if (data->food_nb >= 0)
		{
			pthread_mutex_lock(&data->philo_full);
			has_eaten = data->has_eaten;
			pthread_mutex_unlock(&data->philo_full);
			if (has_eaten == data->philo_nb)
			{
				pthread_mutex_lock(&data->sv_mutex);
				data->sim_on = 0;
				pthread_mutex_unlock(&data->sv_mutex);
				return (NULL);
			}
		}
		ft_usleep(1);
	}
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		if (eating_act(philo))
			return (NULL);
		if (sleep_act(philo))
			return (NULL);
		if (think_act(philo))
			return (NULL);
	}
}

int	check_sim(t_data *data)
{
	pthread_mutex_lock(&data->sv_mutex);
	if (data->sim_on == 0)
	{
		pthread_mutex_unlock(&data->sv_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->sv_mutex);
	return (0);
}
