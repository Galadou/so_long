/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_fonction_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:26:31 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/27 16:26:37 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

size_t	ft_strlen_pf(const char *s)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			i = i + 2;
		else
		{
			c++;
			i++;
		}
	}
	return (c);
}