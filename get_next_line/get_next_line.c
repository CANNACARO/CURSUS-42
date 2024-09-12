/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:50:04 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/09/12 19:34:51 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	updatestack(char *stack, int cnt)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(stack) - cnt + 1));
	while (stack[cnt + i])
	{
		tmp[i] = stack[cnt + i];
		i++;
	}
	tmp[i] = '\0';
	free(stack);
	stack = tmp;
}

char	*extractline(char *stack)
{
	int		i;
	char	*line;

	i = 0;
	while (stack[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		line[i] = stack[i];
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

char	*fillstack(char *buf, int fd, char *stack)
{
	ssize_t	len;

	len = 1;
	while (len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = '\0';
		stack = ft_strjoin(stack, buf);
		if (checkstack(stack) == 1)
			break ;
	}
	free(buf);
	if (len <= 0)
	{
		free(stack);
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
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!stack)
		stack = "";
	stack = fillstack(buf, fd, stack);
	line = extractline(stack);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

/*int	main(void)
{
	int	fd;

	char* line;
	fd= open("text1.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s",line);
	free (line);
	close (fd);
	return (0);
}
*/
