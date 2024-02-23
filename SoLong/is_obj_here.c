/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_obj_here.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:12:41 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 05:45:50 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	is_obj_here_next(t_coord *c)
{
	if (c->nb_find_obj == 4 || c->nb_find_obj == 10 || c->nb_find_obj == 12)
	{
		c->nb_beer_cub++;
		if (c->nb_beer_cub == 1)
			c->tab.tab_0_1[c->y][c->x] = 'M';
		if (c->nb_beer_cub == 2)
			c->tab.tab_0_1[c->y][c->x] = 'B';
		if (c->nb_beer_cub == 3)
			c->tab.tab_0_1[c->y][c->x] = 'V';
	}
	else if (c->nb_find_obj > 1)
	{
		c->nb_head++;
		if (c->nb_head > 3)
			c->nb_head = 1;
		if (c->nb_head == 1)
			c->tab.tab_0_1[c->y][c->x] = 'b';
		if (c->nb_head == 2)
			c->tab.tab_0_1[c->y][c->x] = 'j';
		if (c->nb_head == 3)
			c->tab.tab_0_1[c->y][c->x] = 'v';
	}
}

void	is_obj_here(t_coord *c)
{
	if (c->tab.tab_0_1[c->y][c->x] == 'C')
	{
		c->nb_find_obj++;
		if (c->nb_find_obj == c->nb_obj_in)
			c->tab.tab_0_1[c->y][c->x] = 'K';
		else
		{
			if (c->nb_find_obj == 1)
				c->tab.tab_0_1[c->y][c->x] = 'L';
			if (c->nb_beer_cub_take == 3)
			{
				c->tab.tab_0_1[c->y][c->x] = '*';
				c->nb_beer_cub_take++;
				system("pkill -9 paplay");
			}
			else
				is_obj_here_next(c);
		}
	}
	put_asked_object(c);
}

void	take_obj_next(t_coord *coordinates)
{
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'b' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'j' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'v')
	{
		coordinates->nb_obj_take++;
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 's';
		system("paplay --volume=40000 song/loot1.wav &");
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'M' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'B' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'V')
	{
		coordinates->nb_obj_take++;
		coordinates->nb_beer_cub_take++;
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = '0';
		system("paplay --volume=40000 song/loot2.wav &");
	}
}

void	take_obj(t_coord *coordinates)
{
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'L')
	{
		coordinates->light = 1;
		coordinates->nb_obj_take++;
		mlx_destroy_image(coordinates->m, coordinates->t.o_l);
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = '0';
		system("paplay --volume=40000 song/loot1.wav &");
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == '*')
	{
		coordinates->nb_obj_take++;
		coordinates->bearkorgeister = 1;
		mlx_destroy_image(coordinates->m, coordinates->t.o_b_k);
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'S';
		system("paplay --volume=40000 song/loot2.wav &");
		system("paplay --volume=60000 song/musique-bonus.wav &");
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'K')
	{
		coordinates->nb_obj_take++;
		mlx_destroy_image(coordinates->m, coordinates->t.o_k);
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = '0';
		system("paplay --volume=40000 song/loot1.wav &");
	}
	take_obj_next(coordinates);
}
