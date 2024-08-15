/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:44:30 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/03/22 19:20:43 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*x;
	unsigned const char	*y;

	x = (unsigned const char *)s1;
	y = (unsigned const char *)s2;
	while (n > 0)
	{
		if (*x != *y)
			return (*x - *y);
		x++;
		y++;
		n--;
	}
	return (0);
}
