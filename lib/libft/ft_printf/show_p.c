/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/12 21:56:18 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	next_step_p(t_conv *a, unsigned long integer, char *buffer, size_t *len)
{
	if (a->signs == '0')
	{
		buffer = usignednbr_tobase_reverse(integer, "0123456789abcdef");
		*len += show_width(' ',
			calcul_width_string(a->width, ft_strlen(buffer)) - 2) + 2;
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(buffer, 1);
		*len += ft_strlen(buffer);
		free(buffer);
	}
	else if (a->signs == '-')
	{
		ft_putstr_fd("0x", 1);
		buffer = usignednbr_tobase_reverse(integer, "0123456789abcdef");
		ft_putstr_fd(buffer, 1);
		*len += ft_strlen(buffer);
		*len += show_width(' ',
			calcul_width_string(a->width, ft_strlen(buffer)) - 2) + 2;
		free(buffer);
	}
}

size_t	show_p(t_conv a, unsigned long integer)
{
	char	*buffer;
	size_t	len;

	len = 0;
	buffer = NULL;
	if (a.width < 0)
	{
		a.width = -a.width;
		a.signs = '-';
	}
	next_step_p(&a, integer, buffer, &len);
	return (len);
}
