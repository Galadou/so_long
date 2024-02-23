/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asked_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:42:22 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 06:50:38 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	put_asked_object_next(t_coord *c)
{
	if (c->tab.tab_0_1[c->y][c->x] == '*')
		mlx_put_image_to_window(c->m, c->w, c->t.o_b_k, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'K')
		mlx_put_image_to_window(c->m, c->w, c->t.o_k, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 's')
		mlx_put_image_to_window(c->m, c->w, c->t.o_t_s, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'b')
		mlx_put_image_to_window(c->m, c->w, c->t.o_t_b, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'j')
		mlx_put_image_to_window(c->m, c->w, c->t.o_t_j, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'v')
		mlx_put_image_to_window(c->m, c->w, c->t.o_t_v, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
}

void	put_asked_object(t_coord *c)
{
	if (c->tab.tab_0_1[c->y][c->x] == 'S')
		mlx_put_image_to_window(c->m, c->w, c->t.o_m, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'L')
		mlx_put_image_to_window(c->m, c->w, c->t.o_l, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'M')
		mlx_put_image_to_window(c->m, c->w, c->t.o_b_br, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'B')
		mlx_put_image_to_window(c->m, c->w, c->t.o_b_bl, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	if (c->tab.tab_0_1[c->y][c->x] == 'V')
		mlx_put_image_to_window(c->m, c->w, c->t.o_b_g, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
	put_asked_object_next(c);
}
