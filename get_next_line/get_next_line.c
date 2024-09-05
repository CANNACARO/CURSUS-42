/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:50:04 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/09/05 20:15:35 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	updatestack(char *stack, int cnt)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(stack) - cnt + 1));
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
	line = (char*) malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack [i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	i++;
	updatestack(stack, i);
	return (line);
}

char	*fillstack(char* buf, int fd)
{
	ssize_t 	len;
	char		*stack;
	
		len = 1;
	while(len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		if (!stack)
			stack = "";
		stack = ft_strjoin(stack, buf);
		free(buf);
		if (checkstack(stack) == 1)
			break;
	}
	if (len <= 0)
	{
		free (stack);
		return (NULL);
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
	buf = (char*) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	stack = fillstack(buf, fd);
	line = extractline(stack);
	return (line);
}

int	main(void)
{
	int	fd;
	char* line;
	fd= open("text1.txt", O_RDONLY);
	
	line = get_next_line(fd);
	while (line)
	{
		printf("%s",line);
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close (fd);
}