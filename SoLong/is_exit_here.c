#include "header.h"

void can_i_exit(t_coordinates *coordinates)
{
	if ((coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 't' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'l' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'r' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'm') &&
	coordinates->nb_obj_take == coordinates->nb_obj_in)
	{
		ft_printf("Vous etes sortie de l'enfer...Pour le moment...");
		mlx_loop_end(coordinates->mlx);
		destroy_hero(coordinates);
		destroy_object(coordinates);
		destroy_img(&coordinates->tiles, *coordinates);
		destroy_exit(coordinates);
		destroy_monster(coordinates);
		mlx_destroy_window(coordinates->mlx,coordinates->win);
		mlx_destroy_display(coordinates->mlx);
		exit(0);
	}
}

void is_exit_here(t_coordinates *coordinates)
{
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 't' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'l' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'r' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'm')
		coordinates->exit_here = 1;
	else
		coordinates->exit_here = 0;
}
