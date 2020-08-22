/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:54:29 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:20 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(str = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char *))))
		return (0);
	while (s1[i] != 0)
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != 0)
	{
		str[j++] = s2[i++];
	}
	str[j] = 0;
	return (str);
}
