/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:31:03 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/04 16:31:03 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCLUDES/so_long.h"

int check_extension(char *map)
{
	if (!(map[ft_strlen(map) - 1]  == 'r' && map[ft_strlen(map) - 2]  == 'e' && 
	map[ft_strlen(map) - 3]  == 'b' && map[ft_strlen(map) - 3]  == '.'))
	{
		perror(ERR_EXT);
		exit (FAILURE);
	}
	return (SUCCESS);
}

int parse_map(char *map)
{
	check_extension(map);
}


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		perror(ERR_ARG);
		exit (FAILURE);
	}
	else
	{
		parse_map(argv[1]);
	}
}