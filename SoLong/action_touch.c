#include "header.h"

int key_hook(int key, void* param)
{
	t_coordinates *coordinates;

	coordinates = (t_coordinates *) param;
	if(key == 41) // 41 is the key code for escape
	{
		destroy_hero(coordinates);
		destroy_object(coordinates);
		destroy_img(&coordinates->tiles, *coordinates);
		destroy_exit(coordinates);
		destroy_monster(coordinates);
		mlx_loop_end(coordinates->mlx); // if escape is pressed we stop the mlx_loop and so we continue in the main function
	}
		//regard
	if (key == 82)
	{
		if (coordinates->player_look.up != 1)
		{
			//put_asked_exit(coordinates);
			//put_asked_hero(coordinates);
			coordinates->coilhead.see_coilhead = 0;
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			define_player_look(coordinates);
			coordinates->player_look.up = 1;
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			put_asked_hero(coordinates);
		}
	}
	if (key == 81)
	{
		if (coordinates->player_look.down != 1)
		{
			//put_asked_exit(coordinates);
		   //put_asked_hero(coordinates);
		   coordinates->coilhead.see_coilhead = 0;
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			define_player_look(coordinates);
			coordinates->player_look.down = 1;
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			//look_down(*coordinates);
			//mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_front, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
			put_asked_hero(coordinates);
		}
	}
	if (key == 80)
	{
		if (coordinates->player_look.left != 1)
		{
			//put_asked_exit(coordinates);
			//put_asked_hero(coordinates);
			coordinates->coilhead.see_coilhead = 0;
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			define_player_look(coordinates);
			coordinates->player_look.left = 1;
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			put_asked_hero(coordinates);
		}
	}
	if (key == 79)
	{
		if (coordinates->player_look.right != 1)
		{
			//put_asked_exit(coordinates);
			//put_asked_hero(coordinates);
			coordinates->coilhead.see_coilhead = 0;
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			define_player_look(coordinates);
			coordinates->player_look.right = 1;
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			put_asked_hero(coordinates);
		}
	}
		//deplacement
	if (key == SDL_SCANCODE_W)
	{
		if (coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1')
		{
			//put_asked_exit(coordinates);
			//put_asked_hero(coordinates);
			coordinates->coilhead.see_coilhead = 0;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			coordinates->y = coordinates->y - 1;
			can_i_exit(coordinates);
			take_obj(coordinates);
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			put_asked_hero(coordinates);
			//ft_printf("\n%d = obj pris, %d = obj total",coordinates->nb_obj_take, coordinates->nb_obj_in);
		}
	}
	if (key == SDL_SCANCODE_S)
	{
		if (coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1')
		{
			//put_asked_exit(coordinates);
		   // put_asked_hero(coordinates);
		   coordinates->coilhead.see_coilhead = 0;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			coordinates->y = coordinates->y + 1;
			can_i_exit(coordinates);
			take_obj(coordinates);
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			put_asked_hero(coordinates);
			//ft_printf("\n%d = obj pris, %d = obj total",coordinates->nb_obj_take, coordinates->nb_obj_in);
		}
	}
	if (key == SDL_SCANCODE_A)
	{
		if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1')
		{
			//put_asked_exit(coordinates);
			//put_asked_hero(coordinates);
			coordinates->coilhead.see_coilhead = 0;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			coordinates->x = coordinates->x - 1;
			can_i_exit(coordinates);
			take_obj(coordinates);
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			put_asked_hero(coordinates);
			//ft_printf("\n%d = obj pris, %d = obj total",coordinates->nb_obj_take, coordinates->nb_obj_in);

		}
	}
	if (key == SDL_SCANCODE_D)
	{
		if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1')
		{
			//put_asked_hero(coordinates);
			coordinates->coilhead.see_coilhead = 0;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->light == 1)
				hide_tiles_light(coordinates);
			put_shadow(*coordinates);
			coordinates->x = coordinates->x + 1;
			can_i_exit(coordinates);
			take_obj(coordinates);
			destroy_hero(coordinates);
			define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
			put_asked_hero(coordinates);
			//ft_printf("\n%d = obj pris, %d = obj total",coordinates->nb_obj_take, coordinates->nb_obj_in);

		}
	}
	return (0);
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
