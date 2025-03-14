/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:34:54 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/03/11 19:46:28 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*It converts textures to images*/
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

/*It load the images into a format in which mlx42 understand it*/
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
}

/*Second part of load_images*/
void	load_images_2(t_map *game)
{
	game->images.player_up = texture_to_image(game, "./images/Player_up.png");
	if (!game->images.player_up)
		ft_free_game(game, ERR_IMAGE);
	game->images.player_down = texture_to_image(game,
			"./images/Player_down.png");
	if (!game->images.player_down)
		ft_free_game(game, ERR_IMAGE);
	game->images.player_left = texture_to_image(game,
			"./images/Player_left.png");
	if (!game->images.player_left)
		ft_free_game(game, ERR_IMAGE);
	game->images.player_right = texture_to_image(game,
			"./images/Player_right.png");
	if (!game->images.player_right)
		ft_free_game(game, ERR_IMAGE);
	game->images.oponent = texture_to_image(game, "./images/Enemy_alien.png");
	if (!game->images.oponent)
		ft_free_game(game, ERR_IMAGE);
}
