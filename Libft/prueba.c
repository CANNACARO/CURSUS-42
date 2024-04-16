/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:53 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/04/16 20:30:22 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>


int	main(void)
{
	char src[]= "hola";
	char dest[]= "adiossss";
	
	memmove(dest, src, 6);
	printf("%s",dest);
}

//memmove original me lanza un error al poner el numero de caracteres mayor al de la fuente
//prueba.c:22:9: error: ‘__builtin_memcpy’ reading 6 bytes from a region of size 5 [-Werror=stringop-overread]
//   22 |         memmove(dest, src, 6);