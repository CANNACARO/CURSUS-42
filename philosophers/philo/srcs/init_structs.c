/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:25:50 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/12 11:31:44 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].arr_pos = i;
		data->philos[i].time_to_die = data->start_t;
		data->philos[i].eat_number = 0;
		i++;
	}
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->philo_nb = ft_atoi(argv[1]);
	if (argc == 6)
		data->food_nb = ft_atoi(argv[5]);
	else
		data->food_nb = -1;
	data->sim_on = 1;
	data->death_t = ft_atoi(argv[2]);
	data->eat_t = ft_atoi(argv[3]);
	data->sleep_t = ft_atoi(argv[4]);
	data->start_t = get_time();
	data->philos = malloc(sizeof(t_philo) * data->philo_nb);
	if (!data->philos)
		return (error_msg(data, ERR_ALLOC));
	init_philo(data);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!data->forks)
		return (error_msg(data, ERR_ALLOC));
	return (0);
}
