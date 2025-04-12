/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:04:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/12 18:42:14 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*It print an error message and ends the execution of the program*/
void	my_exit(char *err)
{
	ft_printf("%s", err);
	exit(FAILURE);
}

/*It frees a matrix **char*/
void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

/*It frees images*/
void	ft_delete_images(t_map *game)
{
	if (game->images.background)
		mlx_delete_image(game->window, game->images.background);
	if (game->images.collectible)
		mlx_delete_image(game->window, game->images.collectible);
	if (game->images.exit)
		mlx_delete_image(game->window, game->images.exit);
	if (game->images.player_up)
		mlx_delete_image(game->window, game->images.player_up);
	if (game->images.player_down)
		mlx_delete_image(game->window, game->images.player_down);
	if (game->images.player_left)
		mlx_delete_image(game->window, game->images.player_left);
	if (game->images.player_right)
		mlx_delete_image(game->window, game->images.player_right);
	if (game->images.wall)
		mlx_delete_image(game->window, game->images.wall);
	if (game->images.oponent)
		mlx_delete_image(game->window, game->images.oponent);
	if (game->images.show_moves)
		mlx_delete_image(game->window, game->images.show_moves);
}

/*It frees t_map variable and the matrix that 
	stores the map
*/
void	ft_free_game(t_map *game, char *err)
{
	ft_delete_images(game);
	if (game->window)
		mlx_terminate(game->window);
	if (game->grid)
		ft_free_matrix(game->grid);
	free(game);
	clear_gnl_stack();
	my_exit(err);
}

/*It creates a copy of the map*/
char	**copy_map(t_map *game)
{
	t_coord	coord;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (game->height + 1));
	if (!new_map)
		ft_free_game(game, ERR_MAP);
	coord.y = 0;
	while (game->grid[coord.y])
	{
		new_map[coord.y] = ft_strdup(game->grid[coord.y]);
		if (!new_map[coord.y])
		{
			ft_free_matrix(new_map);
			ft_free_game(game, ERR_MAP);
		}
		coord.y++;
	}
	new_map[coord.y] = NULL;
	return (new_map);
}
