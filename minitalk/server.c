/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:36:02 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/19 08:31:05 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	sig_handler(int sig)
{
	static int		count = 0;
	static int		ascii_char = 0;
	static char		*str = NULL;

	if (!str)
		str = ft_strdup("");
	if (sig == SIGUSR1)
		ascii_char += 0;
	if (sig == SIGUSR2)
		ascii_char += two_power(count);
	count++;
	if (count == 8)
	{
		str = str_record(str, ascii_char);
		if (ascii_char == 0)
		{
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
			free(str);
			str = NULL;
		}
		count = 0;
		ascii_char = 0;
	}
}

int	main(void)
{
	char				*server_pid;
	struct sigaction	sa;

	server_pid = ft_itoa(getpid());
	write(1, "Server PID: ", 12);
	write(1, server_pid, ft_strlen(server_pid));
	write(1, "\n", 1);
	free(server_pid);
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
