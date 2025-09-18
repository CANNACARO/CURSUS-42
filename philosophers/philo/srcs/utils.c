/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:40:09 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/18 12:58:41 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = str[i] - 48 + res * 10;
		i++;
	}
	res = res * sign;
	return (res);
}*/

uint64_t	ft_atoi(const char *str)
{
	uint64_t	res;
	int			i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = str[i] - 48 + res * 10;
		i++;
	}
	if (res > INT_MAX)
		return (UINT64_ERROR);
	return ((int)res);
}

uint64_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(uint64_t t)
{
	uint64_t	start_time;

	start_time = get_time();
	while (get_time() - start_time < t)
		usleep(1000);
}

void	print_state(t_philo	*philo, t_action action)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&philo->data->write);
	pthread_mutex_lock(&philo->data->sv_mutex);
	timestamp = get_time() - philo->data->start_t;
	if (philo->data->sim_on)
	{
		if (action == TAKE_FORK)
			printf("%llu %d has taken a fork\n",
				(unsigned long long)timestamp, philo->id);
		else if (action == EAT)
			printf("%llu %d is eating\n",
				(unsigned long long)timestamp, philo->id);
		else if (action == SLEEP)
			printf("%llu %d is sleeping\n",
				(unsigned long long)timestamp, philo->id);
		else if (action == THINK)
			printf("%llu %d is thinking\n",
				(unsigned long long)timestamp, philo->id);
	}
	if (action == DIE)
		printf("%llu %d died\n",
			(unsigned long long) timestamp, philo->id);
	pthread_mutex_unlock(&philo->data->sv_mutex);
	pthread_mutex_unlock(&philo->data->write);
}
