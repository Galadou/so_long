/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asked_hero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 04:47:56 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 04:47:58 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	put_asked_hero_next(t_coord *c)
{
	if (c->player_look.left == 1)
	{
		mlx_put_image_to_window(c->m, c->w, c->t.p_l, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
		look_left(c);
	}
	if (c->player_look.right == 1)
	{
		mlx_put_image_to_window(c->m, c->w, c->t.p_r, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
		look_right(c);
	}
}

void	put_asked_hero(t_coord *c)
{
	put_asked_image(c);
	put_asked_exit(c);
	put_asked_object(c);
	if (c->player_look.up == 1)
	{
		mlx_put_image_to_window(c->m, c->w, c->t.p_b, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
		look_up(c);
	}
	if (c->player_look.down == 1)
	{
		mlx_put_image_to_window(c->m, c->w, c->t.p_f, \
		c->t_x + 16 + (c->x * 64), c->t_y + 16 + (c->y * 64));
		look_down(c);
	}
	put_asked_hero_next(c);
}
