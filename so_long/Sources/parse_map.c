/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:02:12 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/09 17:42:09 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/so_long.h"

t_map	*parse_map(char *map, t_map *game)
{
	check_extension(map);
	check_shape(map, game);
	game->store_map = malloc(sizeof(char *) * ((game->height) + 1));
	if (!(game->store_map))
		ft_free_game(game, "The map could not be allocated");
	game->store_map = fill_map(map);
	check_char(game);
	check_walls(game);
	//me falta el flood_fill
	return (game);
}

t_map	*init_map(t_map *game)
{
	game->store_map = NULL;
	game->height = 0;
	game->width = 0;
	game->count_P = 0;
	game->count_E = 0;
	game->count_C = 0;
	return (game);
}

char	**fill_map(char *map)
{
	char	**matrix;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		matrix[i] = line;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	matrix[i] = NULL;
	return (matrix);
}
