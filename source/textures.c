/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:14:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:30:19 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void		load_texture(t_engine *e, t_image *img, char *file)
{
	int		fd;
	int		tab[5];

	if (!is_extention(file, ".xpm"))
	{
		pt("Error : config file bad extention\n");
		return ;
	}
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		pt("Error : impossible d'ouvrir le fichier config\n");
		return ;
	}
	close(fd);
	img->ptr = mlx_xpm_file_to_image(e->ptr, file, &tab[0], &tab[1]);
	if (img->ptr == 0 || tab[0] != 64 || tab[1] != 64)
		return ;
	img->adr = (unsigned int *)mlx_get_data_addr(img->ptr,
		&tab[2], &tab[3], &tab[4]);
}

void		parse_texture_line(t_engine *e, t_image *img, char *l, int *i)
{
	char	*file;
	int		j;

	if (img->ptr != 0)
	{
		e->textures.error = 1;
		return ;
	}
	(*i) += 2;
	clean_spaces(l, i);
	j = *i;
	while (l[*i] != ' ' && l[*i] != 0)
		(*i)++;
	if (!(file = malloc(sizeof(char) * (*i - j + 1))))
	{
		e->error = 1;
		return ;
	}
	*i = j;
	j = 0;
	while (l[*i] != ' ' && l[*i] != 0)
		file[j++] = l[(*i)++];
	file[j] = 0;
	load_texture(e, img, file);
	free(file);
}

void		parse_color_line(unsigned int *color, char *l, int *i, int *error)
{
	int	r;
	int	g;
	int	b;

	if (*color != 0)
	{
		*error = 2;
		return ;
	}
	(*i)++;
	r = parse_num(l, i);
	(*i)++;
	g = parse_num(l, i);
	(*i)++;
	b = parse_num(l, i);
	clean_spaces(l, i);
	if (l[*i] != 0 || r > 255 || g > 255 || b > 255)
		return ;
	*color = r * 256 * 256 + g * 256 + b;
}
