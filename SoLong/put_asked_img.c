#include "header.h"

void put_asked_object(t_coordinates coordinates)
{
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'S')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_mask, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'L')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_light, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'M')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_beer_cub_brown, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'B')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_beer_cub_blue, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'V')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_beer_cub_green, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == '*')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_beer_cub_korgeister, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'K')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_key, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));

	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 's')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_t_sang, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'b')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_t_bleu, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'j')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_t_jaune, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
	if (coordinates.tab.tab_0_1[coordinates.y][coordinates.x] == 'v')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.obj_t_vert, coordinates.tiles_x + 16 + (coordinates.x * 64), coordinates.tiles_y + 16 + (coordinates.y * 64));
}

void	put_asked_coilhead(t_coordinates *coordinates)
{
	if (coordinates->coilhead.go_up == 1)
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_back, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
	else if (coordinates->coilhead.go_left == 1)
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_left, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
	else if (coordinates->coilhead.go_down == 1)
	{
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_front, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
	}
	else if (coordinates->coilhead.go_right == 1)
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_right, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
	else
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_front, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
}


void put_asked_exit(t_coordinates *coordinates)
{
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 't')
	{
		if (coordinates->nb_obj_take == coordinates->nb_obj_in)
		{
			if (coordinates->door_look_far == 1)
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_smile, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + (coordinates->y * 64));
			else
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_open, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + (coordinates->y * 64));
		}
		else
			mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_close, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + (coordinates->y * 64));
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'm')
	{
		if (coordinates->nb_obj_take == coordinates->nb_obj_in)
		{
			if (coordinates->door_look_far == 1)
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_trap_smile, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
			else
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_trap_open, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
		}
		else
			mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_trap_close, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'l')
	{
		if (coordinates->nb_obj_take == coordinates->nb_obj_in)
		{
			if (coordinates->door_look_far == 1)
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_open, coordinates->tiles_x + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
			else
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_smile, coordinates->tiles_x + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
		}
		else
			mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_close, coordinates->tiles_x + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'r')
	{
		if (coordinates->nb_obj_take == coordinates->nb_obj_in)
		{
			if (coordinates->door_look_far == 1)
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_smile, coordinates->tiles_x + 32 + (coordinates->x * 64), coordinates->tiles_y + (coordinates->y * 64));
			else
				mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_open, coordinates->tiles_x + 32 + (coordinates->x * 64), coordinates->tiles_y + (coordinates->y * 64));
		}
		else
			mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.exit_door_close, coordinates->tiles_x + 32 + (coordinates->x * 64), coordinates->tiles_y + (coordinates->y * 64));
	}
}

void put_asked_hero(t_coordinates *coordinates)
{
	put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
	put_asked_exit(coordinates);
	put_asked_object(*coordinates);
	if (coordinates->player_look.up == 1)
	{
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_back, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
		look_up(coordinates);
	}
	if (coordinates->player_look.down == 1)
	{
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_front, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
		look_down(coordinates);
	}
	if (coordinates->player_look.left == 1)
	{
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_left, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
		look_left(coordinates);
	}
	if (coordinates->player_look.right == 1)
	{
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_right, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
		look_right(coordinates);
	}

}

void put_asked_image(char **tab_tiles, t_coordinates coordinates, t_tiles tiles)
{
	if (tab_tiles[coordinates.y][coordinates.x] == 'H')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_H, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'Z')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_Z, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'X')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_X, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'a')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_a, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'b')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_b, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'l')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_l, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'L')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_L, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == '_')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == '7')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_7, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'K')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_K, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'T')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_T, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'U')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_U, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == ']')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_c_left, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'c')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_c, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));
	if (tab_tiles[coordinates.y][coordinates.x] == 'n')
		mlx_put_image_to_window(coordinates.mlx, coordinates.win, tiles.hall_n, coordinates.tiles_x + (coordinates.x * 64), coordinates.tiles_y + (coordinates.y * 64));

	//personnage/objet/exit
}
void put_shadow(t_coordinates coordinates)
{
	size_t y;
	size_t x;

	y = 0;
	while(y < coordinates.l)
	{
		x = 0;
		while (x < coordinates.c)
		{
			mlx_put_image_to_window(coordinates.mlx, coordinates.win, coordinates.tiles.shadow, coordinates.tiles_x + (64 * x), coordinates.tiles_y + (64 * y));
			x++;
		}
		y++;
	}
}

void put_img_base(t_coordinates *coordinates, t_tiles tiles)
{
	size_t y;
	size_t x;

	coordinates->tiles_y = 64;
	coordinates->tiles_x = 0;
	y = 0;
	while(y < coordinates->l)
	{
		x = 0;
		while (x < coordinates->c)
		{
			mlx_put_image_to_window(coordinates->mlx, coordinates->win, tiles.wall, coordinates->tiles_x + (64 * x), coordinates->tiles_y + (64 * y));
			x++;
		}
		y++;
	}
	x = 0;
	while (x < coordinates->c)
	{
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, tiles.hall_hide, coordinates->tiles_x + (64 * x), 0);
		x++;
	}
}
