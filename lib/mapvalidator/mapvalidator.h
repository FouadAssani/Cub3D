/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapvalidator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 21:12:34 by fassani           #+#    #+#             */
/*   Updated: 2020/09/12 17:42:34 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPVALIDATOR_H
# define MAPVALIDATOR_H
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

void	m_pt(char *str);
int		m_clean_spaces(char *line, int *i);
int		valide_caractere(char c);
void	show_map(char **tab, int max_y);
void	free_map(char **tab, int y);
int		fill_map(char **tab, int max_x, int max_y);
int		buff_map(int fd, char **tab);
void	get_size_map(char fd, int *x, int *y);
void	ready_map(char **tab, int max_y);
int		map_verification(char **tab, int max_x, int max_y);
int		map_line_handler(char *ln, char	*tab_line,
	int *nb_line, int *map_begin);
void	map_size_handler(char *ln, int *i, int *x, int *y);
int		v_left_verif_x(char **tab, int x, int y);
int		v_left_verif_exclude(char **tab, int x, int y);
int		v_left(char	**tab, int x, int y);
int		v_right_verif_x(char **tab, int x, int y, int max_x);
int		v_right_verif_exclude(char **tab, int x, int y, int max_x);
int		v_right(char **tab, int x, int y, int max_x);
int		v_up_verif_x(char **tab, int x, int y);
int		v_up_verif_exclude(char **tab, int x, int y);
int		v_up(char **tab, int x, int y);
int		v_down_verif_x(char	**tab, int x, int y, int max_y);
int		v_down_verif_exclude(char **tab, int x, int y, int max_y);
int		v_down(char **tab, int x, int y, int max_y);
char	**map_readconfig(const char *path, char **tab, int *m_x, int *m_y);
char	**mapvalidator(const char *path, char **tab, int *m_x, int *m_y);

#endif
