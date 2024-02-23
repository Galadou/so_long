/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:19:56 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 02:19:58 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ultimate_free_next1(t_coord *c)
{
	int	i;

	if (c->tab.tab_dupp_coilhead_moove_right)
	{
		i = 0;
		while (c->tab.tab_dupp_coilhead_moove_right[i])
		{
			free(c->tab.tab_dupp_coilhead_moove_right[i]);
			i++;
		}
		free(c->tab.tab_dupp_coilhead_moove_right);
	}
	if (c->tab.tab_dupp_coilhead_moove_up)
	{
		i = 0;
		while (c->tab.tab_dupp_coilhead_moove_up[i])
		{
			free(c->tab.tab_dupp_coilhead_moove_up[i]);
			i++;
		}
		free(c->tab.tab_dupp_coilhead_moove_up);
	}
}

static void	ultimate_free_next2(t_coord *c)
{
	int	i;

	if (c->tab.tab_dupp_coilhead_moove_down)
	{
		i = 0;
		while (c->tab.tab_dupp_coilhead_moove_down[i])
		{
			free(c->tab.tab_dupp_coilhead_moove_down[i]);
			i++;
		}
		free(c->tab.tab_dupp_coilhead_moove_down);
	}
	if (c->tab.tab_dupp_coilhead_moove_left)
	{
		i = 0;
		while (c->tab.tab_dupp_coilhead_moove_left[i])
		{
			free(c->tab.tab_dupp_coilhead_moove_left[i]);
			i++;
		}
		free(c->tab.tab_dupp_coilhead_moove_left);
	}
}

static void	ultimate_free_next3(t_coord *c)
{
	int	i;

	if (c->tab.tab_dup_monsterspawn)
	{
		i = 0;
		while (c->tab.tab_dup_monsterspawn[i])
		{
			free(c->tab.tab_dup_monsterspawn[i]);
			i++;
		}
		free(c->tab.tab_dup_monsterspawn);
	}
	if (c->tab.tab_dupp_coilhead_moove)
	{
		i = 0;
		while (c->tab.tab_dupp_coilhead_moove[i])
		{
			free(c->tab.tab_dupp_coilhead_moove[i]);
			i++;
		}
		free(c->tab.tab_dupp_coilhead_moove);
	}
}

void	ultimate_free(t_coord *c)
{
	int	i;

	if (c->tab.tab_0_1)
	{
		i = 0;
		while (c->tab.tab_0_1[i])
		{
			free(c->tab.tab_0_1[i]);
			i++;
		}
		free(c->tab.tab_0_1);
	}
	if (c->tab.tab_tiles)
	{
		i = 0;
		while (c->tab.tab_tiles[i])
		{
			free(c->tab.tab_tiles[i]);
			i++;
		}
		free(c->tab.tab_tiles);
	}
	ultimate_free_next1(c);
	ultimate_free_next2(c);
	ultimate_free_next3(c);
}
