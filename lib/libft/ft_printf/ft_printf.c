/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/09 10:10:05 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_conv		*list;
	va_list		arg;
	va_list		copy;
	size_t		len;

	len = 0;
	list = NULL;
	if (!(list = malloc(sizeof(t_conv) * len_arg((char*)str))))
		return (0);
	set_list_zero(list, len_arg((char*)str));
	parse_input((char*)str, list);
	va_start(arg, str);
	va_copy(copy, arg);
	va_end(arg);
	len = read_array(str, copy, list);
	free(list);
	return (len);
}
