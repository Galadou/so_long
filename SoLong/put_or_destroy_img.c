#include "header.h"

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
    mlx_destroy_image(coordinates.mlx, tiles->p_left);
    mlx_destroy_image(coordinates.mlx, tiles->p_right);
    mlx_destroy_image(coordinates.mlx, tiles->p_back);
    mlx_destroy_image(coordinates.mlx, tiles->p_front);
}
void destroy_hero(t_coordinates *coordinates)
{
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_left);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_right);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_back);
    mlx_destroy_image(coordinates->mlx, coordinates->tiles.p_front);
}
