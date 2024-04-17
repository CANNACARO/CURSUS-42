/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:53 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/04/17 20:00:46 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <bsd/string.h>


int	main(void)
{
	char src[]= "hola";
	char dest[]= "adiossss";
	int x;
	
	x = strlcpy(dest, src, 0);
	printf("%s   %d",dest, x);
}

/*memmove original me lanza un error al poner el numero de caracteres mayor al de la fuente
prueba.c:22:9: error: ‘__builtin_memcpy’ reading 6 bytes from a region of size 5 [-Werror=stringop-overread]
   22 |         memmove(dest, src, 6);
   
   Mi ft_strlcpy hace segfault (core dumped) cuando pon size = 0
   
   
   */