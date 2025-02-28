/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/04 16:31:03 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/02/04 16:31:03 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_map	*game;

	if (argc != 2)
		my_exit(ERR_ARG);
	else
	{
		game = malloc(sizeof(t_map));
		if (!game)
			my_exit("The game could not be allocated");
		game = init_map(game);
		game = parse_map(argv[1], game);
	}
	return (0);
}
