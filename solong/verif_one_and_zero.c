/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_one_and_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 06:09:05 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 06:35:50 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_rule_respected(char **tab, int *C)
{
	int	e;
	int	p;
	int	i;
	int	f;

	e = 0;
	p = 0;
	i = -1;
	while (tab[++i])
	{
		f = 0;
		while (tab[i][f])
		{
			if (tab[i][f] == 'E')
				e++;
			if (tab[i][f] == 'P')
				p++;
			if (tab[i][f] == 'C')
				*C = *C + 1;
			f++;
		}
	}
	if (e != 1 || p != 1 || *C < 1)
		return (0);
	return (1);
}

static int	verif_if_close_next(char **tab, int l, int y)
{
	while (tab[l][y])
	{
		if (tab[l][y] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	verif_if_close(char **tab, int l, int c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	c--;
	l--;
	while (tab[x][y])
	{
		if (tab[x][y] != '1')
			return (0);
		y++;
	}
	while (tab[x])
	{
		if (tab[x][0] != '1' || tab[x][c] != '1')
			return (0);
		x++;
	}
	y = 0;
	if (verif_if_close_next(tab, l, y) == 0)
		return (0);
	return (1);
}

int	verif_one_and_zero(char **tab, int l, int c, int *C)
{
	int	i;
	int	f;

	i = 0;
	while (tab[i])
	{
		f = 0;
		while (tab[i][f])
		{
			if (tab[i][f] != '0' && tab[i][f] != '1' &&
			tab[i][f] != 'E' && tab[i][f] != 'P' && tab[i][f] != 'C')
				return (0);
			f++;
		}
		i++;
	}
	if (verif_if_close(tab, l, c) == 0)
		return (0);
	if (is_rule_respected(tab, C) == 0)
		return (0);
	return (1);
}
