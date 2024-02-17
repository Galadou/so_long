#ifndef HEADER_H
#define HEADER_H

#include "MacroLibX/includes/mlx.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/libft.h"
#include "libft/includes/ftprintf.h"

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>

typedef struct s_found_loot_exit
{
	int	c;
	int	e;
}	t_loot_exit;

typedef struct s_tab
{
	char	**tab_0_1;
	char	**tab_tiles;
	char	**tab_dupp_coilhead_moove_up;
	char	**tab_dupp_coilhead_moove_right;
	char	**tab_dupp_coilhead_moove_left;
	char	**tab_dupp_coilhead_moove_down;
	char	**tab_dupp_coilhead_moove;

	char	**tab_dup_monsterspawn;
}	t_tab;

typedef struct s_coilhead
{
	int	y;
	int	x;

	int	see_coilhead;
	int	last_seen_player_y;
	int	last_seen_player_x;
	int far_p_y;
	int far_p_x;
	int far_p_y_buf;
	int far_p_x_buf;

	int has_moove;
	int frame;
	int can_moove;
/*
	//trouver player
	int h;
	int b;
	int g;
	int d;
	int count_direction_up;
	int count_direction_down;
	int count_direction_left;
	int count_direction_right;*/
	int go_up;
	int go_left;
	int go_down;
	int go_right;

}	t_coilhead;

typedef struct s_tiles
{
    void*	hall_H;
	void*	hall_Z;
	void*	hall_X;
	void*	hall_a;
	void*	hall_b;
	void*	hall_l;
	void*	hall_L;
	void*	hall_;
	void*	hall_7;
	void*	hall_K;
	void*	hall_T;
	void*	hall_U;
	void*	hall_c_left;
	void*	hall_c;
	void*	hall_n;
	void*	wall;
	void*	shadow;

	void*	exit_door_close;
	void*	exit_door_open;
	void*	exit_door_smile;
	void*	exit_trap_close;
	void*	exit_trap_open;
	void*	exit_trap_smile;


	void*	p_left;
	void*	p_right;
	void*	p_back;
	void*	p_front;

	void*	obj_light;
	void*	obj_key;

	void*	obj_t_bleu;
	void*	obj_t_grise;
	void*	obj_t_jaune;
	void*	obj_t_vert;
	void*	obj_t_sang;

	void*	obj_beer_cub_brown;
	void*	obj_beer_cub_blue;
	void*	obj_beer_cub_green;
	void*	obj_beer_cub_korgeister;
	void*	obj_mask;

	void*	m_coil_front;
	void*	m_coil_front_left;
	void*	m_coil_front_right;
	void*	m_coil_back;
	void*	m_coil_back_left;
	void*	m_coil_back_right;
	void*	m_coil_left;
	void*	m_coil_right;
	void*	m_little_girl;

}	t_tiles;

typedef struct s_player_look
{
	int up;
	int down;
	int left;
	int right;
}	t_player_look;

typedef struct coordinates
{
	void	*mlx;
	void	*win;
	int	tiles_y;
	int	tiles_x;

	int	img_width;
	int	img_height;
	int	y;
	int	x;

	int	buffer_y;
	int	buffer_x;

	size_t l;
	size_t c;

	int nb_obj_in;//nombre d'objet dans la map
	int nb_find_obj; //nbr obj trouve
	int nb_obj_take;
	int nb_beer_cub;
	int light;
	//si celui en dessous = 1 alors petite fille ou event mask
	int bearKorgeister;

	int frame;

	t_player_look player_look;
	t_tiles tiles;
	t_tab tab;
	t_coilhead coilhead;
	time_t one_time;
	time_t times;
	time_t times_buf;

//incrementation diverse
	int door_look_far;
	int exit_here;
	int nb_head;
	int nb_beer_cub_take;

	int i;
	int mid_second;
}	t_coordinates;

void	game(t_coordinates coordinates);
int		window_view_and_game(t_coordinates coordinates);
char	**tab_creator(char *map_ber, int l, int c);
void	define_tab(t_coordinates *coordinates, char **argv);
void	tab_transform_for_tiles(char **tab);
void	tab_transform_for_exit(char **tab);

//Les verifications
int verif_map(char *map_ber, size_t *l, size_t *c, t_coordinates *coordinates);
int is_dotber(char *map_ber);
int verif_rectangle(char *map_ber, size_t *l, size_t *c);
int verif_one_and_zero(char **tab, int l, int c, int *C);
int verif_player_can_exit(char **tab, int C);

//fin du jeu
void	can_i_exit(t_coordinates *coordinates);
void	is_exit_here(t_coordinates *coordinates);

//obj
void	is_obj_here(t_coordinates *coordinates);
void	take_obj(t_coordinates *coordinates);

//monstre
void monster_spawn(t_coordinates *coordinates);
void coilhead_moove(t_coordinates *coordinates);
void	is_coilhead_here(t_coordinates *coordinates, int y, int x);
void	head_moove_down(t_coordinates *coordinates);
void	head_moove_up(t_coordinates *coordinates);
void	kill_player(t_coordinates *coordinates);

//autre fonction
int	abs(int nb);
void tab_reset(char **dest, char **src);


//fermeture de la fenetre
int		key_hook(int key, void* param);
int		window_hook(int event, void* param);
int		update(void* param);
void	put_asked_image(char **tab_tiles, t_coordinates coordinates, t_tiles tiles);
void	put_asked_hero(t_coordinates *coordinates);
void	put_asked_object(t_coordinates coordinates);
void	put_asked_exit(t_coordinates *coordinates);
void	put_asked_coilhead(t_coordinates *coordinates);
void	destroy_img(t_tiles *tiles, t_coordinates coordinates);
void	destroy_hero(t_coordinates *coordinates);
void	destroy_object(t_coordinates *coordinates);
void	destroy_exit(t_coordinates *coordinates);
void	destroy_monster(t_coordinates *coordinates);

//la lumiere en face du mec
void	look_up(t_coordinates *coordinates);
void	look_left(t_coordinates *coordinates);
void	look_down(t_coordinates *coordinates);
void	look_right(t_coordinates *coordinates);

//cacher les tiles qui viennent d'etre afficher qudn on bouge
void	hide_tiles_light(t_coordinates *coordinates);
void	hide_tiles_light_up(t_coordinates *coordinates);
void	hide_tiles_light_down(t_coordinates *coordinates);
void	hide_tiles_light_left(t_coordinates *coordinates);
void	hide_tiles_light_right(t_coordinates *coordinates);

// mettretoute le image noir
void	put_img_base(t_coordinates *coordinates, t_tiles tiles);
void	put_shadow(t_coordinates coordinates);

void	define_img(int img_height, int img_width, t_tiles *tiles, t_coordinates coordinates);
void	define_hero(int img_height, int img_width, t_tiles *tiles, t_coordinates coordinates);
void	define_object(t_coordinates *coordinates);
void	define_exit(t_coordinates *coordinates);
void	define_player_look(t_coordinates *coordinates);
void	define_coilhead_go(t_coordinates *coordinates);
void	define_count(t_coordinates *coordinates);
void	define_monster(t_coordinates *coordinates);
void	define_search_p(t_coordinates *coordinates);

#include <stdio.h>

#endif
