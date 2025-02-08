/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:31:03 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/04 16:31:03 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/so_long.h"

//check if the extension is ".ber" 
void check_extension(char *map)
{
	if (!(map[ft_strlen(map) - 1]  == 'r' && map[ft_strlen(map) - 2]  == 'e' && 
	map[ft_strlen(map) - 3]  == 'b' && map[ft_strlen(map) - 4]  == '.'))
	{
		perror(ERR_EXT);
		exit (FAILURE);
	}
}
void *check_shape_2(int fd, char *line, t_map *game)
{
	while (line)
	{
		if (game -> height == 0)
			game -> width = ft_strlen(line);
		if (ft_strlen(line) != game -> width || game -> width == 0)
		{
			free(line);
			free(game);
			exit(ERR_INCORRECT);
		}
		else
		{
			game -> height++;
			free (line);
			line = get_next_line(fd);
		}
	}
}

//check if the map is rectangular
void	*check_shape(char *map, t_map *game)
{
	char *line;
	int fd;

	fd = open(map,O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		free(game);
		exit (ERR_EMPTY);
	}
	check_shape_2(fd, line, game);
}

char **fill_map(char *map)
{
	char **matrix;
	char *line;
	int fd;
	int i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		matrix[i] = line;
		i++;
		free (line);
		line = get_next_line(fd);
	}
	matrix[i] = NULL;
	return (matrix);
}

t_map *parse_map(char *map, t_map *game)
{
	check_extension(map);
	check_shape(map, game);
	game -> store_map = malloc(sizeof(char*) * (game -> height + 1));
	if (!(game -> store_map))
	{
		free(game);
		perror("The map could not be allocated");
	}
	game -> store_map= fill_map(map);

	return (game);
}
t_map *init_map(t_map *game)
{
	game -> store_map = NULL;
	game -> height = 0;
	game -> width = 0;
	return (game);
}

int main(int argc, char *argv[])
{
	t_map *game;
	if (argc != 2)
	{
		perror(ERR_ARG);
		exit (FAILURE);
	}
	else
	{
		game = malloc(sizeof(t_map));
		if (!game)
		{
			perror("The game could not be allocated");
			exit(FAILURE);
		}
		game = init_map(game);
		game = parse_map(argv[1], game);
	}
	return (0);
}
