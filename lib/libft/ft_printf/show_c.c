/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/13 08:28:05 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	next_step_c(t_conv *array)
{
	if (array->fill == 0)
		show_width(' ', (array->width - 1));
	else
		show_width('0', (array->width - 1));
}

size_t	show_c(t_conv array, int integer)
{
	if (array.width < 0)
	{
		array.width = -array.width;
		array.signs = '-';
	}
	array.prec = 1;
	if (array.signs == '0')
	{
		if (integer == '%')
			next_step_c(&array);
		else
			show_width(' ', (array.width - 1));
		ft_putchar_fd(integer, 1);
	}
	else if (array.signs == '-')
	{
		ft_putchar_fd(integer, 1);
		show_width(' ', (array.width - 1));
	}
	if (array.width == 0)
		return (1);
	else
		return (array.width);
}
