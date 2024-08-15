/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:44:53 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/03/28 16:55:15 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((char)c == str[i])
			return ((char *)str + i);
		i++;
	}
	if ((char)c == str[i])
		return ((char *)str + i);
	return (NULL);
}
