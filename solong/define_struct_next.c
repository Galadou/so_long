/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_struct_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:02:50 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 07:07:54 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	define_player_look(t_coord *coordinates)
{
	coordinates->player_look.up = 0;
	coordinates->player_look.down = 0;
	coordinates->player_look.left = 0;
	coordinates->player_look.right = 0;
}

void	define_coilhead_go(t_coord *coordinates)
{
	coordinates->coilhead.go_up = 0;
	coordinates->coilhead.go_left = 0;
	coordinates->coilhead.go_down = 0;
	coordinates->coilhead.go_right = 0;
}

static void	define_count_next(t_coord *coordinates)
{
	coordinates->mid_second = 0;
	coordinates->player_dead = 0;
	coordinates->nb_moove = 0;
	coordinates->string_count_move = 0;
	coordinates->string_nb_obj_in = 0;
	coordinates->string_bearkorgeister = 0;
	coordinates->nb_head = 0;
	coordinates->monster_show = 1;
}

void	define_count(t_coord *coordinates)
{
	coordinates->nb_obj_take = 0;
	coordinates->light = 0;
	coordinates->bearkorgeister = 0;
	coordinates->door_look_far = 0;
	coordinates->exit_here = 0;
	coordinates->nb_beer_cub_take = 0;
	coordinates->nb_beer_cub = 0;
	coordinates->nb_find_obj = 0;
	coordinates->coilhead.y = 0;
	coordinates->coilhead.x = 0;
	coordinates->coilhead.see_coilhead = 0;
	coordinates->coilhead.far_p_y = 0;
	coordinates->coilhead.far_p_x = 0;
	coordinates->coilhead.far_p_y_buf = 0;
	coordinates->coilhead.far_p_x_buf = 0;
	coordinates->coilhead.has_moove = 0;
	coordinates->coilhead.frame = 0;
	coordinates->coilhead.can_moove = 0;
	coordinates->one_time = 0;
	coordinates->m_speed = 0;
	coordinates->m_find_speed = 0;
	coordinates->exit_get_out = 0;
	coordinates->times_count = 0;
	coordinates->time_bonus = 0;
	define_count_next(coordinates);
}
