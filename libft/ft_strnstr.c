/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:45:27 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/03 14:49:59 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0] && i + ft_strlen(little) <= len)
		{
			if (!ft_strncmp(big + i, little, ft_strlen(little)))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
