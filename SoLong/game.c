/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:08:46 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 18:00:51 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	find_p(t_coord *coordinates, char **tab_0_1)
{
	coordinates->y = 0;
	coordinates->x = 0;
	while (tab_0_1[coordinates->y][coordinates->x] != 'P')
	{
		coordinates->x = 0;
		while (tab_0_1[coordinates->y][coordinates->x])
		{
			if (tab_0_1[coordinates->y][coordinates->x] == 'P')
				break ;
			coordinates->x = coordinates->x + 1;
		}
		if (tab_0_1[coordinates->y][coordinates->x] == '\0')
			coordinates->y = coordinates->y + 1;
	}
}

void	init_player(char **tab_0_1, t_coord *c, t_tiles t)
{
	find_p(c, tab_0_1);
	c->player_look.left = 1;
	mlx_put_image_to_window(c->m, c->w, t.p_l, 16 + c->x * 64, 80 + c->y * 64);
	put_asked_hero(c);
}

void	game(t_coord *c)
{
	c->player_look.left = 1;
	mlx_on_event(c->m, c->w, MLX_KEYDOWN, key_hook, c);
	mlx_on_event(c->m, c->w, MLX_WINDOW_EVENT, window_hook, c);
	mlx_loop_hook(c->m, update, c);
	mlx_loop(c->m);
}

int	window_view_and_game(t_coord *c)
{
	c->m = mlx_init();
	c->w = mlx_new_window(c->m, 64 * c->c, 64 * c->l + 64, "so_long");
	define_img(c);
	def_hero(c);
	define_object(c);
	define_exit(c);
	define_count(c);
	define_monster(c);
	define_coilhead_go(c);
	define_player_look(c);
	put_img_base(c, c->t);
	put_shadow(c);
	init_player(c->tab.tab_0_1, c, c->t);
	monster_spawn(c);
	game(c);
	destroy_hero(c);
	destroy_img(c);
	destroy_object(c);
	destroy_exit(c);
	destroy_monster(c);
	mlx_destroy_window(c->m, c->w);
	mlx_destroy_display(c->m);
	return (0);
}
