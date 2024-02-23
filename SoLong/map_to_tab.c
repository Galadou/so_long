/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:44:35 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 02:21:54 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**tab_creator(char *map_ber, int l, int c)
{
	int		fd;
	char	*line;
	int		i;
	char	**tab;

	fd = open(map_ber, O_RDONLY);
	line = get_next_line(fd);
	tab = ft_calloc(l + 1, sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (line)
	{
		tab[i] = ft_calloc(c + 1, sizeof(char));
		if (!tab[i])
			return (0);
		ft_strlcpy(tab[i], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (tab);
}
