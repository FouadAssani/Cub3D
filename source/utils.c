/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:33:50 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int			clean_spaces(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int			parse_num(char *line, int *i)
{
	int	num;

	num = 0;
	clean_spaces(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		num = num * 10 + (line[*i] - 48);
		(*i)++;
	}
	return (num);
}

void		set_resolution_screen(t_engine *engine, char *line, int *i)
{
	if (engine->win.width != 0 || engine->win.height != 0)
	{
		engine->win.error = 1;
		return ;
	}
	(*i)++;
	engine->win.width = parse_num(line, i);
	engine->win.height = parse_num(line, i);
	if (engine->win.width > engine->win.max_width)
		engine->win.width = engine->win.max_width;
	if (engine->win.height > engine->win.max_height)
		engine->win.height = engine->win.max_height;
	clean_spaces(line, i);
	if (engine->win.width <= 0 || engine->win.height <= 0 || line[*i] != 0)
	{
		engine->win.error = 2;
		return ;
	}
}

int			pt(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
