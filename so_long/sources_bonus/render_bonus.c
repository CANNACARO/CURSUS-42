/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:38:35 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/14 20:15:45 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*It draws the whole initial map*/
void	render_window(t_map *game)
{
	t_coord	c;

	c.y = -1;
	while (game->grid[++c.y])
	{
		c.x = -1;
		while (game->grid[c.y][++c.x])
		{
			if (game->grid[c.y][c.x] == 'P')
				mlx_image_to_window(game->window, game->images.player_up,
					c.x * 64, c.y * 64);
			if (game->grid[c.y][c.x] == 'E')
				mlx_image_to_window(game->window, game->images.exit,
					c.x * 64, c.y * 64);
			if (game->grid[c.y][c.x] == 'C')
				mlx_image_to_window(game->window, game->images.collectible,
					c.x * 64, c.y * 64);
			if (game->grid[c.y][c.x] == '1')
				mlx_image_to_window(game->window, game->images.wall,
					c.x * 64, c.y * 64);
			if (game->grid[c.y][c.x] == 'O')
				mlx_image_to_window(game->window, game->images.oponent,
					c.x * 64, c.y * 64);
		}
	}
}

/*It draws the background in the whole map*/
void	render_background(t_map *game)
{
	t_coord	c;

	c.y = -1;
	while (game->grid[++c.y])
	{
		c.x = -1;
		while (game->grid[c.y][++c.x])
		{
			mlx_image_to_window(game->window, game->images.background,
				c.x * 64, c.y * 64);
		}
	}
}

mlx_image_t	*my_put_string(t_map *game)
{
	char		*str_moves;
	char		*message;
	mlx_image_t	*show_moves;

	str_moves = (ft_itoa(game->moves));
	if (!str_moves)
		ft_free_game(game, ERR_STR);
	message = ft_strjoin("Moves: ", str_moves);
	if (!message)
		ft_free_game(game, ERR_STR);
	show_moves = mlx_put_string(game->window, message, 80, 20);
	free (str_moves);
	free (message);
	return (show_moves);
}

/*It involves everything about the window
	(initiate it, rendering, key hook...))*/
void	create_window(t_map *game)
{
	game->window = mlx_init(game->width * 64, game->height * 64, TITLE, true);
	if (!game->window)
		ft_free_game(game, ERR_WINDOW);
	load_images(game);
	load_images_2(game);
	render_background(game);
	render_window(game);
	game->images.show_moves = my_put_string(game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->window);
}
