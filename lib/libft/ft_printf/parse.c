/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/12 23:06:53 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_list_zero(t_conv *list, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		list[i].signs = '0';
		list[i].fill = 0;
		list[i].width = 0;
		list[i].prec_is_on = 'n';
		list[i].prec = 0;
		list[i].type = '\0';
		list[i].size = 0;
		i++;
	}
}

int		len_arg(char *str)
{
	int i;
	int nb_var;

	i = 0;
	nb_var = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == '%') && (str[i + 1] != '%'))
			nb_var++;
		else if ((str[i] == '%') && (str[i + 1] == '%'))
		{
			nb_var++;
			i++;
		}
		i++;
	}
	return (nb_var);
}

void	parse_input(char *str, t_conv *list)
{
	t_parse_buf p_buff;

	p_buff.index = 0;
	p_buff.arg_index = -1;
	p_buff.str_buffer = NULL;
	p_buff.list_conv = ft_strdup("cspdiuxX%");
	p_buff.buffer = 1;
	while (str[p_buff.index] != 0)
	{
		if (str[p_buff.index] == '%')
		{
			p_buff.arg_index++;
			next_step_parse(str, list, &p_buff);
			next_step2_parse(str, list, &p_buff);
			next_step3_parse(str, list, &p_buff);
			while (str[p_buff.index] == ' ')
				p_buff.index++;
			if (ft_strchr(p_buff.list_conv, str[p_buff.index]))
				list[p_buff.arg_index].type = str[p_buff.index];
		}
		p_buff.index++;
	}
	free(p_buff.list_conv);
}
