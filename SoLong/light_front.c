#include "header.h"

void look_up(t_coordinates coordinates)
{
    if(coordinates.tab.tab_tiles[coordinates.y - 1][coordinates.x] != '1')
    {
        coordinates.y--;//on va voir si en face c possible ;
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x + 1] != '1')
        {
            coordinates.x++;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.x--;
        }
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x - 1] != '1')
        {
            coordinates.x--;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.x++;
        }
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x] != '1')
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
        coordinates.y++;
    }
}

void look_left(t_coordinates coordinates)
{
    if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x - 1] != '1')
    {
        coordinates.x--;//on va voir si en face c possible ;
        if(coordinates.tab.tab_tiles[coordinates.y + 1][coordinates.x] != '1')
        {
            coordinates.y++;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.y--;
        }
        if(coordinates.tab.tab_tiles[coordinates.y - 1][coordinates.x] != '1')
        {
            coordinates.y--;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.y++;
        }
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x] != '1')
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
        coordinates.x++;
    }
}

void look_down(t_coordinates coordinates)
{
    if(coordinates.tab.tab_tiles[coordinates.y + 1][coordinates.x] != '1')
    {
        coordinates.y++;//on va voir si en face c possible ;
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x + 1] != '1')
        {
            coordinates.x++;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.x--;
        }
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x - 1] != '1')
        {
            coordinates.x--;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.x++;
        }
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x] != '1')
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
        coordinates.y--;
    }
}

void look_right(t_coordinates coordinates)
{
    if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x +1] != '1')
    {
        coordinates.x++;//on va voir si en face c possible ;
        if(coordinates.tab.tab_tiles[coordinates.y + 1][coordinates.x] != '1')
        {
            coordinates.y++;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.y--;
        }
        if(coordinates.tab.tab_tiles[coordinates.y - 1][coordinates.x] != '1')
        {
            coordinates.y--;
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
            coordinates.y++;
        }
        if(coordinates.tab.tab_tiles[coordinates.y][coordinates.x] != '1')
            put_asked_image(coordinates.tab.tab_tiles, coordinates, coordinates.tiles);
        coordinates.x--;
    }
}