#include "header.h"

void	playersee_p1(t_coordinates *coordinates)
{
	coordinates->coilhead.see_coilhead = 0;
	if (coordinates->light == 1)
		hide_tiles_light(coordinates);
	put_shadow(*coordinates);
	define_player_look(coordinates);
}
void	playersee_p2(t_coordinates *coordinates)
{
	destroy_hero(coordinates);
	define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
	put_asked_hero(coordinates);
}

void	playermove_p1(t_coordinates *coordinates)
{
	mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.hall_hide, 64, 0);
	coordinates->nb_moove++;
	ft_printf("Nombres de pas = %d\n", coordinates->nb_moove);
	coordinates->string_count_moove = ft_itoa(coordinates->nb_moove);
	mlx_string_put(coordinates->mlx, coordinates->win, 70, 20, 0xF000F000, coordinates->string_count_moove);
	free(coordinates->string_count_moove);
	coordinates->coilhead.see_coilhead = 0;
	put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
	if (coordinates->light == 1)
		hide_tiles_light(coordinates);
	put_shadow(*coordinates);
}
void	playermove_p2(t_coordinates *coordinates)
{
	can_i_exit(coordinates);
	take_obj(coordinates);
	destroy_hero(coordinates);
	define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
	put_asked_hero(coordinates);
}

void key_hook_close(int key, t_coordinates *coordinates)
{
	if(key == 41) // 41 is the key code for escape
	{
		destroy_hero(coordinates);
		destroy_object(coordinates);
		destroy_img(&coordinates->tiles, *coordinates);
		destroy_exit(coordinates);
		destroy_monster(coordinates);
		mlx_loop_end(coordinates->mlx); // if escape is pressed we stop the mlx_loop and so we continue in the main function
	}
}
