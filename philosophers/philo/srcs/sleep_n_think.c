/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_n_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:01:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/18 12:59:56 by jcaro-lo         ###   ########.fr       */
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
	/*uint64_t	timestamp;
	uint64_t	time_to_think;
	uint32_t	last_meal;*/

	/*pthread_mutex_lock(&philo->l_meal);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->l_meal);
	time_to_think = ((philo->data->death_t
			- (get_time() - last_meal)) - 10) / 2;
	if (check_sim(philo->data))
		return (1);
	timestamp = get_time() - philo->data->start_t;*/
	print_state(philo, THINK);
	/*while (get_time() - philo->data->start_t - timestamp < time_to_think)
	{
		if (check_sim(philo->data))
			return (1);
		ft_usleep(1);
	}*/
	ft_usleep(10);
	return (0);
}
