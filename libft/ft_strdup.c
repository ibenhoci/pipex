/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenhoci <ibenhoci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:44:39 by ibenhoci          #+#    #+#             */
/*   Updated: 2023/04/05 18:19:09 by ibenhoci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*x;

	i = ft_strlen(str);
	x = (char *)malloc(i + 1);
	if (x == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		x[i] = str[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}
