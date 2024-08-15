/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:31:50 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/01 19:10:39 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_node;

	if (lst)
	{
		if ((*lst) == NULL)
		{
			(*lst) = new;
		}
		else
		{
			lst_node = ft_lstlast(*lst);
			lst_node->next = new;
		}
	}
}
