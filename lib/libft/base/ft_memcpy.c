/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:00:21 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:44 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
**	La fonction memcpy() copie n octets depuis
**	la zone mémoire src vers la zone mémoire dest
**	et La fonction memcpy() renvoie un pointeur sur dest.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*temp_dst;
	char		*temp_src;

	temp_dst = dst;
	temp_src = (char *)src;
	if (temp_dst == 0 && temp_src == 0)
		return (0);
	while (n--)
		temp_dst[n] = temp_src[n];
	return (dst);
}
