#include "header.h"

void look_up(t_coordinates *coordinates)
{
	coordinates->buffer_x = coordinates->x;
	coordinates->buffer_y = coordinates->y;
	if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1')
	{
		coordinates->y--;//on va voir si en face c possible ;
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x + 1] != '1' && coordinates->light == 1)
		{
			coordinates->x++;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->x--;
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1' && coordinates->light == 1)
		{
			coordinates->x--;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->x++;
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
		{
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
		}
		if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1' && coordinates->light == 1)
		{
			coordinates->y--;
			while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
			{
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
				is_obj_here(coordinates);
				is_exit_here(coordinates);
				if (coordinates->exit_here == 1 && coordinates->door_look_far == 0 && coordinates->nb_obj_take == coordinates->nb_obj_in)
					coordinates->door_look_far = 1;
				else
					coordinates->door_look_far = 0;
				put_asked_exit(coordinates);
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
				coordinates->y--;
			}
		}
		coordinates->door_look_far = 0;
		coordinates->y = coordinates->buffer_y;
	}
}

void look_left(t_coordinates *coordinates)
{
	coordinates->buffer_x = coordinates->x;
	coordinates->buffer_y = coordinates->y;
	if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1')
	{
		coordinates->x--;//on va voir si en face c possible ;
		if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1' && coordinates->light == 1)
		{
			coordinates->y++;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->y--;
		}
		if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1' && coordinates->light == 1)
		{
			coordinates->y--;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->y++;
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
		{
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1' && coordinates->light == 1)
		{
			coordinates->x--;
			while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
			{
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
				is_obj_here(coordinates);
				is_exit_here(coordinates);
				if (coordinates->exit_here == 1 && coordinates->door_look_far == 0 && coordinates->nb_obj_take == coordinates->nb_obj_in)
					coordinates->door_look_far = 1;
				else
					coordinates->door_look_far = 0;
				put_asked_exit(coordinates);
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
				coordinates->x--;
			}
		}
		coordinates->door_look_far = 0;
		coordinates->x = coordinates->buffer_x;
	}
}

void look_down(t_coordinates *coordinates)
{
	coordinates->buffer_x = coordinates->x;
	coordinates->buffer_y = coordinates->y;
	if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1')
	{
		coordinates->y++;//on va voir si en face c possible ;
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x + 1] != '1' && coordinates->light == 1)
		{
			coordinates->x++;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->x--;
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x - 1] != '1' && coordinates->light == 1)
		{
			coordinates->x--;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->x++;
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
		{
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
		}
		if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1' && coordinates->light == 1)
		{
			coordinates->y++;
			while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
			{
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
				is_obj_here(coordinates);
				is_exit_here(coordinates);
				if (coordinates->exit_here == 1 && coordinates->door_look_far == 0 && coordinates->nb_obj_take == coordinates->nb_obj_in)
					coordinates->door_look_far = 1;
				else
					coordinates->door_look_far = 0;
				put_asked_exit(coordinates);
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
				coordinates->y++;
			}
		}
		coordinates->door_look_far = 0;
		coordinates->y = coordinates->buffer_y;
	}
}

void look_right(t_coordinates *coordinates)
{
	coordinates->buffer_x = coordinates->x;
	coordinates->buffer_y = coordinates->y;
	if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x +1] != '1')
	{
		coordinates->x++;//on va voir si en face c possible ;
		if(coordinates->tab.tab_tiles[coordinates->y + 1][coordinates->x] != '1' && coordinates->light == 1)
		{
			coordinates->y++;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->y--;
		}
		if(coordinates->tab.tab_tiles[coordinates->y - 1][coordinates->x] != '1' && coordinates->light == 1)
		{
			coordinates->y--;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
			coordinates->y++;
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
		{
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			is_obj_here(coordinates);
			put_asked_exit(coordinates);
			is_coilhead_here(coordinates, coordinates->y, coordinates->x);
		}
		if(coordinates->tab.tab_tiles[coordinates->y][coordinates->x + 1] != '1' && coordinates->light == 1)
		{
			coordinates->x++;
			while (coordinates->tab.tab_tiles[coordinates->y][coordinates->x] != '1')
			{
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
				is_obj_here(coordinates);
				is_exit_here(coordinates);
				if (coordinates->exit_here == 1 && coordinates->door_look_far == 0 && coordinates->nb_obj_take == coordinates->nb_obj_in)
					coordinates->door_look_far = 1;
				else
					coordinates->door_look_far = 0;
				put_asked_exit(coordinates);
				is_coilhead_here(coordinates, coordinates->y, coordinates->x);
				coordinates->x++;
			}
		}
		coordinates->door_look_far = 0;
		coordinates->x = coordinates->buffer_x;
	}
}
