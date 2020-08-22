/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:58:03 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:59 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_minus(int ascii_code)
{
	if ((ascii_code >= 97) && (ascii_code <= 122))
		return (1);
	else
		return (0);
}

int			ft_toupper(int c)
{
	if (check_minus(c) == 1)
		c = c - 32;
	return (c);
}
