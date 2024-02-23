/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 02:22:13 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 02:32:14 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	find_apropriate_tiles_next(char **tab, int y, int x)
{
	if (tab[y -1][x] == '1' && tab[y][x - 1] == '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
		return ('b');
	if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] == '1' && tab[y][x + 1] == '1')
		return ('l');
	if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && \
	tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
		return ('L');
	if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
		return ('_');
	if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
		return ('7');
	if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
		return ('K');
	if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
		return ('T');
	return (0);
}

static char	find_apropriate_tiles(char **tab, int y, int x)
{
	if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && \
	tab[y + 1][x] == '1' && tab[y][x + 1] == '1')
		return ('U');
	if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] == '1' && tab[y][x + 1] == '1')
		return (']');
	if (tab[y -1][x] == '1' && tab[y][x - 1] == '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
		return ('n');
	if (tab[y -1][x] == '1' && tab[y][x - 1] == '1' && \
	tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
		return ('c');
	if (tab[y -1][x] != '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] != '1')
		return ('X');
	if (tab[y -1][x] != '1' && tab[y][x - 1] == '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
		return ('H');
	if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] == '1' && tab[y][x + 1] != '1')
		return ('Z');
	if (tab[y -1][x] == '1' && tab[y][x - 1] != '1' && \
	tab[y + 1][x] != '1' && tab[y][x + 1] == '1')
		return ('a');
	return (find_apropriate_tiles_next(tab, y, x));
}

void	tab_transform_for_tiles(char **tab)
{
	int	y;
	int	x;

	y = 1;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] != '1')
				tab[y][x] = find_apropriate_tiles(tab, y, x);
			x++;
		}
		y++;
	}
}

static char	find_apropriate_exit(char **tab, int y, int x)
{
	if (tab[y - 1][x] == '1')
		return ('t');
	if (tab[y][x - 1] == '1')
		return ('l');
	if (tab[y][x + 1] == '1')
		return ('r');
	return ('m');
}

void	tab_transform_for_exit(char **tab)
{
	int	y;
	int	x;

	y = 1;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'E')
				tab[y][x] = find_apropriate_exit(tab, y, x);
			x++;
		}
		y++;
	}
}
