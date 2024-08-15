/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:44:38 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/05 13:49:20 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_goodcopy(char *dest, char *src, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	*ft_badcopy(char *dest, char *src, size_t n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src && dest - src < (int)n)
	{
		d = ft_badcopy(d, s, n);
		return (dest);
	}
	if (dest < src && src - dest < (int)n)
	{
		d = ft_goodcopy(d, s, n);
		return (dest);
	}
	ft_memcpy(d, s, n);
	return (dest);
}
