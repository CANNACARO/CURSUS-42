/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:58:51 by jcaro-lo          #+#    #+#             */
/*   Updated: 2025/09/10 16:59:13 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_data(t_data *data)
{
	if (data->philos)
		free (data->philos);
	if (data->forks)
		free (data->forks);
	free (data);
}

int	clear_program(t_data *data)
{
	destroy_mutex(data);
	return (error_msg(data, ERR_TH_JOIN));
}

int	error_msg(t_data *data, char *str)
{
	printf(str);
	free_data(data);
	return (1);
}
