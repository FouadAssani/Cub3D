/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:08:08 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:11 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
** La fonction bzero() met à 0 (octets contenant « \0 »)
** les n premiers octets du bloc pointé par s.
*/

void	ft_bzero(void *b, size_t len)
{
	char			*temp_b;
	size_t			i;

	i = 0;
	temp_b = b;
	while (i < len)
	{
		temp_b[i] = 0;
		i++;
	}
}
