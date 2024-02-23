/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exit_here.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:11:24 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 06:34:09 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	can_i_exit(t_coord *coordinates)
{
	if ((coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 't' || \
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'l' || \
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'r' || \
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'm') &&
	coordinates->nb_obj_take == coordinates->nb_obj_in)
	{
		system("pkill -9 paplay");
		if (coordinates->bearkorgeister == 1)
			system("paplay --volume=75000 song/exit-voice-bonus.wav &");
		else
			system("paplay --volume=75000 song/exit-voice.wav &");
		ft_printf("Vous etes sortie de l'enfer...Pour le moment...");
		coordinates->exit_get_out = 1;
	}
}

void	get_out(t_coord *coordinates)
{
	usleep(5000000);
	mlx_loop_end(coordinates->m);
	destroy_hero(coordinates);
	destroy_object(coordinates);
	destroy_img(coordinates);
	destroy_exit(coordinates);
	destroy_monster(coordinates);
	mlx_destroy_window(coordinates->m, coordinates->w);
	mlx_destroy_display(coordinates->m);
	ultimate_free(coordinates);
	system("pkill -9 paplay");
	exit(0);
}

void	is_exit_here(t_coord *coordinates)
{
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 't' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'l' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'r' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'm')
		coordinates->exit_here = 1;
	else
		coordinates->exit_here = 0;
}
