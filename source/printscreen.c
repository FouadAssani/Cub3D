/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printscreen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/09 21:04:08 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	reset_ray(t_engine *engine)
{
	engine->ray.r_x = 0;
	engine->ray.r_y = 0;
	engine->ray.r_i = 0;
	engine->ray.r_v = 0;
	engine->ray.r_w = 0;
	engine->ray.h_x = 0;
	engine->ray.h_y = 0;
	engine->ray.h_d = 0;
	engine->ray.str = 0;
}

void	printscreen(t_engine *engine)
{
	reset_ray(engine);
	if (!(engine->ray.str = malloc(sizeof(t_ray_storage) * engine->win.width)))
		return ;
	while (engine->ray.r_i < engine->win.width)
	{
		ray(engine);
		store(engine);
		draw(engine, fisheye_correction(engine));
		engine->ray.r_i++;
	}
	draw_items(engine);
	mlx_put_image_to_window(engine->ptr, engine->win.ptr,
		engine->image.ptr, 0, 0);
}
