/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_coilhead_move_next.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:52:42 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 02:02:36 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	coilhead_moove_next(t_coord *c)
{
	if (c->coilhead.last_seen_player_x > c->coilhead.x)
	{
		c->coilhead.x++;
		define_coilhead_go(c);
		c->coilhead.go_right = 1;
		c->coilhead.has_moove = 1;
	}
}

void	head_moove_down_next(t_coord *c)
{
	if (c->coilhead.frame == 2 && c->m_speed == c->mid_second / 2)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
	else if (c->coilhead.frame == 3 && c->m_speed == c->mid_second - 1)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f_r, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
	else if (c->coilhead.frame == 4 && c->m_speed == c->mid_second / 3)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
}

void	head_moove_up_next(t_coord *c)
{
	if (c->coilhead.frame == 2 && c->m_speed == c->mid_second / 2)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_b, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
	else if (c->coilhead.frame == 3 && c->m_speed == c->mid_second - 1)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_b_r, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
	else if (c->coilhead.frame == 4 && c->m_speed == c->mid_second / 3)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_b, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
}
