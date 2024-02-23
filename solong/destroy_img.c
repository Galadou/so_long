/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:07:29 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 06:05:19 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	destroy_img(t_coord *coordinates)
{
	mlx_destroy_image(coordinates->m, coordinates->t.h_);
	mlx_destroy_image(coordinates->m, coordinates->t.z_);
	mlx_destroy_image(coordinates->m, coordinates->t.x_);
	mlx_destroy_image(coordinates->m, coordinates->t.a);
	mlx_destroy_image(coordinates->m, coordinates->t.b);
	mlx_destroy_image(coordinates->m, coordinates->t.l);
	mlx_destroy_image(coordinates->m, coordinates->t.l_);
	mlx_destroy_image(coordinates->m, coordinates->t._);
	mlx_destroy_image(coordinates->m, coordinates->t._7);
	mlx_destroy_image(coordinates->m, coordinates->t.k_);
	mlx_destroy_image(coordinates->m, coordinates->t.t_);
	mlx_destroy_image(coordinates->m, coordinates->t.u_);
	mlx_destroy_image(coordinates->m, coordinates->t.c);
	mlx_destroy_image(coordinates->m, coordinates->t.c_l);
	mlx_destroy_image(coordinates->m, coordinates->t.n);
	mlx_destroy_image(coordinates->m, coordinates->t.w);
	mlx_destroy_image(coordinates->m, coordinates->t.s);
	mlx_destroy_image(coordinates->m, coordinates->t.h);
}

void	destroy_exit(t_coord *coordinates)
{
	mlx_destroy_image(coordinates->m, coordinates->t.d_c);
	mlx_destroy_image(coordinates->m, coordinates->t.d_o);
	mlx_destroy_image(coordinates->m, coordinates->t.d_os);
	mlx_destroy_image(coordinates->m, coordinates->t.t_c);
	mlx_destroy_image(coordinates->m, coordinates->t.t_o);
	mlx_destroy_image(coordinates->m, coordinates->t.t_os);
}

void	destroy_hero(t_coord *coordinates)
{
	mlx_destroy_image(coordinates->m, coordinates->t.p_l);
	mlx_destroy_image(coordinates->m, coordinates->t.p_r);
	mlx_destroy_image(coordinates->m, coordinates->t.p_b);
	mlx_destroy_image(coordinates->m, coordinates->t.p_f);
}

void	destroy_object(t_coord *coordinates)
{
	mlx_destroy_image(coordinates->m, coordinates->t.o_l);
	mlx_destroy_image(coordinates->m, coordinates->t.o_b_br);
	mlx_destroy_image(coordinates->m, coordinates->t.o_b_bl);
	mlx_destroy_image(coordinates->m, coordinates->t.o_b_g);
	mlx_destroy_image(coordinates->m, coordinates->t.o_b_k);
	mlx_destroy_image(coordinates->m, coordinates->t.o_k);
	mlx_destroy_image(coordinates->m, coordinates->t.o_m);
	mlx_destroy_image(coordinates->m, coordinates->t.o_t_b);
	mlx_destroy_image(coordinates->m, coordinates->t.o_t_g);
	mlx_destroy_image(coordinates->m, coordinates->t.o_t_j);
	mlx_destroy_image(coordinates->m, coordinates->t.o_t_v);
	mlx_destroy_image(coordinates->m, coordinates->t.o_t_s);
}

void	destroy_monster(t_coord *coordinates)
{
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_f);
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_f_l);
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_f_r);
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_b);
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_b_l);
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_b_r);
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_l);
	mlx_destroy_image(coordinates->m, coordinates->t.m_c_r);
	mlx_destroy_image(coordinates->m, coordinates->t.m_monstre);
}
