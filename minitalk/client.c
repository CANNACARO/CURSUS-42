/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:16:31 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/17 20:17:23 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			if (((str[i] >> (7 - j) & 1) == 0))
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
				write(1, "You must enter a number as a PID\n", 33);
				return (0);
			}
			i++;
		}
		server_pid = ft_atoi(argv[1]);
		message = argv[2];
		send_signals(server_pid, message);
	}
	else
		write(1, "Wrong number of arguments\n", 27);
	return (0);
}
