/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_monster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:54:49 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 04:37:20 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	where_coilhead_spawn_recursive(t_coord *c)
{
	if (abs(c->coilhead.far_p_y) + abs(c->coilhead.far_p_x) > \
	abs(c->coilhead.far_p_y_buf) + abs(c->coilhead.far_p_x_buf))
	{
		c->coilhead.far_p_y_buf = c->coilhead.far_p_y;
		c->coilhead.far_p_x_buf = c->coilhead.far_p_x;
		c->coilhead.x = c->x;
		c->coilhead.y = c->y;
	}
	c->tab.tab_dup_monsterspawn[c->y][c->x] = '1';
	if (c->tab.tab_dup_monsterspawn[c->y - 1][c->x] != '1')
	{
		c->y--;
		c->coilhead.far_p_y--;
		where_coilhead_spawn_recursive(c);
		c->y++;
	}
	where_coilhead_spawn_recursive_next(c);
}

void	where_coilhead_spawn_recursive_next(t_coord *c)
{
	if (c->tab.tab_dup_monsterspawn[c->y][c->x - 1] != '1')
	{
		c->x--;
		c->coilhead.far_p_x--;
		where_coilhead_spawn_recursive(c);
		c->x++;
	}
	if (c->tab.tab_dup_monsterspawn[c->y + 1][c->x] != '1')
	{
		c->y++;
		c->coilhead.far_p_y++;
		where_coilhead_spawn_recursive(c);
		c->y--;
	}
	if (c->tab.tab_dup_monsterspawn[c->y][c->x + 1] != '1')
	{
		c->x++;
		c->coilhead.far_p_x++;
		where_coilhead_spawn_recursive(c);
		c->x--;
	}
}

void	monster_spawn(t_coord *c)
{
	where_coilhead_spawn_recursive(c);
	c->coilhead.last_seen_player_x = c->coilhead.x;
	c->coilhead.last_seen_player_y = c->coilhead.y;
}

void	put_asked_coilhead(t_coord *c)
{
	if (c->coilhead.go_up == 1)
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_b, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
	else if (c->coilhead.go_left == 1)
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_l, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
	else if (c->coilhead.go_down == 1)
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
	else if (c->coilhead.go_right == 1)
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_r, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
	else
		mlx_put_image_to_window(c->m, c->w, c->t.m_c_f, \
		c->t_x + (c->coilhead.x * 64), c->t_y + (c->coilhead.y * 64));
}
