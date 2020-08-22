/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyshandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/15 17:04:15 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		keys_handler(t_engine *engine)
{
	if (engine->keys.l)
		turn_left_right(engine, -1);
	if (engine->keys.r)
		turn_left_right(engine, 1);
	if (engine->keys.w)
		move_up_down(engine, 1);
	if (engine->keys.s)
		move_up_down(engine, -1);
	if (engine->keys.a)
		move_left_right(engine, -1);
	if (engine->keys.d)
		move_left_right(engine, 1);
	printscreen(engine);
	return (0);
}

void	set_key(t_engine *engine, int key, char state)
{
	if (key == ESC)
		exit_game(engine);
	else if (key == LEFT)
		engine->keys.l = state;
	else if (key == RIGHT)
		engine->keys.r = state;
	else if (key == W)
		engine->keys.w = state;
	else if (key == S)
		engine->keys.s = state;
	else if (key == A)
		engine->keys.a = state;
	else if (key == D)
		engine->keys.d = state;
}

int		on_pressed_event(int key, t_engine *engine)
{
	set_key(engine, key, 1);
	return (1);
}

int		on_released_event(int key, t_engine *engine)
{
	set_key(engine, key, 0);
	return (1);
}
