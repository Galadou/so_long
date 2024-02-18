#include "header.h"


static void update_coilhead_up(t_coordinates *coordinates)
{
	if (coordinates->player_look.up == 1)
	{
		coordinates->buffer_y = coordinates->y;
		if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1')
		{
			coordinates->y--;//on va voir si en face c possible ;
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x + 1] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y, coordinates->x + 1);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y, coordinates->x - 1);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1' && coordinates->light == 1)
			{
				coordinates->y--;
				while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				{
					is_coilhead_here(coordinates, coordinates->y, coordinates->x);
					coordinates->y--;
				}
			}
			coordinates->y = coordinates->buffer_y;
		}
	}
}
static void update_coilhead_left(t_coordinates *coordinates)
{
	if (coordinates->player_look.left == 1)
	{
		coordinates->buffer_x = coordinates->x;
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1')
		{
			coordinates->x--;//on va voir si en face c possible ;
			if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y + 1, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y - 1, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1' && coordinates->light == 1)
			{
				coordinates->x--;
				while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				{
					is_coilhead_here(coordinates, coordinates->y, coordinates->x);
					coordinates->x--;
				}
			}
			coordinates->x = coordinates->buffer_x;
		}
	}
}
static void update_coilhead_down(t_coordinates *coordinates)
{
	if (coordinates->player_look.down == 1)
	{
		coordinates->buffer_y = coordinates->y;
		if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1')
		{
			coordinates->y++;//on va voir si en face c possible ;
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x + 1] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y, coordinates->x + 1);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y, coordinates->x - 1);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1' && coordinates->light == 1)
			{
				coordinates->y++;
				while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				{
					is_coilhead_here(coordinates, coordinates->y, coordinates->x);
					coordinates->y++;
				}
			}
			coordinates->y = coordinates->buffer_y;
		}
	}
}
static void update_coilhead_right(t_coordinates *coordinates)
{
	if (coordinates->player_look.right == 1)
	{
		coordinates->buffer_x = coordinates->x;
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x +1] != '1')
		{
			coordinates->x++;//on va voir si en face c possible ;
			if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y + 1, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1' && coordinates->light == 1)
				is_coilhead_here(coordinates, coordinates->y - 1, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x + 1] != '1' && coordinates->light == 1)
			{
				coordinates->x++;
				while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
				{
					is_coilhead_here(coordinates, coordinates->y, coordinates->x);
					coordinates->x++;
				}
			}
			coordinates->x = coordinates->buffer_x;
		}
	}
}


int update(void* param)
{
	t_coordinates *coordinates;

	coordinates = (t_coordinates *) param;
	coordinates->times = time(NULL);
	//si le monstre est sur le joueur
	if (coordinates->player_dead == 1)
		kill_player(coordinates);
	if (coordinates->x == coordinates->coilhead.x && coordinates->y == coordinates->coilhead.y)
	{
		destroy_hero(coordinates);
		destroy_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.obj_t_grise, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
		coordinates->player_dead = 1;
	}

	if (coordinates->i == 0)
		coordinates->times_buf = time(NULL);
	if (coordinates->times == coordinates->times_buf + 1)
		coordinates->i++;
	//printf("%d\n", coordinates->i);
	if (coordinates->times == coordinates->times_buf + 2 && coordinates->i > 1)
	{
		//printf("%ld\n", coordinates->times);
		//printf("%ld\n", coordinates->times_buf);
		coordinates->mid_second = coordinates->i / 5;
		//printf("%d = mid\n", coordinates->mid_second);
		//printf("%d = i\n", coordinates->i);
		coordinates->i = 1;
	}
	if (coordinates->times > coordinates->times_buf + 2)
		coordinates->i++;
	if (coordinates->i == coordinates->mid_second)
	{
		coordinates->coilhead.can_moove = 1;
		coordinates->i = 1;
	}
	if (coordinates->coilhead.can_moove == 1 && coordinates->coilhead.see_coilhead == 0)
	{
		coordinates->i = 1;
		coordinates->coilhead.can_moove = 0;
		coordinates->one_time = coordinates->times;
		coilhead_moove(coordinates);
	}

//a bouger potentiellement
if (coordinates->coilhead.go_down == 1)
	head_moove_down(coordinates);
if (coordinates->coilhead.go_up == 1)
	head_moove_up(coordinates);
	//if (coordinates->coilhead.frame == 1 && coordinates->coilhead.go_down == 1 && coordinates->times % )


if (coordinates->coilhead.see_coilhead == 0)
{
	update_coilhead_up(coordinates);
	update_coilhead_left(coordinates);
	update_coilhead_right(coordinates);
	update_coilhead_down(coordinates);
}
	return (0);
}
