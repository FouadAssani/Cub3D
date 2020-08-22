/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:11:19 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:38 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** La fonction memchr() examine les n premiers octets de la zone mémoire
** pointée par s à la recherche du caractère c. Le premier octet correspondant
** à c (interprété comme un unsigned char) arrête l'opération.
** Les fonctions memchr() et memrchr() renvoient un pointeur sur l'octet
** correspondant, ou NULL si le caractère n'est pas présent
** dans la zone de mémoire concernée
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	temp_c;
	size_t			i;

	temp_s = (unsigned char *)s;
	temp_c = c;
	i = 0;
	while (i < n)
	{
		if (temp_s[i] == temp_c)
			return (void *)&temp_s[i];
		i++;
	}
	return (0);
}
