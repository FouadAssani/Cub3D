/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_i_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/09 10:08:56 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	next_step5_i(t_conv *a, long int integer, size_t *len, int is_neg)
{
	if (a->prec_is_on == 'y')
	{
		if (a->prec >= a->size)
			*len += show_width(' ', a->width - (a->prec + is_neg));
		else
			*len += show_width(' ', a->width - a->size);
		ft_putchar_fd('-', 1);
		*len += calcul_and_show_int_prec(*a, is_neg);
		ft_putnbr_fd(integer, 1);
		*len += a->size;
	}
	else
	{
		*len += show_width(' ', a->width - a->size);
		ft_putchar_fd('-', 1);
		ft_putnbr_fd(integer, 1);
		*len += a->size;
	}
}

void	next_step4_i(t_conv *a, long int integer, size_t *len, int is_neg)
{
	if (a->prec >= a->size)
		*len += show_width(' ', a->width - (a->prec));
	else
	{
		if (a->prec < 0)
			*len += show_width('0', a->width - a->size);
		else
			*len += show_width(' ', a->width - a->size);
	}
	*len += calcul_and_show_int_prec(*a, is_neg);
	if (a->prec == 0 && integer == 0)
	{
		if (a->width != 0)
		{
			show_width(' ', 1);
			*len += a->size;
		}
	}
	else
	{
		ft_putnbr_fd(integer, 1);
		*len += a->size;
	}
}

void	next_step3_i(t_conv *a, long int integer, size_t *len, int is_neg)
{
	if (a->prec_is_on == 'y')
	{
		if (a->prec < 0)
			a->prec = a->width - 1;
		if (a->prec >= a->size)
			*len += show_width(' ', a->width - (a->prec + is_neg));
		else
			*len += show_width(' ', a->width - a->size);
		ft_putchar_fd('-', 1);
		*len += calcul_and_show_int_prec(*a, is_neg);
		ft_putnbr_fd(integer, 1);
		*len += a->size;
	}
	else
	{
		ft_putchar_fd('-', 1);
		*len += show_width('0', a->width - a->size);
		ft_putnbr_fd(integer, 1);
		*len += a->size;
	}
}

void	next_step2_i(t_conv *a, long int integer, size_t *len, int is_neg)
{
	if (is_neg)
		next_step3_i(a, integer, len, is_neg);
	else
	{
		if (a->prec_is_on == 'y')
			next_step4_i(a, integer, len, is_neg);
		else
		{
			*len += show_width('0', a->width - a->size);
			ft_putnbr_fd(integer, 1);
			*len += a->size;
		}
	}
}

void	next_step_i(t_conv *a, long int integer, size_t *len, int is_neg)
{
	if (a->fill)
		next_step2_i(a, integer, len, is_neg);
	else
	{
		if (is_neg)
			next_step5_i(a, integer, len, is_neg);
		else
		{
			if (a->prec_is_on == 'y')
				next_step6_i(a, integer, len, is_neg);
			else
			{
				*len += show_width(' ', a->width - a->size);
				ft_putnbr_fd(integer, 1);
				*len += a->size;
			}
		}
	}
}
