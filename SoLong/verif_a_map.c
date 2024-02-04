/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_a_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:42:12 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/02 15:01:38 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int verif_map(char *map_ber, size_t *l, size_t *c)
{
    char **tab_dup;
    int i;
    int C; //nombre d'objet dans la map

    *l = 0;
    *c = 0;
    C = 0;
    
    
        
    if (is_dotber(map_ber) == 0)//est ce aue c'est un .ber
	{
		ft_printf("Error\nThe map is not in format '.ber'");
		return (0);
	}
    
    if (verif_rectangle(map_ber, l, c) == 0) //est ce aue c'est un rectangle et recup la longueur et hauteur
    {
        ft_printf("Error\nThe map is not a rectangle");
        return (0);
    }
    if (verif_rectangle(map_ber, l, c) == 2) //est ce aue c'est un rectangle et recup la longueur et hauteur
    {
        ft_printf("Error\nFiles does not exist or is empty");
        return (0);
    }
    *c = *c -1;
    tab_dup = tab_creator(map_ber, *l, *c);
    if (!tab_dup)
    {
        ft_printf("Error\nMalloc Failed at 'tab_creator' for tab_dup");
        return (0);
    }

    if (verif_one_and_zero(tab_dup, *l, *c, &C) == 0) // on verifie si y'a bien que des 0, 1 etc en fonction de la consigne
    {
        ft_printf("Error\nMap does not only contain “0”, “1”, “E”, “P” or “C” and need to be closed only by '1'.");
        i = 0;
        while (tab_dup[i])
        {
            free(tab_dup[i]);
            i++;
        }
        free(tab_dup);
        return (0);
    }

    if (verif_player_can_exit(tab_dup, C) == 0)
    {
        ft_printf("Error\nExit or loot are not reachable for the player");
        i = 0;
        while (tab_dup[i])
        {
            free(tab_dup[i]);
            i++;
        }
        free(tab_dup);
        return(0);
    }
   /* int j;
    i = 0;
    while (tab[i])
    {
        j = 0;
        while (tab[i][j])
        {
           ft_printf("%c", tab[i][j]);
           j++;
        }
        ft_printf("\n");
        i++;
    }*/
    i = 0;
    while (tab_dup[i])
    {
        free(tab_dup[i]);
        i++;
    }
    free(tab_dup);
    return (1);
}
