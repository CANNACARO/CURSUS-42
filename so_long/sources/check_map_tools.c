/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:06:41 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/12 17:04:07 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*check if the extension is ".ber"*/
void	check_extension(char *map, t_map *game)
{
	if (!(map[ft_strlen(map) - 1] == 'r' && map[ft_strlen(map) - 2] == 'e'
			&& map[ft_strlen(map) - 3] == 'b'
			&& map[ft_strlen(map) - 4] == '.'))
		ft_free_game(game, ERR_EXT);
}

/*check if the map is rectangular*/
void	check_shape(char *map, t_map *game)
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

/*second part of check_shape*/
void	check_shape_2(int fd, char *line, t_map *game)
{
	int	real_len;

	real_len = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			real_len = ft_strlen(line) - 1;
		else
			real_len = ft_strlen(line);
		if (game->height == 0)
			game->width = real_len;
		if (real_len != game->width || game->width == 0)
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

/*check that the characters at the map are correct*/
void	check_char(t_map *game)
{
	t_coord	c;

	c.y = 0;
	while (game->grid[c.y])
	{
		c.x = 0;
		while (game->grid[c.y][c.x])
		{
			if (game->grid[c.y][c.x] != '1' && game->grid[c.y][c.x] != '0'
				&& game->grid[c.y][c.x] != 'C' && game->grid[c.y][c.x] != 'E'
				&& game->grid[c.y][c.x] != 'P')
				ft_free_game(game, ERR_CHAR);
			if (game->grid[c.y][c.x] == 'C')
				game->count_c++;
			if (game->grid[c.y][c.x] == 'P')
				game->count_p++;
			if (game->grid[c.y][c.x] == 'E')
				game->count_e++;
			c.x++;
		}
		c.y++;
	}
	if (game->count_e != 1 || game->count_p != 1 || game->count_c < 1)
		ft_free_game(game, ERR_INCORRECT);
}

/*It checks if the map is surrounded by walls*/
void	check_walls(t_map *game)
{
	t_coord	coord;

	coord.y = 0;
	while (game->grid[coord.y])
	{
		coord.x = 0;
		while (game->grid[coord.y][coord.x])
		{
			if ((coord.y == 0 || coord.y == ((game->height) - 1)
					|| coord.x == 0 || coord.x == ((game->width) - 1))
				&& (game->grid[coord.y][coord.x] != '1'))
				ft_free_game(game, ERR_INCORRECT);
			coord.x++;
		}
		coord.y++;
	}
}
