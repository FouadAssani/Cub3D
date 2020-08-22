/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:37:06 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:45:40 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include "../lib/minilibx_linux/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "../lib/libft/includes/get_next_line.h"
# define SPEED 9
# define TURN 0.04
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define S 115
# define A 97
# define D 100

typedef struct		s_image
{
	void			*ptr;
	unsigned int	*adr;
	int				bpp;
	int				endian;
	int				size_l;
	int				width;
	int				height;
}					t_image;

typedef struct		s_window
{
	void			*ptr;
	int				width;
	int				height;
	int				max_width;
	int				max_height;
	int				error;
}					t_window;

typedef struct		s_textures
{
	t_image			nord;
	t_image			sud;
	t_image			est;
	t_image			west;
	t_image			item;
	unsigned int	sky_color;
	unsigned int	floor_color;
	int				error;
}					t_textures;

typedef struct		s_world_map
{
	char			**grid;
	int				x;
	int				y;
	int				item_len;
	int				error;
}					t_world_map;

typedef struct		s_player
{
	double			position_x;
	double			position_y;
	double			direction_x;
	double			direction_y;
	double			direction_a;
	int				error;
}					t_player;

typedef struct		s_ray_storage
{
	double			x;
	double			y;
	double			d;
}					t_ray_storage;

typedef struct		s_ray
{
	double			r_x;
	double			r_y;
	int				r_i;
	double			r_v;
	double			r_w;
	double			h_x;
	double			h_y;
	double			h_d;
	t_ray_storage	*str;
}					t_ray;

typedef struct		s_keys
{
	char			l;
	char			r;
	char			w;
	char			s;
	char			a;
	char			d;
}					t_keys;

typedef struct		s_engine
{
	void			*ptr;
	t_window		win;
	t_image			image;
	t_world_map		world_map;
	t_textures		textures;
	t_player		player;
	t_ray			ray;
	t_keys			keys;
	t_ray_storage	*items;
	int				error;
}					t_engine;

void				draw_step4(t_engine *engine, int fd);
void				draw_step3(t_engine *engine, int fd);
void				draw_step2(t_engine *engine, int fd);
int					draw_step1(t_engine *engine);
void				save_image(int fd);
void				draw(t_engine *engine, int size);
int					fisheye_correction(t_engine *engine);
void				store(t_engine *engine);
int					exit_game(t_engine *engine);
int					start_game(t_engine *engine);
int					game(int fd);
void				free_memory(t_engine *engine);
void				free_textures(t_engine *engine);
void				init_world(t_engine *engine);
void				init_screen(t_engine *engine);
void				init_keys(t_engine *engine);
int					init_engine(t_engine *engine);
unsigned int		item_pixel(t_engine *engine, int i, unsigned int col);
void				item_draw(t_engine *engine, int loc, double d);
void				spot_item(t_engine *engine, double x, double y, double d);
void				item_action(t_engine *engine);
void				draw_items(t_engine *en);
int					keys_handler(t_engine *engine);
void				set_key(t_engine *engine, int key, char state);
int					on_pressed_event(int key, t_engine *engine);
int					on_released_event(int key, t_engine *engine);
void				test_save_option(int argc, char const *argv[], int fd);
int					main(int argc, char const *argv[]);
int					get_size_map_line(t_engine *engine, char *line);
char				*parse_map_line(t_engine *e, char *l, int *i, int j);
void				map(t_engine *engine, char *line, int *i);
void				move_up_down(t_engine *engine, char dir);
void				move_left_right(t_engine *engine, char dir);
void				turn_left_right(t_engine *engine, char dir);
void				reset_ray(t_engine *engine);
void				printscreen(t_engine *engine);
void				ray(t_engine *engine);
void				ray_direction(t_engine *engine);
void				ray_vertical(t_engine *engine);
void				ray_horizontal(t_engine *engine);
unsigned int		ray_pixel(t_engine *engine, double i);
int					line_handler(t_engine *e, char *ln, int *i);
int					ping_items(t_engine *e);
void				is_invalide_line(char *ln, int *error, int *i);
int					valide_config_line(t_engine *e,
	char *ln, int index, int nb_l);
int					readconfig(int fd, t_engine *engine,
	int nb_ligne, int index);
void				load_texture(t_engine *e, t_image *img, char *file);
void				parse_texture_line(t_engine *e,
	t_image *img, char *l, int *i);
void				parse_color_line(unsigned int *color,
	char *l, int *i, int *error);
int					clean_spaces(char *line, int *i);
int					parse_num(char *line, int *i);
void				set_resolution_screen(t_engine *engine, char *line, int *i);
int					pt(char *str);
int					is_extention(char *path, char *extention);
int					mapvalidation(t_engine *engine);
int					verification_config(t_engine *e);
void				view_spawn(t_engine *engine);

#endif
