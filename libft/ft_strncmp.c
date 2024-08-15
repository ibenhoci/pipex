/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:45:21 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/06 16:47:05 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (t1[i] && t2[i] && i < n - 1)
	{
		if (t1[i] != t2[i])
		{
			return (t1[i] - t2[i]);
		}
		i++;
	}
	return (t1[i] - t2[i]);
}
