/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:04:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/04/12 18:21:59 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

/*It frees t_map variable and the matrix that 
	stores the map
*/
void	ft_free_game(t_map *game, char *err)
{
	if (game->images.background)
		mlx_delete_image(game->window, game->images.background);
	if (game->images.collectible)
		mlx_delete_image(game->window, game->images.collectible);
	if (game->images.exit)
		mlx_delete_image(game->window, game->images.exit);
	if (game->images.player)
		mlx_delete_image(game->window, game->images.player);
	if (game->images.wall)
		mlx_delete_image(game->window, game->images.wall);
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
