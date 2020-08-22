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

char		*parse_map_line(t_engine *e, char *l, int *i, int j)
{
	char	*b_map;

	if (!(b_map = malloc(sizeof(char) * (ft_strlen(l) + 1))))
		return (0);
	while (l[++*i] != 0)
	{
		if (l[*i] == '0' || l[*i] == '1' || l[*i] == '2')
		{
			b_map[j++] = l[*i];
			if (l[*i] == '2')
				e->world_map.item_len++;
		}
		else if (l[*i] == 'N' || l[*i] == 'S' || l[*i] == 'E' || l[*i] == 'W')
		{
			b_map[j++] = l[*i];
			e->player.error++;
		}
		else if (l[*i] != ' ')
		{
			free(b_map);
			return (0);
		}
	}
	b_map[j] = 0;
	return (b_map);
}

void		map(t_engine *engine, char *line, int *i)
{
	char	**chunk;
	int		j;

	j = -1;
	if (!(chunk = malloc(sizeof(char *) * (engine->world_map.y + 2))))
	{
		engine->error = 1;
		return ;
	}
	while (++j < engine->world_map.y)
		chunk[j] = engine->world_map.grid[j];
	(*i)--;
	if ((chunk[engine->world_map.y] = parse_map_line(engine, line, i, 0)) == 0)
	{
		engine->error = 1;
		free(chunk);
		return ;
	}
	chunk[engine->world_map.y + 1] = 0;
	if (engine->world_map.y > 0)
		free(engine->world_map.grid);
	engine->world_map.grid = chunk;
	engine->world_map.y++;
	if ((engine->world_map.x = get_size_map_line(engine, line)) == -1)
		engine->world_map.error = 1;
}
