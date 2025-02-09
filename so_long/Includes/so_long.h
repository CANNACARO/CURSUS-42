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

# include "./libft/libft.h"


// ERROR MESSAGES

# define ERR_ARG "Wrong number of arguments"
# define ERR_EXT "The extension of the file is not valid"
# define ERR_EMPTY "The file is empty"
# define ERR_INCORRECT "The map in not correct"
# define ERR_CHAR "The character is not valid"

//RETURN VALUES

# define SUCCESS 0
# define FAILURE 1
# define ERROR -1

//STRUCTURES
typedef struct s_map
{
	char **store_map;
	int height;
	int width;
	int count_P;
	int count_E;
	int count_C;
}	t_map;

typedef struct s_coord
{
	int x;
	int y;
}	t_coord;

#endif