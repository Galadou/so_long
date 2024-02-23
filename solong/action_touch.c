/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_touch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:13:24 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/21 00:52:35 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int key, void *param)
{
	t_coord	*coordinates;

	coordinates = (t_coord *) param;
	key_hook_close(key, coordinates);
	key_hook_look(key, coordinates);
	key_hook_move(key, coordinates);
	return (0);
}

void	key_hook_move(int key, t_coord *co)
{
	if ((key == SDL_SCANCODE_W || key == SDL_SCANCODE_A || \
	key == SDL_SCANCODE_S || key == SDL_SCANCODE_D))
	{
		if ((key == 26 && co->tab.tab_0_1[co->y - 1][co->x] != '1') ||
		(key == SDL_SCANCODE_S && co->tab.tab_0_1[co->y + 1][co->x] != '1') ||
		(key == SDL_SCANCODE_A && co->tab.tab_0_1[co->y][co->x - 1] != '1') ||
		(key == SDL_SCANCODE_D && co->tab.tab_0_1[co->y][co->x + 1] != '1'))
			playermove_p1(co);
		if (key == SDL_SCANCODE_W && co->tab.tab_0_1[co->y - 1][co->x] != '1')
			co->y = co->y - 1;
		else if (key == SDL_SCANCODE_S && \
		co->tab.tab_0_1[co->y + 1][co->x] != '1')
			co->y = co->y + 1;
		else if (key == SDL_SCANCODE_A && \
		co->tab.tab_0_1[co->y][co->x - 1] != '1')
			co->x = co->x - 1;
		else if (key == SDL_SCANCODE_D && \
		co->tab.tab_0_1[co->y][co->x + 1] != '1')
			co->x = co->x + 1;
		if ((key == SDL_SCANCODE_W || key == SDL_SCANCODE_S || \
		key == SDL_SCANCODE_A || \
		key == SDL_SCANCODE_D) && co->tab.tab_0_1[co->y][co->x] != '1')
			playermove_p2(co);
	}
}

void	key_hook_look(int key, t_coord *co)
{
	if (key >= 79 && key <= 82)
	{
		if ((key == 79 && co->player_look.right != 1) || \
		(key == 80 && co->player_look.left != 1) || \
		(key == 81 && co->player_look.down != 1) || \
		(key == 82 && co->player_look.up != 1))
			playersee_p1(co);
		if (key == 79 && co->player_look.right != 1)
			co->player_look.right = 1;
		else if (key == 80 && co->player_look.left != 1)
			co->player_look.left = 1;
		else if (key == 81 && co->player_look.down != 1)
			co->player_look.down = 1;
		else if (key == 82 && co->player_look.up != 1)
			co->player_look.up = 1;
		if ((key == 79 && co->player_look.right == 1) || \
		(key == 80 && co->player_look.left == 1) || \
		(key == 81 && co->player_look.down == 1) || \
		(key == 82 && co->player_look.up == 1))
			playersee_p2(co);
	}
}

int	window_hook(int event, void *param)
{
	t_coord	*coordinates;

	coordinates = (t_coord *) param;
	if (event == 0)
	{
		destroy_hero(coordinates);
		destroy_object(coordinates);
		destroy_img(coordinates);
		destroy_exit(coordinates);
		destroy_monster(coordinates);
		mlx_loop_end(coordinates->m);
	}
	return (0);
}
