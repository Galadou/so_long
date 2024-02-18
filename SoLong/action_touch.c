#include "header.h"

int key_hook(int key, void* param)
{
	t_coordinates *coordinates;

	coordinates = (t_coordinates *) param;
	key_hook_close(key, coordinates);
	key_hook_look(key, coordinates);
	key_hook_move(key, coordinates);
	return (0);
}

void key_hook_move(int key, t_coordinates *coordinates)
{
	if (key == SDL_SCANCODE_W || key == SDL_SCANCODE_A || key == SDL_SCANCODE_S || key == SDL_SCANCODE_D)
	{
		if ((key == SDL_SCANCODE_W && coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1') ||
		(key == SDL_SCANCODE_S && coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1') ||
		(key == SDL_SCANCODE_A && coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1') ||
		(key == SDL_SCANCODE_D && coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1'))
			playermove_p1(coordinates);
		if (key == SDL_SCANCODE_W && coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1')
			coordinates->y = coordinates->y - 1;
		else if (key == SDL_SCANCODE_S && coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1')
			coordinates->y = coordinates->y + 1;
		else if (key == SDL_SCANCODE_A && coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1')
			coordinates->x = coordinates->x - 1;
		else if (key == SDL_SCANCODE_D && coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1')
			coordinates->x = coordinates->x + 1;
		if ((key == SDL_SCANCODE_W && coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1') ||
		(key == SDL_SCANCODE_S && coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1' )||
		(key == SDL_SCANCODE_A && coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1' )||
		(key == SDL_SCANCODE_D && coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1'))
			playermove_p2(coordinates);
	}
}

void key_hook_look(int key, t_coordinates *coordinates)
{
	if (key >= 79 && key <= 82)
	{
		if ((key == 79 && coordinates->player_look.right != 1) ||
		(key == 80 && coordinates->player_look.left != 1) ||
		(key == 81 && coordinates->player_look.down != 1) ||
		(key == 82 && coordinates->player_look.up != 1))
			playersee_p1(coordinates);
		if (key == 79 && coordinates->player_look.right != 1)
			coordinates->player_look.right = 1;
		else if (key == 80 && coordinates->player_look.left != 1)
			coordinates->player_look.left = 1;
		else if (key == 81 && coordinates->player_look.down != 1)
			coordinates->player_look.down = 1;
		else if (key == 82 && coordinates->player_look.up != 1)
			coordinates->player_look.up = 1;
		if ((key == 79 && coordinates->player_look.right == 1) ||
		(key == 80 && coordinates->player_look.left == 1) ||
		(key == 81 && coordinates->player_look.down == 1) ||
		(key == 82 && coordinates->player_look.up == 1))
			playersee_p2(coordinates);
	}
}

int window_hook(int event, void* param)
{
	t_coordinates *coordinates;

	coordinates = (t_coordinates *) param;
	if(event == 0) // 0 is when we trigger the close of the window (by clicking the cross for example)
	{
		mlx_loop_end(coordinates->mlx);
		destroy_hero(coordinates);
		destroy_object(coordinates);
		destroy_img(&coordinates->tiles, *coordinates);
		destroy_exit(coordinates);
		destroy_monster(coordinates);
	}
	return (0);
}
