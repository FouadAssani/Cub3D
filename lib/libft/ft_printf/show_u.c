/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/13 10:29:19 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_intlen(unsigned int value)
{
	int i;

	i = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		i++;
		value /= 10;
	}
	return (i);
}

size_t	show_u(t_conv a, unsigned int integer)
{
	int		prec;
	size_t	len;

	prec = 0;
	len = 0;
	if (a.width < 0)
	{
		a.width = -a.width;
		a.signs = '-';
	}
	if (a.prec_is_on == 'n')
		a.prec = ft_unsigned_intlen(integer);
	prec = calcul_prec(ft_unsigned_intlen(integer), a.prec);
	if (a.signs == '0')
		next_step_u(&a, integer, prec, &len);
	else if (a.signs == '-')
		next_step3_u(&a, integer, prec, &len);
	return (len);
}
