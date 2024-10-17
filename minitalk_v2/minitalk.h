/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:42:52 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/14 17:50:18 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	send_signals(int pid, char *str);
int		two_power(int number);
char	*str_record(char *str, int ascii_char);
void	sig_handler(int sig);
int		ft_atoi(const char *str);
void	ft_putnbr(char *s, int n, int size);
char	*ft_itoa(int n);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

#endif
