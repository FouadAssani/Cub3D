/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:56:57 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:50 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	is_on_array(char c, char *array)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(array);
	while (i < len)
	{
		if (c == array[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*str;

	if (!s1)
		return (0);
	begin = 0;
	end = ft_strlen(s1);
	while (begin < end && is_on_array(s1[begin], (char *)set) == 1)
		begin++;
	if (begin >= end)
	{
		if (!(str = ft_calloc(1, sizeof(char))))
			return (0);
		str[0] = 0;
		return (str);
	}
	while (end-- && is_on_array(s1[end], (char *)set) == 1)
	{
	}
	if (!(str = ft_calloc((end - begin) + 1, sizeof(char))))
		return (0);
	str = ft_substr(s1, begin, (end - begin) + 1);
	return (str);
}
