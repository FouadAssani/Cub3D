/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:26:33 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	init_world(t_engine *engine)
{
	engine->world_map.grid = 0;
	engine->world_map.x = 0;
	engine->world_map.y = 0;
	engine->world_map.item_len = 0;
	engine->world_map.error = 0;
	engine->textures.nord.ptr = 0;
	engine->textures.nord.adr = 0;
	engine->textures.sud.ptr = 0;
	engine->textures.sud.adr = 0;
	engine->textures.est.ptr = 0;
	engine->textures.est.adr = 0;
	engine->textures.west.ptr = 0;
	engine->textures.west.adr = 0;
	engine->textures.item.ptr = 0;
	engine->textures.item.adr = 0;
	engine->textures.sky_color = 0;
	engine->textures.floor_color = 0;
	engine->textures.error = 0;
	engine->player.position_x = 0;
	engine->player.position_y = 0;
	engine->player.direction_x = 0;
	engine->player.direction_y = 0;
	engine->player.direction_a = 0;
	engine->player.error = 0;
}

void	init_screen(t_engine *engine)
{
	engine->win.ptr = 0;
	engine->win.width = 0;
	engine->win.height = 0;
	mlx_get_screen_size(engine->ptr,
		&engine->win.max_width, &engine->win.max_height);
	engine->win.error = 0;
	engine->image.ptr = 0;
	engine->image.adr = 0;
	engine->image.bpp = 0;
	engine->image.endian = 0;
	engine->image.size_l = 0;
	engine->image.width = 0;
	engine->image.height = 0;
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

void	init_keys(t_engine *engine)
{
	engine->keys.l = 0;
	engine->keys.r = 0;
	engine->keys.w = 0;
	engine->keys.s = 0;
	engine->keys.a = 0;
	engine->keys.d = 0;
}

int		init_engine(t_engine *engine)
{
	if (!(engine->ptr = mlx_init()))
		return (0);
	init_world(engine);
	init_screen(engine);
	init_keys(engine);
	engine->items = 0;
	engine->error = 0;
	return (0);
}
