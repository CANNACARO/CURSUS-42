/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:02:12 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/16 18:21:29 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/so_long.h"

/*It check if the map is correct and convert the map
	from file .ber into a **char*/
t_map	*parse_map(char *map, t_map *game)
{
	check_extension(map);
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
	game->store_map = NULL;
	game->height = 0;
	game->width = 0;
	game->count_P = 0;
	game->count_E = 0;
	game->count_C = 0;
	game->P_Pos.x = -1;
	game->P_Pos.y = -1;
	return (game);
}

/*It fill the map in a **char*/
void	*fill_map(t_map *game, char *map)
{
	char	*line;
	int		fd;
	int		i;

	game->store_map = malloc(sizeof(char *) * ((game->height) + 1));
	if (!game->store_map)
		ft_free_game(game, ERR_MAP);
	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free_game(game, ERR_FILE);
	line = get_next_line(fd);
	while (line)
	{
		game->store_map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	if (!line && i != game->height)
		ft_free_game(game, ERR_MAP);
	game->store_map[i] = NULL;
	close(fd);
}
