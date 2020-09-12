/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 21:14:09 by fassani           #+#    #+#             */
/*   Updated: 2020/09/12 17:45:30 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapvalidator.h"
#include "../libft/includes/ft_printf.h"

int	main(void)
{
	char	**tab;
	int		map_max_x;
	int		map_max_y;

	tab = 0;
	map_max_x = 0;
	map_max_y = 0;
	if (!(tab = mapvalidator("map.cub", tab, &map_max_x, &map_max_y)))
		return (0);
	show_map(tab, map_max_y);
	ft_printf("map x:[%i] y:[%i] \n", map_max_x, map_max_y);
	if (tab != 0)
		free_map(tab, map_max_y);
	return (0);
}
