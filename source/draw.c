/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:42:27 by fassani           #+#    #+#             */
/*   Updated: 2020/08/09 21:25:07 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void			draw(t_engine *engine, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	start = engine->win.width * (engine->win.height - size) / 2;
	if (size > engine->win.height)
		count = (size - engine->win.height) / 2;
	else
		count = 0;
	color = engine->textures.sky_color;
	while (engine->ray.r_i < engine->win.width * engine->win.height)
	{
		if (engine->ray.r_i >= start && count < size)
		{
			color = ray_pixel(engine, (double)count / size);
			count++;
		}
		else if (count == size)
			color = engine->textures.floor_color;
		engine->image.adr[engine->ray.r_i] =
		mlx_get_color_value(engine->ptr, color);
		engine->ray.r_i += engine->win.width;
	}
	engine->ray.r_i -= engine->win.width * engine->win.height;
}

int				fisheye_correction(t_engine *engine)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)engine->ray.r_i / (engine->win.width / 2) - 1);
	fisheye *= 29 * M_PI / 180;
	correc = (double)engine->ray.h_d * cos(fisheye);
	return (round(engine->win.height / correc));
}

void			store(t_engine *engine)
{
	engine->ray.str[engine->ray.r_i].x = engine->ray.r_x;
	engine->ray.str[engine->ray.r_i].y = engine->ray.r_y;
	engine->ray.str[engine->ray.r_i].d = engine->ray.h_d;
}
