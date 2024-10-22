/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:36:02 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/19 10:46:34 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	two_power(int number)
{
	int	pos;
	int	result;

	pos = 7 - number;
	result = 1;
	while (pos > 0)
	{
		result *= 2;
		pos--;
	}
	return (result);
}

char	*str_record(char *str, int ascii_char)
{
	char	*tmp;
	char	c;
	int		i;

	c = (char)ascii_char;
	i = 0;
	tmp = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	free(str);
	tmp[i] = c;
	i++;
	tmp[i] = '\0';
	return (tmp);
}

void	print_message(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int		count = 0;
	static int		ascii_char = 0;
	static char		*str = NULL;

	(void)context;
	if (!str)
		str = ft_strdup("");
	if (sig == SIGUSR1)
		ascii_char += 0;
	if (sig == SIGUSR2)
		ascii_char += two_power(count);
	kill(info->si_pid, SIGUSR2);
	count++;
	if (count == 8)
	{
		str = str_record(str, ascii_char);
		if (ascii_char == 0)
		{
			print_message(str);
			free(str);
			str = NULL;
		}
		count = 0;
		ascii_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				*server_pid;

	server_pid = ft_itoa(getpid());
	write(1, "Server PID: ", 12);
	write(1, server_pid, ft_strlen(server_pid));
	write(1, "\n", 1);
	free (server_pid);
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
