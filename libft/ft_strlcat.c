/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:44:57 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/03/28 16:57:17 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dstlen;
	size_t	i;

	i = 0;
	while (i < n && dst[i])
		i++;
	dstlen = ft_strlcpy(dst + i, src, n - i);
	return (dstlen + i);
}
