#include "header.h"

int key_hook(int key, void* param)
{
    t_coordinates *coordinates;

    coordinates = (t_coordinates *) param;
    if(key == 41) // 41 is the key code for escape
        mlx_loop_end(param); // if escape is pressed we stop the mlx_loop and so we continue in the main function
    if (key == SDL_SCANCODE_W)
    {
        if (coordinates->player_look.up != 1)
        {
            define_player_look(coordinates);
            coordinates->player_look.up = 1;
            destroy_hero(coordinates);
            define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
            look_up(*coordinates);
            mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_back, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
        }
        else if (coordinates->player_look.up == 1)
        {
            if (coordinates->tab.tab_0_1[coordinates->y - 1][coordinates->x] != '1')
            {
                coordinates->y = coordinates->y - 1;
                destroy_hero(coordinates);
                define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
                look_up(*coordinates);
                mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_back, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
            }
        }
    }
    if (key == SDL_SCANCODE_S)
    {
        if (coordinates->player_look.down != 1)
        {
            define_player_look(coordinates);
            coordinates->player_look.down = 1;
            destroy_hero(coordinates);
            define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
            look_down(*coordinates);
            mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_front, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
        }
        else if (coordinates->player_look.down == 1)
        {
            if (coordinates->tab.tab_0_1[coordinates->y + 1][coordinates->x] != '1')
            {
                coordinates->y = coordinates->y + 1;
                destroy_hero(coordinates);
                define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
                look_down(*coordinates);
                mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_front, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
            }
        }
    }
    if (key == SDL_SCANCODE_A)
    {
        if (coordinates->player_look.left != 1)
        {
            define_player_look(coordinates);
            coordinates->player_look.left = 1;
            destroy_hero(coordinates);
            define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
            look_left(*coordinates);
            mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_left, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
        }
        else if (coordinates->player_look.left == 1)
        {
            if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x - 1] != '1')
            {
                coordinates->x = coordinates->x - 1;
                destroy_hero(coordinates);
                define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
                look_left(*coordinates);
                mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_left, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
            }
        }
    }
    if (key == SDL_SCANCODE_D)
    {
        if (coordinates->player_look.right != 1)
        {
            define_player_look(coordinates);
            coordinates->player_look.right = 1;
            destroy_hero(coordinates);
            define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
            look_right(*coordinates);
            mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_right, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
        }
        else if (coordinates->player_look.right == 1)
        {
            if (coordinates->tab.tab_0_1[coordinates->y][coordinates->x + 1] != '1')
            {
                coordinates->x = coordinates->x + 1;
                destroy_hero(coordinates);
                define_img(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
                look_right(*coordinates);
                mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_right, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
            }
        }
    }
    return (0);
}

int window_hook(int event, void* param)
{
    t_coordinates *coordinates;

    coordinates = (t_coordinates *) param;
    if(event == 0) // 0 is when we trigger the close of the window (by clicking the cross for example)
        mlx_loop_end(coordinates->mlx);
    return (0);
}
