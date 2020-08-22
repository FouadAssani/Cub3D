/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsignednbr_tobase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 03:49:12 by fassani           #+#    #+#             */
/*   Updated: 2020/08/02 11:16:25 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rev_char_tab(char *tab, int size)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}

char	*usignednbr_tobase(unsigned long nbr, char *base)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = newline(50)))
		return (0);
	if ((nbr == 0) || (nbr >= (unsigned long)-1))
	{
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	while (nbr != 0)
	{
		str[i] = base[nbr % ft_strlen(base)];
		nbr = nbr / ft_strlen(base);
		i++;
	}
	str[i + 1] = 0;
	return (str);
}

char	*usignednbr_tobase_reverse(unsigned long nbr, char *base)
{
	char *str;

	str = usignednbr_tobase(nbr, base);
	ft_rev_char_tab(str, ft_strlen(str));
	return (str);
}
