
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

void init_player(char **tab_0_1, t_coordinates *coordinates, t_tiles tiles)
{
	//on trouve la pos du joueur
	find_p(coordinates, tab_0_1);
	coordinates->player_look.left = 1;
	//on affiche la case du joueur et sa position
	mlx_put_image_to_window(coordinates->mlx, coordinates->win, tiles.p_left, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));
	put_asked_hero(coordinates);
}



/*
	{
		//if il regarde vers le haut, image diiferente pour le haut etc
		destroy_hero(coordinates);
		define_hero(coordinates->img_height,coordinates->img_width, &coordinates->tiles, *coordinates);
		mlx_put_image_to_window(coordinates->mlx, coordinates->win, coordinates->tiles.p_back, coordinates->tiles_x + 16 + (coordinates->x * 64), coordinates->tiles_y + 16 + (coordinates->y * 64));

		//autre if
		//etc
	}*/

void game(t_coordinates coordinates)
{
	//on defini la diretion du regard du joueur
	define_player_look(&coordinates);
	coordinates.player_look.left = 1;
	//on fait les event enfonction des touches

	mlx_on_event(coordinates.mlx, coordinates.win, MLX_KEYDOWN, key_hook, &coordinates);
	mlx_on_event(coordinates.mlx, coordinates.win, MLX_WINDOW_EVENT, window_hook, &coordinates);
	mlx_loop_hook(coordinates.mlx, update, &coordinates);

	mlx_loop(coordinates.mlx);
}

int window_view_and_game(t_coordinates coordinates)
{
	coordinates.mlx = mlx_init();
	coordinates.win = mlx_new_window(coordinates.mlx, 64 * coordinates.c, 64 * coordinates.l + 64, "So_Long");

	//on defini les images
	define_img(coordinates.img_height,coordinates.img_width, &coordinates.tiles, coordinates);
	define_hero(coordinates.img_height,coordinates.img_width, &coordinates.tiles, coordinates);
	define_object(&coordinates);
	define_exit(&coordinates);
	define_count(&coordinates);
	define_monster(&coordinates);
	//on affiche les image de base
	put_img_base(&coordinates, coordinates.tiles);
	put_shadow(coordinates);
	//on initialise le joueur et les case devant lui
	init_player(coordinates.tab.tab_0_1, &coordinates, coordinates.tiles);

	/* int i;
    int j;
    ft_printf("\n");
	i = 0;
	 while (coordinates.tab.tab_dup_monsterspawn[i])
    {
        j = 0;
        while (coordinates.tab.tab_dup_monsterspawn[i][j])
        {
           ft_printf("%c", coordinates.tab.tab_dup_monsterspawn[i][j]);
           j++;
        }
        ft_printf("\n");
        i++;
    }
    ft_printf("\n DANS GAME");*/

	monster_spawn(&coordinates);


   /* ft_printf("\n");
	i = 0;
	 while (coordinates.tab.tab_dup_monsterspawn[i])
    {
        j = 0;
        while (coordinates.tab.tab_dup_monsterspawn[i][j])
        {
           ft_printf("%c", coordinates.tab.tab_dup_monsterspawn[i][j]);
           j++;
        }
        ft_printf("\n");
        i++;
    }
	ft_printf("\n APRES MONSTERSPAWN");*/


	//en fonction des touche il se passe des choses(mlx_loop)
	game(coordinates);



	//mlx_loop_end(coordinates.mlx);
	destroy_hero(&coordinates);
	destroy_img(&coordinates.tiles, coordinates);
	destroy_object(&coordinates);
	destroy_exit(&coordinates);
	destroy_monster(&coordinates);
	mlx_destroy_window(coordinates.mlx,coordinates.win);
	mlx_destroy_display(coordinates.mlx);
	return (0);
}
