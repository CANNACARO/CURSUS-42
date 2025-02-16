/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:06:41 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/16 18:26:12 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/so_long.h"

/*check if the extension is ".ber"*/
void	check_extension(char *map)
{
	if (!(map[ft_strlen(map) - 1] == 'r' && map[ft_strlen(map) - 2] == 'e'
			&& map[ft_strlen(map) - 3] == 'b'
			&& map[ft_strlen(map) - 4] == '.'))
		my_exit(ERR_EXT);
}

/*second part of check_shape*/
void	*check_shape_2(int fd, char *line, t_map *game)
{
	while (line)
	{
		if (game->height == 0)
			game->width = ft_strlen(line);
		if (ft_strlen(line) != game->width || game->width == 0)
		{
			free(line);
			ft_free_game(game, ERR_INCORRECT);
		}
		else
		{
			game->height++;
			free(line);
			line = get_next_line(fd);
		}
	}
}

/*check if the map is rectangular*/
void	*check_shape(char *map, t_map *game)
{
	char	*line;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_free_game(game, ERR_FILE);
	line = get_next_line(fd);
	if (!line)
		ft_free_game(game, ERR_EMPTY);
	check_shape_2(fd, line, game);
	close(fd);
}

/*check that the characters at the map are correct*/
void	*check_char(t_map *game)
{
	t_coord	coord;

	coord.y = 0;
	while (game->store_map[coord.y])
	{
		coord.x = 0;
		while (game->store_map[coord.y][coord.x])
		{
			if (game->store_map[coord.y][coord.x] != '1'
				|| game->store_map != '0' || game->store_map != 'C'
				|| game->store_map != 'E' || game->store_map != 'P')
				ft_free_game(game, ERR_CHAR);
			if (game->store_map[coord.y][coord.x] == 'C')
				game->count_C++;
			if (game->store_map[coord.y][coord.x] == 'P')
				game->count_P++;
			if (game->store_map[coord.y][coord.x] == 'E')
				game->count_E++;
			coord.x++;
		}
		coord.y++;
	}
	if (game->count_E != 1 || game->count_P != 1 || game->count_C < 1)
		ft_free_game(game, ERR_INCORRECT);
}
/*It checks if the map is surrounded by walls*/
void	*check_walls(t_map *game)
{
	t_coord coord;
	
	coord.y = 0;
	while (game->store_map[coord.y])
	{
		coord.x = 0;
		while (game->store_map[coord.y][coord.x])
		{
			if (coord.y == 0 || coord.y == ((game->height) - 1)
				|| coord.x == 0 || coord.x == ((game->width) - 1))
			{
				if (game->store_map[coord.y][coord.x] != '1')
					ft_free_game(game, ERR_INCORRECT);
			}
			coord.x++;
		}
		coord.y++;
	}
}
