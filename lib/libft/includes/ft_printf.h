/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 13:47:30 by fouadassani       #+#    #+#             */
/*   Updated: 2020/08/02 11:16:43 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "libft.h"

typedef struct	s_conversion
{
	char	signs;
	int		fill;
	int		width;
	char	prec_is_on;
	int		prec;
	char	type;
	int		size;
}				t_conv;

typedef struct	s_save
{
	char	*buff;
	int		prec_buff;
	size_t	len;
}				t_save;

typedef struct	s_array_buf
{
	int		index;
	int		list_index;
	size_t	len;
	char	*list_conv;
}				t_array_buf;

typedef struct	s_parse_buf
{
	int		index;
	int		arg_index;
	int		buffer;
	char	*str_buffer;
	char	*list_conv;
}				t_parse_buf;

int				ft_intlen (int value);
int				len_arg(char *str);
size_t			show_width(char fill, int width);
size_t			calcul_width_string(int width, int len);
void			ft_rev_char_tab(char *tab, int size);
size_t			calcul_prec(int len, int precision);
int				calcul_and_show_int_prec(t_conv a, int is_neg);
size_t			show_i(t_conv a, long int integer);
void			next_step9_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step8_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step7_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step6_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step5_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step4_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step3_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step2_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
void			next_step_i(t_conv *a, long int integer,
	size_t *len, int is_neg);
size_t			show_u(t_conv a, unsigned int integer);
int				ft_unsigned_intlen(unsigned int value);
void			next_step3_u(t_conv *a, unsigned int integer,
	int prec, size_t *len);
void			next_step2_u(t_conv *a, unsigned int integer,
	int prec, size_t *len);
void			next_step2bis_u(t_conv *a, unsigned int integer,
	int prec, size_t *len);
void			next_step_u(t_conv *a, unsigned int integer,
	int prec, size_t *len);
size_t			show_s(t_conv a, char *str);
size_t			show_c(t_conv array, int integer);
size_t			show_x(t_conv a, unsigned int integer, int maj);
void			next_step4_x(t_conv *a, t_save *v, unsigned int integer);
void			next_step3_x(t_conv *a, t_save *v, unsigned int integer);
void			next_step2bis2_x(t_conv *a, t_save *v);
void			next_step2bis_x(t_conv *a, t_save *v);
void			next_step2_x(t_conv *a, t_save *v, unsigned int integer);
void			next_step_x(t_conv *a, t_save *v, unsigned int integer);
size_t			show_p(t_conv a, unsigned long integer);
void			next_step_p(t_conv *a, unsigned long integer,
	char *buffer, size_t *len);
void			set_list_zero(t_conv *list, int len);
size_t			read_array(const char *str, va_list arg, t_conv *list);
void			ft_putunsignednbr_fd(unsigned int n, int fd);
char			*usignednbr_tobase(unsigned long nbr, char *base);
char			*usignednbr_tobase_reverse(unsigned long nbr, char *base);
void			parse_input(char *str, t_conv *list);
void			next_step3_parse(char *str, t_conv *list, t_parse_buf *p_buff);
void			next_step2_parse(char *str, t_conv *list, t_parse_buf *p_buff);
void			next_step_parse(char *str, t_conv *list, t_parse_buf *p_buff);
int				ft_printf(const char *str, ...);

#endif
