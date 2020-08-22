/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:17:38 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:35 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
**	La fonction memccpy() copie au plus n octets de la zone mémoire src
**	vers la zone mémoire dest, s'arrêtant dès qu'elle rencontre le caractère c
**	et La fonction memccpy() renvoie un pointeur sur
**	le caractère immédiatement après c dans la zone dest, ou NULL
**	si c n'a pas été trouvé dans les n premiers caractères de src
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;
	size_t				i;

	temp_dst = dst;
	temp_src = src;
	i = 0;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		if ((unsigned char)temp_src[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
