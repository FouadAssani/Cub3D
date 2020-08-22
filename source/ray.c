/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/09 20:09:12 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void			ray(t_engine *engine)
{
	double	angle;
	double	d;

	angle = ((double)engine->ray.r_i - (engine->win.width / 2)) *
	33 / (engine->win.width / 2);
	angle = angle * M_PI / 180;
	engine->ray.r_x = engine->player.direction_x *
	cos(angle) - engine->player.direction_y * sin(angle);
	engine->ray.r_y = engine->player.direction_y *
	cos(angle) + engine->player.direction_x * sin(angle);
	d = hypot(engine->ray.r_x, engine->ray.r_y);
	engine->ray.r_x /= d;
	engine->ray.r_y /= d;
	ray_direction(engine);
}

void			ray_direction(t_engine *engine)
{
	if (engine->ray.r_x >= 0)
		engine->ray.r_v = 1;
	else
		engine->ray.r_v = 0;
	if (engine->ray.r_y >= 0)
		engine->ray.r_w = 1;
	else
		engine->ray.r_w = 0;
	ray_vertical(engine);
}

void			ray_vertical(t_engine *engine)
{
	double	x;
	double	y;

	x = floor(engine->player.position_x) + engine->ray.r_v;
	y = engine->player.position_y +
	(x - engine->player.position_x) * (engine->ray.r_y / engine->ray.r_x);
	while ((int)floor(y) > 0 && (int)floor(y) < engine->world_map.y)
	{
		if (engine->world_map.grid[(int)floor(y)]
			[(int)(x - 1 + engine->ray.r_v)] == '1')
		{
			engine->ray.h_x = x;
			engine->ray.h_y = y;
			engine->ray.h_d = hypot(x - engine->player.position_x,
				y - engine->player.position_y);
			ray_horizontal(engine);
			return ;
		}
		x += (2 * engine->ray.r_v - 1);
		y += (2 * engine->ray.r_v - 1) * engine->ray.r_y / engine->ray.r_x;
	}
	engine->ray.h_x = engine->player.position_x;
	engine->ray.h_y = engine->player.position_y;
	engine->ray.h_d = 1000000000;
	ray_horizontal(engine);
}

void			ray_horizontal(t_engine *engine)
{
	double	y;
	double	x;

	y = floor(engine->player.position_y) + engine->ray.r_w;
	x = engine->player.position_x +
	(y - engine->player.position_y) * (engine->ray.r_x / engine->ray.r_y);
	while ((int)floor(x) > 0 && (int)floor(x) < engine->world_map.x)
	{
		if (engine->world_map.grid[(int)(y - 1 +
			engine->ray.r_w)][(int)floor(x)] == '1')
		{
			if (engine->ray.h_d > hypot(x - engine->player.position_x,
				y - engine->player.position_y))
			{
				engine->ray.h_x = x;
				engine->ray.h_y = y;
				engine->ray.h_d = hypot(x - engine->player.position_x,
					y - engine->player.position_y);
			}
			return ;
		}
		y += (2 * engine->ray.r_w - 1);
		x += (2 * engine->ray.r_w - 1) * engine->ray.r_x / engine->ray.r_y;
	}
}

unsigned int	ray_pixel(t_engine *engine, double i)
{
	int	index;

	if (floor(engine->ray.h_y) == engine->ray.h_y)
	{
		index = 64 * floor(64 * i) + 64 *
		(engine->ray.h_x - floor(engine->ray.h_x));
		if (engine->ray.r_w == 1)
			return (engine->textures.sud.adr[index]);
		else if (engine->ray.r_w == 0)
			return (engine->textures.nord.adr[index]);
	}
	else if (floor(engine->ray.h_x) == engine->ray.h_x)
	{
		index = 64 * floor(64 * i) + 64 *
		(engine->ray.h_y - floor(engine->ray.h_y));
		if (engine->ray.r_v == 1)
			return (engine->textures.est.adr[index]);
		else if (engine->ray.r_v == 0)
			return (engine->textures.west.adr[index]);
	}
	return (0);
}
