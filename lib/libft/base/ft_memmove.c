/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:45:54 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:47 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
**	La fonction memmove() copie n octets depuis la zone mémoire src vers la zone
**	mémoire dest. Les deux zones peuvent se chevaucher : la copie se passe
**	comme si les octets de src étaient d'abord copiés dans une zone temporaire
**	qui ne chevauche ni src ni dest, et les octets sont ensuite
**	copiés de la zone temporaire vers dest
**	La fonction memmove() renvoie un pointeur sur dest
*/

static int		because_norme2(char *dst, char *src, char temp_char, size_t len)
{
	size_t i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		while (len-- && ++i)
		{
			temp_char = src[len];
			dst[len] = temp_char;
		}
	}
	else
	{
		while (i < len)
		{
			temp_char = src[i];
			dst[i++] = temp_char;
		}
	}
	return (1);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*temp_dst;
	const char		*temp_src;
	char			temp_char;

	temp_dst = dst;
	temp_src = src;
	temp_char = 0;
	because_norme2(temp_dst, (char *)temp_src, temp_char, len);
	return (dst);
}
