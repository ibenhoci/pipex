/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:56:50 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/05/11 10:17:39 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*x;
	unsigned int	i;

	i = 0;
	if (ft_strlen(s) < start)
	{
		x = malloc(1);
		if (x == NULL)
			return (NULL);
		x[0] = '\0';
		return (x);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (x == NULL)
		return (NULL);
	while (i < len)
	{
		x[i] = s[start + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
