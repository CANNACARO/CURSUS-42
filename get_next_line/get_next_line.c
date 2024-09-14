/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:50:04 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/09/14 17:50:46 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*updatestack(char *stack)
{
	char	*aux;
	char	*new_stack;
	int		i;

	i = 0;
	new_stack = ft_strchr(stack, '\n');
	if (new_stack == NULL)
	{
		free (stack);
		stack = NULL;
		return (NULL);
	}
	new_stack++;
	aux = malloc((ft_strlen(new_stack) + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	while (new_stack[i])
	{
		aux[i] = new_stack[i];
		i++;
	}
	aux[i] = '\0';
	free(stack);
	return (aux);
}

char	*extractline(char *stack)
{
	int		i;
	char	*line;

	i = 0;
	while (stack[i] != '\n' && stack[i])
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
		if (len == 0)
			ft_bzero(buf, BUFFER_SIZE);
		stack = ft_strjoin(stack, buf);
		if (checkstack(stack) == 1)
			break ;
	}
	free(buf);
	if (len == -1)
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
	ft_bzero(buf, BUFFER_SIZE);
	if (!stack)
		stack = "";
	stack = fillstack(buf, fd, stack);
	line = extractline(stack);
	stack = updatestack(stack);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("text1.txt", O_RDONLY);
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}*/

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
