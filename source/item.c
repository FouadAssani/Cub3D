/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:21:10 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:34:23 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

unsigned int	item_pixel(t_engine *engine, int i, unsigned int col)
{
	int	t;
	int	r;
	int	g;
	int	b;

	if (col == 0xf701eb)
		return (engine->image.adr[i]);
	else if (col < 256 * 256 * 256)
		return (col);
	t = col / (256 * 256 * 256);
	r = (col / (256 * 256) % 256) * (1 - (double)t / 256);
	g = (col / 256 % 256) * (1 - (double)t / 256);
	b = (col % 256) * (1 - (double)t / 256);
	r += (engine->image.adr[i] / (256 * 256) % 256) * ((double)t / 256);
	g += (engine->image.adr[i] / 256 % 256) * ((double)t / 256);
	b += (engine->image.adr[i] % 256) * ((double)t / 256);
	return (r * 256 * 256 + g * 256 + b);
}

void			item_draw(t_engine *engine, int loc, double d)
{
	unsigned int	col;
	double			size;
	int				index;
	int				i;
	int				j;

	i = 0;
	j = 0;
	size = engine->win.height / d / 2;
	loc = loc - size / 2;
	while (i < size)
	{
		while ((loc + i >= 0 && loc + i < engine->win.width) &&
				(j < size && engine->ray.str[loc + i].d > d))
		{
			col = 64 * floor(64 * (double)j / size) + (double)i / size * 64;
			col = engine->textures.item.adr[col];
			index = loc + i + (engine->win.height / 2 + j) * engine->win.width;
			if (index < engine->win.width * engine->win.height)
				engine->image.adr[index] = item_pixel(engine, index, col);
			j++;
		}
		i++;
		j = 0;
	}
}

void			spot_item(t_engine *engine, double x, double y, double d)
{
	double	angle;

	x = (x - engine->player.position_x) / d;
	y = (y - engine->player.position_y) / d;
	if (y <= 0)
		angle = acos(x) * 180 / M_PI;
	else
		angle = 360 - acos(x) * 180 / M_PI;
	angle = engine->player.direction_a - angle + 33;
	if (angle >= 180)
		angle -= 360;
	else if (angle <= -180)
		angle += 360;
	item_draw(engine, angle * engine->win.width / 66, d);
}

void			item_action(t_engine *engine)
{
	t_ray_storage	tmp;
	int				i;
	int				j;

	i = 0;
	while (i < engine->world_map.item_len - 1)
	{
		j = i + 1;
		while (j < engine->world_map.item_len)
		{
			if (engine->items[i].d < engine->items[j].d)
			{
				tmp = engine->items[i];
				engine->items[i] = engine->items[j];
				engine->items[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			draw_items(t_engine *en)
{
	int		i;
	double	d;

	d = hypot(en->player.direction_x, en->player.direction_y);
	if (en->player.direction_y <= 0)
		en->player.direction_a = acos(en->player.direction_x / d) * 180 / M_PI;
	else
		en->player.direction_a = 360 -
			acos(en->player.direction_x / d) * 180 / M_PI;
	i = 0;
	while (i < en->world_map.item_len)
	{
		en->items[i].d = hypot(en->items[i].x -
			en->player.position_x, en->items[i].y - en->player.position_y);
		i++;
	}
	item_action(en);
	i = 0;
	while (i < en->world_map.item_len)
	{
		spot_item(en, en->items[i].x, en->items[i].y, en->items[i].d);
		i++;
	}
	free(en->ray.str);
}
