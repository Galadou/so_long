/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_front_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:58:13 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 04:13:16 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	look_up_next(t_coord *co)
{
	if (co->tab.tab_tiles[co->y - 1][co->x] != '1' && co->light == 1)
	{
		co->y--;
		while (co->tab.tab_tiles[co->y][co->x] != '1')
		{
			put_asked_image(co);
			is_obj_here(co);
			is_exit_here(co);
			if (co->exit_here == 1 && co->door_look_far == 0 && \
			co->nb_obj_take == co->nb_obj_in)
				co->door_look_far = 1;
			else
				co->door_look_far = 0;
			put_asked_exit(co);
			is_coilhead_here(co, co->y, co->x);
			co->y--;
		}
	}
	co->door_look_far = 0;
	co->y = co->buffer_y;
}

void	look_left_next(t_coord *co)
{
	if (co->tab.tab_tiles[co->y][co->x - 1] != '1' && co->light == 1)
	{
		co->x--;
		while (co->tab.tab_tiles[co->y][co->x] != '1')
		{
			put_asked_image(co);
			is_obj_here(co);
			is_exit_here(co);
			if (co->exit_here == 1 && co->door_look_far == 0 && \
			co->nb_obj_take == co->nb_obj_in)
				co->door_look_far = 1;
			else
				co->door_look_far = 0;
			put_asked_exit(co);
			is_coilhead_here(co, co->y, co->x);
			co->x--;
		}
	}
	co->door_look_far = 0;
	co->x = co->buffer_x;
}

void	look_down_next(t_coord *co)
{
	if (co->tab.tab_tiles[co->y + 1][co->x] != '1' && co->light == 1)
	{
		co->y++;
		while (co->tab.tab_tiles[co->y][co->x] != '1')
		{
			put_asked_image(co);
			is_obj_here(co);
			is_exit_here(co);
			if (co->exit_here == 1 && co->door_look_far == 0 && \
			co->nb_obj_take == co->nb_obj_in)
				co->door_look_far = 1;
			else
				co->door_look_far = 0;
			put_asked_exit(co);
			is_coilhead_here(co, co->y, co->x);
			co->y++;
		}
	}
	co->door_look_far = 0;
	co->y = co->buffer_y;
}

void	look_right_next(t_coord *co)
{
	if (co->tab.tab_tiles[co->y][co->x + 1] != '1' && co->light == 1)
	{
		co->x++;
		while (co->tab.tab_tiles[co->y][co->x] != '1')
		{
			put_asked_image(co);
			is_obj_here(co);
			is_exit_here(co);
			if (co->exit_here == 1 && co->door_look_far == 0 && \
			co->nb_obj_take == co->nb_obj_in)
				co->door_look_far = 1;
			else
				co->door_look_far = 0;
			put_asked_exit(co);
			is_coilhead_here(co, co->y, co->x);
			co->x++;
		}
	}
	co->door_look_far = 0;
	co->x = co->buffer_x;
}
