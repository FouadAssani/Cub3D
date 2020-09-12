/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvalidator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 21:15:41 by fassani           #+#    #+#             */
/*   Updated: 2020/09/12 17:41:28 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mapvalidator.h"

int		buffering_grid(int fd, char **tab, int *max_x, int *max_y)
{
	if (!buff_map(fd, tab))
	{
		pt("Error: la map n'est pas fermé\n");
		free_map(tab, *max_y);
		return (0);
	}
	if (!fill_map(tab, *max_x, *max_y))
	{
		pt("Error: caractere non autorisé\n");
		free_map(tab, *max_y);
		return (0);
	}
	return (1);
}

char	**readconfig(const char *path, char **tab, int *m_x, int *m_y)
{
	int i;
	int fd;

	i = 0;
	fd = -1;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	get_size_map(fd, m_x, m_y);
	if (!(tab = ft_calloc(*m_y + 1, sizeof(char*))))
		return (0);
	while (i < *m_y + 1)
	{
		if (!(tab[i] = ft_calloc(*m_x + 1, sizeof(char*))))
			return (0);
		i++;
	}
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	if (!buffering_grid(fd, tab, m_x, m_y))
		return (0);
	if (!map_verification(tab, *m_x, *m_y))
		return (0);
	close(fd);
	return (tab);
}

char	**mapvalidator(const char *path, char **tab, int *m_x, int *m_y)
{
	int fd;

	fd = -1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		pt("Error: impossible d'ouvrir le fichier\n");
		free_map(tab, *m_y);
		return (0);
	}
	if (!(tab = readconfig(path, tab, m_x, m_y)))
	{
		pt("Error: map non valide\n");
		free_map(tab, *m_y);
		return (0);
	}
	ready_map(tab, *m_y);
	return (tab);
}
