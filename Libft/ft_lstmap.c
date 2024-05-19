/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:10:31 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/05/19 13:11:54 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_lst;
	t_list	*root;

	res_lst = NULL;
	root = res_lst;
	if (!lst)
		return (NULL);
	while (lst)
	{
		res_lst = malloc(sizeof(t_list));
		if (!res_lst)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		res_lst = f(lst -> content);
		res_lst = res_lst -> next;
		lst = lst -> next;
	}
	res_lst = NULL;
	return (res_lst);
}
