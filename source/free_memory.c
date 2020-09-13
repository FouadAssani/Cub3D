/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 13:57:52 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:32:34 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	free_textures(t_engine *engine)
{
	if (engine->textures.nord.adr != 0)
		mlx_destroy_image(engine->ptr, engine->textures.nord.ptr);
	if (engine->textures.sud.adr != 0)
		mlx_destroy_image(engine->ptr, engine->textures.sud.ptr);
	if (engine->textures.est.adr != 0)
		mlx_destroy_image(engine->ptr, engine->textures.est.ptr);
	if (engine->textures.west.adr != 0)
		mlx_destroy_image(engine->ptr, engine->textures.west.ptr);
	if (engine->textures.item.adr != 0)
		mlx_destroy_image(engine->ptr, engine->textures.item.ptr);
}

void	free_memory(t_engine *engine)
{
	int i;

	i = 0;
	free_textures(engine);
	if (engine->image.ptr != 0)
		mlx_destroy_image(engine->ptr, engine->image.ptr);
	if (engine->items != 0)
		free(engine->items);
	free_map(engine->world_map.grid, engine->world_map.y);
}
