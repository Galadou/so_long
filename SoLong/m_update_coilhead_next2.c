/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_update_coilhead_next2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 07:23:38 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/23 07:23:42 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	update_next_5(t_coord *co)
{
	if (co->coilhead.go_down == 1)
		head_moove_down(co);
	if (co->coilhead.go_up == 1)
		head_moove_up(co);
	if (co->coilhead.has_moove == 1 && co->coilhead.see_coilhead == 1)
		co->coilhead.has_moove = 0;
	if (co->coilhead.see_coilhead == 0)
	{
		update_coilhead_up(co);
		update_coilhead_left(co);
		update_coilhead_right(co);
		update_coilhead_down(co);
	}
}
