/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:57:35 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:31:56 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_maj(int ascii_code)
{
	if ((ascii_code >= 65) && (ascii_code <= 90))
		return (1);
	else
		return (0);
}

int			ft_tolower(int c)
{
	if (check_maj(c) == 1)
		c = c + 32;
	return (c);
}
