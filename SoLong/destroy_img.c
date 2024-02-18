#include "header.h"

void destroy_img(t_tiles *tiles, t_coordinates coordinates)
{
    mlx_destroy_image(coordinates.mlx, tiles->hall_H);
    mlx_destroy_image(coordinates.mlx, tiles->hall_Z);
    mlx_destroy_image(coordinates.mlx, tiles->hall_X);
    mlx_destroy_image(coordinates.mlx, tiles->hall_a);
    mlx_destroy_image(coordinates.mlx, tiles->hall_b);
    mlx_destroy_image(coordinates.mlx, tiles->hall_l);
    mlx_destroy_image(coordinates.mlx, tiles->hall_L);
    mlx_destroy_image(coordinates.mlx, tiles->hall_);
    mlx_destroy_image(coordinates.mlx, tiles->hall_7);
    mlx_destroy_image(coordinates.mlx, tiles->hall_K);
    mlx_destroy_image(coordinates.mlx, tiles->hall_T);
    mlx_destroy_image(coordinates.mlx, tiles->hall_U);
    mlx_destroy_image(coordinates.mlx, tiles->hall_c);
    mlx_destroy_image(coordinates.mlx, tiles->hall_c_left);
    mlx_destroy_image(coordinates.mlx, tiles->hall_n);
    mlx_destroy_image(coordinates.mlx, tiles->wall);
    mlx_destroy_image(coordinates.mlx, tiles->shadow);
    mlx_destroy_image(coordinates.mlx, tiles->hall_hide);
}
void destroy_exit(t_coordinates *coordinates)
{
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.exit_door_close);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.exit_door_open);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.exit_door_smile);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.exit_trap_close);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.exit_trap_open);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.exit_trap_smile);
}

void destroy_hero(t_coordinates *coordinates)
{
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_left);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_right);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_back);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_front);
}
void destroy_object(t_coordinates *coordinates)
{
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_light);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_beer_cub_brown);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_beer_cub_blue);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_beer_cub_green);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_beer_cub_korgeister);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_key);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_mask);

    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_t_bleu);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_t_grise);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_t_jaune);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_t_vert);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.obj_t_sang);

}

void	destroy_monster(t_coordinates *coordinates)
{
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_front);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_front_left);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_front_right);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_back);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_back_left);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_back_right);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_left);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_coil_right);

    mlx_destroy_image(coordinates->mlx, coordinates->tiles.m_little_girl);
}
