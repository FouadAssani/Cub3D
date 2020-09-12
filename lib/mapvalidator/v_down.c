/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_down.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:16:56 by fassani           #+#    #+#             */
/*   Updated: 2020/09/11 22:00:08 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	v_down_verif_x(char **tab, int x, int y, int max_y)
{
	while (tab[y][x] != 0)
	{
		if (tab[y][x] == 'x')
			y++;
		else if (tab[y][x] == '1')
			return (1);
		else
			return (0);
	}
	return (1);
}

int	v_down_verif_exclude(char **tab, int x, int y, int max_y)
{
	while (tab[y][x] != 0)
	{
		y++;
		if (y == max_y - 1 && tab[y][x] == '1')
			return (1);
		else if (tab[y][x] == '1' && tab[y + 1][x] == 'x')
			return (1);
		else if (tab[y][x] == 'x')
			return (0);
	}
	return (0);
}

int	v_down(char **tab, int x, int y, int max_y)
{
	if (tab[y][x] == 'x')
		return (v_down_verif_x(tab, x, y, max_y));
	else if (tab[y][x] == '1')
		return (1);
	else if (tab[y][x] != 'x' && tab[y][x] != '1')
		return (v_down_verif_exclude(tab, x, y, max_y));
	return (0);
}
