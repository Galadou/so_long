/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_search_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:24:12 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 07:24:13 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	is_p_here(t_coord *co)
{
	if (co->coilhead.y == co->y && co->coilhead.x == co->x)
	{
		co->coilhead.last_seen_player_y = co->y;
		co->coilhead.last_seen_player_x = co->x;
	}
}

static void	m_search_player_next(t_coord *co, int y_buf, int x_buf)
{
	while (co->tab.tab_0_1[co->coilhead.y + 1][co->coilhead.x] != '1')
	{
		co->coilhead.y++;
		is_p_here(co);
	}
	co->coilhead.y = y_buf;
	while (co->tab.tab_0_1[co->coilhead.y][co->coilhead.x + 1] != '1')
	{
		co->coilhead.x++;
		is_p_here(co);
	}
	co->coilhead.x = x_buf;
}

void	m_search_player(t_coord *co)
{
	int	y_buf;
	int	x_buf;

	y_buf = co->coilhead.y;
	x_buf = co->coilhead.x;
	while (co->tab.tab_0_1[co->coilhead.y - 1][co->coilhead.x] != '1')
	{
		co->coilhead.y--;
		is_p_here(co);
	}
	co->coilhead.y = y_buf;
	while (co->tab.tab_0_1[co->coilhead.y][co->coilhead.x - 1] != '1')
	{
		co->coilhead.x--;
		is_p_here(co);
	}
	co->coilhead.x = x_buf;
	m_search_player_next(co, y_buf, x_buf);
}
