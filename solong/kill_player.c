/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:26:15 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 06:43:13 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	kill_player(t_coord *coordinates)
{
	ft_printf("Game Over : vous etes mort");
	usleep(5000000);
	mlx_loop_end(coordinates->m);
	destroy_hero(coordinates);
	destroy_object(coordinates);
	destroy_img(coordinates);
	destroy_exit(coordinates);
	destroy_monster(coordinates);
	ultimate_free(coordinates);
	system("pkill -9 paplay");
	exit(0);
}
