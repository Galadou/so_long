#include "header.h"


void	is_coilhead_here(t_coordinates *coordinates, int y, int x)
{
	if (coordinates->coilhead.x == x && coordinates->coilhead.y == y)
	{
		coordinates->coilhead.see_coilhead = 1;
		coordinates->coilhead.last_seen_player_y = coordinates->buffer_y;
		coordinates->coilhead.last_seen_player_x = coordinates->buffer_x;
		destroy_monster(coordinates);
		define_monster(coordinates);
		put_asked_coilhead(coordinates);
	}
}

void	coilhead_moove(t_coordinates *coordinates)
{
	//si lq derniere pos du joueur est en haut
	if (coordinates->coilhead.last_seen_player_y < coordinates->coilhead.y)
	{
		coordinates->coilhead.y--;
		define_coilhead_go(coordinates);
		coordinates->coilhead.go_up = 1;
		coordinates->coilhead.has_moove = 1;
	}
	else if (coordinates->coilhead.last_seen_player_y > coordinates->coilhead.y)
	{
		coordinates->coilhead.y++;
		define_coilhead_go(coordinates);
		coordinates->coilhead.go_down = 1;
		coordinates->coilhead.has_moove = 1;
	}
	else if (coordinates->coilhead.last_seen_player_x < coordinates->coilhead.x)
	{
		coordinates->coilhead.x--;
		define_coilhead_go(coordinates);
		coordinates->coilhead.go_left = 1;
		coordinates->coilhead.has_moove = 1;
	}
	else if (coordinates->coilhead.last_seen_player_x > coordinates->coilhead.x)
	{
		coordinates->coilhead.x++;
		define_coilhead_go(coordinates);
		coordinates->coilhead.go_right = 1;
		coordinates->coilhead.has_moove = 1;
	}
}

void	head_moove_down(t_coordinates *coordinates)
{
	if (coordinates->coilhead.frame == 5 || (coordinates->coilhead.frame && coordinates->coilhead.see_coilhead == 0))
		coordinates->coilhead.frame = 0;

	if(coordinates->coilhead.has_moove == 1 && coordinates->coilhead.see_coilhead == 1)
	{
		coordinates->coilhead.has_moove = 0;
		coordinates->coilhead.frame++;
	}


	if (coordinates->coilhead.frame == 1)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_front_left, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 1\n");
	}
	else if (coordinates->coilhead.frame == 2 && coordinates->i == coordinates->mid_second / 2)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_front, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 2\n");
	}
	else if (coordinates->coilhead.frame == 3 && coordinates->i == coordinates->mid_second - 1)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_front_right, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 3\n");
	}
	else if (coordinates->coilhead.frame == 4 && coordinates->i == coordinates->mid_second / 3)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_front, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 4\n");
	}
}

void	head_moove_up(t_coordinates *coordinates)
{
	if (coordinates->coilhead.frame == 5 || (coordinates->coilhead.frame && coordinates->coilhead.see_coilhead == 0))
		coordinates->coilhead.frame = 0;

	if(coordinates->coilhead.has_moove == 1 && coordinates->coilhead.see_coilhead == 1)
	{
		coordinates->coilhead.has_moove = 0;
		coordinates->coilhead.frame++;
	}
	if (coordinates->coilhead.frame == 1)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_back_left, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 1\n");
	}
	else if (coordinates->coilhead.frame == 2 && coordinates->i == coordinates->mid_second / 2)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_back, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 2\n");
	}
	else if (coordinates->coilhead.frame == 3 && coordinates->i == coordinates->mid_second - 1)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_back_right, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 3\n");
	}
	else if (coordinates->coilhead.frame == 4 && coordinates->i == coordinates->mid_second / 3)
	{
		destroy_monster(coordinates);
		define_monster(coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.m_coil_back, coordinates->tiles_x + (coordinates->coilhead.x * 64), coordinates->tiles_y + (coordinates->coilhead.y * 64));
		coordinates->coilhead.frame++;
		//ft_printf("frame 4\n");
	}
}
