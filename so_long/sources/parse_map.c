/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:02:12 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/08 18:24:59 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*It check if the map is correct and convert the map
	from file .ber into a **char*/
t_map	*parse_map(char *map, t_map *game)
{
	check_extension(map, game);
	check_shape(map, game);
	fill_map(game, map);
	check_char(game);
	check_walls(game);
	check_path(game);
	return (game);
}

/*Initialize structure game variables*/
t_map	*init_map(t_map *game)
{
	game->grid = NULL;
	game->height = 0;
	game->width = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
	game->p_pos.x = -1;
	game->p_pos.y = -1;
	game->moves = 0;
	game->images.background = NULL;
	game->images.collectible = NULL;
	game->images.exit = NULL;
	game->images.player = NULL;
	game->images.wall = NULL;
	game->window = NULL;
	return (game);
}

/*It fill the map in a **char*/
void	fill_map(t_map *game, char *map)
{
	char	*line;
	int		fd;
	int		i;

	game->grid = malloc(sizeof(char *) * ((game->height) + 1));
	if (!game->grid)
		ft_free_game(game, ERR_MAP);
	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free_game(game, ERR_FILE);
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		game->grid[i] = line;
		i++;
		line = get_next_line(fd);
	}
	if (!line && i != game->height)
		ft_free_game(game, ERR_MAP);
	game->grid[i] = NULL;
	close(fd);
}
