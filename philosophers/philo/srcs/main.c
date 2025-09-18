/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:58:28 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/16 16:44:11 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	first_think_msg(t_data *data)
{
	int			i;
	uint64_t	timestamp;

	i = 0;
	timestamp = get_time() - data->start_t;
	while (i < data->philo_nb)
	{
		printf("%llu %d is thinking\n",
			(unsigned long long)timestamp, data->philos[i].id);
		i++;
	}
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

int	check_input(int argc, char **argv)
{
	int	i;
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
		if (argv[1][0] == '0' && argv[1][1] == '\0')
		{
			printf(ERR_INPUT);
			return (0);
		}
		if (argc == 6 && argv[5][0] == '0')
			return (0);
		data = malloc(sizeof(t_data));
		if (!data)
		{
			printf(ERR_ALLOC);
			return (1);
		}
		if (init_data(data, argc, argv))
			return (1);
		first_think_msg(data);
		if (start_threads(data))
			return (1);
		free_data(data);
	}
	return (0);
}
