/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_u_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/13 10:28:01 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	next_step3_u(t_conv *a, unsigned int integer, int prec, size_t *len)
{
	if (a->prec_is_on == 'y')
		*len += show_width('0', prec);
	if (a->prec == 0 && integer == 0)
	{
		if (a->width != 0)
		{
			show_width(' ', 1);
			*len += ft_unsigned_intlen(integer);
		}
	}
	else
	{
		ft_putunsignednbr_fd(integer, 1);
		*len += ft_unsigned_intlen(integer);
	}
	*len += show_width(' ', calcul_width_string(a->width
		- prec, ft_unsigned_intlen(integer)));
}

void	next_step2bis_u(t_conv *a, unsigned int integer, int prec, size_t *len)
{
	if (a->prec < 0)
		*len += show_width('0', calcul_width_string(a->width
			- prec, ft_unsigned_intlen(integer)));
	else
		*len += show_width(' ', calcul_width_string(a->width
			- prec, ft_unsigned_intlen(integer)));
}

void	next_step2_u(t_conv *a, unsigned int integer, int prec, size_t *len)
{
	if ((a->prec == 0 && integer == 0) || (a->prec == 0))
		*len += show_width(' ', calcul_width_string(a->width
			- prec, ft_unsigned_intlen(integer)));
	else
	{
		if (a->prec_is_on == 'y' && a->prec == 1)
			*len += show_width(' ', calcul_width_string(a->width
				- prec, ft_unsigned_intlen(integer)));
		else
		{
			if (a->prec_is_on == 'y' && a->prec >= ft_unsigned_intlen(integer))
				*len += show_width(' ', calcul_width_string(a->width
					- prec, ft_unsigned_intlen(integer)));
			else if (a->prec_is_on == 'y' && a->fill == 1
				&& a->prec < ft_unsigned_intlen(integer))
				next_step2bis_u(a, integer, prec, len);
			else
				*len += show_width('0', calcul_width_string(a->width
					- prec, ft_unsigned_intlen(integer)));
		}
	}
}

void	next_step_u(t_conv *a, unsigned int integer, int prec, size_t *len)
{
	if (a->fill == 1)
		next_step2_u(a, integer, prec, len);
	else
		*len += show_width(' ', calcul_width_string(a->width
			- prec, ft_unsigned_intlen(integer)));
	if (a->prec_is_on == 'y')
		*len += show_width('0', prec);
	if (a->prec == 0 && integer == 0)
	{
		if (a->width != 0)
		{
			show_width(' ', 1);
			*len += ft_unsigned_intlen(integer);
		}
	}
	else
	{
		ft_putunsignednbr_fd(integer, 1);
		*len += ft_unsigned_intlen(integer);
	}
}
