/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:44:18 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/03/28 17:00:28 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char		*x;
	unsigned int	i;

	i = 0;
	x = (const char *)str;
	while (i < n)
	{
		if ((unsigned char)x[i] == (unsigned char)c)
			return ((unsigned char *)(x + i));
		i++;
	}
	return (NULL);
}
