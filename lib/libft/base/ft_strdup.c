/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:59:28 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:15 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = malloc(sizeof(*tab) * (ft_strlen(s1) + 1))))
		return (0);
	while (s1[i] != 0)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}
