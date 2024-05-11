/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:54:53 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/05/11 13:13:13 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "libft.h"

int main()
{

	char s[] = "chatarra";
	int i = 0;
	char c = 'a';

	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c || s[i] != '\0')
				i++;
		}
		else
			i++;
	}
}

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
