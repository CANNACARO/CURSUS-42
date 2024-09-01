/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:50:04 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/09/01 16:33:45 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	updatestack(char *stack, int cnt)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(stack) - cnt));
	tmp = &stack[cnt];
	free(stack);
	stack = tmp;
}

char	*extractline(char* stack)
{
	int		i;
	char	*line;

	i = 0;
	while (stack[i] != '\n')
		i++;
	line = (char*) malloc(sizeof(char) * (i + 1));
	i = 0;
	while (stack[i] != '\n')
	{
		line[i] = stack [i];
		i++;
	}
	line[i] = '\0';
	i++;
	updatestack(stack, i);
	return (line);
}

char	*fillstack(char* buf, int fd)
{
	int 	len;
	char	*stack;
	
	len = 1;
	while(len > 0)
	{
		buf = (char*) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		len = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (!stack)
			stack = "";
		stack = ft_strjoin(stack, buf);
		free(buf);
		if (checkstack(stack) == 1)
			break;
	}
	return (stack);
}


char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack;
	char		*buf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stack = fillstack(buf, fd);
	line = extractline(stack);
	
}