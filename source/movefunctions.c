/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/09 21:19:56 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	move_up_down(t_engine *engine, char dir)
{
	engine->player.position_x += dir *
	(engine->player.direction_x * SPEED / 101);
	if (engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] == '1')
		engine->player.position_x -= dir *
	(engine->player.direction_x * SPEED / 101);
	engine->player.position_y += dir *
	(engine->player.direction_y * SPEED / 101);
	if (engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] == '1')
		engine->player.position_y -= dir *
	(engine->player.direction_y * SPEED / 101);
	if (engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] == '2')
	{
		engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] = '0';
		engine->world_map.item_len--;
	}
}

void	move_left_right(t_engine *engine, char dir)
{
	engine->player.position_x -= dir *
	(engine->player.direction_y * SPEED / 101);
	if (engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] == '1')
		engine->player.position_x += dir *
	(engine->player.direction_y * SPEED / 101);
	engine->player.position_y += dir *
	(engine->player.direction_x * SPEED / 101);
	if (engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] == '1')
		engine->player.position_y -= dir *
	(engine->player.direction_x * SPEED / 101);
	if (engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] == '2')
	{
		engine->world_map.grid[(int)floor(engine->player.position_y)]
		[(int)floor(engine->player.position_x)] = '0';
		engine->world_map.item_len--;
	}
}

void	turn_left_right(t_engine *engine, char dir)
{
	double	dist;

	engine->player.direction_x = engine->player.direction_x
	* cos(dir * TURN) - engine->player.direction_y * sin(dir * TURN);
	engine->player.direction_y = engine->player.direction_y
	* cos(dir * TURN) + engine->player.direction_x * sin(dir * TURN);
	dist = hypot(engine->player.direction_x, engine->player.direction_y);
	engine->player.direction_x /= dist;
	engine->player.direction_y /= dist;
}
