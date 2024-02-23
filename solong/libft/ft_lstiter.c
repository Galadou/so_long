/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmersch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:40:37 by gmersch           #+#    #+#             */
/*   Updated: 2023/11/19 16:40:40 by gmersch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*b;

	if (!lst || !f)
		return ;
	while (lst)
	{
		b = (lst)->next;
		f((lst)->content);
		lst = b;
	}
}