/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:33:08 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/04 16:33:08 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//LIBRARIES//

# include <stdio.h>

# include "../libft/libft.h"


// ERROR MESSAGES

# define ERR_ARG "Wrong number of arguments"
# define ERR_EXT "The extension of the file is not valid"
# define ERR_EMPTY "The file is empty"
# define ERR_INCORRECT "The map in not correct"
# define ERR_CHAR "The character is not valid"
# define ERR_MAP "The map's copy could not be allocated"
# define ERR_FILE "The file could not be open"
# define ERR_INT "The int var could not be allocated"

//RETURN VALUES

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

//STRUCTURES
typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		count_p;
	int		count_e;
	int		count_c;
	t_coord	p_pos;
}	t_map;

//tools
void	my_exit(char *err);
void	ft_free_matrix(char **matrix);
void	ft_free_game(t_map *game, char *err);
char	**copy_map(t_map *game);

//parse_map
t_map	*parse_map(char *map, t_map *game);
t_map	*init_map(t_map *game);
void	fill_map(t_map *game, char *map);

//check_path
void	find_player(t_map *game, char **map);
void	find_collect(char **map, t_coord player, int *count_c);
void	find_exit(char **map, t_coord player);
void	find_exit_2(t_map *game, char **map);
void	check_path(t_map *game);

//check_map_tools
void	check_extension(char *map, t_map *game);
void	check_shape(char *map, t_map *game);
void	check_shape_2(int fd, char *line, t_map *game);
void	check_char(t_map *game);
void	check_walls(t_map *game);

#endif