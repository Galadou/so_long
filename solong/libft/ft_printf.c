/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:49:11 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/22 16:10:36 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static	int	type_finder(char c, va_list lst)
{
	if (c == 'd')
		return (ft_putnbr_pf(va_arg(lst, int)));
	else if (c == 'c')
		return (ft_putchar_pf((char)va_arg(lst, int)));
	else if (c == 's')
		return (ft_putstr_pf(va_arg(lst, char *)));
	else if (c == 'i')
		return (ft_putnbr_pf(va_arg(lst, long int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned_pf(va_arg(lst, unsigned int)));
	else if (c == 'x')
		return (hexa_base_16_lower(va_arg(lst, int)));
	else if (c == 'X')
		return (hexa_base_16_upper(va_arg(lst, int)));
	else if (c == 'p')
		return (hexa_base_16_pt(va_arg(lst, unsigned long)));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

static void	percent_or_write(va_list lst, int *result, int *i, const char *str)
{
	if (str[*i] == '%' && str[*i + 1] != '\0')
	{
		*result = *result + type_finder(str[*i + 1], lst);
		*i = *i + 1;
	}
	else
		write(1, &str[*i], 1);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	int		i;
	va_list	lst;

	if (str == NULL)
		return (-1);
	i = 0;
	result = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		percent_or_write(lst, &result, &i, str);
		i++;
	}
	va_end(lst);
	return (ft_strlen_pf(str) + result);
}
