/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/07/09 10:09:45 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	if (n < 0)
	{
		if (n == 0)
			ft_putstr_fd("0", fd);
		else
		{
			n = n * -1;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
	}
	else if (n >= 0 && n <= 9)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}
