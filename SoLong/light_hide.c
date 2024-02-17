#include "header.h"

void	hide_tiles_light(t_coordinates *coordinates)
{
	if (coordinates->player_look.up == 1)
		hide_tiles_light_up(coordinates);
	else if (coordinates->player_look.down == 1)
		hide_tiles_light_down(coordinates);
	else if (coordinates->player_look.left == 1)
		hide_tiles_light_left(coordinates);
	else if (coordinates->player_look.right == 1)
		hide_tiles_light_right(coordinates);
}



void	hide_tiles_light_up(t_coordinates *coordinates)
{
	int buffer_x;
	int buffer_y;

	buffer_x = coordinates->x;
	buffer_y = coordinates->y;
		if (coordinates->player_look.up == 1 && coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1')
		{
			coordinates->y--;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1')
			{
				coordinates->x--;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->x = buffer_x;
			if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1')
			{
				coordinates->x++;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->x = buffer_x;
			if (coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1')
			{
				coordinates->y--;
				while (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1')
				{
					put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
					coordinates->y--;
				}
			}
			coordinates->x = buffer_x;
			coordinates->y = buffer_y;
		}
}

void	hide_tiles_light_down(t_coordinates *coordinates)
{
	int buffer_x;
	int buffer_y;

	buffer_x = coordinates->x;
	buffer_y = coordinates->y;
		if (coordinates->player_look.down == 1 && coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1')
		{
			coordinates->y++;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1')
			{
				coordinates->x--;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->x = buffer_x;
			if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1')
			{
				coordinates->x++;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->x = buffer_x;
			if (coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1')
			{
				coordinates->y++;
				while (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1')
				{
					put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
					coordinates->y++;
				}
			}
			coordinates->x = buffer_x;
			coordinates->y = buffer_y;
		}
}

void	hide_tiles_light_left(t_coordinates *coordinates)
{
	int buffer_x;
	int buffer_y;

	buffer_x = coordinates->x;
	buffer_y = coordinates->y;
		if (coordinates->player_look.left == 1 && coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1')
		{
			coordinates->x--;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1')
			{
				coordinates->y--;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->y = buffer_y;
			if (coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1')
			{
				coordinates->y++;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->y = buffer_y;
			if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1')
			{
				coordinates->x--;
				while (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1')
				{
					put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
					coordinates->x--;
				}
			}
			coordinates->x = buffer_x;
			coordinates->y = buffer_y;
		}
}

void	hide_tiles_light_right(t_coordinates *coordinates)
{
	int buffer_x;
	int buffer_y;

	buffer_x = coordinates->x;
	buffer_y = coordinates->y;
		if (coordinates->player_look.right == 1 && coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1')
		{
			coordinates->x++;
			put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			if (coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1')
			{
				coordinates->y--;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->y = buffer_y;
			if (coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1')
			{
				coordinates->y++;
				put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
			}
			coordinates->y = buffer_y;
			if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1')
			{
				coordinates->x++;
				while (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] != '1')
				{
					put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
					coordinates->x++;
				}
			}
			coordinates->x = buffer_x;
			coordinates->y = buffer_y;
		}
}
