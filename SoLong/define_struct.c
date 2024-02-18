#include "header.h"

void    define_img(int img_height, int img_width, t_tiles *tiles, t_coordinates coordinates)
{
	tiles->hall_H = mlx_png_file_to_image(coordinates.mlx, "tiles/front_back/hall_H.png", &img_width, &img_height);
	tiles->hall_Z = mlx_png_file_to_image(coordinates.mlx, "tiles/front_back/hall_Z.png", &img_width, &img_height);
	tiles->hall_X = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_O.png", &img_width, &img_height);
	tiles->hall_a = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_>.png", &img_width, &img_height);
	tiles->hall_b = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_<.png", &img_width, &img_height);
	tiles->hall_l = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_l.png", &img_width, &img_height);
	tiles->hall_L = mlx_png_file_to_image(coordinates.mlx, "tiles/turn/hall_L.png", &img_width, &img_height);
	tiles->hall_ = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/_.png", &img_width, &img_height);
	tiles->hall_7 = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/7.png", &img_width, &img_height);
	tiles->hall_K = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/K.png", &img_width, &img_height);
	tiles->hall_T = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_t/T.png", &img_width, &img_height);
	tiles->hall_U = mlx_png_file_to_image(coordinates.mlx, "tiles/u/U.png", &img_width, &img_height);
	tiles->hall_c_left = mlx_png_file_to_image(coordinates.mlx, "tiles/u/].png", &img_width, &img_height);
	tiles->hall_c = mlx_png_file_to_image(coordinates.mlx, "tiles/u/c.png", &img_width, &img_height);
	tiles->hall_n = mlx_png_file_to_image(coordinates.mlx, "tiles/u/n.png", &img_width, &img_height);
	tiles->wall = mlx_png_file_to_image(coordinates.mlx, "tiles/wall.png", &img_width, &img_height);
	tiles->shadow = mlx_png_file_to_image(coordinates.mlx, "tiles/opacity.png", &img_width, &img_height);
	tiles->hall_hide = mlx_png_file_to_image(coordinates.mlx, "tiles/hall_hide.png", &img_width, &img_height);
}
void    define_hero(int img_height, int img_width, t_tiles *tiles, t_coordinates coordinates)
{
	tiles->p_left = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_left.png", &img_width, &img_height);
    tiles->p_right = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_right.png", &img_width, &img_height);
    tiles->p_back = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_back.png", &img_width, &img_height);
    tiles->p_front = mlx_png_file_to_image(coordinates.mlx, "tiles/hero/p_front.png", &img_width, &img_height);
}

