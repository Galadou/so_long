#include "header.h"

void is_obj_here(t_coordinates *coordinates)
{
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'C')
	{
		coordinates->nb_find_obj++;
		//ft_printf("\n%d = obj trouve,    %d = obj total,    %d  =obj pris ", coordinates->nb_find_obj, coordinates->nb_obj_in, coordinates->nb_obj_take);
		//clef
		//coordinates->nb
		if (coordinates->nb_find_obj == coordinates->nb_obj_in)
			coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'K';
		else
		{
			//torche
			if (coordinates->nb_find_obj == 1)
				coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'L';
			//shiny
			if (coordinates->nb_beer_cub_take == 3)
			{
				coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = '*';
				coordinates->nb_beer_cub_take++;
			}
			//ourson
			else
			{
				if (coordinates->nb_find_obj == 4 || coordinates->nb_find_obj == 10 || coordinates->nb_find_obj == 12)
				{
					coordinates->nb_beer_cub++;
					if (coordinates->nb_beer_cub == 1)
						coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'M';
					if (coordinates->nb_beer_cub == 2)
						coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'B';
					if (coordinates->nb_beer_cub == 3)
						coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'V';
				}
				else if (coordinates->nb_find_obj > 1)
				{
					coordinates->nb_head++;
					if (coordinates->nb_head > 3)
						coordinates->nb_head = 1;
					if (coordinates->nb_head == 1)
						coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'b';
					if (coordinates->nb_head == 2)
						coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'j';
					if (coordinates->nb_head == 3)
						coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'v';
				}
			}
		}
	}
	put_asked_object(*coordinates);
}

void take_obj(t_coordinates *coordinates)
{
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'L')
	{
		coordinates->light = 1;
		coordinates->nb_obj_take++;
		mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_light);
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = '0';
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == '*')
	{
		coordinates->nb_obj_take++;
		coordinates->bearKorgeister++;
		mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_beer_cub_korgeister);
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'S';
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'K')
	{
		coordinates->nb_obj_take++;
		mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_key);
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = '0';

	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'b' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'j' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'v')
	{
		coordinates->nb_obj_take++;
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 's';
	}
	if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'M' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'B' ||
	coordinates->tab.tab_0_1[coordinates->y][coordinates->x] == 'V')
	{
		coordinates->nb_obj_take++;
		coordinates->nb_beer_cub_take++;
		//put_asked_image(coordinates->tab.tab_tiles, *coordinates, coordinates->tiles);
		coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = '0';
	}
}
//coordinates->tab.tab_0_1[coordinates->y][coordinates->x] = 'c';
