/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_left.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 19:16:56 by fassani           #+#    #+#             */
/*   Updated: 2020/09/12 08:46:44 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	v_left_verif_x(char **tab, int x, int y)
{
	while (x > 0)
	{
		if (tab[y][x] == 'x')
			x--;
		else if (tab[y][x] == '1')
			return (1);
		else
			return (0);
	}
	return (1);
}

int	v_left_verif_exclude(char **tab, int x, int y)
{
	while (x > 0)
	{
		x--;
		if (x == 0 && tab[y][x] == '1')
			return (1);
		else if (tab[y][x] == '1' && tab[y][x - 1] == 'x')
			return (1);
		else if (tab[y][x] == 'x')
			return (0);
	}
	return (0);
}

int	v_left(char **tab, int x, int y)
{
	if (tab[y][x] == 'x')
		return (v_left_verif_x(tab, x, y));
	else if (tab[y][x] == '1')
		return (1);
	else if (tab[y][x] != 'x' && tab[y][x] != '1')
		return (v_left_verif_exclude(tab, x, y));
	return (0);
}
