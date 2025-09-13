/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:46:16 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/13 12:43:54 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eating_act(t_philo *philo)
{
	uint64_t	now;
	uint64_t	timestamp;

	now = get_time();
	timestamp = now - philo->data->start_t;
	if (lock_forks(philo, timestamp))
		return (1);
	now = get_time();
	timestamp = now - philo->data->start_t;
	print_state(philo, TAKE_FORK, timestamp);
	if (check_sim(philo->data))
	{
		unlock_forks(philo);
		return (1);
	}
	if (eating_act2(philo, now, timestamp))
		return (1);
	return (0);
}

int	eating_act2(t_philo *philo, uint64_t now, uint64_t timestamp)
{
	print_state(philo, EAT, timestamp);
	philo->time_to_die = now;
	while ((now - philo->data->start_t - timestamp) < philo->data->eat_t)
	{
		if (check_sim(philo->data))
		{
			unlock_forks(philo);
			return (1);
		}
		ft_usleep(1);
		now = get_time();
	}
	unlock_forks(philo);
	philo->eat_number++;
	if (philo->eat_number == philo->data->food_nb)
	{
		pthread_mutex_lock(&philo->data->philo_full);
		philo->data->has_eaten++;
		pthread_mutex_unlock(&philo->data->philo_full);
		return (1);
	}
	return (0);
}

int	lock_forks(t_philo *philo, uint64_t timestamp)
{
	if (check_sim(philo->data))
		return (1);
	if (philo->id % 2 != 0)
		pthread_mutex_lock(&philo->data->forks[philo->arr_pos]);
	else
		pthread_mutex_lock(&philo->data->forks[philo->arr_pos - 1]);
	print_state(philo, TAKE_FORK, timestamp);
	if (check_sim(philo->data))
	{
		if (philo->id % 2 != 0)
			pthread_mutex_unlock(&philo->data->forks[philo->arr_pos]);
		else
			pthread_mutex_unlock(&philo->data->forks[philo->arr_pos - 1]);
		return (1);
	}
	if (philo->id % 2 != 0)
	{
		if (philo->id == 1)
			pthread_mutex_lock(&philo->data->forks[philo->data->philo_nb - 1]);
		else
			pthread_mutex_lock(&philo->data->forks[philo->arr_pos - 1]);
	}
	else
		pthread_mutex_lock(&philo->data->forks[philo->arr_pos]);
	return (0);
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->arr_pos]);
		if (philo->id == 1)
			pthread_mutex_unlock(&philo->data
				->forks[philo->data->philo_nb - 1]);
		else
			pthread_mutex_unlock(&philo->data->forks[philo->arr_pos - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[philo->arr_pos - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->arr_pos]);
	}
}