void	define_exit(t_coordinates *coordinates)
{
	coordinates->tiles.exit_door_close = mlx_png_file_to_image(coordinates->mlx, "tiles/exit/door/door_close.png", &coordinates->img_width, &coordinates->img_height);
    coordinates->tiles.exit_door_open = mlx_png_file_to_image(coordinates->mlx, "tiles/exit/door/door_open.png", &coordinates->img_width, &coordinates->img_height);
    coordinates->tiles.exit_door_smile = mlx_png_file_to_image(coordinates->mlx, "tiles/exit/door/door_open_smile.png", &coordinates->img_width, &coordinates->img_height);
    coordinates->tiles.exit_trap_close = mlx_png_file_to_image(coordinates->mlx, "tiles/exit/trap/trap_close.png", &coordinates->img_width, &coordinates->img_height);
    coordinates->tiles.exit_trap_open = mlx_png_file_to_image(coordinates->mlx, "tiles/exit/trap/trap_open.png", &coordinates->img_width, &coordinates->img_height);
    coordinates->tiles.exit_trap_smile = mlx_png_file_to_image(coordinates->mlx, "tiles/exit/trap/trap_open_smile.png", &coordinates->img_width, &coordinates->img_height);
}
void	define_object(t_coordinates *coordinates)
{
	coordinates->tiles.obj_light = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/TORCHE.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_key = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/cle.png", &coordinates->img_width, &coordinates->img_height);

	coordinates->tiles.obj_t_bleu = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/obj_tete_base/bleu.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_t_grise = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/obj_tete_base/grise.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_t_jaune= mlx_png_file_to_image(coordinates->mlx, "tiles/obj/obj_tete_base/jaune.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_t_vert = mlx_png_file_to_image(coordinates->mlx, "tiles/obj//obj_tete_base/vert.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_t_sang = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/obj_tete_base/sang.png", &coordinates->img_width, &coordinates->img_height);

//ourson
	coordinates->tiles.obj_beer_cub_brown = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/ourson_brun.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_beer_cub_blue = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/ourson_bleu.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_beer_cub_green = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/ourson_vert.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_beer_cub_korgeister = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/ourson_shiny.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.obj_mask = mlx_png_file_to_image(coordinates->mlx, "tiles/obj/masque_Korgeister.png", &coordinates->img_width, &coordinates->img_height);
}

void	define_monster(t_coordinates *coordinates)
{
	coordinates->tiles.m_coil_front = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_face.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.m_coil_front_left = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_head_l.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.m_coil_front_right = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_head_r.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.m_coil_back = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_back.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.m_coil_back_left = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_back_l.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.m_coil_back_right = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_back_r.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.m_coil_left = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_left.png", &coordinates->img_width, &coordinates->img_height);
	coordinates->tiles.m_coil_right = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/coilhead_right.png", &coordinates->img_width, &coordinates->img_height);

	coordinates->tiles.m_little_girl = mlx_png_file_to_image(coordinates->mlx, "tiles/Monster/little_girl.png", &coordinates->img_width, &coordinates->img_height);
}

void	define_player_look(t_coordinates *coordinates)
{
	coordinates->player_look.up = 0;
	coordinates->player_look.down = 0;
	coordinates->player_look.left = 0;
	coordinates->player_look.right = 0;
}
void	define_coilhead_go(t_coordinates *coordinates)
{
	coordinates->coilhead.go_up = 0;
	coordinates->coilhead.go_left = 0;
	coordinates->coilhead.go_down = 0;
	coordinates->coilhead.go_right = 0;
}

void define_count(t_coordinates *coordinates)
{
		coordinates->nb_obj_take = 0;
		coordinates->light = 0;
		coordinates->bearKorgeister = 0;
		coordinates->door_look_far = 0;
		coordinates->exit_here = 0;
		coordinates->nb_beer_cub_take = 0;
		coordinates->nb_beer_cub = 0;
		coordinates->nb_find_obj = 0;
		coordinates->coilhead.y = 0;
		coordinates->coilhead.x = 0;
		coordinates->coilhead.see_coilhead = 0;
		coordinates->coilhead.far_p_y = 0;
		coordinates->coilhead.far_p_x = 0;
		coordinates->coilhead.far_p_y_buf = 0;
		coordinates->coilhead.far_p_x_buf= 0;
		coordinates->coilhead.has_moove = 0;
		coordinates->coilhead.frame = 0;
		coordinates->coilhead.can_moove = 0;
		coordinates->one_time = 0;
		coordinates->i = 0;
		coordinates->mid_second = 0;
		coordinates->player_dead = 0;
		coordinates->nb_moove = 0;
		coordinates->string_count_moove = "0";
}
/*void define_search_p(t_coordinates *coordinates)
{
	coordinates->coilhead.h = coordinates->l * coordinates->c;
	coordinates->coilhead.b = coordinates->l * coordinates->c;
	coordinates->coilhead.g = coordinates->l * coordinates->c;
	coordinates->coilhead.d = coordinates->l * coordinates->c;
}*/
void define_tab(t_coordinates *coordinates, char **argv)
{
	coordinates->tab.tab_0_1 = tab_creator(argv[1], coordinates->l, coordinates->c);
	coordinates->tab.tab_dupp_coilhead_moove_up = tab_creator(argv[1], coordinates->l, coordinates->c);
	coordinates->tab.tab_dupp_coilhead_moove_right = tab_creator(argv[1], coordinates->l, coordinates->c);
	coordinates->tab.tab_dupp_coilhead_moove_left = tab_creator(argv[1], coordinates->l, coordinates->c);
	coordinates->tab.tab_dupp_coilhead_moove_down = tab_creator(argv[1], coordinates->l, coordinates->c);
	coordinates->tab.tab_dupp_coilhead_moove = tab_creator(argv[1], coordinates->l, coordinates->c);

	coordinates->tab.tab_tiles = tab_creator(argv[1], coordinates->l, coordinates->c);
	coordinates->tab.tab_dup_monsterspawn = tab_creator(argv[1], coordinates->l, coordinates->c);

}
