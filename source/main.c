/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/09 20:27:20 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	test_save_option(int argc, char const *argv[], int fd)
{
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0)
		{
			pt("Cub3D: illegal option\n");
			pt("usage: Cub3D [Path config file] [--save]\n");
			return ;
		}
		save_image(fd);
	}
	else if (argc > 3)
	{
		pt("Cub3D: illegal option\n");
		pt("usage: Cub3D [Path config file] [--save]\n");
		return ;
	}
	else
		game(fd);
}

int		main(int argc, char const *argv[])
{
	int fd;

	fd = 0;
	if (argc < 2)
	{
		pt("Error: fichier de configuration (*.cub) non défini\n");
		pt("usage: Cub3D [Path config file] [--save]\n");
		return (0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			pt("Error: impossible d'ouvrir le fichier config (*.cub)\n");
		else if (fd > 0)
		{
			if (!is_extention((char*)argv[1], ".cub"))
			{
				pt("Error: mauvaise extension (*.cub)\n");
				return (0);
			}
			test_save_option(argc, argv, fd);
		}
	}
	return (0);
}
