/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:24:27 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int			get_size_map_line(t_engine *engine, char *line)
{
	int	count;

	count = 0;
	count = ft_strlen(line);
	if (engine->world_map.x != 0 && engine->world_map.x != count)
		return (-1);
	return (count);
}

void		parse_map_line(t_engine *e, char *l, int *i)
{
	while (l[++*i] != 0)
	{
		if (l[*i] == '2')
			e->world_map.item_len++;
		else if (l[*i] == 'N' || l[*i] == 'S' || l[*i] == 'E' || l[*i] == 'W')
		{
			e->player.error++;
		}
	}
}

void		map(t_engine *engine, char *line, int *i)
{
	parse_map_line(engine, line, i);
}
