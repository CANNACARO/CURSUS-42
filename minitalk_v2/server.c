/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:36:02 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/13 18:10:09 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(char *s, int n, int size)
{
	int	i;

	i = 0;
	s[i] = '0';
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	while (size - 1 >= i)
	{
		if (n < 0)
		{
			s[size - 1] = -(n % 10) + '0';
		}
		else
		{
			s[size - 1] = n % 10 + '0';
		}
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		str_size;
	char	*str;
	int		nbr;

	nbr = n;
	str_size = 0;
	if (nbr < 0)
		str_size++;
	if (nbr == 0)
		str_size++;
	while (nbr != 0)
	{
		str_size++;
		nbr = nbr / 10;
	}
	str = malloc(sizeof(char) * (str_size + 1));
	if (!str)
		return (NULL);
	ft_putnbr(str, n, str_size);
	str[str_size] = '\0';
	return (str);
}


int	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	char	*point;
	size_t	i;

	i = 0;
	point = malloc(ft_strlen(s1) + 1);
	if (!point)
		return (NULL);
	while (s1[i])
	{
		point[i] = s1[i];
		i++;
	}
	point[i] = '\0';
	return (point);
}

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
	int					server_id;
	struct sigaction	sa;

	server_id = getpid();
	write(1, "Server PID: ", 12);
	write(1, ft_itoa(server_id), ft_strlen(ft_itoa(server_id)));
	write(1, "\n", 1);
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
