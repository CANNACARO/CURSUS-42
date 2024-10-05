/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:16:31 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/05 11:03:03 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
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
}

void	send_signals(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if (((str[i] >> (7 - i)) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;
	int		i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (argv[1][i] < 48 || argv[1][i] > 57)
			{
				printf("You must enter a number as a PID\n");
				return (0);
			}
			i++;
		}
		server_pid = ft_atoi(argv[1]);
		message = argv[2];
		send_signals(server_pid, message);
	}
	else
		printf("Wrong number of arguments\n");
	return (0);
}
