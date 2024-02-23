/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_player_can_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 06:31:35 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 06:53:33 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	verif_player_can_exit_r(char **tab, int y, int x, t_loot_exit *l_ex)
{
	if (tab[y][x] == 'E')
		l_ex->e++;
	if (tab[y][x] == 'C')
		l_ex->c = l_ex->c + 1;
	tab[y][x] = '1';
	if (tab[y - 1][x] != '1')
		verif_player_can_exit_r(tab, y - 1, x, l_ex);
	if (tab[y][x - 1] != '1')
		verif_player_can_exit_r(tab, y, x - 1, l_ex);
	if (tab[y + 1][x] != '1')
		verif_player_can_exit_r(tab, y + 1, x, l_ex);
	if (tab[y][x + 1] != '1')
		verif_player_can_exit_r(tab, y, x + 1, l_ex);
}

int	verif_player_can_exit(char **tab, int C)
{
	int			y;
	int			x;
	t_loot_exit	loot_exit;

	y = 0;
	loot_exit.c = 0;
	loot_exit.e = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'P')
				break ;
			x++;
		}
		if ((size_t)x != ft_strlen(tab[0]))
			break ;
		y++;
	}
	verif_player_can_exit_r(tab, y, x, &loot_exit);
	if (loot_exit.e == 1 && loot_exit.c == C)
		return (1);
	return (0);
}
