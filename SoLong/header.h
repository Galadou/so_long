#ifndef HEADER_H
#define HEADER_H

#include "MacroLibX/includes/mlx.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/libft.h"
#include "libft/includes/ftprintf.h"

#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct s_found_loot_exit
{
    int c;
    int e;
}t_loot_exit;

typedef struct s_tab
{
	char **tab_0_1;
	char **tab_tiles;
}t_tab;

typedef struct s_tiles
{
    void* hall_H;
    void* hall_Z;
    void* hall_X;
	void* hall_a;
	void* hall_b;
	void* hall_l;
	void* hall_L; 
	void* hall_;
	void* hall_7; 
	void* hall_K;
	void* hall_T;
	void* hall_U;
	void* hall_c_left; 
	void* hall_c;
	void* hall_n;
	void* wall;

	void* p_left;
	void* p_right;
	void* p_back;
	void* p_front;
}t_tiles;

typedef struct s_player_look
{
	int up;
	int down;
	int left;
	int right;
}t_player_look;

typedef struct coordinates
{
    void *mlx;
    void *win;
    int tiles_y;
    int tiles_x;

    int img_width;
    int img_height;
	int y;
	int x;

	t_player_look player_look;
	t_tiles tiles;
	t_tab tab;

}t_coordinates;

void game(t_coordinates coordinates);
int window_view_and_game(int l, int c, t_coordinates coordinates);
char **tab_creator(char *map_ber, int l, int c);
void tab_transform_for_tiles(char **tab);

//Les verifications
int verif_map(char *map_ber, size_t *l, size_t *c);
int is_dotber(char *map_ber);
int verif_rectangle(char *map_ber, size_t *l, size_t *c);
int verif_one_and_zero(char **tab, int l, int c, int *C);
int verif_player_can_exit(char **tab, int C);

//fermeture de la fenetre
int key_hook(int key, void* param);
int window_hook(int event, void* param);
void put_asked_image(char **tab_tiles, t_coordinates coordinates, t_tiles tiles);
void destroy_img(t_tiles *tiles, t_coordinates coordinates);
void destroy_hero(t_coordinates *coordinates);

//la lumiere en face du mec
void look_up(t_coordinates coordinates);
void look_left(t_coordinates coordinates);
void look_down(t_coordinates coordinates);
void look_right(t_coordinates coordinates);

// mettretoute le image noir
void put_img_base(size_t l, size_t c, t_coordinates *coordinates, t_tiles tiles);

void    define_img(int img_height, int img_width, t_tiles *tiles, t_coordinates coordinates);
void	define_player_look(t_coordinates *coordinates);

#include <stdio.h>

#endif