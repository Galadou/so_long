#include "header.h"

void    define_img(int img_height, int img_width, t_tiles *tiles, t_coordinates coordinates)
{
    tiles->hall_H = mlx_png_file_to_image(coordinates.mlx, "tiles/front_back/hall_H.png", &img_width, &img_height);
    tiles->hall_Z = mlx_png_file_to_image(coordinates.mlx, "tiles/front_back/hall_Z.png", &img_width, &img_height);
    tiles->hall_X = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_O.png", &img_width, &img_height);
	tiles->hall_a = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_>.png", &img_width, &img_height);
	tiles->hall_b = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_<.png", &img_width, &img_height);
	tiles->hall_l = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_l.png", &img_width, &img_height);
	tiles->hall_L = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_L.png", &img_width, &img_height);
	tiles->hall_ = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/_.png", &img_width, &img_height);
	tiles->hall_7 = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/7.png", &img_width, &img_height);
	tiles->hall_K = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/K.png", &img_width, &img_height);
	tiles->hall_T = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/T.png", &img_width, &img_height);
	tiles->hall_U = mlx_png_file_to_image(coordinates.mlx, "tiles/u/U.png", &img_width, &img_height);
	tiles->hall_c_left = mlx_png_file_to_image(coordinates.mlx, "tiles/u/].png", &img_width, &img_height);
	tiles->hall_c = mlx_png_file_to_image(coordinates.mlx, "tiles/u/c.png", &img_width, &img_height);
	tiles->hall_n = mlx_png_file_to_image(coordinates.mlx, "tiles/u/n.png", &img_width, &img_height);
    tiles->wall = mlx_png_file_to_image(coordinates.mlx, "tiles/wall.png", &img_width, &img_height);
    tiles->p_left = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_left.png", &img_width, &img_height);
    tiles->p_right = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_right.png", &img_width, &img_height);
    tiles->p_back = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_back.png", &img_width, &img_height);
    tiles->p_front = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_front.png", &img_width, &img_height);
}

void	define_player_look(t_coordinates *coordinates)
{
	coordinates->player_look.up = 0;
	coordinates->player_look.down = 0;
	coordinates->player_look.left = 0;
	coordinates->player_look.right = 0;
}
