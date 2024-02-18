#include "header.h"

static void where_coilhead_spawn_recursive(t_coordinates coordinates, t_coilhead *coilhead)
{
	//ft_printf("\n%d = y, %d = x", coilhead->y, coilhead->x);
	//ft_printf("\n%d = far_y, %d = far_x", abs(coordinates.coilhead.far_p_y_buf), abs(coordinates.coilhead.far_p_x_buf));
	if (abs(coordinates.coilhead.far_p_y) + abs(coordinates.coilhead.far_p_x) > abs(coordinates.coilhead.far_p_y_buf) + abs(coordinates.coilhead.far_p_x_buf))
	{
		//ft_printf("je suis entre dans le if");
		coordinates.coilhead.far_p_y_buf = coordinates.coilhead.far_p_y;
		coordinates.coilhead.far_p_x_buf = coordinates.coilhead.far_p_x;
		coilhead->x = coordinates.x;
		coilhead->y = coordinates.y;
		//ft_printf("\n%d = y, %d = x", coordinates.y, coordinates.x);
	}
	coordinates.tab.tab_dup_monsterspawn[coordinates.y][coordinates.x] = '1';
	if (coordinates.tab.tab_dup_monsterspawn[coordinates.y - 1][coordinates.x] != '1')
	{
		coordinates.y--;
		coordinates.coilhead.far_p_y--;
		where_coilhead_spawn_recursive(coordinates, coilhead);
		coordinates.y++;
	}
	if (coordinates.tab.tab_dup_monsterspawn[coordinates.y][coordinates.x - 1] != '1')
	{
		coordinates.x--;
		coordinates.coilhead.far_p_x--;
		where_coilhead_spawn_recursive(coordinates, coilhead);
		coordinates.x++;
	}
	if (coordinates.tab.tab_dup_monsterspawn[coordinates.y + 1][coordinates.x] != '1')
	{
		coordinates.y++;
		coordinates.coilhead.far_p_y++;
		where_coilhead_spawn_recursive(coordinates, coilhead);
		coordinates.y--;
	}
	if (coordinates.tab.tab_dup_monsterspawn[coordinates.y][coordinates.x + 1] != '1')
	{
		coordinates.x++;
		coordinates.coilhead.far_p_x++;
		where_coilhead_spawn_recursive(coordinates, coilhead);
		coordinates.x--;
	}
}

void monster_spawn(t_coordinates *coordinates)
{
	where_coilhead_spawn_recursive(*coordinates, &coordinates->coilhead);
	//mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_front, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
	coordinates->coilhead.last_seen_player_x = coordinates->coilhead.x;
	coordinates->coilhead.last_seen_player_y = coordinates->coilhead.y;
}
