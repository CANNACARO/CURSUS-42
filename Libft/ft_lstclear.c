/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 10:30:10 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/05/19 11:29:44 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *aux;

	if (*lst == NULL)
	{
		return ;
	}
	while (*lst != NULL)
	{
		aux = (*lst) ->next;
		del ((*lst) ->content);
		free(*lst);
		*lst = aux;
	}
}
