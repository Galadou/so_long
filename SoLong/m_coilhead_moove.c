/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_coilhead_moove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:32:56 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 06:33:36 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	is_coilhead_here(t_coord *coordinates, int y, int x)
{
	if (coordinates->coilhead.x == x && coordinates->coilhead.y == y)
	{
		coordinates->coilhead.see_coilhead = 1;
		coordinates->coilhead.last_seen_player_y = coordinates->buffer_y;
		coordinates->coilhead.last_seen_player_x = coordinates->buffer_x;
		destroy_monster(coordinates);
		define_monster(coordinates);
		put_asked_coilhead(coordinates);
		if (coordinates->coilhead.see_coilhead == 1 && \
		coordinates->coilhead.has_moove == 1)
			system("paplay --volume=65536 song/coilhead-stop.wav &");
	}
}

void	coilhead_moove(t_coord *coordinates)
{
	if (coordinates->coilhead.last_seen_player_y < coordinates->coilhead.y)
	{
		coordinates->coilhead.y--;
		define_coilhead_go(coordinates);
		coordinates->coilhead.go_up = 1;
		coordinates->coilhead.has_moove = 1;
	}
	else if (coordinates->coilhead.last_seen_player_y > coordinates->coilhead.y)
	{
		coordinates->coilhead.y++;
		define_coilhead_go(coordinates);
		coordinates->coilhead.go_down = 1;
		coordinates->coilhead.has_moove = 1;
	}
	else if (coordinates->coilhead.last_seen_player_x < coordinates->coilhead.x)
	{
		coordinates->coilhead.x--;
		define_coilhead_go(coordinates);
		coordinates->coilhead.go_left = 1;
		coordinates->coilhead.has_moove = 1;
	}
	else if (coordinates->coilhead.last_seen_player_x > coordinates->coilhead.x)
		coilhead_moove_next(coordinates);
	else
		coordinates->coilhead.has_moove = 0;
}

void	head_moove_down(t_coord *c)
{
	if (c->coilhead.frame == 5 || (c->coilhead.frame && \
	c->coilhead.see_coilhead == 0))
		c->coilhead.frame = 0;
	if (c->coilhead.has_moove == 1 && c->coilhead.see_coilhead == 1)
	{
		c->coilhead.has_moove = 0;
		c->coilhead.frame++;
	}
	if (c->coilhead.frame == 1)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f_l, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
	head_moove_down_next(c);
}

void	head_moove_up(t_coord *c)
{
	if (c->coilhead.frame == 5 || (c->coilhead.frame && \
	c->coilhead.see_coilhead == 0))
		c->coilhead.frame = 0;
	if (c->coilhead.has_moove == 1 && c->coilhead.see_coilhead == 1)
	{
		c->coilhead.has_moove = 0;
		c->coilhead.frame++;
	}
	if (c->coilhead.frame == 1)
	{
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_b_l, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
		c->coilhead.frame++;
	}
	head_moove_up_next(c);
}
