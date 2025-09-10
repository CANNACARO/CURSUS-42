/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:58:28 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/10 17:03:55 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void*	philo_routine(void *arg)
{
	
}

int	start_threads(t_data *data)
{
	if (init_mutex(data))
		return (1);
	if (create_threads(data))
		return (1);
	if (join_threads(data))
		return (1);
	if (destroy_mutex(data))
		return (error_msg(data, ERR_MUTEX_DESTROY));
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
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

int	check_input(int argc, char **argv)
{
	int i;
	int	j;
	
	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf(ERR_INPUT_NUMBER);
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf(ERR_INPUT);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (check_input(argc, argv))
	{
		data = malloc(sizeof(t_data));
		if (!data)
		{
			printf(ERR_ALLOC);
			return (1);
		}
		if (init_data(data, argc, argv))
			return (1);
		if (start_threads(data))
			return (1);
	}
	else
		return (0); // tal vez pueda quitar este return
}
