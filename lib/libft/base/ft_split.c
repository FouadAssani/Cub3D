/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:53:57 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:08 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	len_word(char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!i)
		i++;
	return (i);
}

static size_t	nb_split(char *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i] != c && (i > 0 && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	char		**array;
	size_t		index;
	size_t		i;

	index = 0;
	i = 0;
	if (!s)
		return (0);
	if (!(array = ft_calloc((nb_split((char *)s, c) + 1), sizeof(char *))))
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			array[index] = ft_substr(&s[i], 0, len_word((char *)&s[i], c));
			i = i + len_word((char *)&s[i], c);
			index++;
		}
	}
	array[index] = 0;
	return (array);
}
