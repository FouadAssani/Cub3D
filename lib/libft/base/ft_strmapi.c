/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:56:00 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:35 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	array = ft_strdup(s);
	if (!array || !f)
		return (0);
	while (array[i])
	{
		array[i] = f(i, array[i]);
		i++;
	}
	return (array);
}
