/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 11:02:14 by fassani           #+#    #+#             */
/*   Updated: 2020/08/02 11:09:44 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*newline(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = 0;
	str = malloc(size * sizeof(char *) + 1);
	if (str == 0)
		return (0);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	str[size] = 0;
	return (str);
}
