/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:08:05 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/11 19:16:18 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*It search the player position, store it on structure t_map
	and set its character to '0' to make next function (find_collect) easier*/
void	find_player(t_map *game, char	**map)
{
	t_coord	coord;

	coord.y = 0;
	while (map[coord.y])
	{
		coord.x = 0;
		while (map[coord.y][coord.x])
		{
			if (map[coord.y][coord.x] == 'P')
			{
				game->p_pos.y = coord.y;
				game->p_pos.x = coord.x;
				map[coord.y][coord.x] = '0';
				break ;
			}
			coord.x++;
		}
		coord.y++;
	}
}

/*It check if there is a path to find all collectibles*/
void	find_collect(char **map, t_coord player, int *count_c)
{
	if (map[player.y][player.x] != '0' && map[player.y][player.x] != 'C')
		return ;
	if (map[player.y][player.x] == 'C')
		(*count_c)++;
	map[player.y][player.x] = '-';
	find_collect(map, (t_coord){player.x - 1, player.y}, count_c);
	find_collect(map, (t_coord){player.x + 1, player.y}, count_c);
	find_collect(map, (t_coord){player.x, player.y - 1}, count_c);
	find_collect(map, (t_coord){player.x, player.y + 1}, count_c);
}

/*It search the exit and set the exit and its path to '0'
	to make find_exit_2 function easier*/
void	find_exit(char **map, t_coord player)
{
	if (map[player.y][player.x] != '-' && map[player.y][player.x] != 'E')
		return ;
	map[player.y][player.x] = '0';
	find_exit(map, (t_coord){player.x - 1, player.y});
	find_exit(map, (t_coord){player.x + 1, player.y});
	find_exit(map, (t_coord){player.x, player.y - 1});
	find_exit(map, (t_coord){player.x, player.y + 1});
}

/*It check if there is only '1' and '0' on the map*/
void	find_exit_2(t_map *game, char **map)
{
	t_coord	coord;

	coord.y = 0;
	while (map[coord.y])
	{
		coord.x = 0;
		while (map[coord.y][coord.x])
		{
			if (map[coord.y][coord.x] != '0' && map[coord.y][coord.x] != '1'
				&& map[coord.y][coord.x] != 'O')
				ft_free_game(game, ERR_INCORRECT);
			coord.x++;
		}
		coord.y++;
	}
}

/*It creates a copy of the map and
	checks if there is a correct path for the player to win the game*/
void	check_path(t_map *game)
{
	char	**new_map;
	t_coord	init_pos;
	int		*count_c;

	count_c = malloc(sizeof(int));
	if (!count_c)
		ft_free_game(game, ERR_INT);
	*count_c = 0;
	new_map = copy_map(game);
	find_player(game, new_map);
	init_pos.y = game->p_pos.y;
	init_pos.x = game->p_pos.x;
	find_collect(new_map, init_pos, count_c);
	if (*count_c != game->count_c)
		ft_free_game(game, ERR_INCORRECT);
	free(count_c);
	find_exit(new_map, init_pos);
	find_exit_2(game, new_map);
	ft_free_matrix(new_map);
}
