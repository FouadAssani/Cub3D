/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_map_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:12:40 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	is_invalide_line(char *ln, int *error, int *i)
{
	if ((ln[*i] == '1') ||
		(ln[*i] == 'R' && ln[*i + 1] == ' ') ||
		(ln[*i] == 'S' && ln[*i + 1] == ' ') ||
		(ln[*i] == 'F' && ln[*i + 1] == ' ') ||
		(ln[*i] == 'C' && ln[*i + 1] == ' ') ||
		(ln[*i] == 0))
	{
		*error = 0;
	}
	if (ft_strlen(ln) >= 2)
	{
		if ((ln[*i] == 'N' && ln[*i + 1] == 'O') ||
			(ln[*i] == 'S' && ln[*i + 1] == 'O' && ln[*i + 2] == ' ') ||
			(ln[*i] == 'W' && ln[*i + 1] == 'E' && ln[*i + 2] == ' ') ||
			(ln[*i] == 'E' && ln[*i + 1] == 'A' && ln[*i + 2] == ' '))
		{
			*error = 0;
		}
	}
}

int		valide_config_line(t_engine *e, char *ln, int nb_l)
{
	int error;
	int i;

	i = 0;
	error = 1;
	clean_spaces(ln, &i);
	is_invalide_line(ln, &error, &i);
	if (error == 1)
	{
		e->world_map.error = 2;
		pt("Error : fichier config ligne ");
		ft_putchar_fd('0' + nb_l, 1);
	}
	if (line_handler(e, ln, &i) == -1)
		return (-1);
	return (1);
}
