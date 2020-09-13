/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:33:28 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	exit_game(t_engine *engine)
{
	free_memory(engine);
	if (engine->win.ptr != 0)
		mlx_destroy_window(engine->ptr, engine->win.ptr);
	free(engine->ptr);
	exit(0);
}

int	start_game(t_engine *engine)
{
	if (!(engine->win.ptr = mlx_new_window(engine->ptr, engine->win.width,
		engine->win.height, "Cub3D")))
		return (0);
	engine->image.ptr = mlx_new_image(engine->ptr,
		engine->win.width, engine->win.height);
	engine->image.adr = (unsigned int *)mlx_get_data_addr(engine->image.ptr,
		&engine->image.bpp, &engine->image.size_l, &engine->image.endian);
	mlx_hook(engine->win.ptr, KeyPress, KeyPressMask, on_pressed_event, engine);
	mlx_hook(engine->win.ptr, KeyRelease,
		KeyReleaseMask, on_released_event, engine);
	mlx_hook(engine->win.ptr, ClientMessage,
		StructureNotifyMask, exit_game, engine);
	mlx_loop_hook(engine->ptr, keys_handler, engine);
	mlx_loop(engine->ptr);
	return (0);
}

int	game(int fd, char *path)
{
	t_engine engine;

	init_engine(&engine);
	if (!load_word_map(&engine, path))
		return (0);
	if (readconfig(fd, &engine, 0, 1))
	{
		start_game(&engine);
		exit_game(&engine);
	}
	if (engine.ptr != 0)
		free(engine.ptr);
	return (0);
}
