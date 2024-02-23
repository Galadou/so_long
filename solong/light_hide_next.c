/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_hide_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:09:39 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 02:40:23 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	hide_tiles_light_up_next(t_coord *c, int buffer_x, int buffer_y)
{
	if (c->tab.tab_0_1[c->y][c->x + 1] != '1')
	{
		c->x++;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
	}
	c->x = buffer_x;
	if (c->tab.tab_0_1[c->y - 1][c->x] != '1')
	{
		c->y--;
		while (c->tab.tab_0_1[c->y][c->x] != '1')
		{
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
			c->y--;
		}
	}
	c->x = buffer_x;
	c->y = buffer_y;
}

void	hide_tiles_light_left_next(t_coord *c, int buffer_x, int buffer_y)
{
	if (c->tab.tab_0_1[c->y][c->x + 1] != '1')
	{
		c->x++;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
	}
	c->x = buffer_x;
	if (c->tab.tab_0_1[c->y + 1][c->x] != '1')
	{
		c->y++;
		while (c->tab.tab_0_1[c->y][c->x] != '1')
		{
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
			c->y++;
		}
	}
	c->x = buffer_x;
	c->y = buffer_y;
}

void	hide_tiles_light_down_next(t_coord *c, int buffer_x, int buffer_y)
{
	if (c->tab.tab_0_1[c->y + 1][c->x] != '1')
	{
		c->y++;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
	}
	c->y = buffer_y;
	if (c->tab.tab_0_1[c->y][c->x - 1] != '1')
	{
		c->x--;
		while (c->tab.tab_0_1[c->y][c->x] != '1')
		{
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
			c->x--;
		}
	}
	c->x = buffer_x;
	c->y = buffer_y;
}

void	hide_tiles_light_right_next(t_coord *c, int buffer_x, int buffer_y)
{
	if (c->tab.tab_0_1[c->y + 1][c->x] != '1')
	{
		c->y++;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
	}
	c->y = buffer_y;
	if (c->tab.tab_0_1[c->y][c->x + 1] != '1')
	{
		c->x++;
		while (c->tab.tab_0_1[c->y][c->x] != '1')
		{
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
			c->x++;
		}
	}
	c->x = buffer_x;
	c->y = buffer_y;
}
