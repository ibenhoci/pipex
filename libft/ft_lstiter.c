/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:27:41 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/01 18:31:37 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && (*f))
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
