/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:38:35 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/08 18:14:48 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_image_t	*texture_to_image(t_map *game, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		mlx_terminate(game->window);
		ft_free_game(game, ERR_TEXTURE);
	}
	image = mlx_texture_to_image(game->window, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	load_images(t_map *game)
{
	game->images.background = texture_to_image(game,
			"./images/Background_space.png");
	if (!game->images.background)
		ft_free_game(game, ERR_IMAGE);
	game->images.collectible = texture_to_image(game,
			"./images/Collect_liquicity.png");
	if (!game->images.collectible)
		ft_free_game(game, ERR_IMAGE);
	game->images.exit = texture_to_image(game, "./images/Exit_bh.png");
	if (!game->images.exit)
		ft_free_game(game, ERR_IMAGE);
	game->images.wall = texture_to_image(game, "./images/Wall_asteroid.png");
	if (!game->images.wall)
		ft_free_game(game, ERR_IMAGE);
	game->images.player = texture_to_image(game, "./images/Player_up.png");
	if (!game->images.player)
		ft_free_game(game, ERR_IMAGE);
}

void	render_window(t_map *game)
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
			if (game->grid[c.y][c.x] == 'P')
				mlx_image_to_window(game->window, game->images.player,
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
		}
	}
}

void	create_window(t_map *game)
{
	game->window = mlx_init(game->width * 64, game->height * 64, TITLE, true);
	if (!game->window)
		ft_free_game(game, ERR_WINDOW);
	load_images(game);
	render_window(game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_loop(game->window);
}
