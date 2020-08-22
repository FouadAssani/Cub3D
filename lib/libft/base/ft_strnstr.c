/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:55:23 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:41 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int			i;
	int			size_needle;
	char		*str1;
	char		*str2;

	i = 0;
	str1 = (char *)haystack;
	str2 = (char *)needle;
	size_needle = ft_strlen(str2);
	if (str2[0] == 0)
		return (str1);
	while (i <= (int)len - size_needle && str1[i])
	{
		if (ft_strncmp(&str1[i], str2, size_needle) == 0)
			return (&str1[i]);
		i++;
	}
	return (0);
}
