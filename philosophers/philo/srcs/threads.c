/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:35:55 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/13 11:33:36 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_philo_threads(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->philo_nb)
	{
		if (pthread_create(&data->philos[i].th,
				NULL, &philo_routine, &data->philos[i]) != 0)
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

int	create_threads(t_data *data)
{
	int	i;

	if (create_philo_threads(data))
		return (1);
	i = 0;
	if (pthread_create(&data->sv, NULL, &sv_routine, data) != 0)
	{
		while (i < data->philo_nb)
		{
			pthread_join(data->philos[i].th, NULL);
			i++;
		}
		return (clear_program(data));
	}
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_join(data->philos[i].th, NULL) != 0)
			return (clear_program(data));
		i++;
	}
	if (pthread_join(data->sv, NULL) != 0)
		return (clear_program(data));
	return (0);
}
