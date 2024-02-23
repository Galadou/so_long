/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:00:35 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/25 18:35:57 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	hexa_base_16_lower(int n)
{
	unsigned int	nb;
	char			*str;
	int				c;

	c = 0;
	str = "0123456789abcdef";
	nb = n;
	if (nb > 15)
		hexa_base_16_lower(nb / 16);
	nb = nb % 16;
	write(1, &str[nb], 1);
	if (n < 0)
		c = 7;
	else
	{
		while (n > 15)
		{
			n = n / 16;
			c++;
		}
	}
	return (c + 1);
}

int	hexa_base_16_upper(int n)
{
	unsigned int	nb;
	char			*str;
	int				c;

	c = 0;
	str = "0123456789ABCDEF";
	nb = n;
	if (nb > 15)
		hexa_base_16_upper(nb / 16);
	nb = nb % 16;
	write(1, &str[nb], 1);
	if (n < 0)
		c = 7;
	else
	{
		while (n > 15)
		{
			n = n / 16;
			c++;
		}
	}
	return (c + 1);
}

int	hexa_base_16_pt(unsigned long int n)
{
	char				*str;
	int					c;

	c = 0;
	str = "0123456789abcdef";
	if (!n)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	if (n > 15)
		c = hexa_base_16_pt(n / 16);
	if (c == 0)
		c += write(1, "0x", 2);
	c += 1;
	n = n % 16;
	write(1, &str[n], 1);
	return (c);
}
