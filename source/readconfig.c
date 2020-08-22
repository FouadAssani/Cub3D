/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readconfig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:03:12 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		line_handler(t_engine *e, char *ln, int *i)
{
	if ((ln[*i] == '1') && ln[*i] != 0)
		map(e, ln, i);
	else if (ln[*i] == 'R' && ln[*i + 1] == ' ')
		set_resolution_screen(e, ln, i);
	else if (ln[*i] == 'N' && ln[*i + 1] == 'O' && ln[*i + 2] == ' ')
		parse_texture_line(e, &e->textures.nord, ln, i);
	else if (ln[*i] == 'S' && ln[*i + 1] == 'O' && ln[*i + 2] == ' ')
		parse_texture_line(e, &e->textures.sud, ln, i);
	else if (ln[*i] == 'W' && ln[*i + 1] == 'E' && ln[*i + 2] == ' ')
		parse_texture_line(e, &e->textures.west, ln, i);
	else if (ln[*i] == 'E' && ln[*i + 1] == 'A' && ln[*i + 2] == ' ')
		parse_texture_line(e, &e->textures.est, ln, i);
	else if (ln[*i] == 'S' && ln[*i + 1] == ' ')
		parse_texture_line(e, &e->textures.item, ln, i);
	else if (ln[*i] == 'F' && ln[*i + 1] == ' ')
		parse_color_line(&e->textures.floor_color, ln, i, &e->textures.error);
	else if (ln[*i] == 'C' && ln[*i + 1] == ' ')
		parse_color_line(&e->textures.sky_color, ln, i, &e->textures.error);
	clean_spaces(ln, i);
	return (0);
}

int		ping_items(t_engine *e)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (e->items != 0)
		free(e->items);
	if (!(e->items = malloc(sizeof(t_ray_storage) * e->world_map.item_len)))
		return (-1);
	while (j < e->world_map.y)
	{
		k = 0;
		while (k < e->world_map.x)
		{
			if (e->world_map.grid[j][k] == '2')
			{
				e->items[i].y = (double)j + 0.5;
				e->items[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}
	return (1);
}

int		readconfig(int fd, t_engine *engine, int nb_ligne, int index)
{
	char	*ln;

	while (index == 1 && engine->world_map.error == 0)
	{
		index = get_next_line(fd, &ln);
		nb_ligne++;
		if (valide_config_line(engine, ln, index, nb_ligne) == -1)
			index = -1;
		free(ln);
	}
	close(fd);
	if (index == -1 || index == -3)
	{
		free_memory(engine);
		return (0);
	}
	if (verification_config(engine) != 0)
	{
		free_memory(engine);
		return (0);
	}
	ping_items(engine);
	view_spawn(engine);
	return (1);
}
