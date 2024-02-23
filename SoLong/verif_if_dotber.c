/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_if_dotber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 06:05:36 by gmersch           #+#    #+#             */
/*   Updated: 2024/02/19 06:05:39 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_dotber(char *map_ber)
{
	int	i;
	int	b;

	i = 0;
	while (map_ber[i])
	{
		if (map_ber[i] == '.')
		{
			b = i;
			i++;
			if (map_ber[i++] == 'b')
				if (map_ber[i++] == 'e')
					if (map_ber[i++] == 'r')
						if (map_ber[i++] == '\0')
							return (1);
			i = b;
		}
		i++;
	}
	return (0);
}
