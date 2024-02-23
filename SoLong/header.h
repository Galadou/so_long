/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 06:37:26 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 17:54:13 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "MacroLibX/includes/mlx.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include "libft/includes/ftprintf.h"

# include <SDL2/SDL.h>
# include <time.h>

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
	int	far_p_y;
	int	far_p_x;
	int	far_p_y_buf;
	int	far_p_x_buf;

	int	has_moove;
	int	frame;
	int	can_moove;

	int	go_up;
	int	go_left;
	int	go_down;
	int	go_right;

}	t_coilhead;

typedef struct s_tiles
{
	void	*h_;
	void	*z_;
	void	*x_;
	void	*a;
	void	*b;
	void	*l;
	void	*l_;
	void	*_;
	void	*_7;
	void	*k_;
	void	*t_;
	void	*u_;
	void	*c_l;
	void	*c;
	void	*n;
	void	*w;
	void	*s;
	void	*h;

	void	*d_c;
	void	*d_o;
	void	*d_os;
	void	*t_c;
	void	*t_o;
	void	*t_os;

	void	*p_l;
	void	*p_r;
	void	*p_b;
	void	*p_f;

	void	*o_l;
	void	*o_k;

	void	*o_t_b;
	void	*o_t_g;
	void	*o_t_j;
	void	*o_t_v;
	void	*o_t_s;

	void	*o_b_br;
	void	*o_b_bl;
	void	*o_b_g;
	void	*o_b_k;
	void	*o_m;

	void	*m_c_f;
	void	*m_c_f_l;
	void	*m_c_f_r;
	void	*m_c_b;
	void	*m_c_b_l;
	void	*m_c_b_r;
	void	*m_c_l;
	void	*m_c_r;
	void	*m_monstre;

}	t_tiles;

typedef struct s_player_look
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_player_look;

typedef struct coordinates
{
	void			*m;
	void			*w;

	int				t_y;
	int				t_x;

	int				wi;
	int				h;
	int				y;
	int				x;

	int				buffer_y;
	int				buffer_x;

	size_t			l;
	size_t			c;

	int				nb_obj_in;

	int				nb_find_obj;
	int				nb_obj_take;
	int				nb_beer_cub;
	int				light;
	int				bearkorgeister;

	int				frame;

	t_player_look	player_look;
	t_tiles			t;
	t_tab			tab;
	t_coilhead		coilhead;
	time_t			one_time;
	time_t			times;
	time_t			times_buf;
	time_t			times_count;
	time_t			time_bonus;

	int				door_look_far;
	int				exit_here;
	int				nb_head;
	int				nb_beer_cub_take;

	int				m_speed;
	int				m_find_speed;
	int				monster_show;
	int				mid_second;
	int				player_dead;

	int				exit_get_out;

	char			*string_count_move;
	char			*string_nb_obj_in;
	char			*string_bearkorgeister;
	int				nb_moove;
}	t_coord;

void	ultimate_free(t_coord *c);
void	game(t_coord *coordinates);
int		window_view_and_game(t_coord *coordinates);
char	**tab_creator(char *map_ber, int l, int c);
int		define_tab(t_coord *coordinates, char **argv);
void	tab_transform_for_tiles(char **tab);
void	tab_transform_for_exit(char **tab);
void	number_to_string(int n, t_coord *coordinates);

int		verif_map(char *map_ber, t_coord *coordinates);
int		is_dotber(char *map_ber);
int		verif_rectangle(char *map_ber, size_t *l, size_t *c, int error);
int		verif_one_and_zero(char **tab, int l, int c, int *C);
int		verif_player_can_exit(char **tab, int C);

void	can_i_exit(t_coord *coordinates);
void	is_exit_here(t_coord *coordinates);
void	get_out(t_coord *coordinates);

void	is_obj_here(t_coord *coordinates);
void	take_obj(t_coord *coordinates);

void	monster_spawn(t_coord *coordinates);
void	coilhead_moove(t_coord *coordinates);
void	is_coilhead_here(t_coord *coordinates, int y, int x);
void	head_moove_down(t_coord *coordinates);
void	head_moove_up(t_coord *coordinates);
void	kill_player(t_coord *coordinates);
void	coilhead_moove_next(t_coord *coordinates);
void	head_moove_down_next(t_coord *coordinates);
void	head_moove_up_next(t_coord *coordinates);
void	where_coilhead_spawn_recursive_next(t_coord *c);
void	m_search_player(t_coord *co);

int		abs(int nb);
void	tab_reset(char **dest, char **src);

int		key_hook(int key, void *param);
void	key_hook_close(int key, t_coord *coordinates);
void	key_hook_look(int key, t_coord *coordinates);
void	key_hook_move(int key, t_coord *coordinates);
int		window_hook(int event, void *param);

void	playermove_p1(t_coord *coordinates);
void	playermove_p2(t_coord *coordinates);
void	playersee_p1(t_coord *coordinates);
void	playersee_p2(t_coord *coordinates);

int		update(void *param);
void	update_next(t_coord *coordinates);
void	update_next_5(t_coord *co);
void	update_coilhead_up(t_coord *coordinates);
void	update_coilhead_left(t_coord *coordinates);
void	update_coilhead_down(t_coord *coordinates);
void	update_coilhead_right(t_coord *coordinates);

void	put_asked_image(t_coord *coordinates);
void	put_asked_hero(t_coord *coordinates);
void	put_asked_object(t_coord *coordinates);
void	put_asked_exit(t_coord *coordinates);
void	put_asked_coilhead(t_coord *coordinates);
void	destroy_img(t_coord *coordinates);
void	destroy_hero(t_coord *coordinates);
void	destroy_object(t_coord *coordinates);
void	destroy_exit(t_coord *coordinates);
void	destroy_monster(t_coord *coordinates);

void	look_up(t_coord *coordinates);
void	look_up_next(t_coord *co);
void	look_left(t_coord *coordinates);
void	look_left_next(t_coord *co);
void	look_down(t_coord *coordinates);
void	look_down_next(t_coord *co);
void	look_right(t_coord *coordinates);
void	look_right_next(t_coord *co);

void	hide_tiles_light(t_coord *coordinates);
void	hide_tiles_light_up(t_coord *coordinates);
void	hide_tiles_light_down(t_coord *coordinates);
void	hide_tiles_light_left(t_coord *coordinates);
void	hide_tiles_light_right(t_coord *coordinates);
void	hide_tiles_light_up_next(t_coord *coordinates, \
int buffer_x, int buffer_y);
void	hide_tiles_light_left_next(t_coord *coordinates, \
int buffer_x, int buffer_y);
void	hide_tiles_light_down_next(t_coord *coordinates, \
int buffer_x, int buffer_y);
void	hide_tiles_light_right_next(t_coord *coordinates, \
int buffer_x, int buffer_y);

void	put_img_base(t_coord *coordinates, t_tiles tiles);
void	put_shadow(t_coord *coordinates);

void	define_img(t_coord *co);
void	def_hero(t_coord *co);
void	define_object(t_coord *coordinates);
void	define_exit(t_coord *coordinates);
void	define_player_look(t_coord *coordinates);
void	define_coilhead_go(t_coord *coordinates);
void	define_count(t_coord *coordinates);
void	define_monster(t_coord *coordinates);
void	define_search_p(t_coord *coordinates);

#endif
