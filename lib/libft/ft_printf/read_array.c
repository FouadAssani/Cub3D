/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/12 22:02:53 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	next_step2(va_list arg, t_conv *list, t_array_buf *a_buf)
{
	if (list[a_buf->list_index].type == 'c')
		a_buf->len += show_c(list[a_buf->list_index],
			va_arg(arg, int));
	else if (list[a_buf->list_index].type == 's')
		a_buf->len += show_s(list[a_buf->list_index],
			va_arg(arg, char *));
	else if (list[a_buf->list_index].type == 'p')
		a_buf->len += show_p(list[a_buf->list_index],
			va_arg(arg, unsigned long));
	else if (list[a_buf->list_index].type == 'i'
		|| list[a_buf->list_index].type == 'd')
		a_buf->len += show_i(list[a_buf->list_index],
			(long int)va_arg(arg, int));
	else if (list[a_buf->list_index].type == 'u')
		a_buf->len += show_u(list[a_buf->list_index],
			va_arg(arg, unsigned int));
	else if (list[a_buf->list_index].type == 'x')
		a_buf->len += show_x(list[a_buf->list_index],
			va_arg(arg, unsigned int), 0);
	else if (list[a_buf->list_index].type == 'X')
		a_buf->len += show_x(list[a_buf->list_index],
			va_arg(arg, unsigned int), 1);
	else if (list[a_buf->list_index].type == '%')
		a_buf->len += show_c(list[a_buf->list_index], '%');
}

void	next_step(const char *str, va_list arg,
	t_conv *list, t_array_buf *a_buf)
{
	a_buf->index++;
	while (!ft_strchr(a_buf->list_conv, str[a_buf->index]))
		a_buf->index++;
	if (list[a_buf->list_index].width < 0)
		list[a_buf->list_index].width = va_arg(arg, int);
	if (list[a_buf->list_index].prec < 0)
		list[a_buf->list_index].prec = va_arg(arg, int);
	next_step2(arg, list, a_buf);
	a_buf->list_index++;
}

size_t	read_array(const char *str, va_list arg, t_conv *list)
{
	t_array_buf a_buf;

	a_buf.list_conv = ft_strdup("cspdiuxX%");
	a_buf.index = 0;
	a_buf.list_index = 0;
	a_buf.len = 0;
	while (str[a_buf.index] != '\0')
	{
		if (str[a_buf.index] == '%')
			next_step(str, arg, list, &a_buf);
		else
		{
			ft_putchar_fd(str[a_buf.index], 1);
			a_buf.len++;
		}
		a_buf.index++;
	}
	va_end(arg);
	free(a_buf.list_conv);
	return (a_buf.len);
}
