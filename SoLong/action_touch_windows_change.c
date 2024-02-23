/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_touch_windows_change.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:15:19 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 17:10:48 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	playersee_p1(t_coord *coordinates)
{
	coordinates->coilhead.see_coilhead = 0;
	hide_tiles_light(coordinates);
	put_shadow(coordinates);
	define_player_look(coordinates);
}

void	playersee_p2(t_coord *coord)
{
	destroy_hero(coord);
	def_hero(coord);
	put_asked_hero(coord);
}

void	playermove_p1(t_coord *c)
{
	mlx_put_image_to_window(c->m, c->w, c->t.h, 0, 0);
	mlx_put_image_to_window(c->m, c->w, c->t.h, 64, 0);
	mlx_put_image_to_window(c->m, c->w, c->t.h, 128, 0);
	mlx_put_image_to_window(c->m, c->w, c->t.h, 192, 0);
	c->nb_moove++;
	c->string_count_move = ft_itoa(c->nb_moove);
	mlx_string_put(c->m, c->w, 0, 18, 0xF000F000, "Moove done = ");
	mlx_string_put(c->m, c->w, 115, 18, 0xF000F000, c->string_count_move);
	free(c->string_count_move);
	c->coilhead.see_coilhead = 0;
	mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, c->t_y + c->y * 64);
	hide_tiles_light(c);
	put_shadow(c);
}

void	playermove_p2(t_coord *coord)
{
	take_obj(coord);
	destroy_hero(coord);
	def_hero(coord);
	put_asked_hero(coord);
	coord->string_nb_obj_in = ft_itoa(coord->nb_obj_in - coord->nb_obj_take);
	mlx_string_put(coord->m, coord->w,
		0, 34, 0xF000F000, "Loot remaining = ");
	mlx_string_put(coord->m, coord->w, 140, 34,
		0xF000F000, coord->string_nb_obj_in);
	free(coord->string_nb_obj_in);
	mlx_string_put(coord->m, coord->w,
		0, 50, 0xF000F000, "Bonus loot collected = ");
	coord->string_bearkorgeister = ft_itoa(coord->bearkorgeister);
	mlx_string_put(coord->m, coord->w,
		192, 50, 0xF000F000, coord->string_bearkorgeister);
	free(coord->string_bearkorgeister);
	mlx_string_put(coord->m, coord->w,
		200, 50, 0xF000F000, " / 1");
	can_i_exit(coord);
	m_search_player(coord);
}

void	key_hook_close(int key, t_coord *coordinates)
{
	if (key == 41)
	{
		destroy_hero(coordinates);
		destroy_object(coordinates);
		destroy_img(coordinates);
		destroy_exit(coordinates);
		destroy_monster(coordinates);
		mlx_loop_end(coordinates->m);
	}
}
