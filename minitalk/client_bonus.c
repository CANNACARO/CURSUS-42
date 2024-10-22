/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:16:31 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/19 12:56:22 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

int	check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < 48 || pid[i] > 57)
		{
			write(1, "You must enter a number as a PID\n", 33);
			return (1);
		}
		i++;
	}
	return (0);
}

void	sig_received(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "Signal received by server\n", 26);
	}
	else
		write(1, "error\n", 6);
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	char				*message;
	struct sigaction	msg_received;

	if (argc == 3)
	{
		msg_received.sa_handler = sig_received;
		msg_received.sa_flags = 0;
		sigemptyset(&msg_received.sa_mask);
		sigaction(SIGUSR1, &msg_received, NULL);
		sigaction(SIGUSR2, &msg_received, NULL);
		check_pid(argv[1]);
		server_pid = ft_atoi(argv[1]);
		message = argv[2];
		send_signals(server_pid, message);
	}
	else
		write(1, "Wrong number of arguments\n", 27);
	return (0);
}
