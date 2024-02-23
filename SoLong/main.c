/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:05:03 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 06:59:32 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_2_argc(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\nPlease just enter the map's files");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_coord	c;

	c.l = 0;
	c.c = 0;
	if (is_2_argc(argc) == 0)
		return (0);
	if (verif_map(argv[1], &c) == 0)
		return (0);
	if (define_tab(&c, argv) == 0)
		return (0);
	tab_transform_for_tiles(c.tab.tab_tiles);
	tab_transform_for_exit(c.tab.tab_0_1);
	system("paplay --volume=40000 song/musique.wav &");
	window_view_and_game(&c);
	system("pkill -9 paplay");
	ultimate_free(&c);
	return (0);
}
