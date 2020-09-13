/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 20:57:24 by fassani           #+#    #+#             */
/*   Updated: 2020/09/12 16:36:15 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mapvalidator.h"

void	m_pt(char *str)
{
	ft_putstr_fd(str, 1);
}

int		m_clean_spaces(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

int		valide_caractere(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == '2')
		return (1);
	else if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'W')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == 0)
		return (1);
	return (0);
}

void	show_map(char **tab, int max_y)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < max_y)
	{
		while (tab[y][x] != 0)
		{
			write(1, &tab[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}

void	free_map(char **tab, int y)
{
	int i;

	i = 0;
	if (tab == 0)
		return ;
	while (i <= y)
	{
		if (tab[i] != 0)
			free(tab[i]);
		i++;
	}
	if (tab != 0)
		free(tab);
}
