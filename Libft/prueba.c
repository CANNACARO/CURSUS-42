/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:53 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/05/03 09:17:18 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

/*int main() {//main para el split
    const char *phrase = "OpenAI is an artificial intelligence company.";
    char **words = ft_split(phrase, 'a');

    if (words) {
        int i = 0;
        while (words[i] != NULL) {
            printf("Word %d: %s\n", i+1, words[i]);
            i++;
        }

        // Free the allocated memory for the words array
        free(words);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/

int main()
{
	int	str_size;
	int n;

	n = -2147483648;
	str_size = 0;
	if (n < 0)
		str_size++;
	while (n / 10 != 0)
	{
		str_size++;
		n = n / 10;
	}
		str_size++;
	printf("%d",str_size);
	return (0);
}
