/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:57:29 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/08 18:33:49 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*game;

	game = (t_map *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_free_game(game, CLOSE_WINDOW);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		moves(game, 0, -1);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		moves(game, 0, 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		moves(game, -1, 0);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		moves(game, 1, 0);
}

void	moves(t_map *game, int x, int y)
{
	t_coord	new_pos;

	new_pos.x = game->p_pos.x + x;
	new_pos.y = game->p_pos.y + y;
	if (game->grid[new_pos.y][new_pos.x] == 'E' && game->count_c == 0)
	{
		game->moves++;
		ft_printf("Number of moves: %d\n", game->moves);
		ft_free_game(game, WIN);
	}
	moves_2(game, new_pos);
}

void	moves_2(t_map *game, t_coord new_pos)
{
	if (game->grid[new_pos.y][new_pos.x] == 'C' ||
		game->grid[new_pos.y][new_pos.x] == '0')
	{
		game->moves++;
		ft_printf("Number of moves: %d\n", game->moves);
		if (game->grid[new_pos.y][new_pos.x] == 'C')
			game->count_c--;
		game->grid[game->p_pos.y][game->p_pos.x] = '0';
		mlx_image_to_window(game->window, game->images.background,
			game->p_pos.x * 64, game->p_pos.y * 64);
		game->p_pos = new_pos;
		mlx_image_to_window(game->window, game->images.background,
			game->p_pos.x * 64, game->p_pos.y * 64);
		mlx_image_to_window(game->window, game->images.player,
			game->p_pos.x * 64, game->p_pos.y * 64);
	}
}
