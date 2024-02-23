/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_front.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:26:59 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 04:13:24 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	look_action(t_coord *co)
{
	put_asked_image(co);
	is_obj_here(co);
	put_asked_exit(co);
	is_coilhead_here(co, co->y, co->x);
}

void	look_up(t_coord *co)
{
	co->buffer_x = co->x;
	co->buffer_y = co->y;
	if (co->tab.tab_tiles[co->y - 1][co->x] != '1')
	{
		co->y--;
		if (co->tab.tab_tiles[co->y][co->x + 1] != '1' && co->light == 1)
		{
			co->x++;
			look_action(co);
			co->x--;
		}
		if (co->tab.tab_tiles[co->y][co->x - 1] != '1' && co->light == 1)
		{
			co->x--;
			look_action(co);
			co->x++;
		}
		if (co->tab.tab_tiles[co->y][co->x] != '1')
			look_action(co);
		look_up_next(co);
	}
}

void	look_left(t_coord *co)
{
	co->buffer_x = co->x;
	co->buffer_y = co->y;
	if (co->tab.tab_tiles[co->y][co->x - 1] != '1')
	{
		co->x--;
		if (co->tab.tab_tiles[co->y + 1][co->x] != '1' && co->light == 1)
		{
			co->y++;
			look_action(co);
			co->y--;
		}
		if (co->tab.tab_tiles[co->y - 1][co->x] != '1' && co->light == 1)
		{
			co->y--;
			look_action(co);
			co->y++;
		}
		if (co->tab.tab_tiles[co->y][co->x] != '1')
			look_action(co);
		look_left_next(co);
	}
}

void	look_down(t_coord *co)
{
	co->buffer_x = co->x;
	co->buffer_y = co->y;
	if (co->tab.tab_tiles[co->y + 1][co->x] != '1')
	{
		co->y++;
		if (co->tab.tab_tiles[co->y][co->x + 1] != '1' && co->light == 1)
		{
			co->x++;
			look_action(co);
			co->x--;
		}
		if (co->tab.tab_tiles[co->y][co->x - 1] != '1' && co->light == 1)
		{
			co->x--;
			look_action(co);
			co->x++;
		}
		if (co->tab.tab_tiles[co->y][co->x] != '1')
			look_action(co);
		look_down_next(co);
	}
}

void	look_right(t_coord *co)
{
	co->buffer_x = co->x;
	co->buffer_y = co->y;
	if (co->tab.tab_tiles[co->y][co->x +1] != '1')
	{
		co->x++;
		if (co->tab.tab_tiles[co->y + 1][co->x] != '1' && co->light == 1)
		{
			co->y++;
			look_action(co);
			co->y--;
		}
		if (co->tab.tab_tiles[co->y - 1][co->x] != '1' && co->light == 1)
		{
			co->y--;
			look_action(co);
			co->y++;
		}
		if (co->tab.tab_tiles[co->y][co->x] != '1')
			look_action(co);
		look_right_next(co);
	}
}
