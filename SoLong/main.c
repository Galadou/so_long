/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:05:03 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/14 16:38:57 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int is_2_argc(int argc)
{
	if (argc != 2)// bien 2 argument ?
    {
		ft_printf("Error\nPlease just enter the map's files");
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int i;
	t_coordinates coordinates;

	coordinates.l = 0;
	coordinates.c = 0;
	if (is_2_argc(argc) == 0)
		return (0);
	if (verif_map(argv[1], &coordinates.l, &coordinates.c, &coordinates) == 0) // map valid ?
	    return (0);
	define_tab(&coordinates, argv);

	tab_transform_for_tiles(coordinates.tab.tab_tiles);
	tab_transform_for_exit(coordinates.tab.tab_0_1);

	/*int j;
	i = 0;
	 while (coordinates.tab.tab_dup[i])
    {
        j = 0;
        while (coordinates.tab.tab_dup[i][j])
        {
           ft_printf("%c", coordinates.tab.tab_dup[i][j]);
           j++;
        }
        ft_printf("\n");
        i++;
    }
	ft_printf("\n");*/
	/*i = 0;
	 while (coordinates.tab.tab_tiles[i])
    {
        j = 0;
        while (coordinates.tab.tab_tiles[i][j])
        {
           ft_printf("%c", coordinates.tab.tab_tiles[i][j]);
           j++;
        }
        ft_printf("\n");
        i++;
    }*/

	//a enlever ;
	window_view_and_game(coordinates);

   /* i = 0;
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


	if (coordinates.tab.tab_0_1)
	{
		i = 0;
   		while (coordinates.tab.tab_0_1[i])
		{
    	    free(coordinates.tab.tab_0_1[i]);
			i++;
		}
   		free(coordinates.tab.tab_0_1);
	}

	if (coordinates.tab.tab_tiles)
	{
		i = 0;
   		while (coordinates.tab.tab_tiles[i])
		{
    	    free(coordinates.tab.tab_tiles[i]);
			i++;
		}
   		free(coordinates.tab.tab_tiles);
	}
	return (0);
}
