/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:05:06 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/09/12 19:25:06 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*fillstack(char *buf, int fd, char *stack);
char	*extractline(char *stack);
void	updatestack(char *stack, int cnt);
char	*ft_strjoin(const char *s1, const char *s2);
int		checkstack(char *stack);
int		ft_strlen(const char *s);

#endif