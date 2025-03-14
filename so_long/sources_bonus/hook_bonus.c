/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:57:29 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/14 19:48:30 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*It handles events of keyboard*/
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

/*It moves the player and reload the window*/
void	moves(t_map *game, int x, int y)
{
	t_coord	new_pos;

	new_pos.x = game->p_pos.x + x;
	new_pos.y = game->p_pos.y + y;
	if (game->grid[new_pos.y][new_pos.x] == 'E' && game->count_c == 0)
	{
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		ft_free_game(game, WIN);
	}
	if (game->grid[new_pos.y][new_pos.x] == 'O')
		ft_free_game(game, LOSE);
	moves_2(game, new_pos, x, y);
}

/*Second part of moves*/
void	moves_2(t_map *game, t_coord new_pos, int x, int y)
{
	if (game->grid[new_pos.y][new_pos.x] == 'C' ||
		game->grid[new_pos.y][new_pos.x] == '0')
	{
		game->moves++;
		mlx_image_to_window(game->window, game->images.background, 64, 0);
		mlx_image_to_window(game->window, game->images.background, 128, 0);
		mlx_image_to_window(game->window, game->images.wall, 64, 0);
		mlx_image_to_window(game->window, game->images.wall, 128, 0);
		game->images.show_moves = my_put_string(game);
		ft_printf("Moves: %d\n", game->moves);
		if (game->grid[new_pos.y][new_pos.x] == 'C')
			game->count_c--;
		game->grid[game->p_pos.y][game->p_pos.x] = '0';
		mlx_image_to_window(game->window, game->images.background,
			game->p_pos.x * 64, game->p_pos.y * 64);
		game->p_pos = new_pos;
		mlx_image_to_window(game->window, game->images.background,
			game->p_pos.x * 64, game->p_pos.y * 64);
		reload_player(game, x, y);
	}
}

/*It renders the new position of the player*/
void	reload_player(t_map *game, int x, int y)
{
	if (y < 0)
		mlx_image_to_window(game->window, game->images.player_up,
			game->p_pos.x * 64, game->p_pos.y * 64);
	if (y > 0)
		mlx_image_to_window(game->window, game->images.player_down,
			game->p_pos.x * 64, game->p_pos.y * 64);
	if (x > 0)
		mlx_image_to_window(game->window, game->images.player_right,
			game->p_pos.x * 64, game->p_pos.y * 64);
	else if (x < 0)
		mlx_image_to_window(game->window, game->images.player_left,
			game->p_pos.x * 64, game->p_pos.y * 64);
}
