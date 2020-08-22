/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/09 10:09:19 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	next_step3_parse(char *str, t_conv *list, t_parse_buf *p_buff)
{
	if (str[p_buff->index] == '.')
	{
		list[p_buff->arg_index].prec_is_on = 'y';
		p_buff->index++;
	}
	if (str[p_buff->index] == '*')
	{
		list[p_buff->arg_index].prec = -1;
		p_buff->index++;
	}
	else if (ft_isdigit(str[p_buff->index]))
	{
		while (ft_isdigit(str[p_buff->index]))
		{
			p_buff->buffer++;
			p_buff->index++;
		}
		p_buff->str_buffer = ft_substr(str, ((p_buff->index + 1)
			- p_buff->buffer), p_buff->buffer);
		list[p_buff->arg_index].prec = ft_atoi(p_buff->str_buffer);
		free(p_buff->str_buffer);
		p_buff->str_buffer = NULL;
		p_buff->buffer = 1;
	}
}

void	next_step2_parse(char *str, t_conv *list, t_parse_buf *p_buff)
{
	if (str[p_buff->index] == '*')
	{
		list[p_buff->arg_index].width = -1;
		p_buff->index++;
	}
	else if (ft_isdigit(str[p_buff->index]))
	{
		while (ft_isdigit(str[p_buff->index]))
		{
			p_buff->buffer++;
			p_buff->index++;
		}
		p_buff->str_buffer = ft_substr(str, ((p_buff->index + 1)
			- p_buff->buffer), p_buff->buffer);
		list[p_buff->arg_index].width = ft_atoi(p_buff->str_buffer);
		free(p_buff->str_buffer);
		p_buff->str_buffer = NULL;
		p_buff->buffer = 1;
	}
}

void	next_step_parse(char *str, t_conv *list, t_parse_buf *p_buff)
{
	if (str[++p_buff->index] == '-')
	{
		while (str[p_buff->index] == '-' || str[p_buff->index] == '0')
			p_buff->index++;
		list[p_buff->arg_index].signs = '-';
	}
	if (str[p_buff->index] == '0')
	{
		while (str[p_buff->index] == '0')
			p_buff->index++;
		list[p_buff->arg_index].fill = 1;
	}
	if (str[p_buff->index] == '-')
	{
		while (str[p_buff->index] == '-' || str[p_buff->index] == '0')
			p_buff->index++;
		list[p_buff->arg_index].signs = '-';
		list[p_buff->arg_index].fill = 0;
	}
}
