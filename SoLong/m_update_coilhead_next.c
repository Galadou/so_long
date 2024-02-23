/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_update_coilhead_next.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:02:36 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 06:30:03 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	update_next_4(t_coord *co)
{
	if (co->times == co->times_buf + 2 && co->m_find_speed > 1)
	{
		co->mid_second = co->m_find_speed / 6;
		co->m_speed = 1;
	}
	if (co->mid_second > 0)
		co->m_speed++;
	if (co->m_speed == co->mid_second)
	{
		co->coilhead.can_moove = 1;
		co->m_speed = 1;
	}
	if (co->coilhead.can_moove == 1 && co->coilhead.see_coilhead == 0)
	{
		co->m_speed = 1;
		co->coilhead.can_moove = 0;
		co->one_time = co->times;
		coilhead_moove(co);
		if (co->coilhead.has_moove)
			system("paplay --volume=100000 song/coilhead-walk.wav &");
	}
	update_next_5(co);
}

static void	update_next_3(t_coord *c)
{
	if (c->x == c->coilhead.x && c->y == c->coilhead.y)
	{
		destroy_hero(c);
		destroy_monster(c);
		define_monster(c);
		mlx_put_image_to_window(c->m, c->w, c->t.o_t_g, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
		c->player_dead = 1;
		system("pkill -9 paplay");
		system("paplay --volume=55000 song/coilhead-kill.wav &");
	}
	if (c->m_find_speed == 0 || c->times == c->times_buf + 30)
	{
		c->times_buf = time(NULL);
		c->m_find_speed = 1;
	}
	if (c->times == c->times_buf + 1)
		c->m_find_speed++;
	update_next_4(c);
}

static void	update_next_2(t_coord *c)
{
	if ((c->times == c->times_count + 15 || c->times == c->times_count + 21 || \
		c->times == c->times_count + 42 || c->times == c->times_count + 97 || \
		c->times == c->times_count + 154 || c->times == c->times_count + 172 || \
		c->times == c->times_count + 111 || c->times == c->times_count + 69) && \
		c->m_speed == c->mid_second - 2)
	{
		mlx_destroy_image(c->m, c->t.m_monstre);
		c->t.m_monstre = mlx_png_file_to_image(c->m, \
		"t/monstre.png", &c->wi, &c->h);
	}
	if (c->exit_get_out == 2)
		get_out(c);
	if (c->exit_get_out == 1)
		c->exit_get_out = 2;
	update_next_3(c);
}

static void	if_next(t_coord *c)
{
	if ((c->times == c->times_count + 21 || \
	c->times == c->times_count + 111) && c->monster_show == 2)
	{
		c->monster_show = 3;
		system("paplay --volume=100000 song/rire1.wav &");
		mlx_put_image_to_window(c->m, c->w, c->t.m_monstre, \
		(c->t_x - 64) + (c->x * 64), c->t_y + (c->y * 64));
	}
	if ((c->times == c->times_count + 42 || \
	c->times == c->times_count + 157) && c->monster_show == 3)
	{
		c->monster_show = 4;
		system("paplay --volume=100000 song/rire3.wav &");
		mlx_put_image_to_window(c->m, c->w, c->t.m_monstre, \
		c->t_x + (c->x * 64), (c->t_y - 64) + (c->y * 64));
	}
	if ((c->times == c->times_count + 69 || \
	c->times == c->times_count + 172) && c->monster_show == 4)
	{
		c->monster_show = 1;
		system("paplay --volume=100000 song/rire1.wav &");
		mlx_put_image_to_window(c->m, c->w, c->t.m_monstre, \
		c->t_x + (c->x * 64), c->t_y + 64 + (c->y * 64));
	}
}

void	update_next(t_coord *c)
{
	if (c->times == c->times_count + 175)
	{
		system("paplay --volume=40000 song/musique.wav &");
		c->times_count = time(NULL);
	}
	if (c->times == c->times_count + 15 || c->times == c->times_count + 21 || \
	c->times == c->times_count + 42 || c->times == c->times_count + 97 || \
	c->times == c->times_count + 154 || c->times == c->times_count + 172 || \
	c->times == c->times_count + 111 || c->times == c->times_count + 69)
	{
		if (c->m_speed < c->mid_second / 1.1)
		{
			if ((c->times == c->times_count + 15 || \
			c->times == c->times_count + 97) && c->monster_show == 1)
			{
				c->monster_show = 2;
				system("paplay --volume=100000 song/rire2.wav &");
				mlx_put_image_to_window(c->m, c->w, c->t.m_monstre, \
				c->t_x + 64 + (c->x * 64), c->t_y + (c->y * 64));
			}
			if_next(c);
		}
	}
	update_next_2(c);
}
