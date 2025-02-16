/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:04:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/16 18:23:45 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/so_long.h"

/*It print an error message and ends the execution of the program*/
void	my_exit(char *err)
{
	perror(err);
	exit(FAILURE);
}
/*It frees a matrix **char*/
void ft_free_matrix(char **matrix)
{
	int i;

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
void	*ft_free_game(t_map *game, char *err)
{
	if (game->store_map)
		ft_free_matrix(game->store_map);
	free(game);
	my_exit(err);
}

char **copy_map(t_map *game)
{
	t_coord coord;
	char **new_map;

	new_map = malloc(sizeof(char *) * (game->height + 1));
	if (!new_map)
		ft_free_game(game, ERR_MAP);
	coord.y = 0;
	while (game->store_map[coord.y])
	{
		new_map[coord.y] = ft_strdup(game->store_map[coord.y]);
		if(!new_map[coord.y])
		{
			ft_free_matrix(new_map);
			ft_free_game(game,ERR_MAP);
		}
		coord.y++;
	}
	new_map[coord.y] = NULL;
	return (new_map);
}