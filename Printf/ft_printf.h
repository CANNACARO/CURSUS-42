/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 19:43:23 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/07/12 20:47:10 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(char c);
int	ft_print_hexa_lower(unsigned int num);
int	ft_print_hexa_upper(unsigned int num);
int	ft_print_int(int num);
int	ft_print_ptr(void *ptr);
int	ft_print_string(char *s);
int	ft_print_unsigint(unsigned int num);
int	ft_printf(char const*, ...);

#endif