/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_update_coilhead.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 03:50:02 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 17:45:08 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_coilhead_up(t_coord *c)
{
	if (c->player_look.up == 1)
	{
		c->buffer_y = c->y;
		if (c->tab.tab_tiles[c->y - 1][c->x] != '1')
		{
			c->y--;
			if (c->tab.tab_tiles[c->y][c->x + 1] != '1' && c->light == 1)
				is_coilhead_here(c, c->y, c->x + 1);
			if (c->tab.tab_tiles[c->y][c->x - 1] != '1' && c->light == 1)
				is_coilhead_here(c, c->y, c->x - 1);
			if (c->tab.tab_tiles[c->y][c->x] != '1')
				is_coilhead_here(c, c->y, c->x);
			if (c->tab.tab_tiles[c->y - 1][c->x] != '1' && c->light == 1)
			{
				c->y--;
				while (c->tab.tab_tiles[c->y][c->x] != '1')
				{
					is_coilhead_here(c, c->y, c->x);
					c->y--;
				}
			}
			c->y = c->buffer_y;
		}
	}
}

void	update_coilhead_left(t_coord *c)
{
	if (c->player_look.left == 1)
	{
		c->buffer_x = c->x;
		if (c->tab.tab_tiles[c->y][c->x - 1] != '1')
		{
			c->x--;
			if (c->tab.tab_tiles[c->y + 1][c->x] != '1' && c->light == 1)
				is_coilhead_here(c, c->y + 1, c->x);
			if (c->tab.tab_tiles[c->y - 1][c->x] != '1' && c->light == 1)
				is_coilhead_here(c, c->y - 1, c->x);
			if (c->tab.tab_tiles[c->y][c->x] != '1')
				is_coilhead_here(c, c->y, c->x);
			if (c->tab.tab_tiles[c->y][c->x - 1] != '1' && c->light == 1)
			{
				c->x--;
				while (c->tab.tab_tiles[c->y][c->x] != '1')
				{
					is_coilhead_here(c, c->y, c->x);
					c->x--;
				}
			}
			c->x = c->buffer_x;
		}
	}
}

void	update_coilhead_down(t_coord *c)
{
	if (c->player_look.down == 1)
	{
		c->buffer_y = c->y;
		if (c->tab.tab_tiles[c->y + 1][c->x] != '1')
		{
			c->y++;
			if (c->tab.tab_tiles[c->y][c->x + 1] != '1' && c->light == 1)
				is_coilhead_here(c, c->y, c->x + 1);
			if (c->tab.tab_tiles[c->y][c->x - 1] != '1' && c->light == 1)
				is_coilhead_here(c, c->y, c->x - 1);
			if (c->tab.tab_tiles[c->y][c->x] != '1')
				is_coilhead_here(c, c->y, c->x);
			if (c->tab.tab_tiles[c->y + 1][c->x] != '1' && c->light == 1)
			{
				c->y++;
				while (c->tab.tab_tiles[c->y][c->x] != '1')
				{
					is_coilhead_here(c, c->y, c->x);
					c->y++;
				}
			}
			c->y = c->buffer_y;
		}
	}
}

void	update_coilhead_right(t_coord *c)
{
	if (c->player_look.right == 1)
	{
		c->buffer_x = c->x;
		if (c->tab.tab_tiles[c->y][c->x +1] != '1')
		{
			c->x++;
			if (c->tab.tab_tiles[c->y + 1][c->x] != '1' && c->light == 1)
				is_coilhead_here(c, c->y + 1, c->x);
			if (c->tab.tab_tiles[c->y - 1][c->x] != '1' && c->light == 1)
				is_coilhead_here(c, c->y - 1, c->x);
			if (c->tab.tab_tiles[c->y][c->x] != '1')
				is_coilhead_here(c, c->y, c->x);
			if (c->tab.tab_tiles[c->y][c->x + 1] != '1' && c->light == 1)
			{
				c->x++;
				while (c->tab.tab_tiles[c->y][c->x] != '1')
				{
					is_coilhead_here(c, c->y, c->x);
					c->x++;
				}
			}
			c->x = c->buffer_x;
		}
	}
}

int	update(void *param)
{
	t_coord	*c;

	c = (t_coord *) param;
	c->times = time(NULL);
	if (c->player_dead == 1)
		kill_player(c);
	if (c->bearkorgeister == 1 && c->time_bonus == 0)
		c->time_bonus = time(NULL);
	if (c->times == c->time_bonus + 43)
	{
		destroy_hero(c);
		mlx_put_image_to_window(c->m, c->w, c->t.o_t_g, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
		system("pkill -9 paplay");
		system("paplay --volume=55000 song/coilhead-kill.wav &");
		c->player_dead = 1;
	}
	if (c->times_count == 0)
		c->times_count = time(NULL);
	update_next(c);
	return (0);
}
