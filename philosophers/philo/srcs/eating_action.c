/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_action.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:46:16 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/18 12:36:02 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	eating_act(t_philo *philo)
{
	if (philo->data->philo_nb == 1)
	{
		pthread_mutex_lock(&philo->data->forks[0]);
		print_state(philo, TAKE_FORK);
		pthread_mutex_unlock(&philo->data->forks[0]);
		return (1);
	}
	if (lock_forks(philo))
		return (1);
	print_state(philo, TAKE_FORK);
	if (check_sim(philo->data))
	{
		unlock_forks(philo);
		return (1);
	}
	print_state(philo, EAT);
	pthread_mutex_lock(&philo->l_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->l_meal);
	if (eating_act2(philo))
		return (1);
	return (0);
}

int	eating_act2(t_philo *philo)
{
	while ((get_time() - philo->last_meal) < philo->data->eat_t)
	{
		if (check_sim(philo->data))
		{
			unlock_forks(philo);
			return (1);
		}
		ft_usleep(1);
	}
	unlock_forks(philo);
	if (philo->data->food_nb >= 0)
	{
		philo->eat_number++;
		if (philo->eat_number == philo->data->food_nb)
		{
			pthread_mutex_lock(&philo->data->philo_full);
			philo->data->has_eaten++;
			pthread_mutex_unlock(&philo->data->philo_full);
			return (1);
		}
	}
	return (0);
}

int	lock_forks(t_philo *philo)
{
	if (check_sim(philo->data))
		return (1);
	if (philo->id % 2 != 0)
	{
		//printf("%lld %d intentando lock left[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos);
		pthread_mutex_lock(&philo->data->forks[philo->arr_pos]);
		//printf("%lld %d consiguió lock left[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos);
	}
	else
	{
		//printf("%lld %d intentando lock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos -1);
		pthread_mutex_lock(&philo->data->forks[philo->arr_pos - 1]);
		//printf("%lld %d consiguió lock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos - 1);
	}
	print_state(philo, TAKE_FORK);
	if (check_sim(philo->data))
	{
		if (philo->id % 2 != 0)
		{
			//printf("%lld %d unlock left[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos);
			pthread_mutex_unlock(&philo->data->forks[philo->arr_pos]);
		}
		else
		{
			//printf("%lld %d unlock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos-1);
			pthread_mutex_unlock(&philo->data->forks[philo->arr_pos - 1]);
		}
		return (1);
	}
	if (philo->id % 2 != 0)
	{
		if (philo->id == 1)
		{
			//printf("%lld %d intentando lock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->data->philo_nb - 1);
			pthread_mutex_lock(&philo->data->forks[philo->data->philo_nb - 1]);
			//printf("%lld %d consiguió lock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->data->philo_nb - 1);
		}
		else
		{
			//printf("%lld %d intentando lock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos - 1);
			pthread_mutex_lock(&philo->data->forks[philo->arr_pos - 1]);
			//printf("%lld %d consiguió lock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos - 1);
		}
	}
	else
	{
		//printf("%lld %d intentando lock left[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos);
		pthread_mutex_lock(&philo->data->forks[philo->arr_pos]);
		//printf("%lld %d consiguió lock left[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos);
	}
	return (0);
}

void	unlock_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		if (philo->id == 1)
		{
			//printf("%lld %d unlock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->data->philo_nb - 1);
			pthread_mutex_unlock(&philo->data
				->forks[philo->data->philo_nb - 1]);
		}
		else
		{
			//printf("%lld %d unlock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos - 1);
			pthread_mutex_unlock(&philo->data->forks[philo->arr_pos - 1]);
		}
		//printf("%lld %d unlock left[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos);
		pthread_mutex_unlock(&philo->data->forks[philo->arr_pos]);
	}
	else
	{
		//printf("%lld %d unlock left[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos);
		pthread_mutex_unlock(&philo->data->forks[philo->arr_pos]);
		//printf("%lld %d unlock right[%d]\n", (unsigned long long)(get_time() - philo->data->start_t), philo->id, philo->arr_pos - 1);
		pthread_mutex_unlock(&philo->data->forks[philo->arr_pos - 1]);
	}
}
