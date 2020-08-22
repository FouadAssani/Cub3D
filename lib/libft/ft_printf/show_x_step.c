/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_x_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/13 10:56:50 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			next_step4_x(t_conv *a, t_save *v, unsigned int integer)
{
	if (a->prec_is_on == 'y')
		v->len += show_width('0', v->prec_buff);
	if (a->prec == 0 && integer == 0)
	{
		if (a->width != 0)
		{
			show_width(' ', 1);
			v->len += ft_strlen(v->buff);
		}
	}
	else
	{
		ft_putstr_fd(v->buff, 1);
		v->len += ft_strlen(v->buff);
	}
	v->len += show_width(' ', calcul_width_string(a->width - v->prec_buff,
		ft_strlen(v->buff)));
}

void			next_step3_x(t_conv *a, t_save *v, unsigned int integer)
{
	if (a->prec_is_on == 'y')
		v->len += show_width('0', v->prec_buff);
	if (a->prec == 0 && integer == 0)
	{
		if (a->width != 0)
		{
			show_width(' ', 1);
			v->len += ft_strlen(v->buff);
		}
	}
	else
	{
		ft_putstr_fd(v->buff, 1);
		v->len += ft_strlen(v->buff);
	}
}

void			next_step2bis2_x(t_conv *a, t_save *v)
{
	v->len += show_width(' ', calcul_width_string(a->width
		- v->prec_buff, ft_strlen(v->buff)));
}

void			next_step2bis_x(t_conv *a, t_save *v)
{
	if (a->prec_is_on == 'y' && a->prec >= (int)ft_strlen(v->buff))
		v->len += show_width(' ', calcul_width_string(a->width
			- v->prec_buff, ft_strlen(v->buff)));
	else if (a->prec_is_on == 'y' && a->fill == 1
		&& a->prec < (int)ft_strlen(v->buff))
	{
		if (a->prec < 0)
			v->len += show_width('0', calcul_width_string(a->width
				- v->prec_buff, ft_strlen(v->buff)));
		else
			v->len += show_width(' ', calcul_width_string(a->width
				- v->prec_buff, ft_strlen(v->buff)));
	}
	else
		v->len += show_width('0', calcul_width_string(a->width
			- v->prec_buff, ft_strlen(v->buff)));
}

void			next_step2_x(t_conv *a, t_save *v, unsigned int integer)
{
	if (a->fill == 1)
	{
		if ((a->prec == 0 && integer == 0) || (a->prec == 0))
			v->len += show_width(' ', calcul_width_string(a->width
				- v->prec_buff, ft_strlen(v->buff)));
		else
		{
			if (a->prec_is_on == 'y' && a->prec == 1)
				v->len += show_width(' ', calcul_width_string(a->width
					- v->prec_buff, ft_strlen(v->buff)));
			else
				next_step2bis_x(a, v);
		}
	}
	else
		next_step2bis2_x(a, v);
}
