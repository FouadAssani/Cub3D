/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 19:19:15 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:27:53 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	draw_step4(t_engine *engine, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = engine->win.width * (engine->win.height - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < engine->win.width)
		{
			buffer[0] = (unsigned char)(engine->image.adr[i] % 256);
			buffer[1] = (unsigned char)(engine->image.adr[i] / 256 % 256);
			buffer[2] = (unsigned char)(engine->image.adr[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * engine->win.width;
	}
}

void	draw_step3(t_engine *engine, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = engine->win.width;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = engine->win.height;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	draw_step2(t_engine *engine, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = engine->win.width * engine->win.height * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int		draw_step1(t_engine *engine)
{
	engine->image.ptr = mlx_new_image(engine->ptr,
		engine->win.width, engine->win.height);
	engine->image.adr = (unsigned int *)mlx_get_data_addr(engine->image.ptr,
		&engine->image.bpp, &engine->image.size_l, &engine->image.endian);
	reset_ray(engine);
	if (!(engine->ray.str = malloc(sizeof(t_ray_storage) * engine->win.width)))
		return (0);
	while (engine->ray.r_i < engine->win.width)
	{
		ray(engine);
		store(engine);
		draw(engine, fisheye_correction(engine));
		engine->ray.r_i++;
	}
	draw_items(engine);
	return (1);
}

void	save_image(int fd, char *path)
{
	int			fd2;
	t_engine	engine;

	init_engine(&engine);
	if (!load_word_map(&engine, path))
		return ;
	if (readconfig(fd, &engine, 0, 1))
	{
		fd2 = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		if (!draw_step1(&engine))
		{
			pt("Error : malloc error\n");
			return ;
		}
		draw_step2(&engine, fd2);
		draw_step3(&engine, fd2);
		draw_step4(&engine, fd2);
		close(fd2);
		free_memory(&engine);
	}
	if (engine.ptr != 0)
		free(engine.ptr);
}
