#include "header.h"

void put_img_base(size_t l, size_t c, t_coordinates *coordinates, t_tiles tiles)
{
    size_t y;
    size_t x;

    coordinates->tiles_y = 0;
    coordinates->tiles_x = 0;
    y = 0;
    while(y < l)
    {
        x = 0;
        while (x < c)
        {
            mlx_put_image_to_window(coordinates->mlx, coordinates->win, tiles.wall, coordinates->tiles_x + (64 * x), coordinates->tiles_y + (64 * y));
            x++;
        }
        y++;
    }
}