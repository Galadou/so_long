/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_a_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:42:12 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/21 18:49:19 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	verif_map_next1(char *map_ber, t_coord *co)
{
	int	error;

	error = 0;
	if (is_dotber(map_ber) == 0)
	{
		ft_printf("Error\nThe map is not in format '.ber'");
		return (0);
	}
	if (verif_rectangle(map_ber, &co->l, &co->c, error) == 0)
	{
		ft_printf("Error\nThe map is not a rectangle");
		return (0);
	}
	if (verif_rectangle(map_ber, &co->l, &co->c, error) == 2)
	{
		ft_printf("Error\nFiles does not exist or is empty");
		return (0);
	}
	co->c = co->c -1;
	return (1);
}

static int	verif_map_next2(t_coord *co, char **tab_dup, int i)
{
	if (verif_one_and_zero(tab_dup, co->l, co->c, &co->nb_obj_in) == 0)
	{
		ft_printf("Error\nMap is not in correct format");
		i = 0;
		while (tab_dup[i])
		{
			free(tab_dup[i]);
			i++;
		}
		free(tab_dup);
		return (0);
	}
	if (verif_player_can_exit(tab_dup, co->nb_obj_in) == 0)
	{
		ft_printf("Error\nExit or loot are not reachable for the player");
		i = 0;
		while (tab_dup[i])
		{
			free(tab_dup[i]);
			i++;
		}
		free(tab_dup);
		return (0);
	}
	return (1);
}

int	verif_map(char *map_ber, t_coord *co)
{
	char	**tab_dup;
	int		i;

	co->l = 0;
	co->c = 0;
	co->nb_obj_in = 0;
	i = 0;
	if (verif_map_next1(map_ber, co) == 0)
		return (0);
	tab_dup = tab_creator(map_ber, co->l, co->c);
	if (!tab_dup)
	{
		ft_printf("Error\nMalloc Failed at 'tab_creator' for tab_dup");
		return (0);
	}
	if (verif_map_next2(co, tab_dup, i) == 0)
		return (0);
	i = 0;
	while (tab_dup[i])
	{
		free(tab_dup[i]);
		i++;
	}
	free(tab_dup);
	return (1);
}
