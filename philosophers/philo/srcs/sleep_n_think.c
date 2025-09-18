/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_n_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:01:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/18 18:08:32 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	sleep_act(t_philo *philo)
{
	uint64_t	timestamp;

	if (check_sim(philo->data))
		return (1);
	timestamp = get_time() - philo->data->start_t;
	print_state(philo, SLEEP);
	while ((get_time() - philo->data->start_t - timestamp)
		< philo->data->sleep_t)
	{
		if (check_sim(philo->data))
			return (1);
		ft_usleep(1);
	}
	return (0);
}

int	think_act(t_philo *philo)
{
	print_state(philo, THINK);
	if (philo->data->death_t - philo->data->eat_t - philo->data->sleep_t > 10)
		ft_usleep(10);
	return (0);
}
