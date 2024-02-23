/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:20:06 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 06:05:06 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	define_img(t_coord *co)
{
	co->t.h_ = mlx_png_file_to_image(co->m, "t/H.png", &co->wi, &co->h);
	co->t.z_ = mlx_png_file_to_image(co->m, "t/Z.png", &co->wi, &co->h);
	co->t.x_ = mlx_png_file_to_image(co->m, "t/O.png", &co->wi, &co->h);
	co->t.a = mlx_png_file_to_image(co->m, "t/>.png", &co->wi, &co->h);
	co->t.b = mlx_png_file_to_image(co->m, "t/<.png", &co->wi, &co->h);
	co->t.l = mlx_png_file_to_image(co->m, "t/l.png", &co->wi, &co->h);
	co->t.l_ = mlx_png_file_to_image(co->m, "t/L.png", &co->wi, &co->h);
	co->t._ = mlx_png_file_to_image(co->m, "t/_.png", &co->wi, &co->h);
	co->t._7 = mlx_png_file_to_image(co->m, "t/7.png", &co->wi, &co->h);
	co->t.k_ = mlx_png_file_to_image(co->m, "t/K.png", &co->wi, &co->h);
	co->t.t_ = mlx_png_file_to_image(co->m, "t/T.png", &co->wi, &co->h);
	co->t.u_ = mlx_png_file_to_image(co->m, "t/U.png", &co->wi, &co->h);
	co->t.c_l = mlx_png_file_to_image(co->m, "t/].png", &co->wi, &co->h);
	co->t.c = mlx_png_file_to_image(co->m, "t/c.png", &co->wi, &co->h);
	co->t.n = mlx_png_file_to_image(co->m, "t/n.png", &co->wi, &co->h);
	co->t.w = mlx_png_file_to_image(co->m, "t/wall.png", &co->wi, &co->h);
	co->t.s = mlx_png_file_to_image(co->m, "t/opa.png", &co->wi, &co->h);
	co->t.h = mlx_png_file_to_image(co->m, "t/hide.png", &co->wi, &co->h);
}

void	def_hero(t_coord *c)
{
	c->t.p_l = mlx_png_file_to_image(c->m, "t/p_l.png", &c->wi, &c->h);
	c->t.p_r = mlx_png_file_to_image(c->m, "t/p_r.png", &c->wi, &c->h);
	c->t.p_b = mlx_png_file_to_image(c->m, "t/p_b.png", &c->wi, &c->h);
	c->t.p_f = mlx_png_file_to_image(c->m, "t/p_f.png", &c->wi, &c->h);
}

void	define_exit(t_coord *c)
{
	c->t.d_c = mlx_png_file_to_image(c->m, "t/d_c.png", &c->wi, &c->h);
	c->t.d_o = mlx_png_file_to_image(c->m, "t/d_o.png", &c->wi, &c->h);
	c->t.d_os = mlx_png_file_to_image(c->m, "t/d_os.png", &c->wi, &c->h);
	c->t.t_c = mlx_png_file_to_image(c->m, "t/t_c.png", &c->wi, &c->h);
	c->t.t_o = mlx_png_file_to_image(c->m, "t/t_o.png", &c->wi, &c->h);
	c->t.t_os = mlx_png_file_to_image(c->m, "t/t_os.png", &c->wi, &c->h);
}

void	define_object(t_coord *c)
{
	c->t.o_l = mlx_png_file_to_image(c->m, "t/o_TO.png", &c->wi, &c->h);
	c->t.o_k = mlx_png_file_to_image(c->m, "t/o_cle.png", &c->wi, &c->h);
	c->t.o_t_b = mlx_png_file_to_image(c->m, "t/o_bleu.png", &c->wi, &c->h);
	c->t.o_t_g = mlx_png_file_to_image(c->m, "t/o_grise.png", &c->wi, &c->h);
	c->t.o_t_j = mlx_png_file_to_image(c->m, "t/o_jaune.png", &c->wi, &c->h);
	c->t.o_t_v = mlx_png_file_to_image(c->m, "t/o_vert.png", &c->wi, &c->h);
	c->t.o_t_s = mlx_png_file_to_image(c->m, "t/o_sang.png", &c->wi, &c->h);
	c->t.o_b_br = mlx_png_file_to_image(c->m, "t/o_o_br.png", &c->wi, &c->h);
	c->t.o_b_bl = mlx_png_file_to_image(c->m, "t/o_o_bl.png", &c->wi, &c->h);
	c->t.o_b_g = mlx_png_file_to_image(c->m, "t/o_o_v.png", &c->wi, &c->h);
	c->t.o_b_k = mlx_png_file_to_image(c->m, "t/o_o_s.png", &c->wi, &c->h);
	c->t.o_m = mlx_png_file_to_image(c->m, "t/o_mK.png", &c->wi, &c->h);
}

void	define_monster(t_coord *c)
{
	c->t.m_c_f = mlx_png_file_to_image(c->m, "t/m_c_f.png", &c->wi, &c->h);
	c->t.m_c_f_l = mlx_png_file_to_image(c->m, "t/m_c_h_l.png", &c->wi, &c->h);
	c->t.m_c_f_r = mlx_png_file_to_image(c->m, "t/m_c_h_r.png", &c->wi, &c->h);
	c->t.m_c_b = mlx_png_file_to_image(c->m, "t/m_c_b.png", &c->wi, &c->h);
	c->t.m_c_b_l = mlx_png_file_to_image(c->m, "t/m_c_b_l.png", &c->wi, &c->h);
	c->t.m_c_b_r = mlx_png_file_to_image(c->m, "t/m_c_b_r.png", &c->wi, &c->h);
	c->t.m_c_l = mlx_png_file_to_image(c->m, "t/m_c_l.png", &c->wi, &c->h);
	c->t.m_c_r = mlx_png_file_to_image(c->m, "t/m_c_r.png", &c->wi, &c->h);
	c->t.m_monstre = mlx_png_file_to_image(c->m, \
	"t/monstre.png", &c->wi, &c->h);
}
