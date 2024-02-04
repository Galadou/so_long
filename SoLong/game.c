
#include "header.h"

static void find_p(t_coordinates *coordinates, char **tab_0_1)
{
    coordinates->y = 0;
    coordinates->x = 0;
    while(tab_0_1[coordinates->y][coordinates->x] != 'P')
    {
        coordinates->x = 0;
        while (tab_0_1[coordinates->y][coordinates->x])
        {
            if(tab_0_1[coordinates->y][coordinates->x] == 'P')
                break; 
            coordinates->x = coordinates->x + 1;
        }
        if (tab_0_1[coordinates->y][coordinates->x] == '\0')
            coordinates->y = coordinates->y + 1;
    }
}

void init_player(char **tab_0_1, char **tab_tiles, t_coordinates *coordinates, t_tiles tiles)
{
    //on trouve la pos du joueur
    find_p(coordinates, tab_0_1);
    //on affiche la case du joueur et sa position
    put_asked_image(tab_tiles, *coordinates, tiles);//sa case
    mlx_put_image_to_window(coordinates->mlx, coordinates->win, tiles.p_left, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
    // j'affiche les 3 potentielle case devant lui :
    if(tab_tiles[coordinates->y][coordinates->x - 1] != '1')
    {
        coordinates->x--;//on va voir si en face c possible ;
        if(tab_tiles[coordinates->y + 1][coordinates->x] != '1')
        {
            coordinates->y++;
            put_asked_image(tab_tiles, *coordinates, tiles);
            coordinates->y--;
        }
        if(tab_tiles[coordinates->y - 1][coordinates->x] != '1')
        {
            coordinates->y--;
            put_asked_image(tab_tiles, *coordinates, tiles);
            coordinates->y++;
        }
        if(tab_tiles[coordinates->y][coordinates->x] != '1')
            put_asked_image(tab_tiles, *coordinates, tiles);
        coordinates->x++;
    }
}

void game(t_coordinates coordinates)
{  
    //on defini la diretion du regard du joueur
    define_player_look(&coordinates);
    coordinates.player_look.left = 1;
    //on fait les event enfonction des touches
	mlx_on_event(coordinates.mlx, coordinates.win, MLX_KEYDOWN, key_hook, &coordinates);
	mlx_on_event(coordinates.mlx, coordinates.win, MLX_WINDOW_EVENT, window_hook, &coordinates);



    mlx_loop(coordinates.mlx);
}

int window_view_and_game(int l, int c, t_coordinates coordinates)
{
	coordinates.mlx = mlx_init();
    coordinates.win = mlx_new_window(coordinates.mlx, 64 *c, 64 * l, "So_Long");
    //coordinates.img_width = 1;
    //coordinates.img_height = 1;
    //on defini les images
    define_img(coordinates.img_height,coordinates.img_width, &coordinates.tiles, coordinates);
    //on affiche les image de base
    put_img_base(l, c, &coordinates, coordinates.tiles);
    //on initialise le joueur et les case devant lui
    init_player(coordinates.tab.tab_0_1, coordinates.tab.tab_tiles, &coordinates, coordinates.tiles);

    //en fonction des touche il se passe des choses(mlx_loop)
	game(coordinates);


    
    //mlx_loop_end(coordinates.mlx);
    destroy_hero(&coordinates);
    destroy_img(&coordinates.tiles, coordinates);
	mlx_destroy_window(coordinates.mlx,coordinates.win);
   	mlx_destroy_display(coordinates.mlx);
	return (0);
}
