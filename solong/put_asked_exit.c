/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asked_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:42:12 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 04:43:22 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	put_asked_exit_next1(t_coord *c)
{
	if (c->tab.tab_0_1[c->y][c->x] == 'm')
	{
		if (c->nb_obj_take == c->nb_obj_in)
		{
			if (c->door_look_far == 1)
				mlx_put_image_to_window(c->m, c->w, c->t.t_os, \
				c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
			else
				mlx_put_image_to_window(c->m, c->w, c->t.t_o, \
				c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
		}
		else
			mlx_put_image_to_window(c->m, c->w, c->t.t_c, \
			c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	}
}

static void	put_asked_exit_next2(t_coord *c)
{
	if (c->tab.tab_0_1[c->y][c->x] == 'l')
	{
		if (c->nb_obj_take == c->nb_obj_in)
		{
			if (c->door_look_far == 1)
				mlx_put_image_to_window(c->m, c->w, c->t.d_o, \
				c->t_x + (c->x * 64), c->t_y + 16 + (c->y * 64));
			else
				mlx_put_image_to_window(c->m, c->w, c->t.d_os, \
				c->t_x + (c->x * 64), c->t_y + 16 + (c->y * 64));
		}
		else
			mlx_put_image_to_window(c->m, c->w, c->t.d_c, \
			c->t_x + (c->x * 64), c->t_y + 16 + (c->y * 64));
	}
}

static void	put_asked_exit_next3(t_coord *c)
{
	if (c->tab.tab_0_1[c->y][c->x] == 'r')
	{
		if (c->nb_obj_take == c->nb_obj_in)
		{
			if (c->door_look_far == 1)
				mlx_put_image_to_window(c->m, c->w, c->t.d_os, \
				c->t_x + 32 + (c->x * 64), c->t_y + (c->y * 64));
			else
				mlx_put_image_to_window(c->m, c->w, c->t.d_o, \
				c->t_x + 32 + (c->x * 64), c->t_y + (c->y * 64));
		}
		else
			mlx_put_image_to_window(c->m, c->w, c->t.d_c, \
			c->t_x + 32 + (c->x * 64), c->t_y + (c->y * 64));
	}
}

void	put_asked_exit(t_coord *c)
{
	if (c->tab.tab_0_1[c->y][c->x] == 't')
	{
		if (c->nb_obj_take == c->nb_obj_in)
		{
			if (c->door_look_far == 1)
				mlx_put_image_to_window(c->m, c->w, c->t.d_os, \
				c->t_x + 16 + (c->x * 64), c->t_y + (c->y * 64));
			else
				mlx_put_image_to_window(c->m, c->w, c->t.d_o, \
				c->t_x + 16 + (c->x * 64), c->t_y + (c->y * 64));
		}
		else
			mlx_put_image_to_window(c->m, c->w, c->t.d_c, \
			c->t_x + 16 + (c->x * 64), c->t_y + (c->y * 64));
	}
	put_asked_exit_next1(c);
	put_asked_exit_next2(c);
	put_asked_exit_next3(c);
}
