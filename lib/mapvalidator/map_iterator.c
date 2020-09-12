/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 21:06:24 by fassani           #+#    #+#             */
/*   Updated: 2020/09/12 17:38:25 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mapvalidator.h"

int		fill_map(char **tab, int max_x, int max_y)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < max_y)
	{
		while (x < max_x)
		{
			if (!valide_caractere(tab[y][x]))
				return (0);
			if (tab[y][x] == ' ' || tab[y][x] == 0)
				tab[y][x] = 'x';
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int		buff_map(int fd, char **tab)
{
	char	*ln;
	int		index;
	int		nb_line;
	int		map_begin;

	ln = 0;
	index = 1;
	nb_line = 0;
	map_begin = 0;
	while (index == 1)
	{
		index = get_next_line(fd, &ln);
		if (!line_handler(ln, tab[nb_line], &nb_line, &map_begin))
			return (0);
		free(ln);
	}
	close(fd);
	return (1);
}

void	get_size_map(char fd, int *x, int *y)
{
	char	*ln;
	int		index;
	int		i;

	ln = 0;
	index = 1;
	i = 0;
	while (index == 1)
	{
		index = get_next_line(fd, &ln);
		map_size_handler(ln, &i, x, y);
		i = 0;
		free(ln);
	}
	close(fd);
}

void	ready_map(char **tab, int max_y)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < max_y)
	{
		while (tab[y][x] != 0)
		{
			if (tab[y][x] == 'x')
				tab[y][x] = '1';
			x++;
		}
		x = 0;
		y++;
	}
}

int		map_verification(char **tab, int max_x, int max_y)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < max_y)
	{
		while (tab[y][x] != 0)
		{
			if (!v_left(tab, x, y) || !v_right(tab, x, y, max_x)
				|| !v_up(tab, x, y) || !v_down(tab, x, y, max_y))
			{
				pt("Error: la map n'est pas fermé\n");
				return (0);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}
