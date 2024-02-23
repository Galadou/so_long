/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asked_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:42:32 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 06:50:16 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	put_asked_image_next(t_coord *c)
{
	if (c->tab.tab_tiles[c->y][c->x] == '_')
		mlx_put_image_to_window(c->m, c->w, c->t._, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == '7')
		mlx_put_image_to_window(c->m, c->w, c->t._7, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'K')
		mlx_put_image_to_window(c->m, c->w, c->t.k_, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'T')
		mlx_put_image_to_window(c->m, c->w, c->t.t_, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'U')
		mlx_put_image_to_window(c->m, c->w, c->t.u_, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == ']')
		mlx_put_image_to_window(c->m, c->w, c->t.c_l, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'c')
		mlx_put_image_to_window(c->m, c->w, c->t.c, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'n')
		mlx_put_image_to_window(c->m, c->w, c->t.n, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
}

void	put_asked_image(t_coord *c)
{
	if (c->tab.tab_tiles[c->y][c->x] == 'H')
		mlx_put_image_to_window(c->m, c->w, c->t.h_, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'Z')
		mlx_put_image_to_window(c->m, c->w, c->t.z_, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'X')
		mlx_put_image_to_window(c->m, c->w, c->t.x_, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'a')
		mlx_put_image_to_window(c->m, c->w, c->t.a, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'b')
		mlx_put_image_to_window(c->m, c->w, c->t.b, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'l')
		mlx_put_image_to_window(c->m, c->w, c->t.l, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	if (c->tab.tab_tiles[c->y][c->x] == 'L')
		mlx_put_image_to_window(c->m, c->w, c->t.l_, \
		c->t_x + (c->x * 64), c->t_y + (c->y * 64));
	put_asked_image_next(c);
}

void	put_shadow(t_coord *c)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < c->l)
	{
		x = 0;
		while (x < c->c)
		{
			mlx_put_image_to_window(c->m, c->w, c->t.s, \
			c->t_x + (64 * x), c->t_y + (64 * y));
			x++;
		}
		y++;
	}
}

void	put_img_base(t_coord *c, t_tiles t)
{
	size_t	y;
	size_t	x;

	c->t_y = 64;
	c->t_x = 0;
	y = 0;
	while (y < c->l)
	{
		x = 0;
		while (x < c->c)
		{
			mlx_put_image_to_window(c->m, c->w, t.w, \
			c->t_x + (64 * x), c->t_y + (64 * y));
			x++;
		}
		y++;
	}
	x = 0;
	while (x < c->c)
	{
		mlx_put_image_to_window(c->m, c->w, t.h, c->t_x + (64 * x), 0);
		x++;
	}
}
