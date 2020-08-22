/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassani <fassani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:34:35 by fassani           #+#    #+#             */
/*   Updated: 2020/08/22 14:17:58 by fassani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		is_extention(char *path, char *extention)
{
	int		len_extention;
	int		len_spot;
	char	*spot;
	int		challenge;

	challenge = -1;
	len_extention = ft_strlen(extention);
	spot = ft_strrchr(path, '.');
	len_spot = ft_strlen(spot);
	if (len_spot != len_extention)
		return (0);
	challenge = ft_strncmp(spot, extention, len_extention);
	if (challenge == 0)
		return (1);
	else
		return (0);
}

int		mapvalidation(t_engine *engine)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < engine->world_map.y)
	{
		j = 0;
		while (j < engine->world_map.x)
		{
			if (engine->world_map.grid[i][j] != '1' && i == 0)
				return (0);
			else if (engine->world_map.grid[i][j]
				!= '1' && i == engine->world_map.y - 1)
				return (0);
			else if (engine->world_map.grid[i][j] != '1' && j == 0)
				return (0);
			else if (engine->world_map.grid[i][j]
				!= '1' && j == engine->world_map.x - 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	verification_next(t_engine *e)
{
	if (e->error == 1)
		return (pt("Error : malloc error\n"));
	else if (e->win.error == 1)
		return (pt("Error : Résolution précisée deux fois\n"));
	else if (e->textures.error == 1)
		return (pt("Error : Chemin de texture précisée deux fois\n"));
	else if (e->textures.error == 2)
		return (pt("Error : Sol/plafond précisée deux fois\n"));
	else if (!mapvalidation(e))
		return (pt("Error : La carte n'est pas entourée de murs\n"));
	return (0);
}

int		verification_config(t_engine *e)
{
	if (e->world_map.error == 2)
		return (pt(": Ligne non valide détecté\n"));
	else if (e->win.width <= 0 || e->win.height <= 0)
		return (pt("Error : Aucune résolution spécifiée\n"));
	else if ((e->textures.nord.adr == 0 || e->textures.sud.adr == 0 ||
		e->textures.est.adr == 0) || (e->textures.west.adr == 0 ||
		e->textures.item.adr == 0))
		return (pt("Error : Texture manquante\n"));
	else if (e->textures.sky_color == 0 || e->textures.floor_color == 0)
		return (pt("Error : Couleur manquante du sol/du plafond\n"));
	else if (e->world_map.error == 1)
		return (pt("Error : la carte n'est pas un rectangle\n"));
	else if (e->player.error == 0)
		return (pt("Error : Pas de position de départ\n"));
	else if (e->player.error > 1)
		return (pt("Error : Plusieurs positions de départ\n"));
	return (verification_next(e));
}
