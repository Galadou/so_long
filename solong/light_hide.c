/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_hide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:09:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 02:39:32 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	hide_tiles_light(t_coord *c)
{
	if (c->player_look.up == 1)
		hide_tiles_light_up(c);
	else if (c->player_look.down == 1)
		hide_tiles_light_down(c);
	else if (c->player_look.left == 1)
		hide_tiles_light_left(c);
	else if (c->player_look.right == 1)
		hide_tiles_light_right(c);
}

void	hide_tiles_light_up(t_coord *c)
{
	int	buffer_x;
	int	buffer_y;

	buffer_x = c->x;
	buffer_y = c->y;
	if (c->player_look.up == 1 && c->tab.tab_0_1[c->y - 1][c->x] != '1')
	{
		c->y--;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
		if (c->tab.tab_0_1[c->y][c->x - 1] != '1')
		{
			c->x--;
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
		}
		c->x = buffer_x;
		hide_tiles_light_up_next(c, buffer_x, buffer_y);
	}
}

void	hide_tiles_light_down(t_coord *c)
{
	int	buffer_x;
	int	buffer_y;

	buffer_x = c->x;
	buffer_y = c->y;
	if (c->player_look.down == 1 && c->tab.tab_0_1[c->y + 1][c->x] != '1')
	{
		c->y++;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
		if (c->tab.tab_0_1[c->y][c->x - 1] != '1')
		{
			c->x--;
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
		}
		c->x = buffer_x;
		hide_tiles_light_left_next(c, buffer_x, buffer_y);
	}
}

void	hide_tiles_light_left(t_coord *c)
{
	int	buffer_x;
	int	buffer_y;

	buffer_x = c->x;
	buffer_y = c->y;
	if (c->player_look.left == 1 && c->tab.tab_0_1[c->y][c->x - 1] != '1')
	{
		c->x--;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
		if (c->tab.tab_0_1[c->y - 1][c->x] != '1')
		{
			c->y--;
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
		}
		c->y = buffer_y;
		hide_tiles_light_down_next(c, buffer_x, buffer_y);
	}
}

void	hide_tiles_light_right(t_coord *c)
{
	int	buffer_x;
	int	buffer_y;

	buffer_x = c->x;
	buffer_y = c->y;
	if (c->player_look.right == 1 && c->tab.tab_0_1[c->y][c->x + 1] != '1')
	{
		c->x++;
		mlx_put_image_to_window(c->m, c->w, c->t.w, c->x * 64, 64 + c->y * 64);
		if (c->tab.tab_0_1[c->y - 1][c->x] != '1')
		{
			c->y--;
			mlx_put_image_to_window(c->m, c->w, c->t.w, \
			c->x * 64, 64 + c->y * 64);
		}
		c->y = buffer_y;
		hide_tiles_light_right_next(c, buffer_x, buffer_y);
	}
}
