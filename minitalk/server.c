/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:36:02 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/13 15:55:16 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	two_power(int number)
{
	int	pos;
	int	result;

	pos = 7 - number;
	result = 1;
	while (pos > 0)
	{
		result *=2;
		pos--;
	}
	return (result);
}

/*void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	count;

	str = s;
	count = 0;
	while (count < n)
	{
		str[count] = '\0';
		count++;
	}
}*/

void	sig_handler(int sig)
{
	char c;
	static int count = 0;
	static int ascii_char = 0;
	
	if (sig == SIGUSR1)
		ascii_char += 0;
	if (sig == SIGUSR2)
		ascii_char += two_power(count);
	count++;
	if (count == 8)
	{
		c = (char)ascii_char;
		write(1, &c, 1);
		count = 0;
		ascii_char = 0;
	}
}

int	main(void)
{
	int					server_id;
	struct sigaction	sa;

	server_id = getpid();
	printf("Server PID: %d\n", server_id);
	while (1)
	{
		sa.sa_handler = sig_handler;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}