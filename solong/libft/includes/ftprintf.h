/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:40:07 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/24 18:41:21 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putnbr_pf(int n);
int		ft_putnbr_unsigned_pf(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_putchar_pf(char letter);
int		ft_putstr_pf(char	*str);
int		hexa_base_16_lower(int n);
int		hexa_base_16_upper(int n);
int		hexa_base_16_pt(unsigned long int n);
size_t	ft_strlen_pf(const char *s);

#endif
