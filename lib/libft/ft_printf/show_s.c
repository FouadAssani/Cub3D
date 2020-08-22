/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/09 10:08:36 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	show_width(char fill, int width)
{
	int i;

	i = 0;
	if (width <= 0)
		return (0);
	while (i < width)
	{
		ft_putchar_fd(fill, 1);
		i++;
	}
	return (i);
}

size_t	calcul_width_string(int width, int len)
{
	if (width <= 0)
		return (0);
	if (len > width)
		return (0);
	else
		return (width - len);
}

char	*string_prec(char *str, size_t prec)
{
	size_t len;

	len = ft_strlen(str);
	if (len <= prec)
		return (ft_substr(str, 0, len));
	else
		return (ft_substr(str, 0, prec));
}

void	next_step_s(t_conv *a, char *str, char *buffer, size_t *len)
{
	buffer = string_prec(str, a->prec);
	if (a->signs == '0')
	{
		*len += show_width(' ',
			calcul_width_string(a->width, ft_strlen(buffer)));
		ft_putstr_fd(buffer, 1);
		*len += ft_strlen(buffer);
	}
	else if (a->signs == '-')
	{
		ft_putstr_fd(buffer, 1);
		*len += ft_strlen(buffer);
		*len += show_width(' ',
			calcul_width_string(a->width, ft_strlen(buffer)));
	}
}

size_t	show_s(t_conv a, char *str)
{
	char	*buffer;
	size_t	len;

	len = 0;
	buffer = NULL;
	if (str == 0)
	{
		if (!(str = newline(6 + 1)))
			return (0);
		str = "(null)";
	}
	if (a.width < 0)
	{
		a.width = -a.width;
		a.signs = '-';
	}
	if (a.prec_is_on == 'n')
		a.prec = ft_strlen(str);
	next_step_s(&a, str, buffer, &len);
	free(buffer);
	return (len);
}
