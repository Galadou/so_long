/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_fonction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:33:19 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/24 18:33:59 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static int	if_int_min(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	ft_putnbr_pf(int n)
{
	unsigned int	nb;
	int				c;
	int				count;

	count = 0;
	if (n == -2147483648)
		return (if_int_min());
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		count++;
	}
	nb = n;
	if (nb > 9)
		ft_putnbr_pf((nb / 10));
	nb = nb % 10;
	c = nb + '0';
	write(1, &c, 1);
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

int	ft_putnbr_unsigned_pf(unsigned int n)
{
	unsigned int	nb;
	int				count;
	int				c;

	count = 0;
	nb = n;
	if (nb > 9)
		ft_putnbr_unsigned_pf((nb / 10));
	nb = nb % 10;
	c = nb + '0';
	write(1, &c, 1);
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

int	ft_putchar_pf(char letter)
{
	write(1, &letter, 1);
	return (1);
}

int	ft_putstr_pf(char	*str)
{
	int	i;

	i = 0;
	if (!str || str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen_pf(str));
}
