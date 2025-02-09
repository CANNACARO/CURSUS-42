/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:04:01 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/09 17:39:46 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/so_long.h"

void	my_exit(char *err)
{
	perror(err);
	exit(FAILURE);
}
//It frees t_map variable and its double char
void	*ft_free_game(t_map *game, char *err)
{
	if (game->store_map)
		free(game->store_map);
	free(game);
	my_exit(err);
}