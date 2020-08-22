/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 01:07:04 by fassani           #+#    #+#             */
/*   Updated: 2020/08/09 20:09:38 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	view_spawn(t_engine *engine)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < engine->world_map.y)
	{
		while (++j < engine->world_map.x)
		{
			c = engine->world_map.grid[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				engine->player.position_y = (double)i + 0.5;
				engine->player.position_x = (double)j + 0.5;
				engine->player.direction_x = (c == 'E' || c == 'W') ? 1 : 0;
				engine->player.direction_x *= (c == 'W') ? -1 : 1;
				engine->player.direction_y = (c == 'S' || c == 'N') ? 1 : 0;
				engine->player.direction_y *= (c == 'N') ? -1 : 1;
			}
		}
		j = -1;
	}
}
