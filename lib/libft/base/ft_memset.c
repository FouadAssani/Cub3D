/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:58:31 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:50 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
**	La fonction memset() remplit les len premiers
**	octets de la zone mémoire pointée par b avec l'octet c
**	et renvoie un pointeur sur la zone mémoire s.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char			*temp_b;
	unsigned char	temp_c;
	int				i;

	i = 0;
	temp_b = b;
	temp_c = c;
	while (len--)
	{
		temp_b[len] = temp_c;
	}
	return (b);
}
