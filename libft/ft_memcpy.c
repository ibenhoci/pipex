/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:44:34 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/03/22 19:59:22 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*x;
	char	*y;

	if (dest == NULL && src == NULL)
		return (NULL);
	x = (char *)dest;
	y = (char *)src;
	while (n > 0)
	{
		*x = *y;
		x++;
		y++;
		n--;
	}
	return (dest);
}
