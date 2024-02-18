#include "header.h"



/*static void	game_over(t_coordinates *coordinates)
{
	//destroy_hero(coordinates);
	destroy_object(coordinates);
	destroy_img(&coordinates->tiles, *coordinates);
	destroy_exit(coordinates);
	//destroy_monster(coordinates);
	mlx_loop_end(coordinates->mlx);
	//usleep(5000000);
}*/

void	kill_player(t_coordinates *coordinates)
{
	//destroy_monster(coordinates);
	//game_over(coordinates);

	usleep(5000000);
	mlx_loop_end(coordinates->mlx);
	destroy_hero(coordinates);
	destroy_object(coordinates);
	destroy_img(&coordinates->tiles, *coordinates);
	destroy_exit(coordinates);
	destroy_monster(coordinates);
	exit(0);
}
