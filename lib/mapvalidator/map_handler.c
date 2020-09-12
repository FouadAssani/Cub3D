/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 21:06:29 by fassani           #+#    #+#             */
/*   Updated: 2020/09/12 17:13:14 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mapvalidator.h"

int		line_handler(char *ln, char *tab_line, int *nb_line, int *map_begin)
{
	int i;

	i = 0;
	clean_spaces(ln, &i);
	if (*map_begin == 1 && ln[i] != '1')
	{
		if (ln[i] == 0)
			pt("Error: ligne vide détécté dans la map\n");
		return (0);
	}
	if (ln[i] == '1')
	{
		*map_begin = 1;
		ft_memcpy(tab_line, ln, ft_strlen(ln));
		*nb_line += 1;
	}
	return (1);
}

void	map_size_handler(char *ln, int *i, int *x, int *y)
{
	clean_spaces(ln, i);
	if (ln[*i] == '1')
	{
		if (ft_strlen(ln) > *x)
			*x = ft_strlen(ln);
		*y += 1;
	}
}
