/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:42:52 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/10/17 20:23:12 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	send_signals(int pid, char *str);
int		two_power(int number);
char	*str_record(char *str, int ascii_char);
void	action(int sig, siginfo_t *info, void *context);
int		ft_atoi(const char *str);
void	ft_putnbr(char *s, int n, int size);
char	*ft_itoa(int n);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		check_pid(char *pid);
void	sig_received(int sig);
void	print_message(char *str);

#endif
