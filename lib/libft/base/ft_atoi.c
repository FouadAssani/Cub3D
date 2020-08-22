/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:46:47 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:06 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	because_norme(char *str, size_t i, long resultat, int signe)
{
	while (ft_isdigit(str[i]))
	{
		if (-2147483648 > ((long)resultat * 10) + (str[i] - '0'))
		{
			if (signe == 1)
				return (-1);
			else
				return (0);
		}
		resultat = (resultat * 10) + (str[i++] - '0');
	}
	if (signe == 1)
		return (resultat);
	else
		return (-resultat);
}

int			ft_atoi(const char *str)
{
	long	resultat;
	int		signe;
	size_t	i;

	i = 0;
	resultat = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	return (because_norme((char *)str, i, resultat, signe));
}
