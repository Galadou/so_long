/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <gmersch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 06:35:14 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/21 00:04:40 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	verif_rectangle(char *map_ber, size_t *l, size_t *c, int error)
{
	int		fd;
	char	*line;

	fd = open(map_ber, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (2);
	*c = ft_strlen(line);
	if (line)
		*l = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*c != ft_strlen(line))
			error = 1;
		*l += 1;
	}
	close(fd);
	if (*l < 2 || error == 1)
		return (0);
	return (1);
}
