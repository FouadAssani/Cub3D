/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/09 10:09:02 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_intlen(int value)
{
	int i;

	i = 0;
	if (value < 0)
		i++;
	if (value == 0)
		return (1);
	while (value)
	{
		i++;
		value /= 10;
	}
	return (i);
}

int		is_negative(int integer)
{
	if (integer < 0)
		return (1);
	else
		return (0);
}

int		calcul_and_show_int_prec(t_conv a, int is_neg)
{
	int len_show_prec;

	len_show_prec = 0;
	len_show_prec = (int)calcul_prec(a.size,
		a.prec + is_neg);
	return (show_width('0', len_show_prec));
}

size_t	show_i(t_conv a, long int integer)
{
	size_t	len;
	int		is_neg;

	len = 0;
	is_neg = 0;
	a.size = ft_intlen(integer);
	if (is_negative(integer))
	{
		is_neg = 1;
		integer = -integer;
	}
	if (a.width < 0)
	{
		a.width = -a.width;
		a.signs = '-';
	}
	if (a.signs == '0')
		next_step_i(&a, integer, &len, is_neg);
	else if (a.signs == '-')
		next_step7_i(&a, integer, &len, is_neg);
	return (len);
}
