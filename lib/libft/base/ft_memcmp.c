/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:41:15 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:41 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
**	La fonction memcmp() compare les n premiers octets des zones mémoire s1
**	et s2. Elle renvoie un entier inférieur, égal, ou supérieur à zéro,
**	si s1 est respectivement inférieure, égale ou supérieur à s2.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*temp_s1;
	unsigned char		*temp_s2;

	temp_s1 = (unsigned char*)s1;
	temp_s2 = (unsigned char*)s2;
	i = 0;
	while (temp_s1[i] == temp_s2[i] && i < n - 1)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	if ((temp_s1[i] != temp_s2[i]) && i < n)
		return (temp_s1[i] - temp_s2[i]);
	return (0);
}
