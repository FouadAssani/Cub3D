/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:43 by fassani           #+#    #+#             */
/*   Updated: 2019/11/15 06:30:32 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long int n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		return (1 + num_len(n / 10));
	return (1);
}

static void		set_str(char *str, long int n, int len)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	while (i <= len)
	{
		str[len] = (n % 10) + '0';
		n = (n / 10);
		len--;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len_n;

	len_n = num_len(n);
	if (n < 0)
		len_n++;
	if (!(str = ft_calloc(len_n + 1, sizeof(char))))
		return (0);
	set_str(str, n, len_n - 1);
	return (str);
}
